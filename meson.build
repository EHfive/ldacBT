project('libldac', ['c'],
 version : '2.0.3.1',
 license : 'Apache-2.0',
 license_files : [ 'LICENSE' ],
 meson_version : '>= 1.9.0',
 default_options : [
    'buildtype=debugoptimized',
	'default_library=static',
	'c_std=c99',
	'b_pie=true',
])

libldac_version = meson.project_version()

prefix = get_option('prefix')
libldac_libdir = prefix / get_option('libdir')
includedir = prefix / get_option('includedir') / 'ldac'
license_option = get_option('install_license') ? true : false
if license_option
    license_installdir = prefix / 'shared' / 'licenses'  / 'ldac'
endif
pkgconfig = import('pkgconfig')

cc = meson.get_compiler('c')
cc_native = meson.get_compiler('c', native: true)
cc_flags = []

if get_option('ldac_soft_float').allowed()
	cc_flags += [ '-D_32BIT_FIXED_POINT' ]
endif

single_lib = get_option('single_library')
encoder =  get_option('ldac_encoder').allowed()
decoder = get_option('ldac_decoder').allowed()
decoder_only = decoder and not encoder and single_lib ? true : false
encoder_only = encoder and not decoder and single_lib ? true : false

if not decoder and not encoder
    error('Is not possible build ldacBT without encoder and encoder')
endif

if decoder_only
    cc_flags += [ '-D_DECODE_ONLY' ]
endif
if encoder_only
    cc_flags += [ '-D_ENCODE_ONLY ' ]
endif

without_abr = decoder and not encoder ? true : false
feature_abr = get_option('abr').disable_auto_if(without_abr)
build_abr = feature_abr.allowed()

if not build_abr
    warning('LDAC ABR depends on ldac encoder option. LDAC ABR library will not build')
endif

add_project_arguments(cc.get_supported_arguments(cc_flags), language: 'c')

cc_flags += [ '-fno-merge-constants' ]
incdir = include_directories('libldac/inc', 'libldac/abr/inc')
mathlib = cc.find_library('m', required : true)

h = [ 'libldac/inc/ldacBT.h' ]
if build_abr
    h += [ 'libldac/abr/inc/ldacBT_abr.h' ]
endif

if license_option
    data = [ 'LICENSE' ]
    install_data(data, install_dir : license_installdir)
    meson.install_dependency_manifest('depmf.json')
endif
install_headers(h, install_dir : includedir)

ldac = []
# libldacBT
if single_lib
    ldacBT_lib = shared_library('ldacBT',
    				[ 'libldac/src/ldaclib.c', 'libldac/src/ldacBT.c' ],
    				include_directories : [ incdir ],
    				dependencies : [ mathlib ],
    				c_args : cc_flags,
    				install_dir : libldac_libdir,
    				soversion : '2.0.3.1',
    				install : true,
    				)
    				ldac += [ ldacBT_lib ]
endif

if not single_lib
    if encoder
        ldacBT_enc_lib = shared_library('ldacBT_enc',
				[ 'libldac/src/ldaclib.c', 'libldac/src/ldacBT.c' ],
				include_directories : [ incdir ],
				dependencies : [ mathlib ],
				c_args : [ cc_flags, '-D_ENCODE_ONLY' ],
				install_dir : libldac_libdir,
				soversion: '2.0.3.1',
				install : true,
                )
                ldac += [ ldacBT_enc_lib ]
    endif
    if decoder
            ldacBT_dec_lib = shared_library('ldacBT_dec',
				[ 'libldac/src/ldaclib.c', 'libldac/src/ldacBT.c' ],
				include_directories : [ incdir ],
				dependencies : [ mathlib ],
				c_args : [ cc_flags, '-D_DECODE_ONLY' ],
				install_dir : libldac_libdir,
				soversion : '2.0.3.1',
				install : true,
				)
    endif
endif

if build_abr
    # libldacBT_abr
    ldacBT_abr_lib = shared_library('ldacBT_abr',
        				[ 'libldac/abr/src/ldacBT_abr.c' ],
        				include_directories : [ incdir ],
        				c_args : cc_flags,
        				link_with : ldac,
        				install_dir : libldac_libdir,
        				soversion : '2.0.3.1',
        				install : true,
        )
endif

subdir('pkgconfig')

ldacbtencso = encoder and not single_lib ? true : false
ldacbtdecso = decoder and not single_lib ? true : false
is_soft_float = get_option('ldac_soft_float').allowed() ? 'Soft Float' : 'Hard Float'
summary({'prefix': get_option('prefix'),
         'libdir': get_option('libdir'),
         'includedir': get_option('includedir'),}, section: 'Directories')
summary ({'LDAC ABR': build_abr,
          'LDAC Decoder': decoder,
          'LDAC Encoder': encoder,
          'LDAC Float': is_soft_float,}, bool_yn: true, section: 'LDAC')
summary({'ldacBT': single_lib,
         'ldacBT_dec': ldacbtdecso,
         'ldacBT_enc': ldacbtencso }, bool_yn: true, section: 'Library')
