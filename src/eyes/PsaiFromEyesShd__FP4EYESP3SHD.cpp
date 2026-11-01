struct EYES { char pad[0x60]; int oid; };
struct SHD { int oid; };
extern "C" int FMatchesSaaOid(EYES *, SHD *);
int PsaiFromEyesShd__FP4EYESP3SHD(EYES *eyes, SHD *shd)
{
    int result = 0;
    if (FMatchesSaaOid(eyes, shd) != 0 || shd->oid == eyes->oid)
        result = 1;
    return result;
}
