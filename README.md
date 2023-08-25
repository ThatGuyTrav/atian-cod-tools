# Atian Call of Duty Tools

My set of tools for Call of Duty.

**Supported games**
- Call of Duty: Black Ops 4 (T8)

## Tools

- dump linked events `acts dfunc [output=func.csv]` (need the game started)
- dump api functions `acts devents [output=events.csv]` (need the game started)
- dump pooled scripts `acts dps [output=pool.csv]` (need the game started)
- dump linked scripts `acts dls [output=linked.csv]` (need the game started)
- dump linked/pooled scripts on disk `acts wps [output=scriptparsetree]` (need the game started)
- gsc disassembler, made in 3 days with a lot of alcohol so don't use it. `acts gscinfo -a -o "output" [input=scriptparsetree]`
- gsc decompiler, same as the disassembler, but 10 days after, not any better. `acts gscinfo -g -o "output" [input=scriptparsetree]`

## Lookup

To have a lookup over the extracted hashes, you can use a file named `strings.txt` when using the process, it will be loaded automatically, one string per line.

## Credits

- Serious's t8-compiler for some opcodes, it fasted up the process of understanding the internal game functions.
