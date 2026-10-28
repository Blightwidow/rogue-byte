struct Src { char pad[0xA8]; int value; };
struct Dst { char pad[0x1C]; int value; };
extern "C" void CloneAct(Dst *, int, int, Src *);
void func_0021C820(Dst *dst, int b, int c, Src *src)
{
    CloneAct(dst, b, c, src);
    dst->value = src->value;
}
