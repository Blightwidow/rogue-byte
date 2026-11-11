// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C5DE0-0X2C67A4 (piece data/sdk_2c49d4), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002C8914[];
extern "C" void __default_terminate();
extern "C" void __empty();
extern "C" void __get_dynamic_handler_chain();
extern "C" void __get_eh_context();
extern "C" void __get_eh_info();
extern "C" void __get_eh_table_language();
extern "C" void __get_eh_table_version();
extern "C" void __rethrow();
extern "C" void __sjthrow();
extern "C" void __terminate();
extern "C" void __throw();
extern "C" void __throw_type_match();
extern "C" void __unwinding_cleanup();
extern "C" void copy_reg();
extern "C" void eh_context_initialize();
extern "C" void eh_context_static();
extern "C" void find_exception_handler();
extern "C" void func_00100000();
extern "C" void func_0023B238();
extern "C" void get_reg_addr();
extern "C" void new_eh_context();
extern "C" void next_stack_level();
extern "C" void old_find_exception_handler();
extern "C" void throw_helper();

// data-ok: retail's bytes at 0X2C5DE0
unsigned int D_002C5DE0[2] = {0, 0};

// data-ok: retail's bytes at 0X2C5DE8
void *D_002C5DE8[16] = {(void *)90, (void *)func_0023B238, (void *)91, (void *)0x80075000, (void *)84, (void *)0x23b600, (void *)85, 0, (void *)86, 0, (void *)87, 0, (void *)88, 0, (void *)89, 0};

// data-ok: retail's bytes at 0X2C5E28
unsigned int D_002C5E28[52] = {0, 0x70000000, 0x80000007, 7, 0x6000, 0xffff8000, 0x1e1f, 0x1f1f, 0, 0x10000000, 0x400017, 0x400053, 0, 0x10002000, 0x400097, 0x4000d7, 0, 0x10004000, 0x400117, 0x400157, 0, 0x10006000, 0x400197, 0x4001d7, 0, 0x10008000, 0x400217, 0x400257, 0, 0x1000a000, 0x400297, 0x4002d7, 0, 0x1000c000, 0x400313, 0x400357, 0, 0x1000e000, 0x400397, 0x4003d7, 0x1e000, 0x11000000, 0x440017, 0x440415, 0x1e000, 0x12000000, 0x480017, 0x480415, 0x1ffe000, 0x1e000000, 0x780017, 0x7c0017};

// data-ok: retail's bytes at 0X2C5EF8
void *D_002C5EF8[72] = {(void *)0x7e000, (void *)0x80000, (void *)0x201f, (void *)0x301f, (void *)0x7e000, (void *)func_00100000, (void *)0x401f, (void *)0x501f, (void *)0x7e000, (void *)0x180000, (void *)0x601f, (void *)0x701f, (void *)0x1fe000, (void *)0x200000, (void *)0x801f, (void *)0xc01f, (void *)0x1fe000, (void *)0x400000, (void *)0x1001f, (void *)0x1401f, (void *)0x1fe000, (void *)0x600000, (void *)0x1801f, (void *)0x1c01f, (void *)0x7fe000, (void *)0x800000, (void *)0x2001f, (void *)0x3001f, (void *)0x7fe000, (void *)0x1000000, (void *)0x4001f, (void *)0x5001f, (void *)0x7fe000, (void *)0x1800000, (void *)0x6001f, (void *)0x7001f, (void *)0x7e000, (void *)0x20080000, (void *)0x2017, (void *)0x3017, (void *)0x7e000, (void *)0x20100000, (void *)0x4017, (void *)0x5017, (void *)0x7e000, (void *)0x20180000, (void *)0x6017, (void *)0x7017, (void *)0x1fe000, (void *)0x20200000, (void *)0x8017, (void *)0xc017, (void *)0x1fe000, (void *)0x20400000, (void *)0x10017, (void *)0x14017, (void *)0x1fe000, (void *)0x20600000, (void *)0x18017, (void *)0x1c017, (void *)0x7fe000, (void *)0x20800000, (void *)0x20017, (void *)0x30017, (void *)0x7fe000, (void *)0x21000000, (void *)0x40017, (void *)0x50017, (void *)0x7fe000, (void *)0x21800000, (void *)0x60017, (void *)0x70017};

// data-ok: retail's bytes at 0X2C6018
unsigned int D_002C6018[32] = {0x7e000, 0x30100000, 0x403f, 0x503f, 0x7e000, 0x30180000, 0x603f, 0x703f, 0x1fe000, 0x30200000, 0x803f, 0xc03f, 0x1fe000, 0x30400000, 0x1003f, 0x1403f, 0x1fe000, 0x30600000, 0x1803f, 0x1c03f, 0x7fe000, 0x30800000, 0x2003f, 0x3003f, 0x7fe000, 0x31000000, 0x4003f, 0x5003f, 0x7fe000, 0x31800000, 0x6003f, 0x7003f};

// data-ok: retail's bytes at 0X2C6098
void *D_002C6098[8] = {(void *)13, (void *)18, (void *)8, 0, (void *)&D_002C5E28, (void *)&D_002C5EF8, (void *)&D_002C6018, (void *)D_002C8914};

// data-ok: retail's bytes at 0X2C60B8
void *D_002C60B8 = (void *)__default_terminate;

// data-ok: retail's bytes at 0X2C60BC
void *D_002C60BC = (void *)eh_context_initialize;

// data-ok: retail's bytes at 0X2C60C0
void *D_002C60C0[384] = {(void *)16, 0, (void *)0x78010001, (void *)0x1d0c40, (void *)0x1f4009, (void *)28, (void *)24, (void *)__default_terminate, (void *)16, (void *)0x404, (void *)0x4100e00, (void *)4, (void *)0x24005, (void *)28, (void *)56, (void *)__terminate, (void *)36, (void *)0x804, (void *)0x4100e00, (void *)8, (void *)0x24005, (void *)36, (void *)88, (void *)__throw_type_match, (void *)44, (void *)0x404, (void *)0x4200e00, (void *)4, (void *)0x4040490, (void *)0x5000000, (void *)0x240, (void *)12, (void *)128, (void *)__empty, (void *)8, (void *)36, (void *)144, (void *)new_eh_context, (void *)84, (void *)0x404, (void *)0x4200e00, (void *)4, (void *)0x4040490, (void *)0x5000000, (void *)0x240, (void *)28, (void *)184, (void *)__get_eh_context, (void *)36, (void *)0x804, (void *)0x4100e00, (void *)8, (void *)0x24005, (void *)28, (void *)216, (void *)__get_eh_info, (void *)40, (void *)0x804, (void *)0x4100e00, (void *)8, (void *)0x24005, (void *)28, (void *)248, (void *)eh_context_initialize, (void *)40, (void *)0x804, (void *)0x4100e00, (void *)12, (void *)0x24005, (void *)44, (void *)0x118, (void *)eh_context_static, (void *)104, (void *)0x804, (void *)0x4300e00, (void *)8, (void *)0x4024005, (void *)4, (void *)0x8040491, (void *)0x90000000, (void *)6, (void *)28, (void *)0x148, (void *)__get_dynamic_handler_chain, (void *)40, (void *)0x804, (void *)0x4100e00, (void *)8, (void *)0x24005, (void *)184, (void *)0x168, (void *)__sjthrow, (void *)0x178, (void *)0x404, (void *)0xed00e00, (void *)0x804, (void *)0x4109e00, (void *)4, (void *)0x40e4005, (void *)4, (void *)0x4041297, (void *)0x96000000, (void *)0x40414, (void *)0x16950000, (void *)0x404, (void *)0x4189400, (void *)4, (void *)0x4041a93, (void *)0x92000000, (void *)0x4041c, (void *)0x1e910000, (void *)0x404, (void *)0x4209000, (void *)4, (void *)0x40401bf, (void *)0xbe000000, (void *)0x40402, (void *)0x3bd0000, (void *)0x404, (void *)0x404bc00, (void *)4, (void *)0x40405bb, (void *)0xba000000, (void *)0x40406, (void *)0x7b90000, (void *)0x404, (void *)0x408b800, (void *)4, (void *)0x40409b7, (void *)0xb6000000, (void *)0x4040a, (void *)0xbb50000, (void *)0x404, (void *)0x40cb400, (void *)12, (void *)0xed01e0c, (void *)176, (void *)0x224, (void *)0x23e618, (void *)0x118, (void *)0x804, (void *)0xed00e00, (void *)0x804, (void *)0xe400500, (void *)0x404, (void *)0x4109e00, (void *)4, (void *)0x4041297, (void *)0x96000000, (void *)0x40414, (void *)0x16950000, (void *)0x404, (void *)0x4189400, (void *)4, (void *)0x4041a93, (void *)0x92000000, (void *)0x4041c, (void *)0x1e910000, (void *)0x404, (void *)0x4209000, (void *)4, (void *)0x40401bf, (void *)0xbe000000, (void *)0x40402, (void *)0x3bd0000, (void *)0x404, (void *)0x404bc00, (void *)4, (void *)0x40405bb, (void *)0xba000000, (void *)0x40406, (void *)0x7b90000, (void *)0x404, (void *)0x408b800, (void *)4, (void *)0x40409b7, (void *)0xb6000000, (void *)0x4040a, (void *)0xbb50000, (void *)0x804, (void *)0xcb400, (void *)36, (void *)0x2d8, (void *)0x23e730, (void *)72, (void *)0x404, (void *)0x4200e00, (void *)4, (void *)0x4040490, (void *)0x5000000, (void *)0x240, (void *)12, (void *)0x300, (void *)__get_eh_table_version, (void *)8, (void *)12, (void *)0x310, (void *)__get_eh_table_language, (void *)8, (void *)12, (void *)0x320, (void *)old_find_exception_handler, (void *)216, (void *)80, (void *)0x330, (void *)find_exception_handler, (void *)0x144, (void *)0x404, (void *)0x1800e00, (void *)0x804, (void *)0x4049600, (void *)4, (void *)0x8040695, (void *)0x94000000, (void *)0x80408, (void *)0xa930000, (void *)0x804, (void *)0x40e9100, (void *)8, (void *)0x4024005, (void *)8, (void *)0x4040c92, (void *)0x90000000, (void *)16, (void *)28, (void *)0x384, (void *)get_reg_addr, (void *)136, (void *)0x404, (void *)0x4100e00, (void *)8, (void *)0x24005, (void *)48, (void *)0x3a4, (void *)copy_reg, (void *)124, (void *)0x404, (void *)0x4400e00, (void *)4, (void *)0x4040691, (void *)0x90000000, (void *)0xc0408, (void *)0x4920000, (void *)0x404, (void *)0x2400500, (void *)44, (void *)0x3d8, (void *)next_stack_level, (void *)140, (void *)0x404, (void *)0x4300e00, (void *)4, (void *)0x8040491, (void *)0x90000000, (void *)0x40406, (void *)0x40050000, (void *)2, (void *)12, (void *)0x408, (void *)__unwinding_cleanup, (void *)8, (void *)92, (void *)0x418, (void *)throw_helper, (void *)0x330, (void *)0x404, (void *)0xda00e00, (void *)0x404, (void *)0x4049e00, (void *)4, (void *)0x8040896, (void *)0x95000000, (void *)0x4040a, (void *)0xc940000, (void *)0x804, (void *)0x40e9300, (void *)8, (void *)0x8041490, (void *)0x5000000, (void *)0x8040240, (void *)0x97000000, (void *)0x40406, (void *)0x10920000, (void *)0x404, (void *)0x129100, (void *)184, (void *)0x478, (void *)__throw, (void *)0x1dc, (void *)0x404, (void *)0xdf00e00, (void *)0x804, (void *)0x4109e00, (void *)4, (void *)0x40e4005, (void *)4, (void *)0x4041297, (void *)0x96000000, (void *)0x40414, (void *)0x16950000, (void *)0x404, (void *)0x4189400, (void *)4, (void *)0x4041a93, (void *)0x92000000, (void *)0x4041c, (void *)0x1e910000, (void *)0x404, (void *)0x4209000, (void *)4, (void *)0x40401bf, (void *)0xbe000000, (void *)0x40402, (void *)0x3bd0000, (void *)0x404, (void *)0x404bc00, (void *)4, (void *)0x40405bb, (void *)0xba000000, (void *)0x40406, (void *)0x7b90000, (void *)0x404, (void *)0x408b800, (void *)4, (void *)0x40409b7, (void *)0xb6000000, (void *)0x4040a, (void *)0xbb50000, (void *)0x404, (void *)0x40cb400, (void *)12, (void *)0xdf01e0c, (void *)184, (void *)0x534, (void *)__rethrow, (void *)0x1e4, (void *)0x404, (void *)0xe800e00, (void *)0x804, (void *)0x4109e00, (void *)4, (void *)0xe801e0c, (void *)0x404, (void *)0xe400500, (void *)0x404, (void *)0x4129700, (void *)4, (void *)0x4041496, (void *)0x95000000, (void *)0x40416, (void *)0x18940000, (void *)0x404, (void *)0x41a9300, (void *)4, (void *)0x4041c92, (void *)0x91000000, (void *)0x4041e, (void *)0x20900000, (void *)0x404, (void *)0x401bf00, (void *)4, (void *)0x40402be, (void *)0xbd000000, (void *)0x40403, (void *)0x4bc0000, (void *)0x404, (void *)0x405bb00, (void *)4, (void *)0x40406ba, (void *)0xb9000000, (void *)0x40407, (void *)0x8b80000, (void *)0x404, (void *)0x409b700, (void *)4, (void *)0x4040ab6, (void *)0xb5000000, (void *)0x4040b, (void *)0xcb40000, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C66C0
unsigned int D_002C66C0[4] = {0x1000404, 0x20000000, 0, 0x5000000};

// data-ok: retail's bytes at 0X2C66D0
unsigned int D_002C66D0[8] = {0x6000000, 0x3000000, 0x2000000, 0x4000000, 0x49497350, 0x6762696c, 0x68706172, 0x30303033};

// data-ok: retail's bytes at 0X2C66F0
unsigned int D_002C66F0[8] = {0x20001, 0x30001, 0, 0, 0x49497350, 0x6462696c, 0x2020616d, 0x30303033};

// data-ok: retail's bytes at 0X2C6710
unsigned int D_002C6710[16] = {0x10008000, 0x10009000, 0x1000a000, 0x1000b000, 0x1000b400, 0x1000c000, 0x1000c400, 0x1000c800, 0x1000d000, 0x1000d400, 0, 0, 0x49497350, 0x6362696c, 0x20647664, 0x30303033};

// data-ok: retail's bytes at 0X2C6750
unsigned int D_002C6750 = 0;

// data-ok: retail's bytes at 0X2C6754
unsigned int D_002C6754 = 0;

// data-ok: retail's bytes at 0X2C6758
unsigned int D_002C6758 = 0;

// data-ok: retail's bytes at 0X2C675C
unsigned int D_002C675C = 0;

// data-ok: retail's bytes at 0X2C6760
unsigned int D_002C6760 = 0xffffffff;

// data-ok: retail's bytes at 0X2C6764
unsigned int D_002C6764 = 0;

// data-ok: retail's bytes at 0X2C6768
unsigned int D_002C6768 = 0xffffffff;

// data-ok: retail's bytes at 0X2C676C
unsigned int D_002C676C = 0xffffffff;

// data-ok: retail's bytes at 0X2C6770
unsigned int D_002C6770 = 0xffffffff;

// data-ok: retail's bytes at 0X2C6774
unsigned int D_002C6774 = 0;

// data-ok: retail's bytes at 0X2C6778
unsigned int D_002C6778 = 0;

// data-ok: retail's bytes at 0X2C677C
unsigned int D_002C677C = 0xffffffff;

// data-ok: retail's bytes at 0X2C6780
unsigned int D_002C6780 = 1;

// data-ok: retail's bytes at 0X2C6784
unsigned int D_002C6784 = 0;

// data-ok: retail's bytes at 0X2C6788
unsigned int D_002C6788 = 0xffffffff;

// data-ok: retail's bytes at 0X2C678C
unsigned int D_002C678C = 0xffffffff;

// data-ok: retail's bytes at 0X2C6790
unsigned int D_002C6790 = 0xffffffff;

// data-ok: retail's bytes at 0X2C6794
unsigned int D_002C6794 = 0xffffffff;

// data-ok: retail's bytes at 0X2C6798
unsigned int D_002C6798 = 0xffffffff;

// data-ok: retail's bytes at 0X2C679C
unsigned int D_002C679C = 0;

// data-ok: retail's bytes at 0X2C67A0
unsigned int D_002C67A0 = 0;
