struct VT1C4228 { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int **, int); };
struct Obj1C4228 { char pad[0xC]; VT1C4228 *vt; };
struct Locals1C4228 { int *args[2]; int gap[2]; int values[2]; };
extern "C" void func_001C4228(Obj1C4228 *obj, int first, int second)
{
    Locals1C4228 l;
    l.args[0] = &l.values[0];
    l.args[1] = &l.values[1];
    VT1C4228 *vt = obj->vt;
    void *self = (char *)obj + vt->delta;
    l.values[1] = second;
    l.values[0] = first;
    vt->fn(self, 12, 0, 2, l.args, 0);
}
