# ldacBT

AOSP libldac dispatcher

https://android.googlesource.com/platform/external/libldac

### Build
```bash
git clone https://github.com/EHfive/ldacBT.git
cd ldacBT
git submodule update --init
```

----------

```bash
mkdir build && cd build
cmake \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DINSTALL_LIBDIR=/usr/lib \
    -DLDAC_SOFT_FLOAT=OFF \
    ../
make DESTDIR=$DEST_DIR install
```

**Tree**

```
usr/
├── include
│   └── ldac
│       ├── ldacBT_abr.h
│       └── ldacBT.h
└── lib
    ├── libldacBT_abr.so
    ├── libldacBT_enc.so
    └── pkgconfig
        ├── ldacBT-abr.pc
        └── ldacBT-enc.pc
```