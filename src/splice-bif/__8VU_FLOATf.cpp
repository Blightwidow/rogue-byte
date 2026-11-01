// Behaviour: VU_FLOAT::VU_FLOAT(float): stores f into lane 0 of the 128-bit value at *this (mfc1), returns this.
typedef int QW __attribute__((mode(TI)));
struct VU_FLOAT { QW value; VU_FLOAT(float f); };
// lane 0 move: mfc1 of f straight into the 128-bit member (gcc goes through a stack temporary, as retail does)
VU_FLOAT::VU_FLOAT(float f) { asm("mfc1 %0, %1" : "=r" (value) : "f" (f)); }
