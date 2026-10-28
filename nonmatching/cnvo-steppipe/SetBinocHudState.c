#include "m2c_macros.h"

M2C_UNK SeekBlotLabel(void *, M2C_UNK, f32);        /* extern */
M2C_UNK SetBlotBlots(void *, M2C_UNK);              /* extern */
M2C_UNK SetTimerTimers__FP5TIMER6TIMERS(void *, M2C_UNK); /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK bevy_ui_binoc_recon_202768(s32, M2C_UNK);   /* extern */
M2C_UNK func_0019D948();                            /* extern */
M2C_UNK func_00213B00(void *, M2C_UNK);             /* extern */
M2C_UNK func_00227788(M2C_UNK *);                   /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_004435F0;

void SetBinocHudState(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_5;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;

    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_v0 != arg1) {
        if (temp_v0 == -1) {
            func_0019D948();
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        switch (arg1) {                             /* irregular */
        case 0:
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x20) == 1) {
                bevy_camera_follow_activity(&B_002DEB30, 0xC, 0);
            } else {
                bevy_camera_follow_activity(&B_002DEB30, 7, 0);
            }
            temp_a2 = M2C_FIELD(arg0, void **, 8);
            if (temp_a2 != NULL) {
                temp_v0_2 = M2C_FIELD(temp_a2, void **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0x188), -1, temp_a2);
                func_00213B00(M2C_FIELD(arg0, void **, 8), 0x352);
                func_00213B00(M2C_FIELD(arg0, void **, 8), 0x351);
                SeekBlotLabel(M2C_FIELD(arg0, void **, 8), 0x352, (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0), f32 *, 0x1A8) + 3.1415927f) * 0.15915494f);
                SeekBlotLabel(M2C_FIELD(arg0, void **, 8), 0x351, M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x3C));
            }
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x20) == 1) {
                func_00227788(&B_004435F0);
                temp_a2_2 = M2C_FIELD(arg0, void **, 0x10);
                if (temp_a2_2 != NULL) {
                    temp_v0_3 = M2C_FIELD(temp_a2_2, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void *), 0x18C)(temp_a2_2 + M2C_FIELD(temp_v0_3, s16 *, 0x188), -1, temp_a2_2);
                }
            }
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x14);
            if (temp_a0 != 0) {
                bevy_ui_binoc_recon_202768(temp_a0, 0);
            }
            break;
        case 2:
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x20) == 1) {
                bevy_camera_follow_activity(&B_002DEB30, 0xD, 0);
            } else {
                bevy_camera_follow_activity(&B_002DEB30, 8, 0);
            }
            temp_a1 = M2C_FIELD(arg0, void **, 8);
            if (temp_a1 != NULL) {
                temp_v0_4 = M2C_FIELD(temp_a1, void **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, void *), 0x194)(temp_a1 + M2C_FIELD(temp_v0_4, s16 *, 0x190), temp_a1);
            }
            temp_a1_2 = M2C_FIELD(arg0, void **, 0x10);
            if (temp_a1_2 != NULL) {
                temp_v0_5 = M2C_FIELD(temp_a1_2, void **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, void *), 0x194)(temp_a1_2 + M2C_FIELD(temp_v0_5, s16 *, 0x190), temp_a1_2);
            }
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x14);
            if (temp_a0_2 != 0) {
                bevy_ui_binoc_recon_202768(temp_a0_2, 0xA);
            }
            break;
        case -1:
            if (temp_v1 != 2) {
                if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x20) == 1) {
                    bevy_camera_follow_activity(&B_002DEB30, 0xD, 0);
                } else {
                    bevy_camera_follow_activity(&B_002DEB30, 8, 0);
                }
            }
            temp_a0_3 = M2C_FIELD(arg0, void **, 8);
            if ((temp_a0_3 != NULL) && (M2C_FIELD(temp_a0_3, s32 *, 0x58) != 0)) {
                SetBlotBlots(temp_a0_3, 1);
                SetTimerTimers__FP5TIMER6TIMERS(M2C_FIELD(arg0, void **, 8), 1);
            }
            temp_a0_4 = M2C_FIELD(arg0, void **, 0x10);
            if ((temp_a0_4 != NULL) && (M2C_FIELD(temp_a0_4, s32 *, 0x58) != 0)) {
                SetBlotBlots(temp_a0_4, 1);
                SetTimerTimers__FP5TIMER6TIMERS(M2C_FIELD(arg0, void **, 0x10), 1);
            }
            temp_a0_5 = M2C_FIELD(arg0, s32 *, 0x14);
            if (temp_a0_5 != 0) {
                bevy_ui_binoc_recon_202768(temp_a0_5, -1);
            }
            break;
        }
    }
}
