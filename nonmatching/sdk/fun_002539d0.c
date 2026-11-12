/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef unsigned int u32;
typedef struct Decoder {
    char pad0[0xE8];
    int fieldE8;
    char padEC[0x134 - 0xEC];
    u32 field134;
    int field138;
    char pad13C[0x144 - 0x13C];
    u32 field144;
    u32 field148;
    char pad14C[0x828 - 0x14C];
    int field828;
    u32 field82C;
    char pad830[0x850 - 0x830];
    u32 field850;
    u32 field854;
    char pad858[0x868 - 0x858];
    void *field868;
} Decoder;

extern int func_00239450(void);
extern void func_002394A0(void);
extern void func_0024B670(void *, int *);
extern void func_0024FA38(Decoder *, const char *);
extern u32 func_00252148(Decoder *, int);
extern void func_002536B8(void *);
extern void func_002542B8(Decoder *);
extern void func_00254488(Decoder *);
extern char D_002C84C0[];
extern char D_002C8500[];

void func_002539D0(Decoder *decoder)
{
    int mode;
    int header;
    u32 flag;
    int interrupts;
    u32 source;
    u32 control;

    decoder->fieldE8 = 0;
    header = func_00252148(decoder, 0x20);
    decoder->field138 = (header >> 8) & 0xFFF;
    decoder->field134 = header >> 20;
    if (decoder->field138 >= 0xAF1)
        func_0024FA38(decoder, "vertical size > 2800");
    header = func_00252148(decoder, 0x1E);
    decoder->field144 = header >> 12;
    decoder->field148 = (header >> 1) & 0x3FF;
    flag = func_00252148(decoder, 1);
    decoder->field850 = flag;
    if (flag != 0) {
        func_00254488(decoder);
        *(volatile u32 *)0x10002000 = 0x50000000;
        decoder->field82C = 0x50000000;
        decoder->field828 = 1;
        func_00254488(decoder);
    } else {
        mode = 2;
        source = (u32)D_002C84C0;
        func_0024B670(decoder->field868, &mode);
        control = 0x50000000;
        func_00254488(decoder);
        *(volatile u32 *)0x10002000 = 0;
        func_00254488(decoder);
        interrupts = func_00239450();
        *(volatile u32 *)0x1000B410 = source & 0x0FFFFFFF;
        *(volatile u32 *)0x1000B420 = 4;
        *(volatile u32 *)0x1000B400 = 0x101;
        if (interrupts != 0)
            func_002394A0();
        *(volatile u32 *)0x10002000 = control;
        decoder->field82C = 0x50000000;
        decoder->field828 = 1;
        func_00254488(decoder);
        mode = 3;
        func_0024B670(decoder->field868, &mode);
    }
    flag = func_00252148(decoder, 1);
    decoder->field854 = flag;
    if (flag != 0) {
        func_00254488(decoder);
        *(volatile u32 *)0x10002000 = 0x58000000;
        decoder->field82C = 0x50000000;
        decoder->field828 = 1;
        func_00254488(decoder);
    } else {
        mode = 2;
        func_0024B670(decoder->field868, &mode);
        func_00254488(decoder);
        *(volatile u32 *)0x10002000 = 0;
        func_00254488(decoder);
        interrupts = func_00239450();
        *(volatile u32 *)0x1000B410 = (u32)D_002C8500 & 0x0FFFFFFF;
        *(volatile u32 *)0x1000B420 = 4;
        *(volatile u32 *)0x1000B400 = 0x101;
        if (interrupts != 0)
            func_002394A0();
        *(volatile u32 *)0x10002000 = 0x58000000;
        decoder->field82C = 0x50000000;
        decoder->field828 = 1;
        func_00254488(decoder);
        mode = 3;
        func_0024B670(decoder->field868, &mode);
    }
    func_002542B8(decoder);
    func_002536B8(decoder->field868);
}
