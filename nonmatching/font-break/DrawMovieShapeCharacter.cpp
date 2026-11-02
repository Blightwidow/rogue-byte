struct VIFS { char pad[0xC]; char *p; };
struct SLOT { int a; float f; int c; int d; };
struct CAM { char pad[0x9C]; float x; float y; };
struct PRIOR { char pad[0xA4]; int scale; char pad2[0x20]; CAM *cam; };
struct SELF { char pad0[8]; PRIOR *owner; char pad1[6]; unsigned short count; int limit; char pad2[4]; int word; };
struct TAIL { int pad0; int kind; float base; int cap; char pad1[0x1C]; float cutoff; };
struct PAIR { float v[6]; };
struct LOCALS { float v[16]; };
extern "C" {
extern VIFS g_2dea28;
SLOT *OnGameLoad__FP4GAME(void);
void *memset(void *, int, unsigned);
static inline void Pad(VIFS *pv) { while ((int)pv->p & 0xF) { *(int *)pv->p = 0; pv->p = pv->p + 4; } }
static inline void Skip(VIFS *pv, int n) { pv->p = pv->p + n; }
static inline void Tail(VIFS *pv, char *tail)
{
    *(int *)pv->p = 0x6C03C004;
    int *to = (int *)(pv->p += 4);
    int *from = (int *)tail;
    int n = 8;
    do {
        n -= 4;
        int w0 = from[0]; int w1 = from[1]; int w2 = from[2]; int w3 = from[3];
        from += 4;
        to[0] = w0; to[1] = w1; to[2] = w2; to[3] = w3;
        to += 4;
    } while (n >= 0);
    pv->p = pv->p + 0x30;
}
void DrawMovieShapeCharacter(SELF *self, PAIR *pair, TAIL *tail, int fade)
{
    LOCALS loc;
    memset(&loc, 0, 0x40);
    float k0 = 0.8f;
    float k1 = 0.45454547f;
    loc.v[0] = pair->v[0] * k0;
    loc.v[1] = pair->v[1] * k1;
    loc.v[4] = pair->v[2] * k0;
    loc.v[5] = pair->v[3] * k1;
    loc.v[8] = pair->v[4] * k0 + self->owner->cam->x + 786432.0f;
    loc.v[0xF] = 1.0f;
    loc.v[9] = pair->v[5] * k1 + self->owner->cam->y + 786432.0f;
    loc.v[10] = 1.0f;
    if (self->count >= 2U)
        tail->kind = 1;
    else
        tail->kind = 0;
    tail->cap = 0x7FFF;
    if (fade) {
        float cutoff = tail->cutoff;
        tail->cutoff = 1.0f;
        if (cutoff < 1.0f) {
            int limit = self->limit;
            int scaled = (int)((float)limit * cutoff);
            if (scaled > limit) scaled = limit;
            int value = scaled > 2 ? scaled : 3;
            tail->cap = value;
            if ((unsigned)value > 0x7FFF) tail->cap = 0x7FFF;
        }
    }
    char *tag = g_2dea28.p;
    *(long *)tag = 0x10000000;
    g_2dea28.p = g_2dea28.p + 0x10;
    *(int *)g_2dea28.p = 0x6C04C000;
    int *to = (int *)(g_2dea28.p += 4);
    int *from = (int *)&loc;
    int n = 0xC;
    do {
        n -= 4;
        int w0 = from[0]; int w1 = from[1]; int w2 = from[2]; int w3 = from[3];
        from += 4;
        to[0] = w0; to[1] = w1; to[2] = w2; to[3] = w3;
        to += 4;
    } while (n >= 0);
    Skip(&g_2dea28, 0x40);
    Tail(&g_2dea28, (char *)tail);
    Pad(&g_2dea28);
    *(int *)tag |= (int)((g_2dea28.p - tag) >> 4) - 1;
    *(long *)g_2dea28.p = 0x60000000;
    g_2dea28.p += 0x10;
    SLOT *slot = OnGameLoad__FP4GAME();
    slot->a = 0x15;
    slot->c = (int)tag & 0x0FFFFFFF;
    slot->f = tail->base + (float)(self->owner->scale << 0x12);
    slot->d = self->word;
}
}
