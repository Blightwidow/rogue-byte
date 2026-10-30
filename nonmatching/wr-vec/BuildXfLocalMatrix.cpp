typedef int QW __attribute__((mode(TI)));
struct Mat3_22C8C0 { QW row[3]; };
void *memcpy(void *, const void *, unsigned int); /* C++ linkage on purpose: extern "C" memcpy is a builtin */
extern "C" {
void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(void *, QW);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
char *BuildXfLocalMatrix(char *dest, char *source, QW vec) {
    switch (*(unsigned *)(source + 0x94)) {
    case 1:
    case 4:
    case 5:
    case 9:
    case 10: {
        memcpy(dest, source, 0x40);
        int z, y;
        asm("pextuw %0, %1, %2" : "=r"(z) : "r"(0), "r"(vec));
        *(int *)(dest + 0x30) = (int)vec;
        asm("prot3w %0, %1" : "=r"(y) : "r"(vec));
        *(int *)(dest + 0x38) = z;
        *(int *)(dest + 0x34) = y;
        break;
    }
    case 2:
    case 3:
        memcpy(dest, source, 0x40);
        break;
    case 6:
    case 7: {
        Mat3_22C8C0 rotation;
        LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&rotation, vec);
        __as__6VECTORG9VU_VECTOR(dest + 0x30, *(QW *)(source + 0x30));
        *(Mat3_22C8C0 *)dest = rotation;
        *(float *)(dest + 0x3C) = 1.0f;
        *(int *)(dest + 0x2C) = 0;
        *(int *)(dest + 0x1C) = 0;
        *(int *)(dest + 0xC) = 0;
        break;
    }
    case 11: {
        memcpy(dest, source, 0x40);
        int z, y;
        asm("pextuw %0, %1, %2" : "=r"(z) : "r"(0), "r"(vec));
        *(QW *)(dest + 0x10) = vec;
        asm("prot3w %0, %1" : "=r"(y) : "r"(vec));
        *(int *)(dest + 0x24) = z;
        *(int *)(dest + 0x20) = y;
        break;
    }
    case 12: {
        memcpy(dest, source, 0x40);
        int z, y;
        asm("pextuw %0, %1, %2" : "=r"(z) : "r"(0), "r"(vec));
        *(QW *)dest = vec;
        asm("prot3w %0, %1" : "=r"(y) : "r"(vec));
        *(int *)(dest + 0x28) = z;
        *(int *)(dest + 0x14) = y;
        break;
    }
    }
    return dest;
}
}
