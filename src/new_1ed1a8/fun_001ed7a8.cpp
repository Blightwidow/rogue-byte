#include "sly2.h"
struct CBinaryInputStream;
struct NODE;
struct VT { char pad[0x38]; short delta; short index; void (*fn)(void *, void *); };
struct NODE { char pad[0xC]; VT *vt; char pad2[0x20]; NODE *owner; };
struct CLS { int a, b, c, d; NODE *(*create)(); };
extern CLS D_002BAAE8[];
unsigned short U16Read__18CBinaryInputStream(CBinaryInputStream *);
extern "C" void CBinaryInputStream_Read_thunk(CBinaryInputStream *, int, void *);
NODE *func_001ED7A8(NODE *owner, CBinaryInputStream *stream)
{
    int index = (int)U16Read__18CBinaryInputStream(stream);
    if (index == -1) return 0;
    NODE *node = D_002BAAE8[index].create();
    node->owner = owner;
    char block[0x20];
    CBinaryInputStream_Read_thunk(stream, 0x20, block);
    VT *vt = node->vt;
    vt->fn((char *)node + vt->delta, block);
    return node;
}
