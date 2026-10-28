struct Parent { char pad[0xF3C]; int value; };
struct Obj { char pad[0x10]; Parent *parent; };
extern "C" void func_00174B28(Obj *);
void func_001752C0(Obj *obj)
{
    func_00174B28(obj);
    obj->parent->value = 0;
}
