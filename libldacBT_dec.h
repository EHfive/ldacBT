#ifndef __LDACBTDEC_H_
#define __LDACBTDEC_H_



typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct _st_ldacbt_config _st_ldacbt_config, *P_st_ldacbt_config;

typedef struct _st_ldacbt_config * P_LDACBT_CONFIG;

struct _st_ldacbt_config {
    int id;
    int nfrm_in_pkt;
    int frmlen;
    int frmlen_1ch;
};

typedef struct _st_ldacbt_eqmid_property _st_ldacbt_eqmid_property, *P_st_ldacbt_eqmid_property;

struct _st_ldacbt_eqmid_property {
    int eqmid;
    char strModeName[4];
    int id_for_2DH5;
};

typedef struct _audio_block_ldac _audio_block_ldac, *P_audio_block_ldac;

typedef struct _audio_channel_ldac _audio_channel_ldac, *P_audio_channel_ldac;

typedef struct _audio_channel_ldac AC;

typedef struct _audio_block_ldac AB;

typedef struct _audio_channel_sub_ldac _audio_channel_sub_ldac, *P_audio_channel_sub_ldac;

typedef struct _audio_channel_sub_ldac ACSUB;

struct _audio_block_ldac {
    int blk_type;
    int blk_nchs;
    int nbands;
    int nqus;
    int unk1;
    int unk2;
    int grad_mode;
    int grad_qu_l;
    int grad_qu_h;
    int grad_os_l;
    int grad_os_h;
    int a_grad[50];
    int nadjqus;
    int abc_status;
    int nbits_ab;
    int nbits_band;
    int nbits_grad;
    int nbits_scfc;
    int nbits_spec;
    int nbits_avail;
    int nbits_used;
    int * p_smplrate_id;
    int * p_error_code;
    AC * ap_ac[2];
};

struct _audio_channel_ldac {
    int ich;
    int frmana_cnt;
    int unk3;
    int sfc_mode;
    int sfc_bitlen;
    int sfc_offset;
    int sfc_weight;
    int a_idsf[34];
    int a_idwl1[34];
    int a_idwl2[34];
    int a_addwl[34];
    int a_tmp[34];
    int a_qspec[256];
    int a_rspec[256];
    AB * p_ab;
    ACSUB * p_ascub;
};

struct _audio_channel_sub_ldac {
    float a_time[512];
    float a_spec[256];
};

typedef union IEEE754_FI IEEE754_FI, *PIEEE754_FI;

union IEEE754_FI {
    float f;
    int i;
};

typedef struct _config_info_ldac _config_info_ldac, *P_config_info_ldac;

typedef struct _config_info_ldac CFG;

struct _config_info_ldac {
    int syncword;
    int smplrate_id;
    int chconfig_id;
    int ch;
    int frame_length;
    int frame_status;
};

typedef struct _sfinfo_ldac _sfinfo_ldac, *P_sfinfo_ldac;

typedef struct _sfinfo_ldac SFINFO;

struct _sfinfo_ldac {
    CFG CFG;
    AB * p_ab;
    AC * ap_ac[2];
    char * p_mempos;
    int error_code;
};

enum{
    _2_DH1=3,
    _2_DH2=4,
    _2_DH3=5,
    _3_DH1=6,
    _3_DH2=7,
    _3_DH3=8,
    ___DH1=0,
    ___DH2=1,
    ___DH3=2
};

typedef enum LDAC_SMPL_FMT_T {
    LDAC_SMPL_FMT_F32=5,
    LDAC_SMPL_FMT_MAX=2147483647,
    LDAC_SMPL_FMT_NONE=0,
    LDAC_SMPL_FMT_NUM=6,
    LDAC_SMPL_FMT_S08=1,
    LDAC_SMPL_FMT_S16=2,
    LDAC_SMPL_FMT_S24=3,
    LDAC_SMPL_FMT_S32=4
} LDAC_SMPL_FMT_T;

typedef struct _handle_ldac_struct _handle_ldac_struct, *P_handle_ldac_struct;

struct _handle_ldac_struct {
    int nlnn;
    int nbands;
    int grad_mode;
    int grad_qu_l;
    int grad_qu_h;
    int grad_os_l;
    int grad_os_h;
    int abc_status;
    int error_code;
    SFINFO sfinfo;
};

typedef struct _ldacbt_pcm_ring_buf _ldacbt_pcm_ring_buf, *P_ldacbt_pcm_ring_buf;

typedef struct _ldacbt_pcm_ring_buf LDACBT_PCM_RING_BUF;

struct _ldacbt_pcm_ring_buf {
    char buf[6144];
    int wp;
    int rp;
    int nsmpl;
};

typedef struct _ldacbt_transport_frame_buf _ldacbt_transport_frame_buf, *P_ldacbt_transport_frame_buf;

struct _ldacbt_transport_frame_buf {
    char buf[1024];
    int used;
    int nfrm_in;
};

typedef struct _st_ldacbt_handle _st_ldacbt_handle, *P_st_ldacbt_handle;

typedef struct _handle_ldac_struct * HANDLE_LDAC;

typedef enum LDACBT_PROCMODE {
    LDACBT_PROCMODE_DECODE=2,
    LDACBT_PROCMODE_ENCODE=1,
    LDACBT_PROCMODE_UNSET=4294967295
} LDACBT_PROCMODE;

typedef struct _ldacbt_pcm_info _ldacbt_pcm_info, *P_ldacbt_pcm_info;

typedef struct _ldacbt_pcm_info LDACBT_PCM_INFO;

typedef struct _ldacbt_tx_info _ldacbt_tx_info, *P_ldacbt_tx_info;

typedef struct _ldacbt_tx_info LDACBT_TX_INFO;

typedef struct _ldacbt_transport_frame_buf LDACBT_TRANSPORT_FRM_BUF;

typedef enum LDACBT_SMPL_FMT_T {
    LDACBT_SMPL_FMT_F32=5,
    LDACBT_SMPL_FMT_S16=2,
    LDACBT_SMPL_FMT_S24=3,
    LDACBT_SMPL_FMT_S32=4
} LDACBT_SMPL_FMT_T;

struct _ldacbt_tx_info {
    int mtu;
    int tx_size;
    int pkt_type;
    int pkt_hdr_sz;
    int nrfm_in_pkt;
};

struct _ldacbt_pcm_info {
    int sf;
    int ch;
    int wl;
    enum LDACBT_SMPL_FMT_T fmt;
};

struct _st_ldacbt_handle {
    HANDLE_LDAC hLDAC;
    enum LDACBT_PROCMODE proc_mode;
    int error_code;
    int error_code_api;
    LDACBT_PCM_INFO pcm;
    LDACBT_TX_INFO tx;
    int frm_samples;
    int sfid;
    int nshift;
    int flg_encode_flushed;
    int frm_status;
    int frmlen;
    int frmlen_tx;
    int bitrate;
    int eqmid;
    int tgt_eqmid;
    int tgt_nfrm_in_pkt;
    int tgt_frmlen;
    int stat_alter_op;
    int cm;
    int cci;
    int transport;
    int some_code;
    LDACBT_TRANSPORT_FRM_BUF ldac_trns_frm_buf;
    LDACBT_PCM_RING_BUF pcmring;
    char * * pp_pcm;
    char * ap_pcm[2];
    char a_pcm[4096];
};

typedef struct _st_ldacbt_handle STRUCT_LDACBT_HANDLE;

typedef uchar STREAM;

typedef struct _st_ldacbt_eqmid_property * P_LDACBT_EQMID_PROPERTY;

typedef struct _st_ldacbt_handle * HANDLE_LDAC_BT;

typedef struct _st_ldacbt_eqmid_property LDACBT_EQMID_PROPERTY;

typedef struct _st_ldacbt_config LDACBT_CONFIG;

int ldacBT_decode(HANDLE_LDAC_BT hLdacBT, uchar *p_stream, void *p_pcm, LDACBT_SMPL_FMT_T fmt, int stream_sz, int *used_bytes, int *pcm_sz);
int ldacBT_init_handle_decode(HANDLE_LDAC_BT hLdacBT, int cm, int sf, int nshift, int var1, int var2);
HANDLE_LDAC_BT ldacBT_get_handle(void);
void ldacBT_free_handle(HANDLE_LDAC_BT hLdacBT);

#endif // __LDACBTDEC_H_
