// Behaviour: VU_FLOAT::VU_FLOAT(float): stores f into lane 0 of a 128-bit value at *this (other lanes = the raw bits' lane 0 only); returns this.
typedef int QW __attribute__((mode(TI)));
// lane 0 move: mfc1 into the 128-bit register
static inline QW FromLane0(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct VU_FLOAT { QW value; VU_FLOAT(float f); };
VU_FLOAT::VU_FLOAT(float f) { value = FromLane0(f); }
