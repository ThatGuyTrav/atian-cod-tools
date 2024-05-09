
// Generated from .\grammar\gsc.g4 by ANTLR 4.13.0


#include "gscLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct GscLexerStaticData final {
  GscLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GscLexerStaticData(const GscLexerStaticData&) = delete;
  GscLexerStaticData(GscLexerStaticData&&) = delete;
  GscLexerStaticData& operator=(const GscLexerStaticData&) = delete;
  GscLexerStaticData& operator=(GscLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag gsclexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
GscLexerStaticData *gsclexerLexerStaticData = nullptr;

void gsclexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (gsclexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(gsclexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GscLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "T__27", "T__28", "T__29", "T__30", "T__31", "T__32", 
      "T__33", "T__34", "T__35", "T__36", "T__37", "T__38", "T__39", "T__40", 
      "T__41", "T__42", "T__43", "T__44", "T__45", "T__46", "T__47", "T__48", 
      "T__49", "T__50", "T__51", "T__52", "T__53", "T__54", "T__55", "T__56", 
      "T__57", "T__58", "T__59", "T__60", "T__61", "T__62", "T__63", "T__64", 
      "T__65", "T__66", "T__67", "T__68", "T__69", "T__70", "T__71", "T__72", 
      "T__73", "T__74", "T__75", "NEWLINE", "WHITESPACE", "INTEGER10", "INTEGER16", 
      "INTEGER8", "INTEGER2", "FLOATVAL", "BUILTIN", "BOOL_VALUE", "UNDEFINED_VALUE", 
      "IDENTIFIER", "STRUCT_IDENTIFIER", "PATH", "STRING", "HASHSTRING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'#include'", "'#using'", "';'", "'#namespace'", "'function'", 
      "'private'", "'autoexec'", "'('", "')'", "'event_handler'", "'['", 
      "']'", "','", "'*'", "'&'", "'='", "'...'", "'{'", "'}'", "':'", "'for'", 
      "'while'", "'do'", "'foreach'", "'in'", "'if'", "'else'", "'switch'", 
      "'case'", "'default'", "'thread'", "'childthread'", "'builtin'", "'nop'", 
      "'Nop'", "'DevOp'", "'devop'", "'Devop'", "'::'", "'->'", "'\\u003F'", 
      "'+='", "'-='", "'/='", "'*='", "'%='", "'&='", "'|='", "'^='", "'<<='", 
      "'>>='", "'~='", "'||'", "'&&'", "'|'", "'^'", "'!='", "'=='", "'!=='", 
      "'==='", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", "'-'", 
      "'/'", "'%'", "'!'", "'~'", "'++'", "'--'", "'.'", "'@'", "", "", 
      "", "", "", "", "", "", "", "'undefined'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "NEWLINE", "WHITESPACE", "INTEGER10", 
      "INTEGER16", "INTEGER8", "INTEGER2", "FLOATVAL", "BUILTIN", "BOOL_VALUE", 
      "UNDEFINED_VALUE", "IDENTIFIER", "STRUCT_IDENTIFIER", "PATH", "STRING", 
      "HASHSTRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,91,667,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,
  	7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,77,
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,84,
  	7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,90,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,
  	16,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,20,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,31,1,
  	31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,
  	32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,35,1,
  	35,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,
  	37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,41,1,41,1,41,1,
  	42,1,42,1,42,1,43,1,43,1,43,1,44,1,44,1,44,1,45,1,45,1,45,1,46,1,46,1,
  	46,1,47,1,47,1,47,1,48,1,48,1,48,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,
  	50,1,51,1,51,1,51,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,55,1,55,1,
  	56,1,56,1,56,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,
  	60,1,60,1,61,1,61,1,61,1,62,1,62,1,63,1,63,1,63,1,64,1,64,1,64,1,65,1,
  	65,1,65,1,66,1,66,1,67,1,67,1,68,1,68,1,69,1,69,1,70,1,70,1,71,1,71,1,
  	72,1,72,1,72,1,73,1,73,1,73,1,74,1,74,1,75,1,75,1,76,3,76,490,8,76,1,
  	76,1,76,3,76,494,8,76,1,76,1,76,1,77,1,77,1,77,1,77,1,78,3,78,503,8,78,
  	1,78,1,78,5,78,507,8,78,10,78,12,78,510,9,78,1,79,3,79,513,8,79,1,79,
  	1,79,1,79,1,79,4,79,519,8,79,11,79,12,79,520,1,80,3,80,524,8,80,1,80,
  	1,80,5,80,528,8,80,10,80,12,80,531,9,80,1,81,3,81,534,8,81,1,81,1,81,
  	1,81,1,81,5,81,540,8,81,10,81,12,81,543,9,81,1,82,3,82,546,8,82,1,82,
  	5,82,549,8,82,10,82,12,82,552,9,82,1,82,1,82,4,82,556,8,82,11,82,12,82,
  	557,1,82,4,82,561,8,82,11,82,12,82,562,1,82,1,82,5,82,567,8,82,10,82,
  	12,82,570,9,82,3,82,572,8,82,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,
  	1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,
  	1,83,1,83,1,83,1,83,1,83,3,83,601,8,83,1,84,1,84,1,84,1,84,1,84,1,84,
  	1,84,1,84,1,84,3,84,612,8,84,1,85,1,85,1,85,1,85,1,85,1,85,1,85,1,85,
  	1,85,1,85,1,86,1,86,5,86,626,8,86,10,86,12,86,629,9,86,1,87,1,87,1,87,
  	5,87,634,8,87,10,87,12,87,637,9,87,1,88,4,88,640,8,88,11,88,12,88,641,
  	1,88,1,88,1,88,1,88,1,88,1,88,1,88,1,88,3,88,652,8,88,1,89,1,89,1,89,
  	1,89,5,89,658,8,89,10,89,12,89,661,9,89,1,89,1,89,1,90,1,90,1,90,0,0,
  	91,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,
  	14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,
  	51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,
  	37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,47,95,48,
  	97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,57,115,58,117,
  	59,119,60,121,61,123,62,125,63,127,64,129,65,131,66,133,67,135,68,137,
  	69,139,70,141,71,143,72,145,73,147,74,149,75,151,76,153,77,155,78,157,
  	79,159,80,161,81,163,82,165,83,167,84,169,85,171,86,173,87,175,88,177,
  	89,179,90,181,91,1,0,11,2,0,9,9,32,32,1,0,49,57,1,0,48,57,2,0,48,57,97,
  	102,1,0,48,55,1,0,48,49,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,
  	97,122,5,0,47,57,65,90,92,92,95,95,97,122,2,0,34,34,92,92,1,0,35,35,694,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,
  	1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,
  	0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,
  	0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,
  	1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,
  	0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,
  	0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,
  	1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,
  	1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,
  	1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,
  	1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,0,0,133,1,0,0,0,0,135,1,0,0,0,0,137,
  	1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,0,0,143,1,0,0,0,0,145,1,0,0,0,0,147,
  	1,0,0,0,0,149,1,0,0,0,0,151,1,0,0,0,0,153,1,0,0,0,0,155,1,0,0,0,0,157,
  	1,0,0,0,0,159,1,0,0,0,0,161,1,0,0,0,0,163,1,0,0,0,0,165,1,0,0,0,0,167,
  	1,0,0,0,0,169,1,0,0,0,0,171,1,0,0,0,0,173,1,0,0,0,0,175,1,0,0,0,0,177,
  	1,0,0,0,0,179,1,0,0,0,0,181,1,0,0,0,1,183,1,0,0,0,3,192,1,0,0,0,5,199,
  	1,0,0,0,7,201,1,0,0,0,9,212,1,0,0,0,11,221,1,0,0,0,13,229,1,0,0,0,15,
  	238,1,0,0,0,17,240,1,0,0,0,19,242,1,0,0,0,21,256,1,0,0,0,23,258,1,0,0,
  	0,25,260,1,0,0,0,27,262,1,0,0,0,29,264,1,0,0,0,31,266,1,0,0,0,33,268,
  	1,0,0,0,35,272,1,0,0,0,37,274,1,0,0,0,39,276,1,0,0,0,41,278,1,0,0,0,43,
  	282,1,0,0,0,45,288,1,0,0,0,47,291,1,0,0,0,49,299,1,0,0,0,51,302,1,0,0,
  	0,53,305,1,0,0,0,55,310,1,0,0,0,57,317,1,0,0,0,59,322,1,0,0,0,61,330,
  	1,0,0,0,63,337,1,0,0,0,65,349,1,0,0,0,67,357,1,0,0,0,69,361,1,0,0,0,71,
  	365,1,0,0,0,73,371,1,0,0,0,75,377,1,0,0,0,77,383,1,0,0,0,79,386,1,0,0,
  	0,81,389,1,0,0,0,83,391,1,0,0,0,85,394,1,0,0,0,87,397,1,0,0,0,89,400,
  	1,0,0,0,91,403,1,0,0,0,93,406,1,0,0,0,95,409,1,0,0,0,97,412,1,0,0,0,99,
  	415,1,0,0,0,101,419,1,0,0,0,103,423,1,0,0,0,105,426,1,0,0,0,107,429,1,
  	0,0,0,109,432,1,0,0,0,111,434,1,0,0,0,113,436,1,0,0,0,115,439,1,0,0,0,
  	117,442,1,0,0,0,119,446,1,0,0,0,121,450,1,0,0,0,123,452,1,0,0,0,125,455,
  	1,0,0,0,127,457,1,0,0,0,129,460,1,0,0,0,131,463,1,0,0,0,133,466,1,0,0,
  	0,135,468,1,0,0,0,137,470,1,0,0,0,139,472,1,0,0,0,141,474,1,0,0,0,143,
  	476,1,0,0,0,145,478,1,0,0,0,147,481,1,0,0,0,149,484,1,0,0,0,151,486,1,
  	0,0,0,153,493,1,0,0,0,155,497,1,0,0,0,157,502,1,0,0,0,159,512,1,0,0,0,
  	161,523,1,0,0,0,163,533,1,0,0,0,165,545,1,0,0,0,167,600,1,0,0,0,169,611,
  	1,0,0,0,171,613,1,0,0,0,173,623,1,0,0,0,175,630,1,0,0,0,177,639,1,0,0,
  	0,179,653,1,0,0,0,181,664,1,0,0,0,183,184,5,35,0,0,184,185,5,105,0,0,
  	185,186,5,110,0,0,186,187,5,99,0,0,187,188,5,108,0,0,188,189,5,117,0,
  	0,189,190,5,100,0,0,190,191,5,101,0,0,191,2,1,0,0,0,192,193,5,35,0,0,
  	193,194,5,117,0,0,194,195,5,115,0,0,195,196,5,105,0,0,196,197,5,110,0,
  	0,197,198,5,103,0,0,198,4,1,0,0,0,199,200,5,59,0,0,200,6,1,0,0,0,201,
  	202,5,35,0,0,202,203,5,110,0,0,203,204,5,97,0,0,204,205,5,109,0,0,205,
  	206,5,101,0,0,206,207,5,115,0,0,207,208,5,112,0,0,208,209,5,97,0,0,209,
  	210,5,99,0,0,210,211,5,101,0,0,211,8,1,0,0,0,212,213,5,102,0,0,213,214,
  	5,117,0,0,214,215,5,110,0,0,215,216,5,99,0,0,216,217,5,116,0,0,217,218,
  	5,105,0,0,218,219,5,111,0,0,219,220,5,110,0,0,220,10,1,0,0,0,221,222,
  	5,112,0,0,222,223,5,114,0,0,223,224,5,105,0,0,224,225,5,118,0,0,225,226,
  	5,97,0,0,226,227,5,116,0,0,227,228,5,101,0,0,228,12,1,0,0,0,229,230,5,
  	97,0,0,230,231,5,117,0,0,231,232,5,116,0,0,232,233,5,111,0,0,233,234,
  	5,101,0,0,234,235,5,120,0,0,235,236,5,101,0,0,236,237,5,99,0,0,237,14,
  	1,0,0,0,238,239,5,40,0,0,239,16,1,0,0,0,240,241,5,41,0,0,241,18,1,0,0,
  	0,242,243,5,101,0,0,243,244,5,118,0,0,244,245,5,101,0,0,245,246,5,110,
  	0,0,246,247,5,116,0,0,247,248,5,95,0,0,248,249,5,104,0,0,249,250,5,97,
  	0,0,250,251,5,110,0,0,251,252,5,100,0,0,252,253,5,108,0,0,253,254,5,101,
  	0,0,254,255,5,114,0,0,255,20,1,0,0,0,256,257,5,91,0,0,257,22,1,0,0,0,
  	258,259,5,93,0,0,259,24,1,0,0,0,260,261,5,44,0,0,261,26,1,0,0,0,262,263,
  	5,42,0,0,263,28,1,0,0,0,264,265,5,38,0,0,265,30,1,0,0,0,266,267,5,61,
  	0,0,267,32,1,0,0,0,268,269,5,46,0,0,269,270,5,46,0,0,270,271,5,46,0,0,
  	271,34,1,0,0,0,272,273,5,123,0,0,273,36,1,0,0,0,274,275,5,125,0,0,275,
  	38,1,0,0,0,276,277,5,58,0,0,277,40,1,0,0,0,278,279,5,102,0,0,279,280,
  	5,111,0,0,280,281,5,114,0,0,281,42,1,0,0,0,282,283,5,119,0,0,283,284,
  	5,104,0,0,284,285,5,105,0,0,285,286,5,108,0,0,286,287,5,101,0,0,287,44,
  	1,0,0,0,288,289,5,100,0,0,289,290,5,111,0,0,290,46,1,0,0,0,291,292,5,
  	102,0,0,292,293,5,111,0,0,293,294,5,114,0,0,294,295,5,101,0,0,295,296,
  	5,97,0,0,296,297,5,99,0,0,297,298,5,104,0,0,298,48,1,0,0,0,299,300,5,
  	105,0,0,300,301,5,110,0,0,301,50,1,0,0,0,302,303,5,105,0,0,303,304,5,
  	102,0,0,304,52,1,0,0,0,305,306,5,101,0,0,306,307,5,108,0,0,307,308,5,
  	115,0,0,308,309,5,101,0,0,309,54,1,0,0,0,310,311,5,115,0,0,311,312,5,
  	119,0,0,312,313,5,105,0,0,313,314,5,116,0,0,314,315,5,99,0,0,315,316,
  	5,104,0,0,316,56,1,0,0,0,317,318,5,99,0,0,318,319,5,97,0,0,319,320,5,
  	115,0,0,320,321,5,101,0,0,321,58,1,0,0,0,322,323,5,100,0,0,323,324,5,
  	101,0,0,324,325,5,102,0,0,325,326,5,97,0,0,326,327,5,117,0,0,327,328,
  	5,108,0,0,328,329,5,116,0,0,329,60,1,0,0,0,330,331,5,116,0,0,331,332,
  	5,104,0,0,332,333,5,114,0,0,333,334,5,101,0,0,334,335,5,97,0,0,335,336,
  	5,100,0,0,336,62,1,0,0,0,337,338,5,99,0,0,338,339,5,104,0,0,339,340,5,
  	105,0,0,340,341,5,108,0,0,341,342,5,100,0,0,342,343,5,116,0,0,343,344,
  	5,104,0,0,344,345,5,114,0,0,345,346,5,101,0,0,346,347,5,97,0,0,347,348,
  	5,100,0,0,348,64,1,0,0,0,349,350,5,98,0,0,350,351,5,117,0,0,351,352,5,
  	105,0,0,352,353,5,108,0,0,353,354,5,116,0,0,354,355,5,105,0,0,355,356,
  	5,110,0,0,356,66,1,0,0,0,357,358,5,110,0,0,358,359,5,111,0,0,359,360,
  	5,112,0,0,360,68,1,0,0,0,361,362,5,78,0,0,362,363,5,111,0,0,363,364,5,
  	112,0,0,364,70,1,0,0,0,365,366,5,68,0,0,366,367,5,101,0,0,367,368,5,118,
  	0,0,368,369,5,79,0,0,369,370,5,112,0,0,370,72,1,0,0,0,371,372,5,100,0,
  	0,372,373,5,101,0,0,373,374,5,118,0,0,374,375,5,111,0,0,375,376,5,112,
  	0,0,376,74,1,0,0,0,377,378,5,68,0,0,378,379,5,101,0,0,379,380,5,118,0,
  	0,380,381,5,111,0,0,381,382,5,112,0,0,382,76,1,0,0,0,383,384,5,58,0,0,
  	384,385,5,58,0,0,385,78,1,0,0,0,386,387,5,45,0,0,387,388,5,62,0,0,388,
  	80,1,0,0,0,389,390,5,63,0,0,390,82,1,0,0,0,391,392,5,43,0,0,392,393,5,
  	61,0,0,393,84,1,0,0,0,394,395,5,45,0,0,395,396,5,61,0,0,396,86,1,0,0,
  	0,397,398,5,47,0,0,398,399,5,61,0,0,399,88,1,0,0,0,400,401,5,42,0,0,401,
  	402,5,61,0,0,402,90,1,0,0,0,403,404,5,37,0,0,404,405,5,61,0,0,405,92,
  	1,0,0,0,406,407,5,38,0,0,407,408,5,61,0,0,408,94,1,0,0,0,409,410,5,124,
  	0,0,410,411,5,61,0,0,411,96,1,0,0,0,412,413,5,94,0,0,413,414,5,61,0,0,
  	414,98,1,0,0,0,415,416,5,60,0,0,416,417,5,60,0,0,417,418,5,61,0,0,418,
  	100,1,0,0,0,419,420,5,62,0,0,420,421,5,62,0,0,421,422,5,61,0,0,422,102,
  	1,0,0,0,423,424,5,126,0,0,424,425,5,61,0,0,425,104,1,0,0,0,426,427,5,
  	124,0,0,427,428,5,124,0,0,428,106,1,0,0,0,429,430,5,38,0,0,430,431,5,
  	38,0,0,431,108,1,0,0,0,432,433,5,124,0,0,433,110,1,0,0,0,434,435,5,94,
  	0,0,435,112,1,0,0,0,436,437,5,33,0,0,437,438,5,61,0,0,438,114,1,0,0,0,
  	439,440,5,61,0,0,440,441,5,61,0,0,441,116,1,0,0,0,442,443,5,33,0,0,443,
  	444,5,61,0,0,444,445,5,61,0,0,445,118,1,0,0,0,446,447,5,61,0,0,447,448,
  	5,61,0,0,448,449,5,61,0,0,449,120,1,0,0,0,450,451,5,60,0,0,451,122,1,
  	0,0,0,452,453,5,60,0,0,453,454,5,61,0,0,454,124,1,0,0,0,455,456,5,62,
  	0,0,456,126,1,0,0,0,457,458,5,62,0,0,458,459,5,61,0,0,459,128,1,0,0,0,
  	460,461,5,60,0,0,461,462,5,60,0,0,462,130,1,0,0,0,463,464,5,62,0,0,464,
  	465,5,62,0,0,465,132,1,0,0,0,466,467,5,43,0,0,467,134,1,0,0,0,468,469,
  	5,45,0,0,469,136,1,0,0,0,470,471,5,47,0,0,471,138,1,0,0,0,472,473,5,37,
  	0,0,473,140,1,0,0,0,474,475,5,33,0,0,475,142,1,0,0,0,476,477,5,126,0,
  	0,477,144,1,0,0,0,478,479,5,43,0,0,479,480,5,43,0,0,480,146,1,0,0,0,481,
  	482,5,45,0,0,482,483,5,45,0,0,483,148,1,0,0,0,484,485,5,46,0,0,485,150,
  	1,0,0,0,486,487,5,64,0,0,487,152,1,0,0,0,488,490,5,13,0,0,489,488,1,0,
  	0,0,489,490,1,0,0,0,490,491,1,0,0,0,491,494,5,10,0,0,492,494,5,13,0,0,
  	493,489,1,0,0,0,493,492,1,0,0,0,494,495,1,0,0,0,495,496,6,76,0,0,496,
  	154,1,0,0,0,497,498,7,0,0,0,498,499,1,0,0,0,499,500,6,77,0,0,500,156,
  	1,0,0,0,501,503,5,45,0,0,502,501,1,0,0,0,502,503,1,0,0,0,503,504,1,0,
  	0,0,504,508,7,1,0,0,505,507,7,2,0,0,506,505,1,0,0,0,507,510,1,0,0,0,508,
  	506,1,0,0,0,508,509,1,0,0,0,509,158,1,0,0,0,510,508,1,0,0,0,511,513,5,
  	45,0,0,512,511,1,0,0,0,512,513,1,0,0,0,513,514,1,0,0,0,514,515,5,48,0,
  	0,515,516,5,120,0,0,516,518,1,0,0,0,517,519,7,3,0,0,518,517,1,0,0,0,519,
  	520,1,0,0,0,520,518,1,0,0,0,520,521,1,0,0,0,521,160,1,0,0,0,522,524,5,
  	45,0,0,523,522,1,0,0,0,523,524,1,0,0,0,524,525,1,0,0,0,525,529,5,48,0,
  	0,526,528,7,4,0,0,527,526,1,0,0,0,528,531,1,0,0,0,529,527,1,0,0,0,529,
  	530,1,0,0,0,530,162,1,0,0,0,531,529,1,0,0,0,532,534,5,45,0,0,533,532,
  	1,0,0,0,533,534,1,0,0,0,534,535,1,0,0,0,535,536,5,48,0,0,536,537,5,98,
  	0,0,537,541,1,0,0,0,538,540,7,5,0,0,539,538,1,0,0,0,540,543,1,0,0,0,541,
  	539,1,0,0,0,541,542,1,0,0,0,542,164,1,0,0,0,543,541,1,0,0,0,544,546,5,
  	45,0,0,545,544,1,0,0,0,545,546,1,0,0,0,546,571,1,0,0,0,547,549,7,2,0,
  	0,548,547,1,0,0,0,549,552,1,0,0,0,550,548,1,0,0,0,550,551,1,0,0,0,551,
  	553,1,0,0,0,552,550,1,0,0,0,553,555,5,46,0,0,554,556,7,2,0,0,555,554,
  	1,0,0,0,556,557,1,0,0,0,557,555,1,0,0,0,557,558,1,0,0,0,558,572,1,0,0,
  	0,559,561,7,2,0,0,560,559,1,0,0,0,561,562,1,0,0,0,562,560,1,0,0,0,562,
  	563,1,0,0,0,563,564,1,0,0,0,564,568,5,46,0,0,565,567,7,2,0,0,566,565,
  	1,0,0,0,567,570,1,0,0,0,568,566,1,0,0,0,568,569,1,0,0,0,569,572,1,0,0,
  	0,570,568,1,0,0,0,571,550,1,0,0,0,571,560,1,0,0,0,572,166,1,0,0,0,573,
  	574,5,98,0,0,574,575,5,114,0,0,575,576,5,101,0,0,576,577,5,97,0,0,577,
  	601,5,107,0,0,578,579,5,99,0,0,579,580,5,111,0,0,580,581,5,110,0,0,581,
  	582,5,116,0,0,582,583,5,105,0,0,583,584,5,110,0,0,584,585,5,117,0,0,585,
  	601,5,101,0,0,586,587,5,103,0,0,587,588,5,111,0,0,588,589,5,116,0,0,589,
  	601,5,111,0,0,590,591,5,114,0,0,591,592,5,101,0,0,592,593,5,116,0,0,593,
  	594,5,117,0,0,594,595,5,114,0,0,595,601,5,110,0,0,596,597,5,119,0,0,597,
  	598,5,97,0,0,598,599,5,105,0,0,599,601,5,116,0,0,600,573,1,0,0,0,600,
  	578,1,0,0,0,600,586,1,0,0,0,600,590,1,0,0,0,600,596,1,0,0,0,601,168,1,
  	0,0,0,602,603,5,116,0,0,603,604,5,114,0,0,604,605,5,117,0,0,605,612,5,
  	101,0,0,606,607,5,102,0,0,607,608,5,97,0,0,608,609,5,108,0,0,609,610,
  	5,115,0,0,610,612,5,101,0,0,611,602,1,0,0,0,611,606,1,0,0,0,612,170,1,
  	0,0,0,613,614,5,117,0,0,614,615,5,110,0,0,615,616,5,100,0,0,616,617,5,
  	101,0,0,617,618,5,102,0,0,618,619,5,105,0,0,619,620,5,110,0,0,620,621,
  	5,101,0,0,621,622,5,100,0,0,622,172,1,0,0,0,623,627,7,6,0,0,624,626,7,
  	7,0,0,625,624,1,0,0,0,626,629,1,0,0,0,627,625,1,0,0,0,627,628,1,0,0,0,
  	628,174,1,0,0,0,629,627,1,0,0,0,630,631,5,35,0,0,631,635,7,6,0,0,632,
  	634,7,7,0,0,633,632,1,0,0,0,634,637,1,0,0,0,635,633,1,0,0,0,635,636,1,
  	0,0,0,636,176,1,0,0,0,637,635,1,0,0,0,638,640,7,8,0,0,639,638,1,0,0,0,
  	640,641,1,0,0,0,641,639,1,0,0,0,641,642,1,0,0,0,642,651,1,0,0,0,643,644,
  	5,46,0,0,644,645,5,103,0,0,645,646,5,115,0,0,646,652,5,99,0,0,647,648,
  	5,46,0,0,648,649,5,99,0,0,649,650,5,115,0,0,650,652,5,99,0,0,651,643,
  	1,0,0,0,651,647,1,0,0,0,651,652,1,0,0,0,652,178,1,0,0,0,653,659,5,34,
  	0,0,654,658,8,9,0,0,655,656,5,92,0,0,656,658,9,0,0,0,657,654,1,0,0,0,
  	657,655,1,0,0,0,658,661,1,0,0,0,659,657,1,0,0,0,659,660,1,0,0,0,660,662,
  	1,0,0,0,661,659,1,0,0,0,662,663,5,34,0,0,663,180,1,0,0,0,664,665,7,10,
  	0,0,665,666,3,179,89,0,666,182,1,0,0,0,25,0,489,493,502,508,512,520,523,
  	529,533,541,545,550,557,562,568,571,600,611,627,635,641,651,657,659,1,
  	6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  gsclexerLexerStaticData = staticData.release();
}

}

gscLexer::gscLexer(CharStream *input) : Lexer(input) {
  gscLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *gsclexerLexerStaticData->atn, gsclexerLexerStaticData->decisionToDFA, gsclexerLexerStaticData->sharedContextCache);
}

gscLexer::~gscLexer() {
  delete _interpreter;
}

std::string gscLexer::getGrammarFileName() const {
  return "gsc.g4";
}

const std::vector<std::string>& gscLexer::getRuleNames() const {
  return gsclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& gscLexer::getChannelNames() const {
  return gsclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& gscLexer::getModeNames() const {
  return gsclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& gscLexer::getVocabulary() const {
  return gsclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView gscLexer::getSerializedATN() const {
  return gsclexerLexerStaticData->serializedATN;
}

const atn::ATN& gscLexer::getATN() const {
  return *gsclexerLexerStaticData->atn;
}




void gscLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  gsclexerLexerInitialize();
#else
  ::antlr4::internal::call_once(gsclexerLexerOnceFlag, gsclexerLexerInitialize);
#endif
}
