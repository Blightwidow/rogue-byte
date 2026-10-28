struct Obj { char pad[0x90]; int count; int *items; };
void func_00173398(Obj *obj, int item)
{
    int n = obj->count;
    if (n < 8) {
        obj->items[n] = item;
        obj->count = n + 1;
    }
}
