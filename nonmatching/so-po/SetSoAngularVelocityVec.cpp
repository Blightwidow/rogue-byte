// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct Mat_1F46D8 { QW row[3]; };
struct Body_1F46D8 {
    char pad0[0x40];
    Mat_1F46D8 matrix;
    char pad1[0x94 - 0x70];
    int kind;
    short xfKind;
    char pad2[0xA0 - 0x9A];
    int xfId;
    char pad3[0xB0 - 0xA4];
    QW velocity;
};
struct Obj_1F46D8 { char pad[0x5C]; Body_1F46D8 *body; };
struct Frame_1F46D8 {
    Mat_1F46D8 rotation;
    Mat_1F46D8 other;
    Mat_1F46D8 inverse;
    QW spare[3];
};
extern "C" {
int FXfKindHasVelocity(int);
void SetXfKind(Obj_1F46D8 *, Body_1F46D8 *, int);
void InvertMatrix3(void *, void *);
void NormalizeRotateMatrix3__FP7MATRIX3(Mat_1F46D8 *);
QW ConvertXfVec(int, int, QW);
void WakeXf(Obj_1F46D8 *, Body_1F46D8 *);
void func_001F4BF8(Obj_1F46D8 *);
void func_001F5078(Obj_1F46D8 *);
void func_001F8668(Obj_1F46D8 *, int);
}
struct Vt_1F46D8 {
    char pad[0x110];
    short delta;
    short index;
    QW (*fn)(void *);
};
struct Virt_1F46D8 { char pad[0xC]; Vt_1F46D8 *vptr; };
#define SP ((char *)&frame)
extern "C" void SetSoAngularVelocityVec(Obj_1F46D8 *self, QW angular)
{
    Frame_1F46D8 frame;
    Body_1F46D8 *body = self->body;
    if (body != 0) {
        if (body->kind == 6) {
            if (FXfKindHasVelocity(body->xfKind) == 0)
                SetXfKind(self, body, 1);
            int *clear = (int *)&body->velocity;
            clear[1] = clear[2] = 0;
            *(int *)&body->velocity = 0;
            Mat_1F46D8 *bodyMatrix = &body->matrix;
            Virt_1F46D8 *virt = (Virt_1F46D8 *)self;
            QW current = virt->vptr->fn((char *)self + virt->vptr->delta);
            frame.rotation = *bodyMatrix;
            NormalizeRotateMatrix3__FP7MATRIX3(&frame.rotation);
            InvertMatrix3(&frame.inverse, &frame.rotation);
            QW delta;
            asm("lqc2 vf1, %8
"
                "lqc2 vf2, %7
"
                "vsub.xyzw vf7, vf1, vf2
"
                "lqc2 vf6, 0x20(%4)
"
                "lqc2 vf2, 0x10(%4)
"
                "lqc2 vf1, 0x40(%5)
"
                "lqc2 vf3, 0x60(%3)
"
                "lqc2 vf4, 0x70(%3)
"
                "vmulax.xyz ACC, vf1, vf3x
"
                "vmadday.xyz ACC, vf2, vf3y
"
                "vmaddz.xyz vf3, vf6, vf3z
"
                "vmulax.xyz ACC, vf1, vf4x
"
                "vmadday.xyz ACC, vf2, vf4y
"
                "vmaddz.xyz vf4, vf6, vf4z
"
                "lqc2 vf5, 0x80(%3)
"
                "vmulax.xyz ACC, vf1, vf5x
"
                "vmadday.xyz ACC, vf2, vf5y
"
                "vmaddz.xyz vf1, vf6, vf5z
"
                "sqc2 vf3, 0x30(%3)
"
                "sqc2 vf4, 0x40(%3)
"
                "vmulax.xyz ACC, vf3, vf7x
"
                "vmadday.xyz ACC, vf4, vf7y
"
                "vmaddz.xyz vf2, vf1, vf7z
"
                "sqc2 vf1, 0x50(%3)
"
                "sqc2 vf3, 0x90(%3)
"
                "qmfc2.ni %0, vf2"
                : "=r"(delta), "=m"(frame.other), "=m"(frame.spare[0])
                : "r"(SP), "r"(bodyMatrix), "r"(body), "m"(frame.inverse), "m"(current), "m"(angular));
            int xfId = body->xfId;
            asm("sqc2 vf4, %0
"
                "sqc2 vf1, %1"
                : "=m"(frame.spare[1]), "=m"(frame.spare[2]));
            QW result = ConvertXfVec(0, xfId, delta);
            body->velocity = result;
            WakeXf(self, body);
            func_001F4BF8(self);
            func_001F5078(self);
            func_001F8668(self, 0);
        }
    }
}
