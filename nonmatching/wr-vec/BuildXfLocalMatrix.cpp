typedef int QW __attribute__((mode(TI)));
struct Mat3_22C8C0 { QW row[3]; };
void *memcpy(void *, const void *, unsigned int);
static inline float LaneOrdered(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
// lane 2 of q moved to lane 0 (the zero operand is the $0 register)
static inline QW UpperWord(QW q) { QW r; asm("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
// lane 0 of q stored as a word: sw of the general register that holds the vector (C has no form without dsll32/dsra32)
static inline void Store0(char *address, QW q) { asm("sw %1, %0" : "=m"(*(int *)address) : "r"(q)); }
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
        float lane2 = LaneOrdered(UpperWord(vec));
        float lane1 = LaneOrdered(__builtin_prot3w(vec));
        Store0(dest + 0x30, vec);
        *(float *)(dest + 0x38) = lane2;
        *(float *)(dest + 0x34) = lane1;
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
        float lane2 = LaneOrdered(UpperWord(vec));
        float lane1 = LaneOrdered(__builtin_prot3w(vec));
        Store0(dest + 0x10, vec);
        *(float *)(dest + 0x24) = lane2;
        *(float *)(dest + 0x20) = lane1;
        break;
    }
    case 12: {
        memcpy(dest, source, 0x40);
        Store0(dest, vec);
        float lane2 = LaneOrdered(UpperWord(vec));
        float lane1 = LaneOrdered(__builtin_prot3w(vec));
        *(float *)(dest + 0x28) = lane2;
        *(float *)(dest + 0x14) = lane1;
        break;
    }
    case 0:
    case 8:
    case 13:
    case 14:
    case 15:
        break;
    }
    return dest;
}
}
