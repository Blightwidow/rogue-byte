typedef signed char s8;
typedef int s32;
typedef float f32;
typedef long s64;
typedef int QW __attribute__((mode(TI)));
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
extern s8 B_003DD490[];
extern s32 func_001FCF70;
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
int ReplaceHitFx(void *, QW, void *, void *);
void func_002330D0(s32, s32, s32, s32, s32, s32, s32, void *, s64);
}
extern "C" void func_001FDA48(s8 *arg0)
{
    if (M2C_FIELD(arg0, s32 *, 0x10) == 0) {
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
    } else if (M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x6C) = 1;
        func_002330D0(0x524B5553, 0xB, 0, 0, 0, 0, 0, &func_001FCF70, (s64) arg0);
    }
    void *pNew = 0;
    QW pos;
    void *pFocus = PpoSwFocusBase(B_003DD490);
    if (pFocus != 0) {
        if (FIsBasicDerivedFrom(pFocus, 0x34) != 0) {
            if (0.5f < M2C_FIELD(arg0, f32 *, 0x70)) {
                pNew = *(void **)(B_003DD490 + 0x4034);
                pos = PosLoWorld(pFocus);
                f32 t = M2C_FIELD(arg0, f32 *, 0x70);
                f32 *pVecA = (f32 *)(arg0 + 0x80);
                f32 *pVecB = (f32 *)(arg0 + 0x90);
                M2C_FIELD(pNew, f32 *, 0x54) = pVecA[0] + t * (pVecA[1] + t * pVecA[2]);
                f32 z = pVecB[0] + M2C_FIELD(arg0, f32 *, 0x70) * (pVecB[1] + M2C_FIELD(arg0, f32 *, 0x70) * pVecB[2]);
                M2C_FIELD(pNew, f32 *, 0x5C) = z;
                M2C_FIELD(pNew, f32 *, 0x58) = -z;
            }
        }
    }
    ReplaceHitFx(pNew, pos, pFocus, arg0 + 0x74);
}
