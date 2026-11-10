#include "sly2.h"
#include "alloc.h"
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void BuildSavePath(const char *, char *, void *);
void *PsavepathNewStack(const char *first, ...)
{
    ALLOCREQ req;
    req.cb = 8;
    req.cbAlign = 0x10;
    char *args = (char *)__builtin_next_arg(first) - 56;
    void *path = PvAllocStackImpl__Fi(&req);
    BuildSavePath(first, args, path);
    return path;
}
