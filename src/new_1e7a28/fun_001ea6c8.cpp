struct Elem { char pad[0x18]; unsigned long mask; };
struct Kind { char pad[0x20]; unsigned long mask; };
struct Table { char pad[8]; void *shape; Kind **kinds; Elem **elems; };
extern "C" int func_001EA688(void *);
extern "C" unsigned long func_001EA6C8(Table *table, int row, int column)
{
    unsigned long mask = table->kinds[row]->mask;
    Elem *elem = table->elems[row * func_001EA688(table->shape) + column];
    if (elem) mask |= elem->mask;
    return mask;
}
