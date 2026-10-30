struct Fade_15DCD8;
struct FadeVt_15DCD8 { char pad[0x48]; short delta; short pad2; void (*fn)(char *); };
struct Fade_15DCD8 { char pad[0xC]; FadeVt_15DCD8 *vt; char pad2[0x4C]; float a, b, c, d; };
extern "C" {
void UpdateLo();
extern float g_2dded0;
void UpdateFade(Fade_15DCD8 *self) {
    UpdateLo();
    float limit = g_2dded0 - self->d;
    if (self->a + self->b + self->c < limit) {
        self->vt->fn((char *)self + self->vt->delta);
    }
}
}
