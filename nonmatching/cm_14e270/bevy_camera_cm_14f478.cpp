#include "sly2.h"
union QV14F478 { QW quad; float lane[4]; };
extern "C" {
QW DecomposeRotateMatrixEuler(void *);
QW bevy_camera_cm_14f478(char *camera)
{
    QV14F478 euler;
    QV14F478 degrees;
    euler.quad = DecomposeRotateMatrixEuler(camera + 0x60);
    degrees.lane[0] = euler.lane[0] * 57.295776f;
    degrees.lane[1] = euler.lane[1] * 57.295776f;
    degrees.lane[2] = euler.lane[2] * 57.295776f;
    return degrees.quad;
}
}
