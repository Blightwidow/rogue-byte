struct SMAVT { char pad0[8]; short deltaA; short indexA; void (*fnA)(void *); short deltaB; short indexB; void (*fnB)(void *); };
struct SMA { char pad0[0xC]; SMAVT *vt; char pad10[0x30 - 0x10]; int pasega; char pad34[0x44 - 0x34]; float svt; };
extern "C" int FSmaRetracted(SMA *, float);
extern "C" void SetAsegaSpeed(int, float);
extern "C" void SetSmaSvt(SMA *sma, float svt)
{
    if (FSmaRetracted(sma, svt) == 0) {
        char dead[0x10] __attribute__((aligned(16))); (void)dead;
        sma->vt->fnA((char *)sma + sma->vt->deltaA);
        sma->svt = svt;
        if (sma->pasega != 0)
            SetAsegaSpeed(sma->pasega, svt);
        sma->vt->fnB((char *)sma + sma->vt->deltaB);
    }
}
