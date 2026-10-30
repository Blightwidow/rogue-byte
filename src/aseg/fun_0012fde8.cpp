struct ALLOCREQ { int cb; int cbAlign; };
struct NODE { float x; float y; int value; };
struct OWNER { char pad[0xB0]; NODE *node; };
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" void func_0012FDE8(OWNER *self, int value, float x, float y)
{
    ALLOCREQ req;
    req.cb = 0xC;
    req.cbAlign = 0x10;
    NODE *node = (NODE *)PvAllocSwImpl__Fi(&req);
    self->node = node;
    node->x = x;
    node->y = y;
    node->value = value;
}
