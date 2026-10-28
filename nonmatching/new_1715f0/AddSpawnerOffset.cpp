typedef int QW __attribute__((mode(TI)));
struct Obj { char pad[0x98]; int count; QW *items; };
void AddSpawnerOffset(Obj *obj, QW offset)
{
    int n = obj->count;
    int next = n + 1;
    if (n < 0x10) {
        QW *items = obj->items;
        obj->count = next;
        items[n] = offset;
    }
}
