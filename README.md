### Tools needed for compilation
- [splat](https://github.com/ethteck/splat)
- [ido-static-recomp](https://github.com/decompals/ido-static-recomp)
- [asm-processor](https://github.com/simonlindholm/asm-processor)
- [ultralib](https://github.com/decompals/ultralib) header files

### Tools used for development
- [m2c](https://github.com/matt-kempster/m2c)
- [asm-differ](https://github.com/simonlindholm/asm-differ)
- [gfxdis.f3dex2](https://github.com/glankk/n64)
- [n64sym](https://github.com/shygoo/n64sym)

### Install `splat`
```
$ python3 -m pip install -U splat64[mips]
```

### Download `tnt-splat`
```
$ cd ~/src

$ git clone https://github.com/chris-gilmore/tnt-splat.git
$ cd tnt-splat
$ make setup-tools
```

Place `baserom.z64` under `~/src/tnt-splat/`.
```
$ crc32 baserom.z64
528a07fa

$ md5sum baserom.z64
7a28179b00734c9aa0f0609fafaafd5f

$ sha1sum baserom.z64
83fff25e82181a6993f28c91b9eeb8430396838b
```

For a clean compilation, repeat these steps.
```
$ rm -rf asm assets
$ splat split newtetris.yaml
$ make clean
$ make
  The above `make` assumes a cross toolchain of `mips64-linux-gnu-`.
  Specify your own cross toolchain if you need to, for example:
  $ make CROSS=mips-linux-gnu-
$ diff baserom.z64 build/tnt.z64
```
