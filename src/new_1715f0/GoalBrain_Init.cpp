struct Obj { char pad[0x30]; int a; };
extern "C" void func_001EEF68(Obj *);
void GoalBrain_Init(Obj *obj)
{
    func_001EEF68(obj);
    obj->a = -1;
}
