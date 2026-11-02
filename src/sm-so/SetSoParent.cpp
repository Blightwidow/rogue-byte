#include "sly2.h"
struct XFN { char pad0[0x40]; MATRIX4 mat; char pad80[0x20]; XFN *next; };
struct PARENT { char pad0[0x50]; int count; int base; char pad58[0xF0]; unsigned long grf; };
struct SO;
struct VE8 { char pad[0xE8]; short d; short i; void (*f)(void *, QW); };
struct VF0 { char pad[0xF0]; short d; short i; void (*f)(void *, MATRIX4 *); };
struct V108 { char pad[0x108]; short d; short i; QW (*f)(void *); };
struct V110 { char pad[0x110]; short d; short i; QW (*f)(void *); };
struct V118 { char pad[0x118]; short d; short i; void (*f)(void *, QW); };
struct V120 { char pad[0x120]; short d; short i; void (*f)(void *, QW); };
struct SO { char pad0[0xC]; char *vt; PARENT *owner; char pad14[0x14]; unsigned long grf; char pad30[0x20]; int count; char *items; char pad58[8]; XFN *xf; };
extern "C" {
void SetLoParent(SO *, SO *, int, int);
void UpdateAloXfWorld(SO *);
void __ml__FRC7MATRIX4T0(MATRIX4 *, void *, MATRIX4 *);
void func_001F2468(SO *);
void func_001F26A8(SO *);
void func_001F8668(SO *, int);
void SetSoParent(SO *self, SO *newParent, int arg2, int arg3)
{
    MATRIX4 mat;
    QW pos;
    QW vel;
    QW pos2;
    if (arg3 & 3) {
        if ((int)(self->grf >> 60) & 1) {
            mat = *(MATRIX4 *)((char *)self->xf + 0x40);
        } else {
            memset(&mat, 0, 0x40);
            XFN *node = self->xf;
            mat.mat[3][3] = 1.0f; //P
            mat.mat[2][2] = 1.0f; //P
            mat.mat[1][1] = 1.0f; //P
            mat.mat[0][0] = 1.0f; //P
            if (node != 0) {
                do {
                    MATRIX4 product;
                    __ml__FRC7MATRIX4T0(&product, node, &mat);
                    mat = product;
                    node = node->next;
                } while (node != 0);
            }
        }
    }
    int flag4 = arg3 & 4;
    if (flag4 != 0) {
        V108 *vtable = (V108 *)self->vt;
        pos = vtable->f((char *)self + vtable->d);
    }
    int flag8 = arg3 & 8;
    if (flag8 != 0) {
        V110 *vtable = (V110 *)self->vt;
        vel = vtable->f((char *)self + vtable->d);
    }
    PARENT *owner = self->owner;
    int rangeCount;
    int rangeBase;
    if (owner != 0) {
        rangeCount = owner->count;
        rangeBase = owner->base;
    } else {
        rangeCount = 1;
        rangeBase = 0;
    }
    int value;
    if (arg2 != 0)
        value = arg2;
    else if (newParent != 0)
        value = *(int *)((char *)newParent + 0x60);
    else
        value = 0;
    int index = 0;
    if (self->count > 0) {
        do {
            int *slot = (int *)(self->items + (index << 8) + 0xA0);
            int rel = (*slot - rangeBase) >> 8;
            if (rel >= 0 && rel < rangeCount)
                *slot = value;
            index++;
        } while (index < self->count);
    }
    SetLoParent(self, newParent, arg2, arg3);
    UpdateAloXfWorld(self);
    if (arg3 & 1) {
        VE8 *vtable = (VE8 *)self->vt;
        vtable->f((char *)self + vtable->d, *(QW *)&mat.mat[3][0]);
    }
    if (arg3 & 2) {
        VF0 *vtable = (VF0 *)self->vt;
        vtable->f((char *)self + vtable->d, &mat);
    }
    if (flag4 != 0) {
        V118 *vtable = (V118 *)self->vt;
        vtable->f((char *)self + vtable->d, pos);
    }
    if (flag8 != 0) {
        V120 *vtable = (V120 *)self->vt;
        vtable->f((char *)self + vtable->d, vel);
    }
    func_001F2468(self);
    func_001F26A8(self);
    PARENT *owner2 = self->owner;
    if (owner2 != 0 && !(owner2->grf & (0x8000UL << 20)))
        func_001F8668(self, 0);
}
}
