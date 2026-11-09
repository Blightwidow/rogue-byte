// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct P12 { char pad[12]; };
struct VA : P12 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void exitA(int);
    virtual void exitB();
};
struct VBB : P12 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual int getMatrix(void *);
};
struct VB : VBB {
    int id;
};
#include "xf.h"
struct SMAREC { int oid; int pad[5]; };
struct SLOT { char pad[16]; };
struct CLOCK { float t; float dt; };
struct MBASE : P12 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void place(int, int, int);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void setA(QW);
    virtual void setB(QW);
};
struct MOUNT : MBASE {
    char pad10[0x54 - 0x10];
    XF *pxfA; XF *pxfB; XF *pxfC;
    char pad60[0x1C0 - 0x60];
    int state;
    float timer;
    char pad1C8[0x230 - 0x1C8];
    int csma;
    char pad234[0x248 - 0x234];
    int asma[1];
    char pad24C[0x294 - 0x24C];
    VB *pobjB;
    int hA;
    int hB;
    VA *pobjA;
    int ref;
    int idEmitter;
};
extern "C" {
extern char B_002DEB30;
extern QW g_2a2dd0;
extern CLOCK g_2dded0;
void ConvertXfMatrix4(MATRIX4 *, XF *, XF *, void *);
QW DecomposeRotateMatrixEuler(void *);
void Mount_UpdateHealthBlot(MOUNT *);
int NewEmitter(int);
void PauseAmb(int);
void SetEmitterUnpositioned(int, int);
void SetSmaGoal__FP3SMA3OID(int, int);
void SetSoCnstrForce(MOUNT *, int);
void SetSoCnstrTorque(MOUNT *, int);
void SetXfKind(MOUNT *, XF *, int);
void StopAmb(int, float);
void VirtualRefPtr_Assign(int *, int);
void bevy_camera_follow_activity(void *, int, MOUNT *);
int func_0012DC18(MOUNT *, XF *, int, int, int, QW);
void func_0012E460(int *);
void func_0017F4C0(MOUNT *, SLOT *);
void func_001A58D0(MOUNT *, int, int);
void func_001F68A8(MOUNT *, int);
void func_00213B00(VA *, int);
}

// Retail reads the state at 0x1C0 and stores the new one there, then the clock time at
// 0x1C4 and the per-state slots from 0x1C8 (sll 4 + 0x1C8), so state/timer sit together
// before the slots. The clock global 0x2DDED0 is read as the first float of a struct
// (time, dt) as in SetBentleyState: as a plain float, gcc hoists its lwc1 above the state
// store into every branch delay slot; a struct member load keeps retail's order
// (sw state, then lwc1 time).
extern "C" void Mount_SetState(MOUNT *self, int newState)
{
    int stateOld = self->state;
    if (newState == stateOld)
        return;
    switch (stateOld) {
    case -1: {
        VA *pobj = self->pobjA;
        if (pobj != 0) {
            pobj->exitA(-1);
            func_00213B00(self->pobjA, 0x34F);
            Mount_UpdateHealthBlot(self);
            if (self->idEmitter != -1) {
                int emitter = NewEmitter(self->idEmitter);
                SetEmitterUnpositioned(emitter, 0);
                VirtualRefPtr_Assign(&self->ref, emitter);
                PauseAmb(self->ref);
            }
        }
        break;
    }
    case 3:
        func_0012E460(&self->hA);
        func_0012E460(&self->hB);
        SetXfKind(self, self->pxfB, 2);
        SetXfKind(self, self->pxfC, 2);
        func_001A58D0(self, 0, 0xF);
        SetSoCnstrForce(self, 5);
        SetSoCnstrTorque(self, 4);
        func_001F68A8(self, 0);
        self->pobjB = 0;
        break;
    case 1: {
        int index = 0;
        if (self->csma > 0) {
            int *psma = self->asma;
            do {
                if (*psma != 0)
                    SetSmaGoal__FP3SMA3OID(*psma, 0x66);
                index += 1;
                psma += 6;
            } while (index < self->csma);
        }
        break;
    }
    }
    self->state = newState;
    self->timer = g_2dded0.t;
    switch (newState) {
    case -1: {
        VA *pobj = self->pobjA;
        if (pobj != 0)
            pobj->exitB();
        int *pref = &self->ref;
        if (*pref != 0) {
            StopAmb(*pref, 0.0f);
            VirtualRefPtr_Assign(pref, 0);
        }
        break;
    }
    case 3: {
        MATRIX4 world;
        MATRIX4 matrix;
        int handle = self->pobjB->getMatrix(&world);
        ConvertXfMatrix4(&matrix, self->pxfA->pxfParent, self->pxfB->pxfParent, &world);
        world = matrix;
        self->place(self->pobjB->id, handle, 3);
        self->setA(g_2a2dd0);
        self->setB(g_2a2dd0);
        self->hA = func_0012DC18(self, self->pxfB, 1, 7, 2, *(QW *)&world.mat[3][0]);
        QW euler = DecomposeRotateMatrixEuler(&world);
        self->hB = func_0012DC18(self, self->pxfC, 1, 7, 2, euler);
        SetSoCnstrForce(self, 1);
        SetSoCnstrTorque(self, 1);
        func_001F68A8(self, 1);
        break;
    }
    case 4:
        bevy_camera_follow_activity(&B_002DEB30, 0x10, self);
        break;
    }
    func_0017F4C0(self, newState != -1 ? (SLOT *)((char *)self + (newState * 0x10 + 0x1C8)) : 0);
}
