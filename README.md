# Atian Tools

[![Build](https://github.com/ate47/atian-cod-tools/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/ate47/atian-cod-tools/actions/workflows/build.yml)

My set of tools. The code is more important than the features, so feel free to reuse it. 🙂

**Supported games**

| Name                                   | Decompiler     | Compiler |
| -------------------------------------- | -------------- | -------- |
| Call of Duty: Black Ops 4 (T8)         | ✅              | ✅        |
| Call of Duty: Black Ops Cold War (T9)  | With predecode | ✅        |
| Call of Duty: Modern Warfare III (JUP) | With extension | ❌        |

## ACTS Lib

Prototype libary for random stuff, probably not linked to Call of Duty.

## Dependencies

This tool is using and providing

- [ANTLR-4](https://github.com/antlr/antlr4) - [BSD-3-Clause license](https://github.com/antlr/antlr4/blob/master/LICENSE.txt).
- [Detours](https://github.com/microsoft/Detours) - [MIT license](https://github.com/microsoft/Detours/blob/main/LICENSE.md).
- [Madler/zlib](https://github.com/madler/zlib) - [Custom license](https://github.com/madler/zlib/blob/master/LICENSE).
- [asmjit](https://github.com/asmjit/asmjit) - [ZLib license](https://github.com/asmjit/asmjit/blob/master/LICENSE.md).
- [ladislav-zezula/CascLib](https://github.com/ladislav-zezula/CascLib) - [MIT license](https://github.com/ladislav-zezula/CascLib/blob/master/LICENSE).
- [lz4/lz4](https://github.com/lz4/lz4) - [Custom license](https://github.com/lz4/lz4/blob/dev/lib/LICENSE).
- [vimpunk/mio](https://github.com/vimpunk/mio) - [MIT license](https://github.com/vimpunk/mio/blob/master/LICENSE).
- [JustasMasiulis/xorstr](https://github.com/JustasMasiulis/xorstr) - [Apache License 2.0](https://github.com/JustasMasiulis/xorstr/blob/master/LICENSE)
- [ocornut/imgui](https://github.com/ocornut/imgui) - [MIT license](https://github.com/ocornut/imgui/blob/master/LICENSE.txt)
- [biocomp/hw_break](https://github.com/biocomp/hw_break) - [MIT license](https://github.com/biocomp/hw_break/blob/master/LICENSE)
- [Tencent/rapidjson](https://github.com/Tencent/rapidjson) - [MIT and JSON license](https://github.com/Tencent/rapidjson/blob/master/license.txt)

## Downloads

You can download the latest release here:

- [Latest Release](https://github.com/ate47/atian-cod-tools/releases/latest)
- [Latest Dev Build](https://github.com/ate47/atian-cod-tools/releases/tag/latest_build) (Might be unstable)

## Related repositories

- [ate47/t8-atian-menu](https://github.com/ate47/t8-atian-menu/tree/master/docs/notes) : All the notes and dump generated by this tool. (All games)
- [ate47/bo4-source](https://github.com/ate47/bo4-source) : Black Ops 4 Dump
- [ate47/bocw-source](https://github.com/ate47/bocw-source) : Black Ops Cold War Dump
- [ate47/BOHashTool](https://github.com/ate47/BOHashTool) : Tool to test hashes with error (en/de)coder for Black Ops games

## Tools

### Mods

Mods implemented in my tool, run `acts mod` for the list.

- `acts mod t8cee` - enable EEs in Custom mutations, offline or casual (Black Ops 4).
- `acts mod t9cee` - enable EEs in offline (Black Ops Cold War).

### Decompiler/Disassembler

Tools to decompile or disassemble the GSC scripts, a bo4 script decompilation is available in the [bo4-source](https://github.com/ate47/bo4-source) and [bocw-source](https://github.com/ate47/bocw-source) repositories.

- gsc disassembler, made in 3 days with a lot of alcohol so don't use it. `acts gscinfo -a -o "output" [input=scriptparsetree]`
- gsc decompiler, same as the disassembler, but 10 days after, not any better. `acts gscinfo -g -o "output" [input=scriptparsetree]`

### Compiler

GSC compiler, not for all the game, scripts can be compiled using the command `acts gscc -g [game] [directory]`.

### GSC Development (Black Ops 4)

Tools to help with the GSC development.

- gsc vm debugger, dump the function stack when the vm has a crash, `acts dbg`
	- can dump the var stack `-s` local var `-v`
	- can look inside structures with the depth for array `-A [depth]` and structs `-S [depth]`  (need the game started)

## Lookup

To have a lookup over the extracted hashes, you can use a file named `strings.txt` when using the process, it will be loaded automatically, one string per line.

You can also use .wni compiled files, create a directory with the name `package_index` and put the .wni files in it.

## Credits

- Serious's t8-compiler for some opcodes for Black Ops 4, it fasted up the process of understanding the internal game functions. Also for the childthread operator syntax.
