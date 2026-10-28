#include "sly2.h"
struct REQ { int a; int b; };
extern "C" void *PvAllocStackImpl__Fi(REQ *);
extern "C" void BuildSavePath(const char *, char *, void *);
void *PsavepathNewStack(const char *first, ...)
{
    REQ req;
    req.a = 8;
    req.b = 0x10;
    char *args = (char *)__builtin_next_arg(first) - 56;
    void *path = PvAllocStackImpl__Fi(&req);
    BuildSavePath(first, args, path);
    return path;
}
