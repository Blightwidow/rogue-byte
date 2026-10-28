#include "sly2.h"
extern "C" int CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" int func_00117F90(void *stream, void *dest)
{
    return CBinaryInputStream_Read_thunk(stream, 12, dest);
}
