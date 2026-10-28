struct VT { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0xC]; VT *vt; };
extern "C" void RunStreamCue(void *, void *);
extern "C" void SetSmaGoal__FP3SMA3OID(void *, int);
extern "C" void StopAmb(void *, float);
extern "C" void func_00259B48(void *, void *);
extern "C" void *memset(void *, int, unsigned);

#define F(type, base, off) (*(type *)((char *)(base) + (off)))

void StopStream(void *stream)
{
    if (F(int, stream, 0x200) == 0)
        return;
    void *pamb = (char *)stream + 0x200;
    Obj **slots = (Obj **)((char *)stream + 0x22C);
    void *rec = F(void *, F(void *, stream, 0x200), 0x60);
    int cue = F(int, stream, 0x244);
    while (cue < F(int, rec, 0x54)) {
        RunStreamCue(stream, (char *)F(void *, rec, 0x58) + cue * 8);
        cue = ++F(int, stream, 0x244);
    }
    if (F(void *, stream, 0x240))
        SetSmaGoal__FP3SMA3OID(F(void *, stream, 0x240), 0x611);
    if (pamb && F(void *, stream, 0x200)) {
        StopAmb(F(void *, stream, 0x200), 0.0f);
        func_00259B48(pamb, 0);
    }
    F(int, stream, 0x244) = 0;
    F(int, stream, 0x248) = 0;
    F(int, stream, 0x24C) = 0;
    for (int slot = 0; slot < 6; slot++) {
        Obj *obj = slots[slot];
        if (obj) {
            VT *vt = obj->vt;
            vt->fn((char *)obj + vt->delta);
        }
    }
    memset(slots, 0, 0x18);
}
