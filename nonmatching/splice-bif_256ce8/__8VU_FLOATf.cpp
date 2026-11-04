typedef int QW __attribute__((mode(TI)));
struct VU_FLOAT { QW lanes; };
extern "C" VU_FLOAT *__8VU_FLOATf(VU_FLOAT *self, float value)
{
    union { float f; int bits; } lane;
    lane.f = value;
    self->lanes = (QW)(long long)lane.bits;
    return self;
}
