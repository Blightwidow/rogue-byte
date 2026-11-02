typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct CamFollow { char pad[0xC]; s32 activity; };
extern "C" {
struct _m2c_stack_UseSlyGadget {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
void CarryThrow_SetState(s8 *, M2C_UNK);
void ExplodeExpl(s32);
s32 FGadgetObjKept(s8 *);
s32 GrfbtnJtGadget(s8 *, s32);
s32 NewEmitter(M2C_UNK);
s32 *PloLeaseCloneObject(s32, M2C_UNK);
void SetClockRate(M2C_UNK *, M2C_UNK, f32);
void SetEmitterUnpositioned(s32, M2C_UNK);
void SetJmpBodyState(s8 *, M2C_UNK, M2C_UNK);
void SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void SetJtState(s8 *, M2C_UNK, M2C_UNK);
f32 SpendJtGadgetPower(s8 *, s32);
void StartAttach(s8 *, M2C_UNK, s32, M2C_UNK);
void VirtualRefPtr_Assign(s8 *, s32);
void bevy_camera_follow_activity(CamFollow *, s32, s8 *);
void func_00141D38(s8 *, s32);
void func_0018D698(s8 *, s8 *, s8 *);
s32 *func_0018D6F8(s8 *, s32);
extern CamFollow B_002DEB30;
extern f32 B_003E1BEC;
extern f32 D_002BF3EC;
extern f32 D_002BF3F0;
extern M2C_UNK g_2dded0;
void UseSlyGadget(s8 *arg0, s32 arg1) {
    s32 emitterId;
    f32 emitterValue;
    s32 jtArg;
    s8 *attachObject;
    s32 attachState;
    s32 attachParam;
    s8 *jmpObject;
    s32 jmpState;
    s8 *temp_s3;
    s8 *temp_v0_2;
    s32 temp_v0;
    s32 temp_a0;
    s32 var_v0;
    B_002DEB30.activity = arg1;
    bevy_camera_follow_activity(&B_002DEB30, 0x3C, arg0);
    switch (arg1) {
    case 29:
        SpendJtGadgetPower(arg0, arg1);
        SetClockRate(&g_2dded0, 1, D_002BF3EC);
        emitterId = 0x67;
        B_003E1BEC = -1.0f;
        goto emit;
    case 42:
        SpendJtGadgetPower(arg0, arg1);
        SetClockRate(&g_2dded0, 1, D_002BF3F0);
        emitterId = 0x66;
        B_003E1BEC = 0.7f;
    emit:
        temp_v0 = NewEmitter(emitterId);
        SetEmitterUnpositioned(temp_v0, 0);
        VirtualRefPtr_Assign(arg0 + 0x2044, temp_v0);
        return;
    case 33:
        SpendJtGadgetPower(arg0, arg1);
        jtArg = 9;
        goto setjt;
    case 27:
        SpendJtGadgetPower(arg0, arg1);
        SetJmpBodyState(arg0 + 0x2C0, 0x13, 0);
        return;
    case 26:
    case 37:
    case 38:
    case 41:
        temp_s3 = (s8 *)(func_0018D6F8(arg0, arg1));
        if ((u32) (M2C_FIELD(arg0, s32 *, 0x11B4) - 4) < 3U) {
            CarryThrow_SetState(arg0 + 0x11B0, 7);
            return;
        }
        attachParam = M2C_FIELD(temp_s3, s32 *, 8);
        attachObject = arg0 + 0x4C0;
        if (attachParam != 0) {
            attachState = 0xB;
            goto attach;
        }
        temp_v0_2 = (s8 *)(PloLeaseCloneObject(M2C_FIELD(temp_s3, s32 *, 4), 0));
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s32 *, 0x15C) = (s32) M2C_FIELD(temp_s3, s32 *, 0);
            if (FGadgetObjKept(temp_v0_2) != 0) {
                M2C_FIELD(temp_v0_2, s8 **, 0x16C) = arg0;
                func_0018D698(arg0, temp_s3, temp_v0_2);
            }
            M2C_FIELD(arg0, s8 **, 0x11C0) = temp_v0_2;
            GrfbtnJtGadget(arg0, arg1);
            SetJtState(arg0, 0x17, -1);
            CarryThrow_SetState(arg0 + 0x11B0, 4);
            return;
        }
        return;
    case 34:
    case 35:
        M2C_FIELD(arg0, s32 *, 0x9BC) = arg1;
        if (arg1 == 0x23) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x1FE0);
        } else {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x1FE4);
        }
        M2C_FIELD(arg0, s32 *, 0x130C) = var_v0;
        attachObject = arg0 + 0x4C0;
        attachState = 0xB;
        goto attach0;
    case 24:
        SpendJtGadgetPower(arg0, arg1);
        jtArg = 6;
    setjt:
        SetJtState(arg0, jtArg, -1);
        return;
    case 25:
        SpendJtGadgetPower(arg0, arg1);
        SetJtState(arg0, 0x18, 0xC);
        return;
    case 39:
        SpendJtGadgetPower(arg0, arg1);
        SetJtState(arg0, 5, 9);
        return;
    case 40:
        SpendJtGadgetPower(arg0, arg1);
        attachObject = arg0 + 0x4C0;
        attachState = 2;
    attach0:
        attachParam = 0;
    attach:
        StartAttach(attachObject, attachState, attachParam, 0);
        return;
    case 31:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x204C);
        if (temp_a0 != 0) {
            ExplodeExpl(temp_a0);
        }
        SpendJtGadgetPower(arg0, arg1);
        jmpObject = arg0 + 0x2C0;
        jmpState = 9;
        goto jmp;
    case 30:
        SpendJtGadgetPower(arg0, arg1);
        jmpObject = arg0 + 0x2C0;
        jmpState = 0xE;
    jmp:
        SetJmpState(jmpObject, jmpState, 0, 0);
        return;
    default:
        func_00141D38(arg0, arg1);
        break;
    }
}
}
