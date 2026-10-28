struct Obj { char pad[0xE78]; int flag; };
extern "C" void InitGuard(Obj *);
void func_0016F148(Obj *obj)
{
    InitGuard(obj);
    obj->flag = 1;
}
