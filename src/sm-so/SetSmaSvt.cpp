/* SPDX-License-Identifier: GPL-3.0-or-later */
struct SMAVT_1F0850 { char pad0[8]; short deltaA; short indexA; void (*fnA)(void *); short deltaB; short indexB; void (*fnB)(void *); };
struct SMA_1F0850 { char pad0[0xC]; SMAVT_1F0850 *vt; char pad10[0x30 - 0x10]; int pasega; char pad34[0x44 - 0x34]; float svt; };
struct HOLD_1F0850 {
    SMA_1F0850 *p;
    HOLD_1F0850(SMA_1F0850 *s) { p = s; p->vt->fnA((char *)p + p->vt->deltaA); }
    ~HOLD_1F0850() { p->vt->fnB((char *)p + p->vt->deltaB); }
};
extern "C" int FSmaRetracted(SMA_1F0850 *);
extern "C" void SetAsegaSpeed(int, float);
extern "C" void SetSmaSvt(SMA_1F0850 *sma, float svt)
{
    if (FSmaRetracted(sma)) return;
    HOLD_1F0850 hold(sma);
    sma->svt = svt;
    if (sma->pasega != 0)
        SetAsegaSpeed(sma->pasega, svt);
}
