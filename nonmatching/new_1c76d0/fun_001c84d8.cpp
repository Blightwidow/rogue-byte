#include "sly2.h"
extern "C" {
int EnsureSggAlarm__FP3SGGP5ALARM(int, int);
int FAsegaGone(int);
int FButtonPressedWithin(void *, int, float);
void func_001C8918(void *, int);
extern QW D_002C0FF0[];
extern const float RO_002C0FE8;
extern const float RO_002A7798;
}
struct Clock { float time; float dt; };
extern Clock g_2dded0;
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

struct Frame_1C84D8 { QW dead[1]; };
extern "C" void func_001C84D8(void *self)
{
    Frame_1C84D8 frame;
    int previous;
    float zero = 0.0f;
    do {
        previous = F(int, self, 0x188);
        if (FButtonPressedWithin(F(void *, self, 0x150), 0x30, zero) != 0) {
            EnsureSggAlarm__FP3SGGP5ALARM(F(int, self, 0x19C), 0x655);
            func_001C8918(self, 3);
        }
        switch (F(int, self, 0x188)) {
        case 0:
            if (FButtonPressedWithin(F(void *, self, 0x150), 0xC0, zero) != 0) {
                func_001C8918(self, 2);
            } else {
                void *pad = F(void *, self, 0x150);
                unsigned current = F(unsigned, self, 0x194);
                float padY = F(float, pad, 0x14);
                float padX = F(float, pad, 0x10);
                QW stick = Vec3(padX, padY, zero);
                frame.dead[0] = stick;
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
                    func_001C8918(self, 1);
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
                    func_001C8918(self, 3);
                } else {
                    func_001C8918(self, 0);
                }
            }
            break;
        }
        case 1:
            if (F(float, F(void *, self, 0x204), 0xA8) <= g_2dded0.time)
                func_001C8918(self, 0);
            break;
        }
    } while (F(int, self, 0x188) != previous);
}
