struct VT { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct Hitfx { char pad[0xC]; VT *vptr; };
struct Sensor { char pad[0xE0]; int chitfx; Hitfx *aphitfx[1]; };
extern "C" {
void *memmove(void *, const void *, unsigned int);
int FHitFxGone(Hitfx *);
void SweepHitFxSensor(Sensor *psensor, int fRemoveAll)
{
    int ihitfx = 0;
    while (ihitfx < psensor->chitfx) {
        Hitfx **pslot = &psensor->aphitfx[ihitfx];
        Hitfx *phitfx = *pslot;
        if (fRemoveAll != 0 || FHitFxGone(phitfx) != 0) {
            VT *vtable = phitfx->vptr;
            vtable->fn((char *)phitfx + vtable->delta);
            memmove(pslot, pslot + 1, (psensor->chitfx - ihitfx) * 4 - 4);
            psensor->chitfx -= 1;
        } else {
            ihitfx++;
        }
    }
}
}
