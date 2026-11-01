struct VT { char pad[0x340]; short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0xC]; VT *vptr; };
extern char B_003DD490;
extern "C" int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
extern "C" void func_0019F0A8(void)
{
    Obj *found[8];
    int count = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0, 8, found);
    for (int index = 0; index < count; index++) { Obj *obj = found[index]; VT *vt = obj->vptr; vt->fn((char *)obj + vt->delta); }
}
