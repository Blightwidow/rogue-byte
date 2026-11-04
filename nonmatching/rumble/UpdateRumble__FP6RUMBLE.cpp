// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
void SetRumbleRums__FP6RUMBLE4RUMS(void *, int);
void StopRumbleActuators__FP6RUMBLE(void *);
int scePadSetActDirect(int, int, unsigned char *, void *);
extern float g_2ddf10;
}
extern "C" void UpdateRumble__FP6RUMBLE(char *pthis)
{
    float f20 = g_2ddf10;
    int mode = *(int *)(pthis + 0x8);
    if (mode == 2) {
        if (0.0f < *(float *)(pthis + 0x14)) {
            *(float *)(pthis + 0x18) = *(float *)(pthis + 0x18) - f20;
            if (!(0.0f < *(float *)(pthis + 0x18))) {
                int index = *(int *)(pthis + 0x10) + 1;
                *(int *)(pthis + 0x10) = index;
                char *table = *(char **)(pthis + 0xC);
                if (!(index < *(int *)table))
                    *(int *)(pthis + 0x10) = 0;
                index = *(int *)(pthis + 0x10);
                char *entry = table + index * 8;
                unsigned char motors[2];
                motors[0] = (unsigned char)entry[4];
                motors[1] = (unsigned char)entry[5];
                scePadSetActDirect(*(int *)pthis, *(int *)(pthis + 0x4), motors, entry);
                *(float *)(pthis + 0x18) = *(float *)(table + (*(int *)(pthis + 0x10)) * 8 + 8);
            }
            *(float *)(pthis + 0x14) = *(float *)(pthis + 0x14) - f20;
        } else {
            SetRumbleRums__FP6RUMBLE4RUMS(pthis, 3);
        }
    } else if (mode < 2 || mode >= 5) {
        return;
    } else {
        if (0.0f < *(float *)(pthis + 0x18)) {
            StopRumbleActuators__FP6RUMBLE(pthis);
            *(float *)(pthis + 0x18) = *(float *)(pthis + 0x18) - f20;
        } else {
            SetRumbleRums__FP6RUMBLE4RUMS(pthis, mode == 3);
        }
    }
}
