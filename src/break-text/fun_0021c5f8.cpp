#include "sly2.h"
struct GLOB { char pad[0x14]; };
struct CENTER { float x, y, z; float pad[3]; };
struct NODE { GLOB *glob; int pad; int pad2; NODE *next; };
struct SO { char pad[0xBC]; GLOB *globs; char pad2[4]; CENTER *centers; char pad3[0xDC - 0xC4 - 4]; NODE *first; };
extern "C" float func_00259D98(VECTOR *);
extern "C" float Vec4_GetY(VECTOR *);
extern "C" float Vec4_GetZ(VECTOR *);

void func_0021C5F8(SO *so, QW center)
{
    VECTOR v;
    for (NODE *node = so->first; node != 0; node = node->next) {
        int index = node->glob - so->globs;
        CENTER *entry = (CENTER *)(index * sizeof(CENTER) + (unsigned)so->centers);
        *(QW *)&v = center;
        float x = func_00259D98(&v);
        float y = Vec4_GetY(&v);
        float z = Vec4_GetZ(&v);
        entry->x = x;
        entry->y = y;
        entry->z = z;
    }
}
