struct Spr { char pad[0x28]; void *inst; };
extern "C" void SeekSpriteInstanceTime(Spr *, int, int);
void func_00218038(Spr *spr)
{
    if (spr->inst) SeekSpriteInstanceTime(spr, 0, 0);
}
