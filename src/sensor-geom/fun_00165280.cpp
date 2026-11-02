#include "sly2.h"
struct CRefX { int tagk; int n; int pad[2]; };
struct TASK { char pad0[0x18]; int oid; char pad1c[0x7C - 0x1C]; TASK *pparent; char pad80[0xB8 - 0x80]; int fB8; char padBC[4]; int fC0; char padC4[0xF0 - 0xC4]; int fF0; int fF4; int fF8; };
struct JOBMGR { char pad0[0x10]; int fieldA; int fieldB; int oid; };
struct SW { char pad[0x3BF4]; int flags; char pad3BF8[0x3C38 - 0x3BF8]; int fieldC; int fieldD; };
struct CTaskHold {
    TASK *pother;
    TASK *ptask;
    int saveF4;
    int saveF8;
    CTaskHold(TASK *task, int value)
    {
        pother = 0;
        ptask = task;
        if (ptask != 0) {
            saveF4 = ptask->fF4;
            ptask->fF4 = value;
            saveF8 = ptask->fF8;
            ptask->fF8 = 0;
        }
    }
    ~CTaskHold()
    {
        if (pother != 0) {
            pother->fF0 = saveF4;
            pother->fF4 = saveF8;
        }
        if (ptask != 0) {
            ptask->fF4 = saveF4;
            ptask->fF8 = saveF8;
        }
    }
};
extern "C" {
extern SW B_003DD490;
extern const char RO_002A5238[];
void CRef_Destruct(CRefX *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void OrderTasks(int *, TASK ***);
TASK *PloFindSwObject_thunk(SW *, int, int, void *);
void RestoreTaskStateFromSave(TASK *);
void SetTaskState(TASK *, int);
void ApplyTaskState(TASK *, int);
void func_001D8B20(CRefX *, CRefX *, const char *, int);
}
extern "C" void func_00165280(JOBMGR *self)
{
    if (!(B_003DD490.flags & 8))
        return;
    char frame[0x10];
    int ctask;
    TASK **aptask;
    CStackFrame_Construct(frame);
    OrderTasks(&ctask, &aptask);
    for (int index = 0; index < ctask; index++) {
        TASK *ptask = aptask[index];
        CTaskHold hold(ptask, 3);
        RestoreTaskStateFromSave(ptask);
    }
    TASK *pjob = PloFindSwObject_thunk(&B_003DD490, 0x105, self->oid, 0);
    self->fieldA = pjob->pparent->oid;
    self->fieldB = pjob->oid;
    {
    CTaskHold holdJob(pjob, 3);
    SetTaskState(pjob, 1);
    int value = pjob->fC0;
    if (value != -1) {
        CRefX result;
        CRefX arg;
        arg.tagk = 0x15;
        arg.n = value;
        func_001D8B20(&result, &arg, RO_002A5238, 0);
        CRef_Destruct(&result);
        CRef_Destruct(&arg);
    }
    for (int index = 0; index < ctask; index++) {
        TASK *ptask = aptask[index];
        CTaskHold hold(ptask, 3);
        ApplyTaskState(ptask, -1);
    }
    B_003DD490.fieldC = pjob->fB8;
    B_003DD490.fieldD = -1;
    B_003DD490.flags = (B_003DD490.flags & ~8) | 4;
    }
    CStackFrame_Destructor(frame, 2);
}
