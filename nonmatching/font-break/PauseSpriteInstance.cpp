struct SPRITEINST218748 { char pad[0x10]; int fPaused; void *pamb; };
struct SPRITE218748 { char pad[8]; SPRITEINST218748 *ainst; };
extern "C" {
void PauseAmb(void *);
void PauseSpriteInstance(SPRITE218748 *sprite, int index) {
    void *amb;
    sprite->ainst[index].fPaused = 1;
    amb = sprite->ainst[index].pamb;
    if (amb) PauseAmb(amb);
}
}
