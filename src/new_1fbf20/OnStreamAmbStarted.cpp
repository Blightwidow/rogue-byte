struct Amb;
struct VT { char pad[0x10]; short delta0; short idx0; void (*fn0)(void *); char pad2[0x38 - 0x18]; short delta1; short idx1; void (*fn1)(void *); };
struct Amb { char pad[0xC]; VT *vt; char pad2[0x40 - 0x10]; int started; char pad3[0x50 - 0x44]; unsigned short flags; short counter; };
extern "C" void SetAmbGrf(Amb *, int, int);
extern "C" void ContinueAmb(Amb *);
extern "C" void OnStreamAmbStarted(int started, long handle)
{
    Amb *amb = (Amb *)(int)handle;
    amb->started = started;
    if (started) {
        SetAmbGrf(amb, 0x1000, 0x1000);
    } else {
        ContinueAmb(amb);
        amb->counter = 0;
        if (!(amb->flags & 8))
            amb->vt->fn1((char *)amb + amb->vt->delta1);
    }
    amb->vt->fn0((char *)amb + amb->vt->delta0);
}
