typedef signed char s8;
typedef int s32;
typedef int QW __attribute__((mode(TI)));
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
struct M3 { QW row[3]; };
struct VjoyFrame { M3 matrix; float pitch; float tilt; };
extern "C" {
extern int g_2dfbc0;
extern s8 B_002DFC00[];
extern s8 B_002E0D00[];
extern s8 g_2ddfa0[];
void ResetVjoy(void *);
M3 *LoadRotateMatrixPanTilt(M3 *, float, float);
void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(void *, float *, float *);
void UpdateVjoyStick(float, void *, float *, float *, float *, float *, float *);
void UpdateVjoyPressTimes(void *);
}
extern "C" void UpdateVjoy(s8 *pvjoy)
{
    VjoyFrame l;
    float zeroAngle = 0.0f;
    l.tilt = zeroAngle;
    l.pitch = zeroAngle;
    s32 mode = M2C_FIELD(pvjoy, s32 *, 0x80);
    switch (mode) {
    case 0:
        ResetVjoy(pvjoy);
        break;
    case 1: {
        s8 *pcfg = (g_2dfbc0 & 2) ? B_002DFC00 : B_002E0D00;
        M2C_FIELD(pvjoy, float *, 0x10) = M2C_FIELD(pcfg, float *, 0x103C);
        M2C_FIELD(pvjoy, float *, 0x14) = M2C_FIELD(pcfg, float *, 0x1040);
        M2C_FIELD(pvjoy, float *, 0x20) = M2C_FIELD(pcfg, float *, 0x1070);
        M2C_FIELD(pvjoy, float *, 0x24) = M2C_FIELD(pcfg, float *, 0x1074);
        s8 *ptarget = M2C_FIELD(pvjoy, s8 **, 0x7C);
        M2C_FIELD(pvjoy, s32 *, 0x30) = (M2C_FIELD(pcfg, s32 *, 0x10B4) & ~M2C_FIELD(pcfg, s32 *, 0x10BC)) | M2C_FIELD(ptarget, s32 *, 0x154);
        DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(g_2ddfa0, &l.pitch, &l.tilt);
        break;
    }
    }
    LoadRotateMatrixPanTilt(&l.matrix, l.pitch, l.tilt);
    QW matrixRow2 = l.matrix.row[2];
    QW matrixRow1 = l.matrix.row[1];
    QW matrixRow0 = l.matrix.row[0];
    M2C_FIELD(pvjoy, QW *, 0x40) = matrixRow0;
    M2C_FIELD(pvjoy, QW *, 0x50) = matrixRow1;
    M2C_FIELD(pvjoy, QW *, 0x60) = matrixRow2;
    UpdateVjoyStick(l.pitch, pvjoy, (float *)(pvjoy + 0x10), (float *)(pvjoy + 0x14), (float *)(pvjoy + 0x18), (float *)(pvjoy + 0x1C), (float *)(pvjoy + 0x70));
    UpdateVjoyStick(l.pitch, pvjoy, (float *)(pvjoy + 0x20), (float *)(pvjoy + 0x24), (float *)(pvjoy + 0x28), (float *)(pvjoy + 0x2C), (float *)(pvjoy + 0x74));
    UpdateVjoyPressTimes(pvjoy);
}
