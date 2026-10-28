extern "C" void *PattachCrv(void *, int);
extern "C" void SetRopeSimLength(void *, float);
extern "C" void SetCrvRopeLength(void *curve, float length)
{
    SetRopeSimLength(PattachCrv(curve, 1), length);
}
