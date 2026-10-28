struct Spr { char pad[0x28]; void *inst; };
extern "C" void SeekSpriteInstanceFraction(Spr *, int, int);
void func_00217FB8(Spr *spr)
{
    if (spr->inst) SeekSpriteInstanceFraction(spr, 0, 0);
}
