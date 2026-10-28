#include "sly2.h"
struct CBinaryInputStream {
    char pad[0x24];
    int U16Read();
};
struct AVT { char pad[8]; short delta; short index; char *(*fn)(void *, int, int); };
struct ALLOC { AVT *vptr; };
extern "C" void CBinaryInputStream_Read_thunk(CBinaryInputStream *, int, char *);

void func_00118380(CBinaryInputStream *stream, char **out, ALLOC *alloc, int arg)
{
    int length = stream->U16Read();
    if (length == 0) {
        *out = 0;
    } else {
        AVT *vtable = alloc->vptr;
        char *buffer = vtable->fn((char *)alloc + vtable->delta, length + 1, arg);
        CBinaryInputStream_Read_thunk(stream, length, buffer);
        buffer[length] = 0;
        *out = buffer;
    }
}
