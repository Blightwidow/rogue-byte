#include "sly2.h"

extern "C" void* PjsgeAllocJsg(void* pjsg, int kind, int fAsync);

void AddSeqRecordRemoveObject(void* pjsg, int nFirst, int fAsync, float gFirst)
{
    void* pjsge = PjsgeAllocJsg(pjsg, 0x2D, fAsync);
    int* p = (int*)pjsge;
    *(int*)((char*)p + 0x10) = nFirst;
    *(float*)((char*)p + 0x14) = gFirst;
}