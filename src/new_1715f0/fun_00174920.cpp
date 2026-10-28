struct Obj { char pad[0x30]; int a; char pad34[8]; int b; };
extern "C" void func_001EEF68(Obj *);
void func_00174920(Obj *obj)
{
    func_001EEF68(obj);
    obj->b = 0;
    obj->a = -1;
}
