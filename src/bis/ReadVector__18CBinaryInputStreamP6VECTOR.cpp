#include "sly2.h"
extern "C" int CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" int ReadVector__18CBinaryInputStreamP6VECTOR(void *stream, void *dest)
{
    return CBinaryInputStream_Read_thunk(stream, 12, dest);
}
