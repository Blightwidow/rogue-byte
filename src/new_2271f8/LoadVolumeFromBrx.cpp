#include "sly2.h"
extern "C" const float RO_002A9880;
struct Geom { int cvert; void *pvert; };
struct Volume {
    char pad0[0xE0];
    char bspc[0x10];
    Geom geom;
    char pad100[0x10];
    QW center;
    float radiusSq;
};
struct Stream;
extern "C" {
void LoadXfmFromBrx(Volume *, Stream *);
void CBinaryInputStream_ReadGeom(Stream *, Geom *);
void CBinaryInputStream_ReadBspc(Stream *, Geom *, void *);
QW VecMinOfVerts(int, void *);
QW VecMaxOfVerts(int, void *);
}

void LoadVolumeFromBrx(Volume *pvolume, Stream *pstream)
{
    Geom *pgeom = &pvolume->geom;
    LoadXfmFromBrx(pvolume, pstream);
    CBinaryInputStream_ReadGeom(pstream, pgeom);
    CBinaryInputStream_ReadBspc(pstream, pgeom, pvolume->bspc);
    if (pvolume->geom.cvert > 0) {
        struct { QW half; QW min; } junk;
        QW vecMin = VecMinOfVerts(pvolume->geom.cvert, pvolume->geom.pvert);
        asm("qmtc2.ni %0, vf2" : : "r" (vecMin));
        register int cvert asm("$4") = pvolume->geom.cvert;
        register void *pvert asm("$5") = pvolume->geom.pvert;
        asm("sqc2 vf2, %0" : "=m" (junk.min) : "r" (cvert), "r" (pvert));
        QW vecMax = VecMaxOfVerts(cvert, pvert);
        register int half asm("$3"); float halfF = 0.5f;
        asm("qmtc2.ni %4, vf4\n\tlqc2 vf2, %6\n\tmfc1 %2, %7\n\tqmtc2.ni %2, vf1\n\tvmulax.xyzw ACC, vf2, vf1x\n\tvmaddx.xyzw vf3, vf4, vf1x\n\tsqc2 vf1, %0\n\tvsub.xyzw vf2, vf3, vf2\n\tsqc2 vf3, %1\n\tvmul.xyz vf2, vf2, vf2\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z\n\tqmfc2.ni %4, vf2\n\tsw %4, %3"
            : "=m" (junk.half), "=m" (pvolume->center), "=&r" (half), "=m" (pvolume->radiusSq), "=r" (vecMax)
            : "4" (vecMax), "m" (junk.min), "f" (halfF));
    } else {
        pvolume->radiusSq = RO_002A9880;
    }
}
