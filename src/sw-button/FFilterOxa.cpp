extern "C" int IMax(int, int);
struct VT { char pad[0x1E8]; short d; short i; int (*fn)(void *, void *); };
struct SOB { char pad[0xC]; VT *vt; };
struct OXA { char pad[0x60]; SOB *so; char pad2[0x70 - 0x64]; unsigned long flags; };
struct OWNER { char pad[0xEC]; OXA *oxa; };
struct GEOM { char pad[4]; OWNER *owner; char pad2[8]; unsigned long grf; };
int FFilterOxa(OXA *ignore, GEOM *geom)
{
    OXA *oxa = geom->owner->oxa;
    if (geom->grf & 0x1000000000000UL) return 0;
    if (oxa->flags & 4) return 0;
    if (oxa == ignore) return 0;
    {
        int x = ignore->so->vt->fn((char *)ignore->so + ignore->so->vt->d, oxa->so);
        int y = oxa->so->vt->fn((char *)oxa->so + oxa->so->vt->d, ignore->so);
        int k = IMax(x, y);
        return k != 1 && k != 3;
    }
}
