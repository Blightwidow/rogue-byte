// SPDX-License-Identifier: GPL-3.0-or-later
struct Handle { char pad0[0x1C]; float tStart; char pad20[0x40 - 0x20]; float tEnd; };
struct Owner { char pad0[0x18]; float angle; char pad1c[0x60 - 0x1C]; char pad60[0]; };
struct Range { char pad[0x18]; float angle; };
struct Actor { char pad0[0x60]; Owner *pdirSource; char pad64[0x150 - 0x64]; Range *prange; char pad154[0x1030 - 0x154]; Handle *phandle; };
struct Jmp {
    Actor *pactor; char pad4[4]; int index; char pad0c[0x1C - 0xC]; int mode; char pad20[0x30 - 0x20]; int started;
    char pad34[0x120 - 0x34]; void *aseg120[5]; void *aseg134[5];
};
extern "C" {
float atan2f(float, float);
float RadNormalize__Ff(float);
void RetractSmaRef(void *);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
}
extern "C" void StartJmpDirectionAseg(Jmp *pthis)
{
    pthis->started = 1;
    float angle = atan2f(((float *)pthis->pactor->pdirSource)[0x44 / 4], ((float *)pthis->pactor->pdirSource)[0x40 / 4]);
    float diff = RadNormalize__Ff(pthis->pactor->prange->angle - angle);
    float absDiff = diff < 0.0f ? -diff : diff;
    if (absDiff < 1.0995574f) {
        pthis->index = 3;
    } else if (2.0420351f < absDiff) {
        pthis->index = 4;
    } else if (0.0f < diff) {
        pthis->index = 2;
    } else {
        pthis->index = 1;
    }
    int mode = pthis->mode;
    Handle *phandle = pthis->pactor->phandle;
    void *paseg;
    if (mode == 2)
        paseg = pthis->aseg134[pthis->index];
    else
        paseg = pthis->aseg120[pthis->index];
    if (paseg == 0) {
        if (mode == 2)
            paseg = pthis->aseg134[0];
        else
            paseg = pthis->aseg120[0];
        if (paseg == 0)
            paseg = pthis->aseg120[0];
    }
    RetractSmaRef((char *)pthis->pactor + 0x1034);
    ApplyAsegToHandle(paseg, pthis->pactor, 1, (char *)pthis->pactor + 0x1030, phandle->tStart, phandle->tEnd);
}
