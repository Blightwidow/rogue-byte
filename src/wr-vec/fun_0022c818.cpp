#include "sly2.h"
struct XF { char pad[0x80]; float tMin, tMax; float *pcur; float *pend; };
extern "C" void func_0022C818(void *palo, XF *pxf)
{
    pxf->tMin = 0.0f; pxf->tMax = 1.0f; pxf->pcur = &pxf->tMin; pxf->pend = &pxf->tMax;
}
