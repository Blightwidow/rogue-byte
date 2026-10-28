typedef int QW __attribute__((mode(TI)));
struct Other { char pad0[0x20]; QW a; QW b; char pad40[4]; int link; char pad48[0xC]; int state; };
struct Obj { char pad0[0x10]; int key; char pad14[0x30]; Other *other; };
QW func_00172760(Obj *obj)
{
    Other *other = obj->other;
    if (other->state == 4 && other->link == obj->key)
        return other->a;
    return obj->other->b;
}
