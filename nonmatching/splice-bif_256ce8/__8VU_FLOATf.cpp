typedef int QW __attribute__((mode(TI)));
struct VU_FLOAT { QW lanes;  VU_FLOAT() {} ~VU_FLOAT(); };
extern "C" VU_FLOAT __8VU_FLOATf(float value) return __ret
{
    union { float f; int bits; } lane;
    lane.f = value;
    __ret.lanes = (QW)(long long)lane.bits;
    return;
}
