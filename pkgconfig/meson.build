pkg = import('pkgconfig')

if single_lib
    pkg.generate(libraries : [ ldacBT_lib ],
                 subdirs : 'ldac',
                 version : libldac_version,
                 name : 'ldacBT',
                 filebase : 'ldacBT',
                 libraries_private : [ mathlib ],
                 license :  'Apache-2.0',
                 description : 'LDAC Bluetooth library.')
    endif

if not single_lib
    if encoder
        pkg.generate(libraries : [ ldacBT_enc_lib ],
                     subdirs : 'ldac',
                     version : libldac_version,
                     name : 'ldacBT-enc',
                     filebase : 'ldacBT-enc',
                     libraries_private : [ mathlib ],
                     license : 'Apache-2.0',
                     description : 'LDAC Encoder Bluetooth library.')
    endif
    if decoder
        pkg.generate(libraries : [ ldacBT_dec_lib ],
                    subdirs : 'ldac',
                    version : libldac_version,
                    name : 'ldacBT-dec',
                    filebase : 'ldacBT-dec',
                    libraries_private : [ mathlib ],
                    license : 'Apache-2.0',
                    description : 'LDAC Decoder Bluetooth library.')
    endif
endif

if build_abr
    pkg.generate(libraries : [ ldacBT_abr_lib ],
                subdirs : 'ldac',
                version : libldac_version,
                name : 'ldacBT-abr',
                filebase : 'ldacBT-abr',
                libraries_private : ldac,
                license : 'Apache-2.0',
                description : 'LDAC ABR Bluetooth library.')
endif
