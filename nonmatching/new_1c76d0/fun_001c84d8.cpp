#include "sly2.h"
extern "C" {
int EnsureSggAlarm__FP3SGGP5ALARM(int, int);
int FAsegaGone(int);
int FButtonPressedWithin(void *, int, int);
void func_001C8918(void *, int, float);
extern QW D_002C0FF0[];
extern const float RO_002C0FE8;
extern const float RO_002A7798;
}
struct Clock { float time; float dt; };
extern Clock g_2dded0;
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

extern "C" void func_001C84D8(void *self)
{
    int previous;
    float zero = 0.0f;
    do {
        previous = F(int, self, 0x188);
        if (FButtonPressedWithin(F(void *, self, 0x150), 0x30, 0) != 0) {
            EnsureSggAlarm__FP3SGGP5ALARM(F(int, self, 0x19C), 0x655);
            func_001C8918(self, 3, zero);
        }
        switch (F(int, self, 0x188)) {
        case 0:
            if (FButtonPressedWithin(F(void *, self, 0x150), 0xC0, 0) != 0) {
                func_001C8918(self, 2, zero);
            } else {
                void *pad = F(void *, self, 0x150);
                unsigned current = F(unsigned, self, 0x194);
                float padY = F(float, pad, 0x14);
                float padX = F(float, pad, 0x10);
                int bitsY, bitsX, bitsZero;
                asm("mfc1 %0, %1" : "=r" (bitsX) : "f" (padX));
                asm("mfc1 %0, %1" : "=r" (bitsY) : "f" (padY));
                QW stick;
                asm("pextlw %0, %1, %2" : "=r" (stick) : "r" (bitsY), "r" (bitsX));
                asm("mfc1 %0, %1" : "=r" (bitsZero) : "f" (zero));
                asm("pcpyld %0, %1, %0" : "+r" (stick) : "r" (bitsZero));
                asm("qmtc2.ni %0, vf3" : : "r" (stick));
                float best = RO_002A7798;
                unsigned bestIndex = -1;
                QW *slot = D_002C0FF0;
                for (unsigned index = 0; index < 9; index++) {
                    int lengthBits;
                    asm volatile("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf3, vf1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (lengthBits) : "m" (*slot));
                    slot++;
                    float length;
                    asm volatile("mtc1 %1, %0" : "=f" (length) : "r" (lengthBits));
                    if (index == current)
                        length *= RO_002C0FE8;
                    if (length < best) {
                        best = length;
                        bestIndex = index;
                    }
                }
                if (bestIndex != current) {
                    F(unsigned, self, 0x194) = bestIndex;
                    func_001C8918(self, 1, zero);
                }
            }
            break;
        case 2: {
            int object = F(int, self, 0x1A0);
            if (object == 0 || FAsegaGone(object) != 0) {
                int next = (F(int, self, 0x198) * 10) % 1000 + 1 + F(unsigned, self, 0x194);
                F(int, self, 0x198) = next;
                if (next == F(int, self, 0x1F0)) {
                    EnsureSggAlarm__FP3SGGP5ALARM(F(int, self, 0x19C), 0x655);
                    func_001C8918(self, 3, zero);
                } else {
                    func_001C8918(self, 0, zero);
                }
            }
            break;
        }
        case 1:
            if (F(float, F(void *, self, 0x204), 0xA8) <= g_2dded0.time)
                func_001C8918(self, 0, zero);
            break;
        }
    } while (F(int, self, 0x188) != previous);
}
