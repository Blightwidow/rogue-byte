extern "C" char D_002CA5A0[];
extern "C" void __builtin_delete(void *);
struct Obj { char pad[0x30]; void *vt; };
void func_001184B8(Obj *o, int flags)
{
    o->vt = D_002CA5A0;
    if (flags & 1)
        __builtin_delete(o);
}
