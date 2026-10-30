typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PostJtLoad {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of sp40[4]? */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ s128 sp60;                           /* inferred */
    /* 0x70 */ s128 sp70;                           /* inferred */
    /* 0x80 */ char pad80[0x70];
};                                                  /* size = 0xF0 */
void CarryThrow_EnsureBlends(s8 *);
s32 CploFindSwObjects_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
void LoadAttach(s8 *);
void LoadJtGadgetSlots(s8 *);
s32 PalertEnsure(s8 *);
s32 *PmatLoWorld(s8 *);
s32 PosLoWorld(s8 *);
void PostBinocLoad(s8 *);
void PostJtLoadPipe(s8 *);
void PostJtLoadZap__FP2JT(s8 *);
void PostStepLoad();
s32 PvAllocSwClearImpl__Fi(s32 *, s32 *);
void QueueSwCallback(M2C_UNK *, s8 *, M2C_UNK, M2C_UNK);
f32 SetSoMass__FP2SOf(s8 *, M2C_UNK);
void SetSoProperties(s8 *, M2C_UNK, M2C_UNK *);
void bevy_player_p18_gadget_refill(s8 *, s32);
void func_001959C0(s8 *);
void func_0019F3F0(s8 *);
s32 memset(s8 *, M2C_UNK, M2C_UNK, s128);
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BC9F0;
extern M2C_UNK RO_002A4D17;
void PostJtLoad(s8 *arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s32 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    M2C_UNK temp_s1;
    s128 temp_a3;
    s32 *var_s1;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_6;
    s32 var_s0;
    s8 *temp_a1_2;
    s8 *temp_a1_3;
    s8 *temp_s0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1;
    s8 *temp_v1_2;
    PostStepLoad();
    SetSoProperties(arg0, 0x35, &D_002BC9F0);
    func_001959C0(arg0 + 0x2C0);
    LoadAttach(arg0 + 0x4C0);
    func_0019F3F0(arg0 + 0x9E0);
    PostJtLoadZap__FP2JT(arg0 + 0xDF0);
    PostBinocLoad(arg0 + 0xF00);
    CarryThrow_EnsureBlends(arg0 + 0x11B0);
    PostJtLoadPipe(arg0 + 0xF50);
    temp_v0 = CploFindSwObjects_thunk(&B_003DD490, 0x401, 0x2AB, arg0);
    if (temp_v0 != 0) {
        sp40 = temp_v0 * 8;
        M2C_FIELD(arg0, s32 *, 0x1094) = temp_v0;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        var_s0 = 0;
        M2C_FIELD(arg0, s32 *, 0x1090) = PvAllocSwClearImpl__Fi(&sp40, &sp40);
        if (temp_v0 > 0) {
            var_s1 = (s32 *)(sp);
            do {
                temp_a0 = var_s0 * 8;
                temp_a1 = *var_s1;
                var_s0 += 1;
                var_s1 += 4;
                *(s32 *)(temp_a0 + M2C_FIELD(arg0, s32 *, 0x1090)) = temp_a1;
                temp_a1_2 = (s8 *)(*(s32 *)(temp_a0 + M2C_FIELD(arg0, s32 *, 0x1090)));
                temp_v0_2 = M2C_FIELD(temp_a1_2, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0x4C)(temp_a1_2 + M2C_FIELD(temp_v0_2, s16 *, 0x48), temp_a1_2);
            } while (var_s0 < temp_v0);
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x278), 0);
    temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *), 0x344)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x340));
    LoadJtGadgetSlots(arg0);
    bevy_player_p18_gadget_refill(arg0, M2C_FIELD(&B_003DD490, s32 *, 0x3BF4) & 4);
    M2C_FIELD(arg0, s32 *, 0x1088) = PalertEnsure(arg0);
    SetSoMass__FP2SOf(arg0, 0x3E800000);
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x54), s32 *, 0x94) == 0) {
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(arg0)));
        temp_s1 = vu_1;
        temp_v0_5 = (s8 *)(PmatLoWorld(arg0));
        temp_s0 = M2C_FIELD(arg0, s8 **, 0x54);
        sp50 = M2C_FIELD(temp_v0_5, s128 *, 0);
        sp60 = M2C_FIELD(temp_v0_5, s128 *, 0x10);
        temp_a3 = M2C_FIELD(temp_v0_5, s128 *, 0x20);
        sp70 = temp_a3;
        memset(temp_s0, 0, 0x40, temp_a3);
        M2C_FIELD(temp_s0, f32 *, 0) = 1.0f;
        M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
        M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
        temp_v0_6 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_6;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x54), s32 *, 0xA4) = temp_v0_6;
        temp_a1_3 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_a1_3, M2C_UNK (**)(s8 *, s8 *), 0x94)(arg0 + M2C_FIELD(temp_a1_3, s16 *, 0x90), temp_a1_3);
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        s64 vu_2;
        asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s1));
        M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK), 0xEC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xE8), vu_2);
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, s128 *), 0xF4)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0xF0), &sp50);
    }
    s32 vu_3;
    asm volatile("ldl %0, %%lo(RO_002A4D17)(%1)" : "=r"(vu_3) : "r"(&RO_002A4D17));
    s32 vu_4;
    asm volatile("ldr %0, %%lo(RO_002A4D10)(%1)" : "=r"(vu_4) : "r"(&RO_002A4D17), "0"(vu_3));
    QueueSwCallback(&B_003DD490, arg0, vu_4, 0);
}
}
