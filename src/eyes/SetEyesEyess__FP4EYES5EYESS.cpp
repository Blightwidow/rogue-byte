extern "C" float GRandInRange__Fff(float, float);
extern float g_2dded0;
struct EYES {
    char pad0[0x1C]; int count; char pad20[0x30]; float scale; float lo; float hi; float limit;
    char pad60[4]; int mode; float value; float level; float step; float pos; float ratio;
};

void SetEyesEyess__FP4EYES5EYESS(EYES *self, int mode)
{
    if (mode == self->mode) return;
    if (mode == 1) goto store;
    if (mode < 2) {
        if (mode == 0) goto zero;
        self->mode = mode;
        goto tail;
    }
    if (mode == 2) goto two;
    self->mode = mode;
    goto tail;

zero:
    {
        int count = self->count;
        float span = (float)(count << 1) * (1.0f - self->ratio) / self->scale;
        self->pos = (float)(count - 1) * self->ratio;
        self->step = span;
        float roll = GRandInRange__Fff(0.0f, 1.0f);
        if (roll < self->limit) {
            self->level = 0.0f;
        } else {
            self->level = GRandInRange__Fff(self->lo, self->hi);
        }
    }
    goto store;

two:
    {
        int last = self->count - 1;
        if ((int)self->pos == last) {
            self->mode = mode;
            goto tail;
        }
        self->pos = (float)last;
    }

store:
    self->mode = mode;

tail:
    self->value = g_2dded0;
}
