// SPDX-License-Identifier: GPL-3.0-or-later
struct CBinaryInputStream;
struct ALLOCREQ { int size; int align; };
struct TASK {
    char pad0[0x90];
    int *list90;
    int count94;
    void *clear98;
    int *list9C;
    int countA0;
    void *clearA4;
    int countA8;
    void *allocAC;
    int countB0;
    void *allocB4;
};
extern "C" {
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void LoadLoFromBrx(TASK *, CBinaryInputStream *);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
int S32Read__18CBinaryInputStream(CBinaryInputStream *);
int U8Read__18CBinaryInputStream(CBinaryInputStream *);
void Unknown1__18CBinaryInputStream(CBinaryInputStream *);
}

// Sets the request's alignment through the pointer the allocator is then given.
static inline ALLOCREQ *Aligned(ALLOCREQ *request)
{
    request->align = 0x10;
    return request;
}

// Retail stores each request's size at 0x10($sp) but its alignment through the register that holds &req for the call
// (`sw $s1, 0x4($s0)`), and keeps &req in two registers (s0 for the first half, s5 copied from it for the second): the
// alignment store goes through an inline helper that takes the request's address, while `req.align = 0x10` in the body
// folds to 0x14($sp) (score 28). The two counts are separate locals: one shared local adds a copy (`daddu $v1, $v0`)
// before each `sll` and moves the loop-head nop to the other loop (score 16).
extern "C" void LoadTaskFromBrx(TASK *task, CBinaryInputStream *stream)
{
    char frame[0x10];
    ALLOCREQ req;
    int index;
    int secondIndex;
    CStackFrame_Construct(frame);
    req.size = 0x200;
    task->allocAC = PvAllocStackImpl__Fi(Aligned(&req));
    req.size = 0x300;
    task->allocB4 = PvAllocStackImpl__Fi(Aligned(&req));
    LoadLoFromBrx(task, stream);
    req.size = task->countA8 * 0x10;
    task->allocAC = PvAllocSwCopyImpl__FiPv(Aligned(&req), task->allocAC);
    req.size = task->countB0 * 0x18;
    task->allocB4 = PvAllocSwCopyImpl__FiPv(Aligned(&req), task->allocB4);
    int count = U8Read__18CBinaryInputStream(stream);
    task->count94 = count;
    req.size = count * 4;
    task->clear98 = PvAllocSwClearImpl__Fi(Aligned(&req));
    req.size = task->count94 * 4;
    task->list90 = (int *)PvAllocSwImpl__Fi(Aligned(&req));
    for (index = 0; index < task->count94; index++) {
        task->list90[index] = S32Read__18CBinaryInputStream(stream);
    }
    int secondCount = U8Read__18CBinaryInputStream(stream);
    task->countA0 = secondCount;
    req.size = secondCount * 4;
    task->clearA4 = PvAllocSwClearImpl__Fi(Aligned(&req));
    req.size = task->countA0 * 4;
    task->list9C = (int *)PvAllocSwImpl__Fi(Aligned(&req));
    for (secondIndex = 0; secondIndex < task->countA0; secondIndex++) {
        task->list9C[secondIndex] = S32Read__18CBinaryInputStream(stream);
    }
    Unknown1__18CBinaryInputStream(stream);
    CStackFrame_Destructor(frame, 2);
}
