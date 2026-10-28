struct Parent { char pad[0x3CC]; int handle; char pad3D0[4]; int blocked; };
struct Obj { char pad[0x10]; Parent *parent; char pad14[0x2C]; int busy; };
extern "C" int func_0020A7E0(int);
int func_00176060(Obj *obj)
{
    int result;
    if (obj->busy) {
        result = 0;
    } else {
        Parent *parent = obj->parent;
        if (parent->blocked)
            result = 0;
        else
            result = func_0020A7E0(parent->handle);
    }
    return result;
}
