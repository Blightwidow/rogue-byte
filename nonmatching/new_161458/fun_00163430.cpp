struct Sub { char pad[0x54]; int value; };
struct Obj { char pad[0x64]; Sub *a; Sub *b; };
int func_00163430(Obj *obj)
{
    Sub *s;
    int m = 1;
    int v = obj->a->value;
    if (v >= 2) {
        s = obj->b;
        v = s->value;
        v = v > m ? v : m;
    }
    return v;
}
