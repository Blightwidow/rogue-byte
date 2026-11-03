// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct Vt1E4D40 {
    char pad0[0xF8];
    short delta;
    short index;
    float *(*getPos)(void *);
};
struct Basic1E4D40 {
    char pad0[0xC];
    Vt1E4D40 *vptr;
};
struct Seqnode1E4D40 {
    char pad0[0x24];
    Basic1E4D40 *object;
    char pad1[0x44 - 0x28];
    Basic1E4D40 *fallback;
};
struct Frame1E4D40 {
    QW position;
    float closestX;
    float closestY;
};
extern "C" {
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
void FindCrvClosestPointAll(void *, QW, int, void *, float *, int, int);
float atan2f(float, float);
}
extern "C" void GetSeqnodeObjectPosRad(Seqnode1E4D40 *node, Basic1E4D40 *curveObject, QW *outPosition, float *outRadians)
{
    Frame1E4D40 frame;
    float radians;
    Basic1E4D40 *object = node->object;
    if (object == 0)
        object = node->fallback;
    if (curveObject != 0) {
        if (FIsBasicDerivedFrom(curveObject, 0xA) != 0) {
            FindCrvClosestPointAll(curveObject, PosLoWorld(object), 0, &frame, &frame.closestX, 0, 0);
            radians = atan2f(frame.closestY, frame.closestX);
        } else {
            frame.position = PosLoWorld(curveObject);
            float *forward = curveObject->vptr->getPos((char *)curveObject + curveObject->vptr->delta);
            radians = atan2f(forward[1], *curveObject->vptr->getPos((char *)curveObject + curveObject->vptr->delta));
        }
    } else {
        frame.position = PosLoWorld(object);
        int isCamera = FIsBasicDerivedFrom(object, 0x33);
        if (isCamera != 0) {
            QW sum;
            QW offset = *(QW *)((char *)object + 0x240);
            asm("vadd.xyzw %0, %1, %2" : "=j"(sum) : "j"(frame.position), "j"(offset));
            frame.position = sum;
            radians = *(float *)((char *)object + 0x1A8);
        } else {
            float *forward = object->vptr->getPos((char *)object + object->vptr->delta);
            radians = atan2f(forward[1], *object->vptr->getPos((char *)object + object->vptr->delta));
        }
    }
    if (outPosition != 0)
        *outPosition = frame.position;
    if (outRadians != 0)
        *outRadians = radians;
}
