typedef int QW __attribute__((mode(TI)));
struct Mat_2314D0 { QW row[4]; };
extern "C" {
void func_0022D148(Mat_2314D0 *, int, int);
extern QW g_2a2dd0;
QW GetXfmAngularVelocity(char *self) {
    int source = *(int *)(self + 0x50);
    QW out;
    if (source != 0) {
        Mat_2314D0 matrix;
        Mat_2314D0 raw;
        func_0022D148(&raw, source, 0);
        matrix = raw;
        float *cells = (float *)&matrix;
        float first = cells[6];
        float second = cells[8];
        float third = cells[1];
        int firstBits, secondBits, thirdBits;
        QW low, result;
        asm("mfc1 %0, %1" : "=r"(firstBits) : "f"(first));
        asm("mfc1 %0, %1" : "=r"(secondBits) : "f"(second));
        asm("pextlw %0, %1, %2" : "=r"(low) : "r"(secondBits), "r"(firstBits));
        asm("mfc1 %0, %1" : "=r"(thirdBits) : "f"(third));
        asm("pcpyld %0, %1, %2" : "=r"(result) : "r"(thirdBits), "r"(low));
        out = result;
    } else {
        out = g_2a2dd0;
    }
    return out;
}
}
