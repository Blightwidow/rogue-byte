typedef int QW __attribute__((mode(TI)));
void *memcpy(void *, const void *, unsigned int); /* C++ linkage: extern "C" memcpy is a builtin */
void *memset(void *, int, unsigned int);
extern "C" {
void BuildXfAngularRateMatrix(QW *, char *, char *, QW, QW);
void BuildXfLinearRateMatrix(QW *, char *, QW);
void BuildXfSpinRateMatrix(QW *, char *, char *, QW);
QW DecomposeRotateMatrixEuler(char *);
void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
QW GetXfDofValue(char *, char *);
extern QW g_2a2dd0;
QW *GetXfLocalRateMatrix(QW *dest, char *xf) {
    QW result[8] __attribute__((aligned(16)));
    switch (*(short *)(xf + 0x98)) {
    case 0:
    case 3:
    case 10:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 19:
        memset(dest, 0, 0x40);
        break;
    default:
        switch (*(unsigned *)(xf + 0x94)) {
        case 0:
        case 2:
        case 3:
        case 13:
        case 15:
            break;
        case 8:
        case 14: {
            GetXfLocalRateMatrix(result, *(char **)(xf + 0xA8));
            memcpy(dest, result, 0x40);
            float *translation = (float *)dest;
            translation[12] = -translation[12];
            translation[13] = -translation[13];
            translation[14] = -translation[14];
            break;
        }
        case 6:
        case 7:
            switch ((short)(*(unsigned short *)(xf + 0x98) - 1)) {
            case 0: case 1: case 6: case 7: case 8: case 10: case 16: case 17: case 19: case 20:
                BuildXfSpinRateMatrix(result, xf, xf, *(QW *)(xf + 0xB0));
                memcpy(dest, result, 0x40);
                break;
            case 4:
            case 5: {
                short kind = *(short *)(xf + 0x9A);
                if (kind == 5) {
                    memset(dest, 0, 0x40);
                } else {
                    QW value;
                    QW extra;
                    switch (kind) {
                    case 0:
                        value = GetXfDofValue(xf, xf);
                        break;
                    case 1: {
                        float start = *(float *)(xf + 0x80);
                        EvaluateBezierPos__FfffP6VECTORN63(*(float *)(xf + 0x84) - start, **(float **)(xf + 0x88) - start, **(float **)(xf + 0x8C),
                            *(QW *)(xf + 0xC0), *(QW *)(xf + 0xD0), *(QW *)(xf + 0xE0), *(QW *)(xf + 0xF0), result, 0, 0);
                        value = result[0];
                        break;
                    }
                    case 2:
                    case 3:
                    case 4:
                        value = *(QW *)(xf + 0xC0);
                        break;
                    case 5:
                        value = DecomposeRotateMatrixEuler(xf + 0xC0);
                        break;
                    default:
                        value = g_2a2dd0;
                        break;
                    }
                    switch (*(short *)(xf + 0x9A)) {
                    case 3:
                    case 4:
                        extra = *(QW *)(xf + 0xD0);
                        break;
                    case 1: {
                        float start = *(float *)(xf + 0x80);
                        EvaluateBezierPos__FfffP6VECTORN63(*(float *)(xf + 0x84) - start, **(float **)(xf + 0x88) - start, **(float **)(xf + 0x8C),
                            *(QW *)(xf + 0xC0), *(QW *)(xf + 0xD0), *(QW *)(xf + 0xE0), *(QW *)(xf + 0xF0), 0, result, 0);
                        extra = result[0];
                        break;
                    }
                    case 0:
                    case 2:
                    case 5:
                    default:
                        extra = g_2a2dd0;
                        break;
                    }
                    BuildXfAngularRateMatrix(result, xf, xf, value, extra);
                    memcpy(dest, result, 0x40);
                }
                break;
            }
            }
            break;
        case 1:
        case 4:
        case 5:
        case 9:
        case 10:
        case 11:
        case 12:
            switch ((short)(*(unsigned short *)(xf + 0x98) - 1)) {
            case 0: case 1: case 6: case 7: case 8: case 10: case 16: case 17: case 19: case 20:
                result[0] = *(QW *)(xf + 0xB0);
                break;
            case 4:
            case 5: {
                QW linear;
                switch (*(short *)(xf + 0x9A)) {
                case 3:
                case 4:
                    linear = *(QW *)(xf + 0xD0);
                    break;
                case 1: {
                    float start = *(float *)(xf + 0x80);
                    EvaluateBezierPos__FfffP6VECTORN63(*(float *)(xf + 0x84) - start, **(float **)(xf + 0x88) - start, **(float **)(xf + 0x8C),
                        *(QW *)(xf + 0xC0), *(QW *)(xf + 0xD0), *(QW *)(xf + 0xE0), *(QW *)(xf + 0xF0), 0, result + 1, 0);
                    linear = result[1];
                    break;
                }
                case 0:
                case 2:
                case 5:
                default:
                    linear = g_2a2dd0;
                    break;
                }
                result[0] = linear;
                break;
            }
            }
            BuildXfLinearRateMatrix(result + 4, xf, result[0]);
            memcpy(dest, result + 4, 0x40);
            break;
        }
        break;
    }
    return dest;
}
}
