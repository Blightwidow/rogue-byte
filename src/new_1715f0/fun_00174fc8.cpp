struct Obj { char pad[0x3C]; int mode; };
extern "C" void func_00174920(Obj *);
void func_00174FC8(Obj *obj)
{
    func_00174920(obj);
    obj->mode = 2;
}
