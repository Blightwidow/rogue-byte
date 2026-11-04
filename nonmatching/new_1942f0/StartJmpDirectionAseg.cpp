// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
float atan2f(float, float);
float RadNormalize__Ff(float);
void RetractSmaRef(void *);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
}
extern "C" void StartJmpDirectionAseg(char *pthis)
{
    char *s0;
    float angle;
    float diff;
    float absDiff;
    int index;
    int mode;
    char *s2;

    *(int *)(pthis + 0x30) = 1;
    {
        char *sub = *(char **)(*(char **)pthis + 0x60);
        angle = atan2f(*(float *)(sub + 0x44), *(float *)(sub + 0x40));
    }
    diff = *(float *)(*(char **)(*(char **)pthis + 0x150) + 0x18) - angle;
    diff = RadNormalize__Ff(diff);
    absDiff = diff < 0.0f ? -diff : diff;
    if (absDiff < 1.0995574f) {
        *(int *)(pthis + 0x8) = 3;
    } else if (2.0420351f < absDiff) {
        *(int *)(pthis + 0x8) = 4;
    } else if (0.0f < diff) {
        *(int *)(pthis + 0x8) = 2;
    } else {
        *(int *)(pthis + 0x8) = 1;
    }
    mode = *(int *)(pthis + 0x1C);
    s2 = *(char **)(*(char **)pthis + 0x1030);
    index = *(int *)(pthis + 0x8);
    if (mode == 2)
        s0 = *(char **)(pthis + index * 4 + 0x134);
    else
        s0 = *(char **)(pthis + index * 4 + 0x120);
    if (s0 == 0) {
        if (mode == 2)
            s0 = *(char **)(pthis + 0x134);
        else
            s0 = *(char **)(pthis + 0x120);
        if (s0 == 0)
            s0 = *(char **)(pthis + 0x120);
    }
    RetractSmaRef(*(char **)pthis + 0x1034);
    ApplyAsegToHandle(s0, *(char **)pthis, 1, *(char **)pthis + 0x1030, *(float *)(s2 + 0x1C), *(float *)(s2 + 0x40));
}
