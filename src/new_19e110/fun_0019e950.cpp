#include "sly2.h"
struct VT_19E950 { char pad[0x290]; short delta; short index; void (*fn)(void *, int, void *, QW, QW, QW); };
struct ALO_19E950 { char pad[0xC]; VT_19E950 *vt; };
struct OWNER_19E950 { ALO_19E950 *palo; char pad[0x8]; void *pcrv; float s; char pad2[0x1C]; QW posLocal; };
extern "C" void GetPathPosFromS(float, void *, QW *, QW *);
extern "C" QW ConvertAloPos(void *, void *, QW);
extern "C" void func_0019E950(OWNER_19E950 *powner)
{
    struct { QW pos; QW tangent; QW posWorld; } l;
    GetPathPosFromS(powner->s, powner->pcrv, &l.pos, &l.tangent);
    l.posWorld = ConvertAloPos(powner->palo, 0, powner->posLocal);
    ALO_19E950 *palo = powner->palo;
    palo->vt->fn((char *)palo + palo->vt->delta, 7, powner->pcrv, l.pos, l.tangent, l.posWorld);
}
