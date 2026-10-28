#include "sly2.h"
extern "C" int CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" void func_002566B0(void *pvec, void *pelem, void *pbis)
{
    CBinaryInputStream_Read_thunk(pbis, 4, pelem);
}
