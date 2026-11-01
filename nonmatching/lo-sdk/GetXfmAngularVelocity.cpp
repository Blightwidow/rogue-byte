// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct Mat_2314D0 { QW row[4]; };
// Builds (x, y, z, 0): mfc1 each float into a GPR, pextlw packs x,y, pcpyld adds z (lane 2).
static inline QW Build(float x, float y, float z)
{
    QW result;
    QW low;
    asm("mfc1 %0, %1" : "=r"(low) : "f"(x));
    asm("mfc1 %0, %1" : "=r"(result) : "f"(y));
    low = __builtin_pextlw(result, low);
    asm("mfc1 %0, %1" : "=r"(result) : "f"(z));
    return __builtin_pcpyld(result, low);
}
extern "C" {
void func_0022D148(Mat_2314D0 *, int, int);
extern QW g_2a2dd0;
QW GetXfmAngularVelocity(char *self) {
    int source = *(int *)(self + 0x50);
    if (source == 0)
        return g_2a2dd0;
    Mat_2314D0 matrix;
    Mat_2314D0 raw;
    func_0022D148(&raw, source, 0);
    matrix = raw;
    float *cells = (float *)&matrix;
    QW result = Build(cells[6], cells[8], cells[1]);
    raw.row[0] = result;
    return result;
}
}
