#include "sly2.h"
extern "C" int CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" int CBinaryInputStream_ReadVector4(void *stream, void *dest)
{
    return CBinaryInputStream_Read_thunk(stream, 16, dest);
}
