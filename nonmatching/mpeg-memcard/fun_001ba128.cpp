typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BA128 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x30];
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ s32 sp44;                            /* inferred */
    /* 0x48 */ char pad48[8];                       /* maybe part of sp44[3]? */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x80];
};                                                  /* size = 0xE0 */
#define sp50 (*(s128 *)(sp + 0x50))
M2C_UNK BuildRotateVectorsMatrix(M2C_UNK *, s128, M2C_UNK); /* extern */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
s32 ConvertAloPos(s8 *, M2C_UNK, s128);           /* extern */
s32 ConvertXfPos(M2C_UNK, s32, M2C_UNK);            /* extern */
s128 DecomposeRotateMatrixEuler(M2C_UNK *);         /* extern */
s32 FAsegaGone(s32);                                /* extern */
s32 FIsGuardInSgs(s8 *, M2C_UNK);                 /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK UpdateGuard();                              /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, M2C_UNK, M2C_UNK *, M2C_UNK, s32 *, s32 *); /* extern */
M2C_UNK func_001BA408(s8 *, M2C_UNK);             /* extern */
s32 func_00227C90(s32, M2C_UNK);                    /* extern */
extern M2C_UNK B_003DD490;
extern s8 *B_003E1444;
extern s128 D_002C0A80;
extern M2C_UNK D_002C0A90;
extern M2C_UNK D_002C0AA0;
extern M2C_UNK func_001BA100;
void func_001BA128(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s32 sp40;
    s32 sp44;
    f32 temp_v0;
    f32 var_f21;
    s32 temp_v1;
    s32 var_s1;
    s32 var_s3;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *var_s0;
    UpdateGuard();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1018);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (FIsGuardInSgs(arg0, 0x25) != 0) {
            if (FIsGuardInSgs(arg0, 9) != 0) {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x1010);
                goto block_8;
            }
            if (FIsGuardInSgs(arg0, 2) != 0) {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x1014);
block_8:
                M2C_FIELD(arg0, s8 **, 0x1028) = NULL;
                var_s0 = B_003E1444;
                var_f21 = 3.4028235e38f;
                if (var_s0 != NULL) {
                    do {
                        if ((var_s0 != arg0) && (FIsGuardInSgs(var_s0, 7) == 0)) {
                            asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(arg0)));
                            asm volatile("sqc2 vf1, 0x60(%0)" : : "r"(sp));
                            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(var_s0)));
                            asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
                            asm volatile("vsub.xyzw vf1, vf1, vf2");
                            asm volatile("vmul.xyz vf1, vf1, vf1");
                            asm volatile("vaddw.x vf2, vf0, vf0w");
                            asm volatile("vadday.x ACC, vf1, vf1y");
                            asm volatile("vmaddz.x vf1, vf2, vf1z");
                            s32 vu_1;
                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                            temp_v0 = vu_1;
                            s64 vu_2;
                            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(PosLoWorld(var_s0)));
                            if (!(var_f21 < temp_v0) && (func_00227C90(var_s3, vu_2) != 0)) {
                                M2C_FIELD(arg0, s8 **, 0x1028) = var_s0;
                                var_f21 = temp_v0;
                            }
                        }
                        var_s0 = M2C_FIELD(var_s0, s8 **, 0xFE0);
                    } while (var_s0 != NULL);
                }
                if (M2C_FIELD(arg0, s8 **, 0x1028) == NULL) {
                    if (FIsGuardInSgs(arg0, 2) == 0) {
                        var_s1 = 0;
                        asm volatile("lqc2 vf3, (%0)" : : "r"(&D_002C0A90));
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertAloPos(arg0, 0, D_002C0A80)));
                        asm volatile("lqc2 vf1, (%0)" : : "r"(&D_002C0AA0));
                        asm volatile("vadd.xyzw vf4, vf2, vf3");
                        asm volatile("vadd.xyzw vf2, vf2, vf1");
                        asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf4, 0x50(%0)" : : "r"(sp));
                        CStackFrame_Construct(sp);
                        asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
                        s32 vu_3;
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                        bevy_camera_follow_push_out(&B_003DD490, sp50, vu_3, &func_001BA100, 0, &sp40, &sp44);
loop_19:
                        if (var_s1 < sp40) {
                            temp_s0 = (s8 *)(*(s32 *)((var_s1 * 4) + sp44));
                            var_s1 += 1;
                            s64 vu_4;
                            asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(PosLoWorld(M2C_FIELD(temp_s0, s8 **, 4))));
                            if (func_00227C90(var_s3, vu_4) != 0) {
                                M2C_FIELD(arg0, s8 **, 0x1028) = (s8 *) M2C_FIELD(temp_s0, s8 **, 4);
                            } else {
                                goto loop_19;
                            }
                        }
                        CStackFrame_Destructor(sp, 2);
                    }
                    if (M2C_FIELD(arg0, s8 **, 0x1028) != NULL) {
                        goto block_25;
                    }
                } else {
block_25:
                    func_001BA408(arg0, 1);
                }
            }
        }
        return;
    case 1:
        if (FAsegaGone(M2C_FIELD(arg0, s32 *, 0x1024)) == 0) {
            temp_s0_2 = M2C_FIELD(arg0, s8 **, 0x1034);
            s64 vu_5;
            asm volatile("por %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x1028))));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertXfPos(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), vu_5)));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0x1034)));
            asm volatile("vsub.xyzw vf2, vf2, vf1");
            s32 vu_6;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_6));
            BuildRotateVectorsMatrix(&sp10, M2C_FIELD(arg0, s128 *, 0x1040), vu_6);
            temp_s0_3 = M2C_FIELD(arg0, s8 **, 0x102C);
            M2C_FIELD(temp_s0_3, s128 *, 0x20) = DecomposeRotateMatrixEuler(&sp10);
        } else {
            func_001BA408(arg0, 0);
        }
        break;
    }
}
}
