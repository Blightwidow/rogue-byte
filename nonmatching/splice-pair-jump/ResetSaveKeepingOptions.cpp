typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ResetSaveKeepingOptions {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s32 sp10;                           /* inferred */
    /* 0x014 */ char pad14[0x24];                   /* maybe part of sp10[0xA]? */
    /* 0x038 */ s32 sp38;                           /* inferred */
    /* 0x03C */ char pad3C[4];
    /* 0x040 */ s32 sp40;                           /* inferred */
    /* 0x044 */ s32 sp44;                           /* inferred */
    /* 0x048 */ s32 sp48;                           /* inferred */
    /* 0x04C */ s32 sp4C;                           /* inferred */
    /* 0x050 */ s32 sp50;                           /* inferred */
    /* 0x054 */ s32 sp54;                           /* inferred */
    /* 0x058 */ s32 sp58;                           /* inferred */
    /* 0x05C */ s32 sp5C;                           /* inferred */
    /* 0x060 */ s32 sp60;                           /* inferred */
    /* 0x064 */ s32 sp64;                           /* inferred */
    /* 0x068 */ s32 sp68;                           /* inferred */
    /* 0x06C */ char pad6C[4];
    /* 0x070 */ s32 sp70;                           /* inferred */
    /* 0x074 */ char pad74[0x54];                   /* maybe part of sp70[0x16]? */
    /* 0x0C8 */ M2C_UNK spC8;                       /* inferred */
    /* 0x0C8 */ char padC8[0xA8];
};                                                  /* size = 0x170 */
M2C_UNK CRef_CopyConstruct(s32 *, s32 *);           /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
s32 FSaveDataMatchesLayout(M2C_UNK *, s32, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK RefGetSaveValue(s32 *, M2C_UNK *, s32, s32); /* extern */
M2C_UNK RefSetGameSaveValue(s32 *, s32, s32 *, s32); /* extern */
M2C_UNK StoreAudioModeInSave();                     /* extern */
M2C_UNK __as__4CRefRC4CRef(s32 *, s32 *);           /* extern */
M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK B_003E0EA8;
void ResetSaveKeepingOptions(s32 arg0, s32 arg1) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp38;
    s32 sp40;
    s32 sp44;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp70;
    M2C_UNK spC8;
    M2C_UNK temp_a0;
    M2C_UNK temp_a1;
    M2C_UNK temp_v0;
    M2C_UNK temp_v0_2;
    M2C_UNK temp_v1;
    s32 *temp_s6;
    s32 *var_a1;
    s32 *var_s0;
    s32 *var_s0_2;
    s32 *var_s0_3;
    s32 *var_s1;
    s32 *var_s1_2;
    s32 *var_t2;
    s32 var_s4;
    s32 var_t3;
    u32 var_s3;
    u32 var_s3_2;
    var_s4 = arg1;
    CStackFrame_Construct(sp);
    var_t2 = &sp70;
    temp_s6 = var_t2;
    var_t3 = 0xA;
    sp40 = M2C_FIELD(&B_003DD490, s32 *, 0x3B2C);
    sp44 = M2C_FIELD(&B_003DD490, s32 *, 0x3B48);
    sp48 = M2C_FIELD(&B_003DD490, s32 *, 0x3B54);
    sp4C = M2C_FIELD(&B_003DD490, s32 *, 0x3B4C);
    sp50 = M2C_FIELD(&B_003DD490, s32 *, 0x3B50);
    sp54 = M2C_FIELD(&B_003DD490, s32 *, 0x3B30);
    sp58 = M2C_FIELD(&B_003DD490, s32 *, 0x3B34);
    sp5C = M2C_FIELD(&B_003DD490, s32 *, 0x3B38);
    sp60 = M2C_FIELD(&B_003DD490, s32 *, 0x3B3C);
    sp64 = M2C_FIELD(&B_003DD490, s32 *, 0x3B40);
    sp68 = M2C_FIELD(&B_003DD490, s32 *, 0x3B44);
    s32 vu_1;
    asm volatile("ldl %0, 0x47(%1)" : "=r"(vu_1) : "r"(sp));
    s32 vu_2;
    asm volatile("ldr %0, 0x40(%1)" : "=r"(vu_2) : "r"(sp), "0"(vu_1));
    temp_v0 = vu_2;
    s32 vu_3;
    asm volatile("ldl %0, 0x4f(%1)" : "=r"(vu_3) : "r"(sp));
    s32 vu_4;
    asm volatile("ldr %0, 0x48(%1)" : "=r"(vu_4) : "r"(sp), "0"(vu_3));
    temp_v1 = vu_4;
    s32 vu_5;
    asm volatile("ldl %0, 0x57(%1)" : "=r"(vu_5) : "r"(sp));
    s32 vu_6;
    asm volatile("ldr %0, 0x50(%1)" : "=r"(vu_6) : "r"(sp), "0"(vu_5));
    temp_a0 = vu_6;
    s32 vu_7;
    asm volatile("ldl %0, 0x5f(%1)" : "=r"(vu_7) : "r"(sp));
    s32 vu_8;
    asm volatile("ldr %0, 0x58(%1)" : "=r"(vu_8) : "r"(sp), "0"(vu_7));
    temp_a1 = vu_8;
    asm volatile("sdl %0, 0x17(%1)" : : "r"(temp_v0), "r"(sp));
    asm volatile("sdr %0, 0x10(%1)" : : "r"(temp_v0), "r"(sp));
    asm volatile("sdl %0, 0x1f(%1)" : : "r"(temp_v1), "r"(sp));
    asm volatile("sdr %0, 0x18(%1)" : : "r"(temp_v1), "r"(sp));
    asm volatile("sdl %0, 0x27(%1)" : : "r"(temp_a0), "r"(sp));
    asm volatile("sdr %0, 0x20(%1)" : : "r"(temp_a0), "r"(sp));
    asm volatile("sdl %0, 0x2f(%1)" : : "r"(temp_a1), "r"(sp));
    asm volatile("sdr %0, 0x28(%1)" : : "r"(temp_a1), "r"(sp));
    s32 vu_9;
    asm volatile("ldl %0, 0x67(%1)" : "=r"(vu_9) : "r"(sp));
    s32 vu_10;
    asm volatile("ldr %0, 0x60(%1)" : "=r"(vu_10) : "r"(sp), "0"(vu_9));
    temp_v0_2 = vu_10;
    asm volatile("sdl %0, 0x37(%1)" : : "r"(temp_v0_2), "r"(sp));
    asm volatile("sdr %0, 0x30(%1)" : : "r"(temp_v0_2), "r"(sp));
    sp38 = sp68;
    do {
        *var_t2 = -1;
        var_t3 -= 1;
        var_t2 += 8;
    } while (var_t3 != -1);
    if (var_s4 != 0) {
        var_s4 = (FSaveDataMatchesLayout(&B_003E0EA8, arg0, M2C_FIELD(&B_003DD490, s32 *, 0x3B50), M2C_FIELD(&B_003DD490, s32 *, 0x3B30), M2C_FIELD(&B_003DD490, s32 *, 0x3B34), M2C_FIELD(&B_003DD490, s32 *, 0x3B38), M2C_FIELD(&B_003DD490, s32 *, 0x3B3C), M2C_FIELD(&B_003DD490, s32 *, 0x3B40)) == 0) ? 0 : var_s4;
        if (var_s4 != 0) {
            var_s3 = 0;
            var_s1 = &sp10;
            var_s0 = temp_s6;
            do {
                RefGetSaveValue(&sp40, &B_003E0EA8, *var_s1, arg0);
                var_s3 += 1;
                __as__4CRefRC4CRef(var_s0, &sp40);
                var_s1 += 4;
                var_s0 += 8;
                CRef_Destruct(&sp40);
            } while (var_s3 < 0xBU);
        }
    }
    memset(arg0, 0, 0x5400);
    StoreAudioModeInSave();
    var_s0_2 = temp_s6;
    if (var_s4 != 0) {
        var_s3_2 = 0;
        var_s1_2 = &sp10;
        var_a1 = var_s0_2;
        do {
            CRef_CopyConstruct(&sp40, var_a1);
            var_s3_2 += 1;
            RefSetGameSaveValue(&sp50, *var_s1_2, &sp40, arg0);
            var_s1_2 += 4;
            var_s0_2 += 8;
            CRef_Destruct(&sp50);
            CRef_Destruct(&sp40);
            var_a1 = var_s0_2;
        } while (var_s3_2 < 0xBU);
    }
    if (temp_s6 != &spC8) {
        var_s0_3 = &spC8 - 8;
        do {
            CRef_Destruct(var_s0_3);
            var_s0_3 -= 8;
        } while (temp_s6 != var_s0_3);
    }
    CStackFrame_Destructor(sp, 2);
}
}
