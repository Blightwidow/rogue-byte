extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void FadeAloIn(void *, float);
extern "C" void FadeAloOut(void *, float);
struct VT { char pad[0x40]; short d40; short i40; void (*f40)(void *); short d48; short i48; void (*f48)(void *); };
struct LO { char pad[0xC]; VT *vt; };
LO *ShowHideLo(void *sw, int show, int oid, void *ctx, float dt)
{
    LO *lo = (LO *)PloFindSwObject_thunk(sw, 4, oid, ctx);
    if (lo) {
        if (dt != 0.0f && FIsBasicDerivedFrom(lo, 0x30)) {
            if (show) FadeAloIn(lo, dt);
            else FadeAloOut(lo, dt);
        } else {
            if (show) lo->vt->f40((char *)lo + lo->vt->d40);
            else lo->vt->f48((char *)lo + lo->vt->d48);
        }
    }
    return lo;
}
