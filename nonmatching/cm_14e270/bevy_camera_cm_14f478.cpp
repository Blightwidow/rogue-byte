#include "sly2.h"
// provisional: the three lane-move asms below are volatile to keep retail's order of the lane moves (pextuw, mtc1 z, mtc1 x, prot3w, mtc1 y)
/* lane 0 of a QW into a float */
static inline float Lane0_14F478(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* lane 1 brought to lane 0 */
static inline QW Rot1_14F478(QW q) { QW t; asm volatile("prot3w %0, %1" : "=r" (t) : "r" (q)); return t; }
/* lane 2 brought to lane 0 */
static inline QW Upper_14F478(QW q) { QW t; asm volatile("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); return t; }
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3_14F478(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
extern "C" {
QW DecomposeRotateMatrixEuler(void *);
QW bevy_camera_cm_14f478(char *camera)
{
    struct { float x, y, z, w; } v;
    QW euler = DecomposeRotateMatrixEuler(camera + 0x60);
    QW upper = Upper_14F478(euler);
    float k = 57.295776f;
    float z = Lane0_14F478(upper);
    float x = Lane0_14F478(euler);
    QW rot = Rot1_14F478(euler);
    x = x * k;
    float y = Lane0_14F478(rot);
    *(QW *)&v = Vec3_14F478(x, y * k, z * k);
    return *(QW *)&v;
}
}
