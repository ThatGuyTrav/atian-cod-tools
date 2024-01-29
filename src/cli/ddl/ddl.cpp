#include "ddlBaseVisitor.h"
#include "ddlLexer.h"
#include "ddlParser.h"
#include "ddlVisitor.h"
#include <includes.hpp>

using namespace antlr4;
using namespace antlr4::tree;

#pragma push_macro("ERROR")
#undef ERROR
constexpr auto TREE_ERROR = ParseTreeType::ERROR;
constexpr auto TREE_RULE = ParseTreeType::RULE;
constexpr auto TREE_TERMINAL = ParseTreeType::TERMINAL;
#pragma pop_macro("ERROR")

// not the same as in game, for them see pool.cpp
enum ACTSDDLType {
    DLL_INVALID = 0xFF,
    DDL_BYTE_TYPE = 0,
    DDL_SHORT_TYPE,
    DDL_UINT_TYPE,
    DDL_INT_TYPE,
    DDL_UINT64_TYPE,
    DDL_HASH_TYPE,
    DDL_FLOAT_TYPE,
    DDL_FIXEDPOINT_TYPE,
    DDL_STRING_TYPE,
    DDL_PAD_TYPE,
    DDL_CLASS_TYPE,
};

class DDLCompilerOption {
public:
    bool m_help = false;
    LPCCH m_ddl = NULL;
    LPCCH m_bin = NULL;

    bool Compute(LPCCH* args, INT startIndex, INT endIndex) {
        // default values
        for (size_t i = startIndex; i < endIndex; i++) {
            LPCCH arg = args[i];

            if (!strcmp("-?", arg) || !_strcmpi("--help", arg) || !strcmp("-h", arg)) {
                m_help = true;
            }
            else if (*arg == '-') {
                std::cerr << "Unknown option: " << arg << "!\n";
                return false;
            }
            else {
                if (!m_ddl) {
                    m_ddl = arg;
                }
                else if (!m_bin) {
                    m_bin = arg;
                }
                // don't care
            }
        }
        return m_bin != NULL;
    }

    void PrintHelp(std::ostream& out) {
        out << "-h --help          : Print help\n";
    }


    std::ostream& PrintLineMessage(std::ostream& out, size_t line, size_t charPositionInLine) {
        out << m_ddl << "#" << line;
        if (charPositionInLine) {
            out << ":" << charPositionInLine;
        }
        return out << " ";
    }
    inline std::ostream& PrintLineMessage(std::ostream& out, Token* token) {
        return PrintLineMessage(out, token->getLine(), token->getCharPositionInLine()) << "(near \"" << token->getText() << "\") ";
    }
    std::ostream& PrintLineMessage(std::ostream& out, ParseTree* token) {
        if (token->getTreeType() == TREE_TERMINAL) {
            return PrintLineMessage(out, dynamic_cast<TerminalNode*>(token)->getSymbol());
        }
        if (token->getTreeType() == TREE_RULE && token->children.size()) {
            // recurse on the first token
            return PrintLineMessage(out, token->children[0]);
        }
        return PrintLineMessage(out, 1, 0);
    }
};

union DDLData {
    double doubleValue;
    uint64_t uintValue;
    int64_t intValue;
};

DDLData ReadDDLMember(UINT64 offset, ACTSDDLType type, UINT64 size, BYTE* raw) {
    DDLData data{};

    assert(size <= 64 && "reading complex objects");

    BYTE buffer[8]{};

    // reading raw

    if ((offset & 7) == 0) {
        // byte aligned, no need to work
        memcpy(buffer, raw + (offset >> 3), ((size - 1) >> 3) + 1);
    }
    else {

    }
 

    return data;
}


class DDLMember {
public:
    UINT64 name;
    UINT64 typeName;
    ACTSDDLType type{ DLL_INVALID };
    UINT64 offset{};
    UINT64 size{};
    bool isArray{};
    UINT64 arraySize{};

    DDLMember(UINT64 name, UINT64 typeName) : name(name), typeName(typeName) {
        struct TmpTypeInfo {
            UINT64 tname{};
            ACTSDDLType val{};
            UINT64 size{};
        };

        static TmpTypeInfo tmp[DDL_CLASS_TYPE + 64 + 64 + 64 + 2]{};
        static std::once_flag tmpFlag{};

        std::call_once(tmpFlag, []() {
            tmp[DDL_BYTE_TYPE] = { hashutils::Hash64("byte"), DDL_BYTE_TYPE, 8 };
            tmp[DDL_SHORT_TYPE] = { hashutils::Hash64("short"), DDL_SHORT_TYPE, 16 };
            tmp[DDL_UINT_TYPE] = { hashutils::Hash64("uint"), DDL_UINT_TYPE, 32 };
            tmp[DDL_INT_TYPE] = { hashutils::Hash64("int"), DDL_INT_TYPE, 32 };
            tmp[DDL_UINT64_TYPE] = { hashutils::Hash64("uint64"), DDL_UINT64_TYPE, 64 };
            tmp[DDL_HASH_TYPE] = { hashutils::Hash64("hash"), DDL_HASH_TYPE, 64 };
            tmp[DDL_FLOAT_TYPE] = { hashutils::Hash64("float"), DDL_FLOAT_TYPE, 32 };
            tmp[DDL_FIXEDPOINT_TYPE] = { hashutils::Hash64("fixedpoint"), DDL_FIXEDPOINT_TYPE, 32 };
            tmp[DDL_STRING_TYPE] = { hashutils::Hash64("char"), DDL_STRING_TYPE, 8 };
            tmp[DDL_PAD_TYPE] = { hashutils::Hash64("padbit"), DDL_PAD_TYPE, 1 };

            size_t idx = DDL_CLASS_TYPE;
            
            tmp[idx++] = { hashutils::Hash64("bit"), DDL_UINT_TYPE, 1 };
            tmp[idx++] = { hashutils::Hash64("double"), DDL_FLOAT_TYPE, 64 };

            char tmpName[0x20];

            for (size_t i = 1; i <= 64; i++) {
                sprintf_s(tmpName, "uint%lld", i);
                tmp[idx] = { hashutils::Hash64(tmpName), DDL_UINT_TYPE, i };
                sprintf_s(tmpName, "int%lld", i);
                tmp[idx + 1] = { hashutils::Hash64(tmpName), DDL_INT_TYPE, i };
                sprintf_s(tmpName, "fixedpoint%lld", i); // wtf if non 8 << (x)?
                tmp[idx + 2] = { hashutils::Hash64(tmpName), DDL_FIXEDPOINT_TYPE, i };

                idx += 3;
            }
        });

        auto it = std::find_if(std::begin(tmp), std::end(tmp), [typeName](const TmpTypeInfo& nfo) { return nfo.tname == typeName; });

        if (it != std::end(tmp)) {
            type = it->val;
            size = it->size;
        }
        else {
            type = DDL_CLASS_TYPE;
            // size is computed during the checks
        }
    }
};

class DDLStruct {
public:
    UINT64 size{};
    std::vector<DDLMember> values{};
};

class DDLEnum {
public:
    std::vector<UINT64> values{};

    UINT64 GetSize() const {
        // too lazy to write a fast log
        if (values.size() < (1ull << 8)) {
            return 8;
        }
        if (values.size() < (1ull << 16)) {
            return 16;
        }
        if (values.size() < (1ull << 32)) {
            return 32;
        }
        return 64;
    }
};

class DDLCompiled {
public:
    UINT64 name;
    UINT32 version{};
    UINT64 metatable{};
    std::unordered_map<UINT64, DDLEnum> enums{};
    std::unordered_map<UINT64, DDLStruct> structs{};


    DDLCompiled(UINT64 name) : name(name) {}

private:
    bool CompleteStruct(DDLStruct& current, std::vector<UINT64>& types) {
        if (current.size) {
            return true; // already computed
        }
        current.size = 0;
        for (auto& sub : current.values) {
            sub.offset = current.size;
            if (sub.type != DDL_CLASS_TYPE) {
                if (sub.isArray) {
                    current.size += sub.size * sub.arraySize;
                }
                else {
                    current.size += sub.size;
                }
                continue; // by default ok
            }

            auto ite = enums.find(sub.typeName);
            if (ite != enums.end()) {
                sub.size = ite->second.GetSize();
                if (sub.isArray) {
                    current.size += sub.size * sub.arraySize;
                }
                else {
                    current.size += sub.size;
                }
                continue; // ok
            }

            auto it = structs.find(sub.typeName);

            if (it == structs.end()) {
                std::cerr << "The type hash_" << std::hex << sub.typeName << " doesn't exist\n";
                return false;
            }

            if (std::find(types.begin(), types.end(), sub.typeName) != types.end()) {
                std::cerr << "Recursion on the type hash_" << std::hex << sub.typeName << "\n";
                return false;
            }

            types.push_back(sub.typeName);
            if (!CompleteStruct(it->second, types)) {
                return false;
            }
            sub.size = it->second.size;
            types.pop_back();
            if (sub.isArray) {
                current.size += sub.size * sub.arraySize;
            }
            else {
                current.size += sub.size;
            }
        }
        return true;
    }
public:
    bool StructEnumExists(UINT64 name) const {
        return enums.contains(name) || structs.contains(name);
    }

    bool CompleteStruct() {
        std::vector<UINT64> types{};
        static auto rootHash = hash::Hash64("root");

        // check that root exists

        if (structs.find(rootHash) == structs.end()) {
            std::cerr << "Can't find root structure\n";
            return false;
        }

        // check loops
        return CompleteStruct(GetRoot(), types);
    }

    DDLStruct& GetRoot() {
        static auto rootHash = hash::Hash64("root");
        return structs[rootHash];
    }
};

class FullDDLCompiled {
public:
    std::vector<DDLCompiled> compiled{};

    bool HasFirst() {
        return compiled.size();
    }

    DDLCompiled& Last() {
        return compiled[compiled.size() - 1];
    }
};

namespace {

    std::string ReadString(ParseTree* pt) {
        auto str = pt->getText();

        return str.substr(1, str.length() - 2);
    }
    INT64 ReadInt(ParseTree* pt) {
        auto str = pt->getText();

        if (str.starts_with("-0x")) return -std::strtoll(str.c_str() + 3, nullptr, 16);
        if (str.starts_with("0x")) return std::strtoll(str.c_str() + 2, nullptr, 16);
        if (str.starts_with("-0b")) return -std::strtoll(str.c_str() + 3, nullptr, 2);
        if (str.starts_with("0b")) return std::strtoll(str.c_str() + 2, nullptr, 2);
        if (str.starts_with("-0")) return -std::strtoll(str.c_str() + 2, nullptr, 8);
        if (str.starts_with("0")) return std::strtoll(str.c_str() + 1, nullptr, 8);
        return std::strtoll(str.c_str(), nullptr, 10);
    }

    void ClearDDLComments(LPCH ddlText) {
        int comment{}; // 1 = // 2 = /*

        for (; *ddlText; ddlText++) {

            if (comment) {
                if (comment == 1) {
                    if (*ddlText == '\n') {
                        comment = 0;
                        continue;
                    }
                }
                else if (comment == 2) {
                    if (ddlText[0] == '*' && ddlText[1] == '/') {
                        comment = 0;
                        ddlText[0] = ' ';
                        ddlText[1] = ' ';
                        ddlText++;
                        continue;
                    }
                }

                *ddlText = ' ';
                continue;
            }
            if (ddlText[0] == '/') {
                if (ddlText[1] == '/') {
                    comment = 1;
                    ddlText[0] = ' ';
                    ddlText[1] = ' ';
                    ddlText++;
                    continue;
                }

                if (ddlText[1] == '*') {
                    comment = 2;
                    ddlText[0] = ' ';
                    ddlText[1] = ' ';
                    ddlText++;
                    continue;
                }
            }
        }
    }

    bool ComputeDDLCheck(DDLCompilerOption& opt, LPCH ddlText, BYTE* binary, SIZE_T binarySize, FullDDLCompiled& ddl) {
        std::cout << "Compiling DDL file...\n";
        ClearDDLComments(ddlText);
        ANTLRInputStream is{ ddlText };

        ddlLexer lexer{ &is };
        CommonTokenStream tokens{ &lexer };

        tokens.fill();
        ddlParser parser{ &tokens };

        ddlParser::ProgContext* prog = parser.prog();

        auto error = parser.getNumberOfSyntaxErrors();
        if (error) {
            std::cerr << std::dec << error << " error(s) detected, abort\n";
            return false;
        }


        auto* eof = prog->EOF();

        for (auto& e : prog->children) {
            if (e == eof) {
                break; // done
            }
            if (e->getTreeType() == TREE_TERMINAL && dynamic_cast<TerminalNode&>(*e).getText() == ";") {
                continue; // ignore that
            }

            if (e->getTreeType() != TREE_RULE) {
                opt.PrintLineMessage(std::cerr, e) << "Bad export rule type\n";
                return false;
            }

            auto rule = dynamic_cast<RuleContext&>(*e).getRuleIndex();

            switch (rule) {
            case ddlParser::RuleData: {
                auto idf = e->children[0]->getText();

                if (idf == "begin") {
                    if (e->children[1]->getTreeType() != TREE_TERMINAL || dynamic_cast<TerminalNode*>(e->children[1])->getSymbol()->getType() != ddlParser::STRING) {
                        opt.PrintLineMessage(std::cerr, e) << "begin should be set using a string value\n";
                        return false;
                    }
                    auto name = ReadString(e->children[1]);
                    ddl.compiled.emplace_back(hashutils::Hash64Pattern(name.c_str()));
                }
                else if (idf == "version") {
                    if (!ddl.HasFirst()) {
                        opt.PrintLineMessage(std::cerr, e) << "Can't set version without begin\n";
                        return false;
                    }
                    if (e->children[1]->getTreeType() == TREE_TERMINAL) {
                        opt.PrintLineMessage(std::cerr, e) << "version should be set using a number value\n";
                        return false;
                    }
                    ddl.Last().version = (UINT32)ReadInt(e->children[1]);
                }
                else if (idf == "metatable") {
                    if (!ddl.HasFirst()) {
                        opt.PrintLineMessage(std::cerr, e) << "Can't set metatable without begin\n";
                        return false;
                    }
                    if (e->children[1]->getTreeType() != TREE_TERMINAL || dynamic_cast<TerminalNode*>(e->children[1])->getSymbol()->getType() != ddlParser::STRING) {
                        opt.PrintLineMessage(std::cerr, e) << "metatable should be set using a string value\n";
                        return false;
                    }
                    auto metatable = ReadString(e->children[1]);
                    ddl.Last().metatable = hashutils::Hash64Pattern(metatable.c_str());
                }
                else {
                    opt.PrintLineMessage(std::cerr, e) << "Invalid data rule: " << idf << ", ignored\n";
                }

            }
                break;
            case ddlParser::RuleEnum: {
                if (!ddl.HasFirst()) {
                    opt.PrintLineMessage(std::cerr, e) << "Can't add enum without begin\n";
                    return false;
                }

                auto name = e->children[1]->getText();

                auto nameHashed = hashutils::Hash64Pattern(name.c_str());

                if (ddl.Last().StructEnumExists(nameHashed)) {
                    opt.PrintLineMessage(std::cerr, e->children[1]) << "The type " << name << " was registered twice\n";
                    return false;
                }

                auto& enumData = ddl.Last().enums[nameHashed];

                for (size_t i = 3; i < e->children.size() - 1; i++)
                {

                    auto* child = e->children[i];
                    if (child->getText() == "=") {
                        i += 3; // = number, (ignored)
                        continue;
                    }
                    if (child->getText() == ",") {
                        continue;
                    }

                    assert(child->getTreeType() == TREE_TERMINAL && dynamic_cast<TerminalNode&>(*child).getSymbol()->getType() == ddlParser::STRING);

                    auto enumVal = ReadString(child);
                    enumData.values.emplace_back(hashutils::Hash64Pattern(enumVal.c_str()));
                }
            }
                break;
            case ddlParser::RuleStruct: {
                if (!ddl.HasFirst()) {
                    opt.PrintLineMessage(std::cerr, e) << "Can't add struct without begin\n";
                    return false;
                }

                auto name = e->children[1]->getText();

                auto nameHashed = hashutils::Hash64Pattern(name.c_str());

                if (ddl.Last().StructEnumExists(nameHashed)) {
                    opt.PrintLineMessage(std::cerr, e->children[1]) << "The type " << name << " was registered twice\n";
                    return false;
                }

                auto& structData = ddl.Last().structs[nameHashed];

                for (size_t i = 3; i < e->children.size() - 1; i++) {
                    auto* def = e->children[i];

                    auto fieldType = def->children[0]->getText();
                    auto fieldName = def->children[1]->getText();

                    ACTSDDLType fieldTypeDDL{};

                    auto fieldTypeHashed = hashutils::Hash64Pattern(fieldType.c_str());


                    auto& fieldDef = structData.values.emplace_back(hashutils::Hash64Pattern(name.c_str()), fieldTypeHashed);

                    if (def->children.size() > 5) { // + [ N ] (3)

                        if (def->children.size() > 8) {
                            if (fieldDef.type != DDL_STRING_TYPE) {
                                opt.PrintLineMessage(std::cerr, def->children[5]) << "Can't define matrix\n";
                                return false;
                            }
                            // char str[array_size][string_len];

                            auto strSize = ReadInt(def->children[6]);

                            if (strSize < 0) {
                                opt.PrintLineMessage(std::cerr, def->children[6]) << "String with negative size\n";
                                return false;
                            }

                            fieldDef.size = strSize * 8;

                            fieldDef.isArray = true;
                            auto arrSize = ReadInt(def->children[3]);

                            if (arrSize < 0) {
                                opt.PrintLineMessage(std::cerr, def->children[3]) << "Array with negative size\n";
                                return false;
                            }
                            fieldDef.arraySize = (size_t)arrSize;
                        }
                        else if (fieldDef.type == DDL_STRING_TYPE) {
                            // char str[string_len];


                            auto strSize = ReadInt(def->children[3]);

                            if (strSize < 0) {
                                opt.PrintLineMessage(std::cerr, def->children[3]) << "String with negative size\n";
                                return false;
                            }

                            fieldDef.size = strSize * 8;
                        }
                        else {
                            // or type arr[array_size];

                            fieldDef.isArray = true;
                            auto arrSize = ReadInt(def->children[3]);

                            if (arrSize < 0) {
                                opt.PrintLineMessage(std::cerr, def->children[3]) << "Array with negative size\n";
                                return false;
                            }
                            fieldDef.arraySize = (size_t)arrSize;
                        }

                    }
                }
            }
            break;
            default:
                opt.PrintLineMessage(std::cerr, e) << "Bad export rule\n";
                return false;
            }
        }

        std::cout << "Checking DDL structure.\n";

        bool errorStruct = false;
        for (auto& ddlVersion : ddl.compiled) {
            if (!ddlVersion.CompleteStruct()) {
                errorStruct = true;
            }
        }
        if (errorStruct) {
            opt.PrintLineMessage(std::cerr, prog) << "Error in the structure\n";
            return false;
        }
        std::cout << "DDL file compiled.\n";
        std::cout << "Versions: " << std::dec << ddl.compiled.size() << "\n";

        for (auto& ver : ddl.compiled) {
            auto& root = ver.GetRoot();


            std::cout << "Vers: " << std::dec << ver.version << "\n";
            std::cout << "Size: 0x" << std::hex << root.size << " bits (" << std::dec << root.size << ")\n";
            std::cout << "    | 0x" << std::hex << (root.size >> 3) << " bytes (" << std::dec << (root.size >> 3) << ")\n";

            uLong len = (uLong)((root.size >> 3) + 0x100000);
            auto decompiledBuffer = std::make_unique<BYTE[]>(len);

            std::cout << "len: " << len << "\n";

            if (binarySize >= 2 && binary[0] == 0x78 && binary[1] == 0x9C) {
                // ZLIB encoded
                uLong binSizeUL = (uLong)binarySize;
                auto res = uncompress2(&decompiledBuffer[0], &len, binary, &binSizeUL);
                if (res != Z_OK) {
                    std::cerr << "Can't uncompress zlib buffer: ";
                    switch (res) {
                        case Z_MEM_ERROR: std::cerr << "Not enough memory"; break;
                        case Z_BUF_ERROR: std::cerr << "Not enough room in the output buffer"; break;
                        case Z_DATA_ERROR: std::cerr << "Corrupted data"; break;
                        default: std::cerr << "unknown"; break;
                    }
                    std::cerr << "\n";
                    return false;
                }
                std::cout << "zlib decompressed\n";
            }
            else {
                memcpy(&decompiledBuffer[0], binary, binarySize);
            }
            std::cout << "len: " << len << "\n";
            break; // only use first version

        }
        return true;
    }

	int ddlcheck(Process& proc, int argc, const char* argv[]) {
        DDLCompilerOption opt{};

        if (!opt.Compute(argv, 2, argc) || opt.m_help) {
            opt.PrintHelp(std::cout);
            return 0;
        }

        LPVOID ddlBuffer{};
        SIZE_T ddlSize{};

        LPVOID binBuffer{};
        SIZE_T binSize{};

        if (!utils::ReadFileNotAlign(opt.m_ddl, ddlBuffer, ddlSize, true)) {
            std::cerr << "Can't read " << opt.m_ddl << "\n";
            return tool::BASIC_ERROR;
        }

        if (!utils::ReadFileNotAlign(opt.m_bin, binBuffer, binSize)) {
            std::cerr << "Can't read " << opt.m_bin << "\n";
            std::free(ddlBuffer);
            return tool::BASIC_ERROR;
        }
        FullDDLCompiled ddl{};

        auto res = ComputeDDLCheck(opt, reinterpret_cast<LPCH>(ddlBuffer), reinterpret_cast<BYTE*>(binBuffer), binSize, ddl);

        std::free(binBuffer);
        std::free(ddlBuffer);

		return res ? tool::OK : tool::BASIC_ERROR;
	}


}
ADD_TOOL("ddlcheck", "", "ddl check", nullptr, ddlcheck);