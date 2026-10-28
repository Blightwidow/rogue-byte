struct Obj { char pad[0x10]; void *parent; char pad14[0x20]; int guard; };
extern "C" void func_001EEF68(Obj *);
extern "C" void AddGuardSgs(void *, int);
void func_001753D8(Obj *obj)
{
    func_001EEF68(obj);
    AddGuardSgs(obj->parent, 0x18);
    obj->guard = -1;
}
