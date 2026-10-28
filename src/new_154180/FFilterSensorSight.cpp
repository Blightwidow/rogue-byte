struct OXA { char pad[0x70]; unsigned long grf; };
struct SO { char pad0[0x10]; SO *pparent; int root; char pad1[0xD4]; OXA *poxa; };
struct SOGEOM { char pad0[4]; SO *psoOwner; char pad1[8]; unsigned long grf; };
struct SENSOR { char pad[0x14]; int root; };
extern "C" int FIsBasicDerivedFrom(void *, int);
int FFilterSensorSight(SENSOR *sensor, SOGEOM *geom)
{
    if ((geom->grf & (1UL << 48)) != 0)
        return 0;
    SO *pso = geom->psoOwner;
    if ((pso->poxa->grf & 4) != 0)
        return 0;
    if (pso->root == sensor->root)
        return 0;
    SO *pobject = pso;
    while (pobject != 0 && !FIsBasicDerivedFrom(pobject, 0x33))
        pobject = pobject->pparent;
    return pobject == 0;
}
