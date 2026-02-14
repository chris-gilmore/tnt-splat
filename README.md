### Tools needed for compilation
- [splat](https://github.com/ethteck/splat)
- [ido-static-recomp](https://github.com/decompals/ido-static-recomp)
- [asm-processor](https://github.com/simonlindholm/asm-processor)
- [ultralib](https://github.com/decompals/ultralib) header files

### Tools used for development
- [m2c](https://github.com/matt-kempster/m2c)
- [asm-differ](https://github.com/simonlindholm/asm-differ)

### Install `splat`
```
$ python3 -m pip install -U splat64[mips]
```

### Install `/opt/ido-static-recomp/`
```
$ mkdir -p ~/src
$ cd ~/src

$ wget https://github.com/decompals/ido-static-recomp/archive/refs/tags/v1.1.tar.gz
$ tar zxf v1.1.tar.gz

$ cd ido-static-recomp-1.1
$ make setup
$ make VERSION=5.3
$ make VERSION=7.1

$ sudo mkdir -p /opt/ido-static-recomp/5.3
$ sudo mkdir -p /opt/ido-static-recomp/7.1
$ sudo cp -r build/5.3/out /opt/ido-static-recomp/5.3/bin
$ sudo cp -r build/7.1/out /opt/ido-static-recomp/7.1/bin
```

### Install `/opt/asm-processor/`
```
$ cd ~/src

$ git clone https://github.com/simonlindholm/asm-processor.git
$ cd asm-processor

$ sudo mkdir -p /opt/asm-processor
$ sudo cp prelude.inc asm_processor.py build.py /opt/asm-processor/
```

### Install `/opt/ultralib`
```
$ cd /opt
$ sudo git clone https://github.com/decompals/ultralib.git
```

### Download `tnt-splat`
```
$ cd ~/src

$ git clone https://github.com/chris-gilmore/tnt-splat.git
$ cd tnt-splat
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
$ diff baserom.z64 build/tnt.z64
```
