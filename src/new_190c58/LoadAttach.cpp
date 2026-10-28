struct ATTACH { int pjt; char pad4[0x68 - 4]; int ptn; char pad6C[0x440 - 0x6C]; };
extern "C" int PloNew(int, int, int, int);
extern "C" void SetTnTnsOverride(int, int);
extern "C" void ResetJtDynamicTunnel__FP2JT(ATTACH *);
extern "C" void BuildPlainBlend(int, void *, void *);
extern "C" void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(void *);
extern "C" void EnsureAsegBlendDynamic(int, int, int, void *, int, int, int, void *);
extern "C" void func_001CC5E8(void *, int, int);

void LoadAttach(ATTACH *attach)
{
    int tn = PloNew(0xF, 0, 0x148, -1);
    attach->ptn = tn;
    SetTnTnsOverride(tn, 0);
    ResetJtDynamicTunnel__FP2JT(attach);
    BuildPlainBlend(attach->pjt, (char *)attach + 0x70, (char *)attach + 0x170);
    BuildPlainBlend(attach->pjt, (char *)attach + 0x330, (char *)attach + 0x430);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL((char *)attach + 0x180);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL((char *)attach + 0x240);
    EnsureAsegBlendDynamic(attach->pjt, 0xC, 3, (char *)attach + 0x2F0, 0, 0, 0, (char *)attach + 0x314);
    int jt = attach->pjt;
    func_001CC5E8((char *)attach + 0x440, jt, jt + 0x1030);
}
