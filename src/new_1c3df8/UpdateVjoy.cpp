// SPDX-License-Identifier: GPL-3.0-or-later
struct MATRIX3 { float mat[3][4]; } __attribute__((aligned(16)));

struct TARGET {
    char field0[0x154];
    int field154;
};

struct VJOYCONFIG {
    char field0[0x103C];
    float field103C;
    float field1040;
    char field1044[0x1070 - 0x1044];
    float field1070;
    float field1074;
    char field1078[0x10B4 - 0x1078];
    int field10B4;
    int field10B8;
    int field10BC;
};

struct VJOY {
    char field0[0x10];
    float field10;
    float field14;
    float field18;
    float field1C;
    float field20;
    float field24;
    float field28;
    float field2C;
    int field30;
    char field34[0x40 - 0x34];
    MATRIX3 matrix;
    float field70;
    float field74;
    int field78;
    TARGET *field7C;
    int field80;
};

extern "C" {
extern int g_2dfbc0;
extern VJOYCONFIG B_002DFC00;
extern VJOYCONFIG B_002E0D00;
extern MATRIX3 g_2ddfa0;
void ResetVjoy(VJOY *pvjoy);
MATRIX3 LoadRotateMatrixPanTilt(float pan, float tilt);
void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(MATRIX3 *pmat, float *ppan, float *ptilt);
void UpdateVjoyStick(float pan, VJOY *pvjoy, float *px, float *py, float *pdx, float *pdy, float *pout);
void UpdateVjoyPressTimes(VJOY *pvjoy);
}

// Choices: LoadRotateMatrixPanTilt returns MATRIX3 by value (retail copies into the hidden pointer in $a0 and returns it); MATRIX3 is
// 16-byte aligned so the copy is lq/sq, not memcpy (this unit declares its own, the shared header's is 4-byte aligned); `pan = tilt = 0.0f`
// gives retail's store order.
extern "C" void UpdateVjoy(VJOY *pvjoy)
{
    float pan;
    float tilt;

    pan = tilt = 0.0f;

    switch (pvjoy->field80) {
    case 0:
        ResetVjoy(pvjoy);
        break;
    case 1: {
        VJOYCONFIG *pconfig = (g_2dfbc0 & 2) ? &B_002DFC00 : &B_002E0D00;
        pvjoy->field10 = pconfig->field103C;
        pvjoy->field14 = pconfig->field1040;
        pvjoy->field20 = pconfig->field1070;
        pvjoy->field24 = pconfig->field1074;
        pvjoy->field30 = (pconfig->field10B4 & ~pconfig->field10BC) | pvjoy->field7C->field154;
        DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(&g_2ddfa0, &pan, &tilt);
        break;
    }
    }
    pvjoy->matrix = LoadRotateMatrixPanTilt(pan, tilt);
    UpdateVjoyStick(pan, pvjoy, &pvjoy->field10, &pvjoy->field14, &pvjoy->field18, &pvjoy->field1C, &pvjoy->field70);
    UpdateVjoyStick(pan, pvjoy, &pvjoy->field20, &pvjoy->field24, &pvjoy->field28, &pvjoy->field2C, &pvjoy->field74);
    UpdateVjoyPressTimes(pvjoy);
}
