struct Spr { char pad[0x28]; void *inst; };
extern "C" void func_002185F8(Spr *, int, int);
void func_002185D0(Spr *spr)
{
    if (spr->inst) func_002185F8(spr, 0, 0);
}
