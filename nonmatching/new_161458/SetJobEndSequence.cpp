struct V;
struct VT {
    char pad0[0x188];
    short delta188; short unused188; void (*fn18C)(void *, int, void *);
    short delta190; short unused190; void (*fn194)(void *, void *);
};
struct V { char pad0[0xC]; VT *vt; };
struct OBJ {
    char pad0[0x40]; int tagged;
    char pad1[0x68 - 0x44]; OBJ *owner;
    char pad2[0x94 - 0x6C]; int cdeps; int *deps; char padA[4]; int cmembers; OBJ **members;
    char pad3[0xB0 - 0xA8]; int seqA; int seqB; V *vB8; V *vBC; OBJ *pick; int state; float timer;
};
extern "C" {
void ClearHandsOff(void *, int);
int FTaskComplete(int);
void SetHandsOff(void *, int);
void func_001A6CA8(OBJ *, int);
void func_00213B00(V *, int);
extern char B_003DD490[];
extern float g_2dded0;
void SetJobEndSequence(OBJ *self, int arg1) {
    if (self->state == arg1) return;
    if (self->state == 0) {
        self->pick = 0;
        for (int index = 0; index < self->owner->cmembers; index++) {
            OBJ *member = self->owner->members[index];
            if (member->state != 0) {
                self->pick = member;
                break;
            }
        }
        if (self->pick != 0) {
            int dep;
            for (dep = 0; dep < self->pick->cdeps; dep++) {
                int other = self->pick->deps[dep];
                if (other == (int)self->owner) continue;
                if (FTaskComplete(other) == 0) {
                    self->pick = 0;
                    break;
                }
            }
        }
        func_001A6CA8(self, 1);
        {
            int raw = self->tagged;
            if ((raw ^ 1) & 1)
                *(int *)raw = *(int *)raw | 0x102;
            else
                self->tagged = raw | 0x102;
        }
        SetHandsOff(B_003DD490 + 0, 2);
    }
    self->state = arg1;
    self->timer = g_2dded0;
    switch (arg1) {
    case 0: {
        V *objC = self->vBC;
        if (objC != 0) {
            VT *vt = objC->vt;
            vt->fn194((char *)objC + vt->delta190, objC);
        }
        V *objB = self->vB8;
        if (objB != 0) {
            VT *vt = objB->vt;
            vt->fn194((char *)objB + vt->delta190, objB);
        }
        func_001A6CA8(self, 2);
        {
            int raw = self->tagged;
            if ((raw ^ 1) & 1)
                *(int *)raw = *(int *)raw & ~0x102;
            else
                self->tagged = raw & ~0x102;
        }
        ClearHandsOff(B_003DD490, 2);
        return;
    }
    case 3: {
        V *objC = self->vBC;
        VT *vt = objC->vt;
        vt->fn18C((char *)objC + vt->delta188, -1, objC);
        return;
    }
    case 1: {
        V *objB = self->vB8;
        VT *vt = objB->vt;
        vt->fn18C((char *)objB + vt->delta188, -1, objB);
        func_00213B00(self->vB8, self->seqA);
        return;
    }
    case 2:
        func_00213B00(self->vB8, self->seqB);
        break;
    }
}
}
