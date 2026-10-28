struct Owner { char pad0[0x4638]; void *swObject; };
extern "C" void *PloFindSwObject_thunk(Owner *, int, int, int);
void func_00210940(Owner *owner)
{
    owner->swObject = PloFindSwObject_thunk(owner, 5, 0x620, 0);
}
