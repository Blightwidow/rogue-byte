typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadAloFromBrx {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[0xB4];
};                                                  /* size = 0xD0 */
M2C_UNK CBinaryInputStream_ReadMatrix4(s32, s8 *); /* extern */
f32 F32Read__18CBinaryInputStream(s32);             /* extern */
s128 GetXfDofValue(s8 *, s8 *);                 /* extern */
M2C_UNK InsertXfAct(s8 *, s8 *, s8 *);        /* extern */
M2C_UNK LoadAloIkLimbs(s8 *, s32);                /* extern */
M2C_UNK LoadXfMirrors(s8 *, s32);                 /* extern */
s8 *PvAllocAct(M2C_UNK);                          /* extern */
s32 PvAllocSwClearImpl__Fi(s8 *, s32, s32);       /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, s8 *, M2C_UNK); /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 S32Read__18CBinaryInputStream(s32);             /* extern */
s32 S8Read__18CBinaryInputStream(...); /* extern */
s32 U8Read__18CBinaryInputStream(s32);              /* extern */
M2C_UNK UpdateAloXfWorld(s8 *);                   /* extern */
M2C_UNK func_00117F90(s32, s8 *);                 /* extern */
M2C_UNK func_00117FB0(s32, s8 *);                 /* extern */
M2C_UNK func_0021C888(s8 *, s32);                 /* extern */
M2C_UNK func_0022C818(s8 *, s8 *);              /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK D_002CA6A0;
extern M2C_UNK D_002CA7A0;
extern M2C_UNK D_002CA7E0;
extern M2C_UNK D_002CA820;
void LoadAloFromBrx(s8 *arg0, s32 arg1) {
    s32 saved_reg_s3;
    s32 saved_reg_s5;
    s32 saved_reg_s6;
    s32 saved_reg_s7;
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    s32 sp18;
    f32 temp_f0;
    s128 temp_v0_10;
    s32 temp_a0;
    s32 temp_s4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_fp;
    s32 var_v0;
    s8 *temp_s0;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    s8 *temp_v0_9;
    s8 *temp_v1;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    s8 *temp_v1_7;
    s8 *var_s3;
    s8 *var_s5;
    s8 *var_s6;
    s8 *var_s7;
    var_s3 = (s8 *)(saved_reg_s3);
    var_s5 = (s8 *)(saved_reg_s5);
    var_s6 = (s8 *)(saved_reg_s6);
    var_s7 = (s8 *)(saved_reg_s7);
    var_fp = 0;
    temp_v0 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x50) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x54) = PvAllocSwClearImpl__Fi(sp, temp_v0 << 8, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
        do {
            temp_s0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x54) + (var_fp << 8));
            temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_s0, s8 **, 0xA0) = M2C_FIELD(temp_v1, s8 *(**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x198), S16Read__18CBinaryInputStream(arg1));
            M2C_FIELD(temp_s0, s32 *, 0x94) = S16Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0, s32 *, 0x9C) = S32Read__18CBinaryInputStream(arg1);
            temp_v0_2 = U8Read__18CBinaryInputStream(arg1);
            if (temp_v0_2 & 1) {
                temp_f0 = F32Read__18CBinaryInputStream(arg1);
                M2C_FIELD(temp_s0, s16 *, 0xAE) = 0x3E8;
                var_v0 = (s32) (temp_f0 * 1000.0f);
                goto block_6;
            }
            var_v0 = 0x3E8;
            if (temp_v0_2 & 2) {
                M2C_FIELD(temp_s0, s16 *, 0xAC) = (s16) (s32) (F32Read__18CBinaryInputStream(arg1) * 1000.0f);
                M2C_FIELD(temp_s0, s16 *, 0xAE) = (s16) (s32) (F32Read__18CBinaryInputStream(arg1) * 1000.0f);
            } else {
                M2C_FIELD(temp_s0, s16 *, 0xAE) = 0x3E8;
block_6:
                M2C_FIELD(temp_s0, s16 *, 0xAC) = (s16) var_v0;
            }
            temp_v0_3 = temp_v0_2 & 4;
            sp10 = temp_v0_3;
            if (temp_v0_3 != 0) {
                temp_v0_4 = PvAllocAct(0x30);
                var_s6 = temp_v0_4;
                M2C_FIELD(temp_v0_4, M2C_UNK **, 0x18) = &D_002CA820;
                M2C_FIELD(temp_v0_4, s32 *, 0) = 1;
                M2C_FIELD(temp_v0_4, s32 *, 0x1C) = 2;
                M2C_FIELD(var_s6, s32 *, 0x14) = S8Read__18CBinaryInputStream(arg1, 1, 2);
            }
            temp_v1_2 = temp_v0_2 & 8;
            sp14 = temp_v1_2;
            if (temp_v1_2 != 0) {
                temp_v0_5 = PvAllocAct(0x80);
                M2C_FIELD(temp_v0_5, s32 *, 0) = 2;
                var_s3 = temp_v0_5;
                M2C_FIELD(temp_v0_5, M2C_UNK **, 0x18) = &D_002CA7E0;
                M2C_FIELD(var_s3, s32 *, 0x14) = S8Read__18CBinaryInputStream(arg1);
                M2C_FIELD(var_s3, f32 *, 0x60) = F32Read__18CBinaryInputStream(arg1);
                func_00117F90(arg1, var_s3 + 0x30);
                func_00117FB0(arg1, var_s3 + 0x50);
                func_00117F90(arg1, var_s3 + 0x40);
                func_00117FB0(arg1, var_s3 + 0x58);
                M2C_FIELD(var_s3, s32 *, 0x64) = S8Read__18CBinaryInputStream(arg1);
                M2C_FIELD(var_s3, s32 *, 0x68) = S8Read__18CBinaryInputStream(arg1);
                M2C_FIELD(var_s3, s32 *, 0x6C) = S32Read__18CBinaryInputStream(arg1);
            }
            temp_v0_6 = temp_v0_2 & 0x10;
            sp18 = temp_v0_6;
            if (temp_v0_6 != 0) {
                temp_v0_7 = PvAllocAct(0x28);
                M2C_FIELD(temp_v0_7, s32 *, 0) = 4;
                var_s5 = temp_v0_7;
                M2C_FIELD(temp_v0_7, M2C_UNK **, 0x18) = &D_002CA7A0;
                M2C_FIELD(var_s5, s32 *, 0x14) = S8Read__18CBinaryInputStream(arg1);
                M2C_FIELD(var_s5, f32 *, 0x1C) = F32Read__18CBinaryInputStream(arg1);
                M2C_FIELD(var_s5, f32 *, 0x20) = F32Read__18CBinaryInputStream(arg1);
            }
            temp_s4 = temp_v0_2 & 0x20;
            if (temp_s4 != 0) {
                temp_v0_8 = PvAllocAct(0x30);
                var_s7 = temp_v0_8;
                M2C_FIELD(temp_v0_8, s32 *, 0) = 9;
                M2C_FIELD(temp_v0_8, M2C_UNK **, 0x18) = &D_002CA6A0;
                M2C_FIELD(temp_v0_8, s32 *, 0x14) = 0x14;
                ReadVector__18CBinaryInputStreamP6VECTOR(arg1, var_s7 + 0x20, 0x14);
            }
            temp_v1_3 = M2C_FIELD(temp_s0, s32 *, 0x94);
            switch (temp_v1_3) {
            case 0:
            case 13:
            case 15:
                CBinaryInputStream_ReadMatrix4(arg1, temp_s0);
                break;
            case 8:
            case 14:
                memset(temp_s0, 0, 0x40);
                M2C_FIELD(temp_s0, f32 *, 0) = 1.0f;
                M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
                M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
                M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
                temp_v1_4 = M2C_FIELD(arg0, s8 **, 0xC);
                temp_v0_9 = M2C_FIELD(temp_v1_4, s8 *(**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x198), S16Read__18CBinaryInputStream(arg1));
                M2C_FIELD(temp_s0, s8 **, 0xA8) = temp_v0_9;
                M2C_FIELD(temp_s0, f32 *, 0x30) = (f32) -M2C_FIELD(temp_v0_9, f32 *, 0x30);
                M2C_FIELD(temp_s0, f32 *, 0x34) = (f32) -M2C_FIELD(temp_v0_9, f32 *, 0x34);
                M2C_FIELD(temp_s0, f32 *, 0x38) = (f32) -M2C_FIELD(temp_v0_9, f32 *, 0x38);
                break;
            default:
                CBinaryInputStream_ReadMatrix4(arg1, temp_s0);
                temp_v0_10 = GetXfDofValue(temp_s0, temp_s0);
                M2C_FIELD(temp_s0, s128 *, 0xC0) = temp_v0_10;
                M2C_FIELD(temp_s0, s128 *, 0xE0) = temp_v0_10;
                break;
            }
            func_0022C818(arg0, temp_s0);
            if (sp10 != 0) {
                M2C_FIELD(var_s6, s8 **, 4) = arg0;
                M2C_FIELD(var_s6, s8 **, 8) = temp_s0;
                M2C_FIELD(var_s6, s32 *, 0xC) = -1;
                M2C_FIELD(var_s6, s128 *, 0x20) = GetXfDofValue(temp_s0, temp_s0);
                InsertXfAct(arg0, temp_s0, var_s6);
            }
            if (sp14 != 0) {
                M2C_FIELD(var_s3, s8 **, 4) = arg0;
                M2C_FIELD(var_s3, s8 **, 8) = temp_s0;
                M2C_FIELD(var_s3, s32 *, 0xC) = (s32) M2C_FIELD(var_s3, s32 *, 0x68);
                M2C_FIELD(var_s3, s128 *, 0x20) = GetXfDofValue(temp_s0, temp_s0);
                InsertXfAct(arg0, temp_s0, var_s3);
            }
            if (sp18 != 0) {
                M2C_FIELD(var_s5, s8 **, 4) = arg0;
                M2C_FIELD(var_s5, s8 **, 8) = temp_s0;
                M2C_FIELD(var_s5, s32 *, 0xC) = -1;
                InsertXfAct(arg0, temp_s0, var_s5);
            }
            if (temp_s4 != 0) {
                M2C_FIELD(var_s7, s8 **, 4) = arg0;
                M2C_FIELD(var_s7, s8 **, 8) = temp_s0;
                M2C_FIELD(var_s7, s32 *, 0xC) = -1;
                InsertXfAct(arg0, temp_s0, var_s7);
            }
            var_fp += 1;
        } while (var_fp < M2C_FIELD(arg0, s32 *, 0x50));
    }
    UpdateAloXfWorld(arg0);
    LoadAloIkLimbs(arg0, arg1);
    LoadXfMirrors(arg0, arg1);
    func_0021C888(arg0, arg1);
    temp_v1_5 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s8 **, 0x58) = M2C_FIELD(temp_v1_5, s8 *(**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x198), S16Read__18CBinaryInputStream(arg1));
    temp_v1_6 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s8 **, 0x5C) = M2C_FIELD(temp_v1_6, s8 *(**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_6, s16 *, 0x198), S16Read__18CBinaryInputStream(arg1));
    temp_v1_7 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s8 **, 0x60) = M2C_FIELD(temp_v1_7, s8 *(**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_7, s16 *, 0x198), S16Read__18CBinaryInputStream(arg1));
    if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x40);
        if ((temp_a0 ^ 1) & 1) {
            *(s32 *)temp_a0 = (s32) (*(s32 *)temp_a0 & ~0x20);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_a0 & ~0x20);
    }
}
}
