typedef int QW __attribute__((mode(TI)));
extern "C" {
QW ConvertAloPos(void *, void *, QW);
int PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *, int, QW);
QW PosLoWorld(void *);
void *PpoSwFocusBase(void *);
void QueueMovie(void *, int);
void RequestTransition(void *, int, int, int, int, int);
void UpdateLo();
void Warp_SetState(void *, int);
void Warp_Start(void *);
extern char B_002F66B0[];
extern char B_003DD490[];
extern float g_2dded0;
void UpdateWarp(char *self) {
    union { QW q; float f[4]; } pos; /* VECTOR local: retail stores the QW at sp+0 */
    int index;
    UpdateLo();
    switch (*(unsigned *)(self + 0x13C)) {
    case 4: {
        float timer = *(float *)(self + 0x158);
        if (timer > 0.0f) {
            if (timer <= g_2dded0) {
                index = 0;
                if (*(int *)(self + 0x148) > 0) {
                    do {
                        int offset = index * 4;
                        index += 1;
                        QueueMovie(B_002F66B0, *(int *)(offset + *(int *)(self + 0x14C)));
                    } while (index < *(int *)(self + 0x148));
                }
                RequestTransition(B_003DD490, *(int *)(self + 0x144), *(int *)(self + 0x150), -1, *(int *)(self + 0x138) != 0 ? 0x20 : 0, *(int *)(self + 0x154));
                *(float *)(self + 0x158) = 0.0f;
            }
        }
        return;
    }
    case 0:
    case 1:
    case 3: {
        void *focus = PpoSwFocusBase(B_003DD490);
        if (focus != 0) {
            QW world = PosLoWorld(focus);
            pos.q = ConvertAloPos(0, self, world);
            int inside = PcgtPointInCbspQuick__FP4CBSPP6VECTOR(*(void **)(self + 0xEC), 0x7FFFFFFF, pos.q) != 0;
            switch (*(unsigned *)(self + 0x13C)) {
            case 3:
                if (inside != 0) Warp_Start(self);
                break;
            case 1:
                if (inside != 0) {
                    Warp_SetState(self, 0);
                } else if (*(float *)(self + 0x15C) < (g_2dded0 - *(float *)(self + 0x140))) {
                    Warp_SetState(self, 3);
                }
                break;
            case 0:
                if (inside == 0) Warp_SetState(self, 1);
                break;
            }
        }
        break;
    }
    case 2:
    default:
        break;
    }
}
}
