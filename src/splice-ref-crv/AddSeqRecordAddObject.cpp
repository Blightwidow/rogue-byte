#include "sly2.h"
extern "C" void* PjsgeAllocJsg(void*, int, int);
void AddJsgKind2C(void* pjsg, int nFirst, int fAsync, float gFirst)
{
    void* pjsge = PjsgeAllocJsg(pjsg, 0x2C, fAsync);
    *(int*)((char*)pjsge + 0x10) = nFirst;
    *(float*)((char*)pjsge + 0x14) = gFirst;
}