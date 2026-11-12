#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
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
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

struct Frame_1C84D8 { QW dead[1]; };
extern "C" void func_001C84D8(void *self)
{
    Frame_1C84D8 frame;
    int previous;
    float zero = FloatFromWord(0);
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
                QW stick = JoinLowDoublewords(zero, InterleaveLowWords(padY, padX));
                frame.dead[0] = stick;
                float best = RO_002A7798;
                unsigned bestIndex = -1;
                QW *slot = D_002C0FF0;
                for (unsigned index = 0; index < 9; index++) {
                    float length = LaneX(SqrtX(SquaredLength(VectorSub(stick, *slot))));
                    slot++;
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
            float now = g_2dded0.time;
            if (F(float, F(void *, self, 0x204), 0xA8) <= now)
                func_001C8918(self, 0);
            break;
        }
    } while (F(int, self, 0x188) != previous);
}
