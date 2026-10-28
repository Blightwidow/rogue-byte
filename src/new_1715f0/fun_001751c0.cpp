struct Obj { char pad[0x3C]; int mode; };
extern "C" void func_00174920(Obj *);
void func_001751C0(Obj *obj)
{
    func_00174920(obj);
    obj->mode = 3;
}
