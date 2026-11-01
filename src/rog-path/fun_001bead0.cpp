struct CHILD;
struct VT_1BEAD0 { char pad0[0x48]; short delta; short index; void (*fn)(void *); };
struct CHILD { char pad0[0xC]; VT_1BEAD0 *vt; char pad10[0x15C - 0x10]; int flagA; int flagB; };
struct PARENT { char pad0[0x104]; int count; CHILD *items[1]; };
extern "C" {
void func_001BEAD0(PARENT *parent, CHILD *child) {
    if (child) {
        int count = parent->count;
        parent->items[count] = child;
        parent->count = count + 1;
        child->flagB = 1;
        child->flagA = 1;
        child->vt->fn((char *)child + child->vt->delta);
    }
}
}
