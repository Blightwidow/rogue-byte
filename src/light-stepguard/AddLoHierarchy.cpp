struct Vt_1A5800 { char pad0[0x20]; short delta; short pad1; void (*fn)(char *, int, char *); };
struct Obj_1A5800 { char pad0[0xC]; Vt_1A5800 *vt; char pad1[0x1C - 8]; long flags; };
extern "C" void AddLoHierarchy(Obj_1A5800 *obj) {
    obj->flags |= 0x8000L << 45;
    obj->vt->fn((char *)obj + obj->vt->delta, 0, (char *)obj);
}
