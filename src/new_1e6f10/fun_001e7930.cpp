extern "C" void *PattachCrv(void *, int);
extern "C" void SetRopeSimEnd(void *, int, void *);
extern "C" void func_001E7930(void *curve, void *value)
{
    SetRopeSimEnd(PattachCrv(curve, 1), 0, value);
}
