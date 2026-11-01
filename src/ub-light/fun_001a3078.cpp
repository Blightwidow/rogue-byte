struct VT { char pad[0x188]; short delta; short index; void (*fn)(void *, int); };
struct Obj { char pad[0xC]; VT *vptr; };
extern "C" void func_00227788(void *);
extern char B_004435F0[];
extern "C" void func_001A3078(Obj **slot)
{
    if (*slot) {
        func_00227788(B_004435F0);
        Obj *obj = *slot;
        VT *vt = obj->vptr;
        vt->fn((char *)obj + vt->delta, -1);
    }
}
