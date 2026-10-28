#define JOY_AT(type, off) (*(type *)((char *)pjoy + (off)))

extern "C" void InitRumble__FP6RUMBLEii(void *, int, int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" char g_2dded0[];

void SetJoyJoys__FP3JOY4JOYS4JOYK(char *pjoy, int joys, int joyk)
{
    if (joys == JOY_AT(int, 0x100C) && joyk == JOY_AT(int, 0x1010))
        return;
    if (joyk == 0) {
        JOY_AT(int, 0x1008) = 0;
        joys = 1;
    }
    if (JOY_AT(int, 0x1010) < 3 && joyk >= 3)
        InitRumble__FP6RUMBLEii(pjoy + 0x10CC, JOY_AT(int, 0x1000), JOY_AT(int, 0x1004));
    if (JOY_AT(int, 0x1010) == 4) {
        if (joyk != 4)
            goto clearPressure;
    } else if (joyk == 4) {
        goto clearPressure;
    }
    goto afterPressure;
clearPressure:
    memset(pjoy + 0x10C0, 0, 0xC);
afterPressure:
    if (JOY_AT(int, 0x100C) == 3) {
        if (joys != 3)
            goto resetRun;
    } else if (joys == 3) {
resetRun:
        JOY_AT(int, 0x1018) = 0;
        JOY_AT(int, 0x1080) = 0;
        JOY_AT(int, 0x104C) = 0;
        JOY_AT(int, 0x10B8) = 0;
        JOY_AT(int, 0x10B4) = 0;
        JOY_AT(int, 0x10BC) = 0xFFFF;
        memset(pjoy + 0x10C0, 0, 0xC);
        float zeroExtent = 0.0f;
        JOY_AT(int, 0x1028) = 0;
        JOY_AT(float, 0x10AC) = zeroExtent;
        JOY_AT(float, 0x1044) = zeroExtent;
        JOY_AT(float, 0x1040) = zeroExtent;
        JOY_AT(float, 0x103C) = zeroExtent;
        JOY_AT(float, 0x1078) = zeroExtent;
        JOY_AT(float, 0x1074) = zeroExtent;
        JOY_AT(float, 0x1070) = zeroExtent;
        JOY_AT(float, 0x10A8) = zeroExtent;
        JOY_AT(float, 0x10A4) = zeroExtent;
        JOY_AT(float, 0x10B0) = zeroExtent;
        JOY_AT(int, 0x1024) = 0;
        float *pLeftMaxB = (float *)(pjoy + 0x1054);
        float *pLeftMaxA = (float *)(pjoy + 0x1088);
        float *pLeftMinB = (float *)(pjoy + 0x1050);
        float *pLeftMinA = (float *)(pjoy + 0x1084);
        unsigned int iAxis = 0;
        do {
            *pLeftMinA = -0.75f;
            iAxis += 1;
            *pLeftMinB = -0.75f;
            pLeftMinA += 2;
            *pLeftMaxA = 0.75f;
            pLeftMinB += 2;
            *pLeftMaxB = 0.75f;
            pLeftMaxA += 2;
            pLeftMaxB += 2;
        } while (iAxis < 4U);
    }
    char *defaultsBase = g_2dded0;
    JOY_AT(int, 0x100C) = joys;
    JOY_AT(int, 0x1010) = joyk;
    JOY_AT(float, 0x1014) = *(float *)(defaultsBase + 0x3C);
}
