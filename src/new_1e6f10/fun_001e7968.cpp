extern "C" void *PattachCrv(void *, int);
extern "C" void SetRopeSimEnd(void *, int, void *);
extern "C" void func_001E7968(void *curve, void *value)
{
    SetRopeSimEnd(PattachCrv(curve, 1), 1, value);
}
