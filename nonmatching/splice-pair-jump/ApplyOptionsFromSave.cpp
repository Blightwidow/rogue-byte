struct CRefA { int tag; union { float g; int n; }; int p2; int p3; };
struct SW { char pad0[0x3B2C]; int path[8]; };
extern "C" {
void CRef_Destruct(CRefA *);
void RefGetGameSaveValue(CRefA *, int, void *);
void SetSndPlaybackMode(void *, int);
void SetSndbankVolumeFactor(void *, int, int, float);
void func_001A2BD0(int);
int func_001A2C98(void);
int func_0023E1C8(float);
extern SW B_003DD490;
extern char B_003DD040[];
extern int B_003DD050;
extern long B_002DEB80[];
static inline int GetSaveInt(int path, void *save)
{
    CRefA ref;
    RefGetGameSaveValue(&ref, path, save);
    int n = ref.n;
    CRef_Destruct(&ref);
    return n;
}
static inline float GetSaveFloat(int path, void *save)
{
    CRefA ref;
    RefGetGameSaveValue(&ref, path, save);
    float g = ref.g;
    CRef_Destruct(&ref);
    return g;
}
void ApplyOptionsFromSave(void *save)
{
    if (B_003DD490.path[0] != 0) {
        if (func_001A2C98() >= 2)
            func_001A2BD0(GetSaveInt(B_003DD490.path[0], save));
    }
    if (B_003DD490.path[1] != 0)
        SetSndPlaybackMode(B_003DD040, GetSaveInt(B_003DD490.path[1], save));
    if (B_003DD490.path[2] != 0)
        SetSndbankVolumeFactor(B_003DD040, 1, 1, 1.0f - GetSaveFloat(B_003DD490.path[2], save));
    if (B_003DD490.path[3] != 0) {
        SetSndbankVolumeFactor(B_003DD040, 0, 1, 1.0f - GetSaveFloat(B_003DD490.path[3], save));
        SetSndbankVolumeFactor(B_003DD040, 3, 1, 1.0f - GetSaveFloat(B_003DD490.path[3], save));
    }
    if (B_003DD490.path[4] != 0)
        B_003DD050 = GetSaveInt(B_003DD490.path[4], save);
    if (B_003DD490.path[5] != 0) {
        float g = GetSaveFloat(B_003DD490.path[5], save);
        long *regs = B_002DEB80;
        int field = func_0023E1C8(g + 636.0f) & 0xFFF;
        regs[8] = (regs[8] & ~0xFFFL) | field;
        regs[3] = (regs[3] & ~0xFFFL) | field;
    }
    if (B_003DD490.path[6] != 0) {
        float g = GetSaveFloat(B_003DD490.path[6], save);
        long *regs = B_002DEB80;
        long field = func_0023E1C8(g + 50.0f) & 0x7FE;
        regs[8] = (regs[8] & ~0x7FF000) | (field << 12);
        regs[3] = (regs[3] & ~0x7FF000) | (field << 12);
    }
}
}
