extern "C" {
void ClearHandsOff(void *, int);
int ClearReconVisibility(char *, int);
void HideReconLinks(char *);
int NewEmitter(int, int);
void SeekBlotLabel(char *, int, int);
void SetBlotBlots(char *, int);
void SetBlotModal(char *, int);
void SetClockRate(void *, int, float);
void SetEmitterUnpositioned(int, int);
void SetHandsOff(void *, int);
void SetReconTargetDone(char *, int);
float SetTimerTimers__FP5TIMER6TIMERS(char *, int);
void ShowReconLinks(char *);
int StartStream(void *, int, int);
void StartWipe(int, int, int);
void UpdateReconLinkFades(char *);
void bevy_camera_follow_activity(void *, int, int);
void bevy_ui_binoc_recon_201f90(char *);
int bevy_ui_binoc_recon_202030(char *);
void bevy_ui_binoc_recon_2021f8(char *);
int bevy_ui_binoc_recon_2022d8(char *);
void func_0014FE28(void *);
int func_001FE5B8(void *, int, int);
int func_00213928(char *, int);
int func_00213B00(char *, int);
extern char B_002DE390;
extern char B_002DEB30;
extern char B_003DD040;
extern char B_003DD490;
extern char g_2dded0;
#define VTAB(object) (*(char **)((char *)(object) + 0xC))
#define VADJ(object, off) ((char *)(object) + *(short *)(VTAB(object) + (off) - 4))
#define VFN(object, off) (*(void **)(VTAB(object) + (off)))
#define VCALL_INT_SELF(object, off, value) ((void (*)(char *, int, char *))VFN(object, off))(VADJ(object, off), (value), (char *)(object))
#define VCALL_SELF(object, off) ((void (*)(char *, char *))VFN(object, off))(VADJ(object, off), (char *)(object))
void bevy_ui_binoc_recon_202768(char *arg0, int arg1) {
    int old = *(int *)arg0;
    if ((old != arg1) && (*(char **)(arg0 + 0xAC) != 0) && (*(char **)(arg0 + 0xB0) != 0)) {
        int newIsRecon = (unsigned int)(arg1 - 8) < 2U;
        if (((unsigned int)(old - 8) < 2U) != newIsRecon) {
            if (newIsRecon != 0) {
                SetHandsOff(&B_003DD490, 0);
            } else {
                ClearHandsOff(&B_003DD490, 0);
            }
        }
        switch (*(int *)arg0) {
        case -1:
        case 10:
            break;
        case 1:
            UpdateReconLinkFades(arg0);
            bevy_ui_binoc_recon_202030(arg0);
            func_00213B00(*(char **)(arg0 + 0xAC), 0x35D);
            if (*(int *)(arg0 + 0x74) > 0) {
                func_00213B00(*(char **)(arg0 + 0xAC), 0x35E);
            }
            bevy_ui_binoc_recon_2021f8(arg0);
            break;
        case 4:
            func_00213928(*(char **)(arg0 + 0xB0), 0x359);
            break;
        case 5:
        case 6:
            func_00213928(*(char **)(arg0 + 0xB0), 0x35A);
            break;
        case 7:
            func_00213928(*(char **)(arg0 + 0xAC), 0x356);
            func_00213928(*(char **)(arg0 + 0xB0), 0x356);
            func_00213928(*(char **)(arg0 + 0xB0), 0x357);
            break;
        case 8: {
            char *holder = **(char ***)(arg0 + 0xA8);
            int tagged = *(int *)(holder + 0x40);
            int saved = *(int *)(arg0 + 0xA0);
            if (!(tagged & 1)) {
                *(int *)tagged = saved | (*(int *)tagged & 1);
            } else {
                *(int *)(holder + 0x40) = saved | (tagged & 1);
            }
            SetClockRate(&g_2dded0, 0, 1.0f);
            func_001FE5B8(&B_003DD040, 1, 1);
            func_00213928(*(char **)(arg0 + 0xAC), 0x358);
            break;
        }
        case 9:
            func_0014FE28(&B_002DE390);
            SetBlotModal(*(char **)(arg0 + 0xAC), -1);
            VCALL_INT_SELF(*(char **)(arg0 + 0xAC), 0x18C, 0x310);
            if (*(int *)(arg0 + 0xA4) != 0) {
                int stream = *(int *)(*(char **)(arg0 + 0x8C) + 0xFC);
                if (stream != -1) {
                    StartStream(&B_003DD040, stream, 0);
                }
                StartWipe(*(int *)(arg0 + 0xA4), 0x608, *(int *)(*(char **)(arg0 + 0x8C) + 0xFC));
            }
            SetReconTargetDone(*(char **)(arg0 + 0x8C), 1);
            bevy_camera_follow_activity(&B_002DEB30, 0xA, 0);
            *(char **)(arg0 + 0x8C) = 0;
            if (bevy_ui_binoc_recon_2022d8(arg0) != 0) {
                func_00213B00(*(char **)(arg0 + 0xAC), 0x35D);
                if (*(int *)(arg0 + 0x74) > 0) {
                    func_00213B00(*(char **)(arg0 + 0xAC), 0x35E);
                }
            }
            bevy_ui_binoc_recon_2021f8(arg0);
            break;
        }
        int previous = *(int *)arg0;
        *(int *)arg0 = arg1;
        int label;
        switch (arg1) {
        case 0:
            *(char **)(arg0 + 0x8C) = 0;
            *(int *)(arg0 + 0xC0) = -1;
            *(int *)(arg0 + 0xBC) = -1;
            ClearReconVisibility(arg0, previous);
            VCALL_INT_SELF(*(char **)(arg0 + 0xAC), 0x18C, -1);
            HideReconLinks(arg0);
            bevy_ui_binoc_recon_201f90(arg0);
            bevy_camera_follow_activity(&B_002DEB30, 9, 0);
            return;
        case 1:
            func_00213928(*(char **)(arg0 + 0xAC), 0x35D);
        case 2:
            VCALL_INT_SELF(*(char **)(arg0 + 0xB0), 0x18C, 0x339);
            return;
        case 5:
        case 6:
            func_00213B00(*(char **)(arg0 + 0xB0), 0x35A);
            SeekBlotLabel(*(char **)(arg0 + 0xB0), 0x35A, 0);
            return;
        case 7:
            SetEmitterUnpositioned(NewEmitter(0x52, previous), 0);
            *(int *)(arg0 + 0xBC) = *(int *)(*(char **)(arg0 + 0x8C) + 0xF4);
            func_00213B00(*(char **)(arg0 + 0xAC), 0x356);
            func_00213B00(*(char **)(arg0 + 0xB0), 0x356);
            func_00213B00(*(char **)(arg0 + 0xB0), 0x357);
            return;
        case 8: {
            func_00213928(*(char **)(arg0 + 0xAC), 0x35B);
            func_00213B00(*(char **)(arg0 + 0xAC), 0x358);
            char **handle = *(char ***)(arg0 + 0xA8);
            int tagged = *(int *)(*handle + 0x40);
            if (!(tagged & 1)) {
                tagged = *(int *)tagged;
            }
            *(int *)(arg0 + 0xA0) = tagged & ~1;
            char *holder = *handle;
            int second = *(int *)(holder + 0x40);
            if (!(second & 1)) {
                *(int *)second = *(int *)second | 0x102;
            } else {
                *(int *)(holder + 0x40) = second | 0x102;
            }
            func_001FE5B8(&B_003DD040, 1, 0);
            SetClockRate(&g_2dded0, 0, 0.0f);
            return;
        }
        case 9:
            VCALL_INT_SELF(*(char **)(arg0 + 0xB0), 0x18C, 0x339);
            VCALL_INT_SELF(*(char **)(arg0 + 0xAC), 0x18C, 0x35C);
            SetBlotModal(*(char **)(arg0 + 0xAC), 0);
            return;
        case 3:
        case 4:
            *(char **)(*(char **)(arg0 + 0xB0) + 0xF4) = *(char **)(arg0 + 0x8C);
            VCALL_INT_SELF(*(char **)(arg0 + 0xB0), 0x18C, 0x337);
            func_00213B00(*(char **)(arg0 + 0xB0), 0x359);
            SeekBlotLabel(*(char **)(arg0 + 0xB0), 0x359, 0);
            return;
        case 10:
            *(char **)(arg0 + 0x8C) = 0;
            *(int *)(arg0 + 0xC0) = -1;
            *(int *)(arg0 + 0xBC) = -1;
            VCALL_SELF(*(char **)(arg0 + 0xB0), 0x194);
            VCALL_SELF(*(char **)(arg0 + 0xAC), 0x194);
            ShowReconLinks(arg0);
            bevy_camera_follow_activity(&B_002DEB30, 0xB, 0);
            return;
        case -1:
            if (previous != 0xA) {
                bevy_camera_follow_activity(&B_002DEB30, 0xB, 0);
                char *first = *(char **)(arg0 + 0xAC);
                if (*(int *)(first + 0x58) != 0) {
                    SetBlotBlots(first, 1);
                    SetTimerTimers__FP5TIMER6TIMERS(*(char **)(arg0 + 0xAC), 1);
                }
                char *second = *(char **)(arg0 + 0xB0);
                if (*(int *)(second + 0x58) != 0) {
                    SetBlotBlots(second, 1);
                    SetTimerTimers__FP5TIMER6TIMERS(*(char **)(arg0 + 0xB0), 1);
                }
            }
            break;
        }
    }
}
}
