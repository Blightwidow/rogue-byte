typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
extern "C" {
struct AlarmBlock_44C300 { AlarmBlock_44C300 *next; char pad[0x3C]; };
struct AlarmState_2C5A30 { s64 ticks; s32 handlerId; s32 pad0C; s32 field10; AlarmBlock_44C300 *pool; };
s32 AddIntcHandler2(s32, void *, s32, s32);
s32 EnableIntc(s32);
s32 func_00239450(void);
void func_002394A0(void);
void func_00239AB0(s32);
void func_00239AC0(s32);
void func_00239AD0(s32);
void func_0023A618(void);
void *memset(void *, s32, u32);
extern AlarmBlock_44C300 B_0044C300[128];
extern AlarmState_2C5A30 D_002C5A30;
extern char func_00239F28[];
s32 func_00239AE0(s32 flags) {
    s32 i;
    s32 handlerId;
    s32 hadPending;
    s32 control;
    if (D_002C5A30.handlerId >= 0) {
        return 0x80008001;
    }
    D_002C5A30.ticks = 0;
    D_002C5A30.field10 = 0;
    memset(B_0044C300, 0, 0x2000);
    D_002C5A30.pool = B_0044C300;
    for (i = 0x7F; i >= 0; i--) {
        B_0044C300[i].next = &B_0044C300[i + 1];
    }
    B_0044C300[0x7F].next = 0;
    func_0023A618();
    handlerId = AddIntcHandler2(0xB, func_00239F28, 0, 0);
    if (handlerId < 0) {
        return 0x80009021;
    }
    D_002C5A30.handlerId = handlerId;
    hadPending = func_00239450();
    control = *(volatile s32 *)0x10001010;
    control = (control & 0xFFFFFFFC) | flags;
    control |= 0x300;
    if (!(control & 0x80)) {
        func_00239AB0(0);
        control |= 0xC80;
        func_00239AD0(0xFFFF);
    }
    func_00239AC0(control);
    EnableIntc(0xB);
    if (hadPending != 0) {
        func_002394A0();
    }
    return 0;
}
}
