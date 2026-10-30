struct Sub { char pad[0x54]; int value; };
struct Obj { char pad[0x64]; Sub *a; Sub *b; };
int func_00163430(Obj *obj)
{
    int v = obj->a->value;
    if (v >= 2) {
        int m = 1;
        int w = obj->b->value;
        return w > m ? w : m;
    }
    return v;
}
