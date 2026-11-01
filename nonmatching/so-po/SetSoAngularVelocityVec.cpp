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
    QW current;
    QW angular;
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
    frame.angular = angular;
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
            frame.current = virt->vptr->fn((char *)self + virt->vptr->delta);
            frame.rotation = *bodyMatrix;
            NormalizeRotateMatrix3__FP7MATRIX3(&frame.rotation);
            InvertMatrix3(&frame.inverse, &frame.rotation);
            asm volatile("lqc2 vf1, 0xd0(%0)" : : "r"(SP));
            asm volatile("lqc2 vf2, 0xc0(%0)" : : "r"(SP));
            asm volatile("vsub.xyzw vf7, vf1, vf2");
            asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(bodyMatrix));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(bodyMatrix));
            asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(body));
            asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(SP));
            asm volatile("lqc2 vf4, 0x70(%0)" : : "r"(SP));
            asm volatile("vmulax.xyz ACC, vf1, vf3x");
            asm volatile("vmadday.xyz ACC, vf2, vf3y");
            asm volatile("vmaddz.xyz vf3, vf6, vf3z");
            asm volatile("vmulax.xyz ACC, vf1, vf4x");
            asm volatile("vmadday.xyz ACC, vf2, vf4y");
            asm volatile("vmaddz.xyz vf4, vf6, vf4z");
            asm volatile("lqc2 vf5, 0x80(%0)" : : "r"(SP));
            asm volatile("vmulax.xyz ACC, vf1, vf5x");
            asm volatile("vmadday.xyz ACC, vf2, vf5y");
            asm volatile("vmaddz.xyz vf1, vf6, vf5z");
            asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(SP));
            asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(SP));
            asm volatile("vmulax.xyz ACC, vf3, vf7x");
            asm volatile("vmadday.xyz ACC, vf4, vf7y");
            asm volatile("vmaddz.xyz vf2, vf1, vf7z");
            asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(SP));
            asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(SP));
            QW delta;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(delta));
            QW result = ConvertXfVec(0, body->xfId, delta);
            asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(SP));
            asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(SP));
            body->velocity = result;
            WakeXf(self, body);
            func_001F4BF8(self);
            func_001F5078(self);
            func_001F8668(self, 0);
        }
    }
}
