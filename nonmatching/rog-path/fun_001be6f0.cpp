typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BE6F0 {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ char pad70[0xC];
    /* 0x07C */ s32 sp7C;                           /* inferred */
    /* 0x080 */ char pad80[0xC];                    /* maybe part of sp7C[4]? */
    /* 0x08C */ s32 sp8C;                           /* inferred */
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[0x20];
    /* 0x0B0 */ M2C_UNK spB0;                       /* inferred */
    /* 0x0B0 */ char padB0[0x40];
    /* 0x0F0 */ s128 spF0;                          /* inferred */
    /* 0x100 */ char pad100[0x30];                  /* maybe part of spF0[4]? */
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x138 */ s32 sp138;                          /* overlap; inferred */
    /* 0x13C */ f32 sp13C;                          /* overlap; inferred */
    /* 0x140 */ char pad140[8];                     /* maybe part of sp13C[3]? */
    /* 0x148 */ s32 sp148;                          /* inferred */
    /* 0x14C */ f32 sp14C;                          /* inferred */
    /* 0x150 */ char pad150[0x70];
};                                                  /* size = 0x1C0 */
#define sp30 (*(s128 *)(sp + 0x030))
#define sp40 (*(s128 *)(sp + 0x040))
M2C_UNK AddDmaCnt__4DMAS(s32, M2C_UNK *, s32, s32, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AddVifBaseOffset__4VIFSii(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifDirect__4VIFSiP2QWi(s32, s32, s32, M2C_UNK); /* extern */
M2C_UNK AddVifFlush__4VIFS(s32);                    /* extern */
M2C_UNK AddVifFlusha__4VIFS(s32);                   /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, M2C_UNK, s128 *, M2C_UNK); /* extern */
M2C_UNK BuildSimpleProjectionMatrix__FffffffP7MATRIX4(M2C_UNK *, f32, f32, M2C_UNK, M2C_UNK, f32, f32); /* extern */
M2C_UNK CombineEyeLookAtProj(s128 *, M2C_UNK *, s128 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
s8 *PmatLoWorld(s8 *);                          /* extern */
s32 PosLoWorld(s8 *, s128);                       /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK); /* extern */
f32 tanf(f32);                                      /* extern */
extern M2C_UNK D_002C1F00;
extern M2C_UNK D_002C1F10;
void func_001BE6F0(s8 *arg0, s32 arg1) {
    s32 unksp6C;
    s8 sp[0x110] __attribute__((aligned(16)));
    s128 sp50;
    s128 sp60;
    s32 sp7C;
    s32 sp8C;
    M2C_UNK sp90;
    M2C_UNK spB0;
    s128 spF0;
    s128 sp130;
    s32 sp138;
    f32 sp13C;
    s32 sp148;
    f32 sp14C;
    M2C_UNK temp_a2;
    M2C_UNK temp_v1_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    s128 temp_v1;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x20);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(temp_v0, s8 **, 0x118);
        temp_s0_2 = (temp_s0 == NULL) ? temp_v0 : temp_s0;
        temp_v0_2 = PmatLoWorld(temp_s0_2);
        asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_2));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
        temp_v1 = M2C_FIELD(temp_v0_2, s128 *, 0x10);
        asm volatile("vmulx.xyzw vf4, vf1, vf2x");
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_2));
        asm volatile("vmulx.xyzw vf1, vf3, vf2x");
        sp50 = temp_v1;
        asm volatile("sqc2 vf2, 0xa0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(temp_s0_2, temp_v1)));
        __as__6VECTORG9VU_VECTOR(&sp90, vu_1);
        sp60 = sp30;
        M2C_FIELD(&sp60, s128 *, 0x10) = sp40;
        temp_f20 = (f32) M2C_FIELD(arg0, s32 *, 0) / (f32) M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(&sp60, s128 *, 0x20) = sp50;
        sp8C = 0;
        sp7C = 0;
        unksp6C = 0;
        M2C_FIELD(&sp60, f32 *, 0x3C) = 1.0f;
        temp_f0 = tanf(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x20), f32 *, 0x11C) * 0.5f);
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0x20);
        BuildSimpleProjectionMatrix__FffffffP7MATRIX4(&spB0, (f32) M2C_FIELD(arg0, s32 *, 0) / (temp_f0 * temp_f20 * 4096.0f), (f32) M2C_FIELD(arg0, s32 *, 4) / (temp_f0 * 4096.0f), 0, 0, M2C_FIELD(temp_v0_3, f32 *, 0x120), M2C_FIELD(temp_v0_3, f32 *, 0x124));
        CombineEyeLookAtProj(&sp60, &spB0, &spF0);
        temp_v0_4 = M2C_FIELD(arg0, s8 **, 0x20);
        temp_f2 = M2C_FIELD(temp_v0_4, f32 *, 0x124);
        temp_f1 = M2C_FIELD(temp_v0_4, f32 *, 0x120);
        s32 vu_2;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_2) : "r"(&D_002C1F00));
        s32 vu_3;
        asm volatile("ldr %0, (%1)" : "=r"(vu_3) : "r"(&D_002C1F00), "0"(vu_2));
        temp_a2 = vu_3;
        asm volatile("sdl %0, 0x137(%1)" : : "r"(temp_a2), "r"(sp));
        asm volatile("sdr %0, 0x130(%1)" : : "r"(temp_a2), "r"(sp));
        sp138 = M2C_FIELD(&D_002C1F00, s32 *, 8);
        temp_f1_2 = (temp_f1 + temp_f2) / (temp_f1 - temp_f2);
        temp_f2_2 = 1.0f - temp_f1_2;
        sp13C = 1.0f / (M2C_FIELD(temp_v0_4, f32 *, 0x120) * temp_f2_2);
        s32 vu_4;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_4) : "r"(&D_002C1F10));
        s32 vu_5;
        asm volatile("ldr %0, (%1)" : "=r"(vu_5) : "r"(&D_002C1F10), "0"(vu_4));
        temp_v1_2 = vu_5;
        asm volatile("sdl %0, 0x147(%1)" : : "r"(temp_v1_2), "r"(sp));
        asm volatile("sdr %0, 0x140(%1)" : : "r"(temp_v1_2), "r"(sp));
        sp148 = M2C_FIELD(&D_002C1F10, s32 *, 8);
        sp14C = -temp_f1_2 / (M2C_FIELD(temp_v0_4, f32 *, 0x120) * temp_f2_2);
        AddDmaCnt__4DMAS(arg1, &D_002C1F10, M2C_FIELD(&D_002C1F10, s32 *, 8), M2C_FIELD(&D_002C1F00, s32 *, 8), &D_002C1F10, &D_002C1F00);
        AddVifFlush__4VIFS(arg1);
        AddVifDirect__4VIFSiP2QWi(arg1, M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x14), 0);
        AddVifFlusha__4VIFS(arg1);
        AddVifBaseOffset__4VIFSii(arg1, 0, 0);
        AddVifUnpack__4VIFS3UPKiPvi(arg1, 0xC, 4, &spF0, 2);
        AddVifUnpack__4VIFS3UPKiPvi(arg1, 0xC, 4, &sp60, 6);
        AddVifUnpack__4VIFS3UPKiPvi(arg1, 0xC, 2, &sp130, 0);
        AddVifBaseOffset__4VIFSii(arg1, 0x32, 0x1E7);
        EndDmaCnt__4DMAS(arg1);
    }
}
}
