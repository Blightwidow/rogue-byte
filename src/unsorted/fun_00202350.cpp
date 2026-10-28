struct OBJ { char pad[0x10]; unsigned long flags; char pad2[0x70 - 0x18]; int count; };
extern "C" int func_00202350(void *unused, OBJ *obj)
{
    int result = 0;
    if (!(obj->flags & 0x1000000000000UL)) result = obj->count > 0;
    return result;
}
