struct Spr { char pad[0x28]; void *inst; };
extern "C" void StopSpriteInstance(Spr *, int);
void StopRootSprite(Spr *spr)
{
    if (spr->inst) StopSpriteInstance(spr, 0);
}
