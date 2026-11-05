typedef signed char s8; typedef int s32;
struct ALLOCREQ { s32 size; s32 align; };
struct TASK {
    s8 pad0[0x90];
    s32 *list90;
    s32 count94;
    s32 clear98;
    s32 *list9C;
    s32 countA0;
    s32 clearA4;
    s32 countA8;
    s32 allocAC;
    s32 countB0;
    s32 allocB4;
};
extern "C" {
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, s32);
void LoadLoFromBrx(TASK *, s32);
s32 PvAllocStackImpl__Fi(ALLOCREQ *);
s32 PvAllocSwClearImpl__Fi(ALLOCREQ *);
s32 PvAllocSwCopyImpl__FiPv(ALLOCREQ *, s32);
s32 PvAllocSwImpl__Fi(ALLOCREQ *);
s32 S32Read__18CBinaryInputStream(s32);
s32 U8Read__18CBinaryInputStream(s32);
void Unknown1__18CBinaryInputStream(s32);
void LoadTaskFromBrx(TASK *task, s32 stream) {
    s8 frame[0x10] __attribute__((aligned(16)));
    ALLOCREQ req;
    s32 index;
    s32 secondIndex;
    CStackFrame_Construct(frame);
    req.size = 0x200;
    req.align = 0x10;
    task->allocAC = PvAllocStackImpl__Fi(&req);
    req.size = 0x300;
    req.align = 0x10;
    task->allocB4 = PvAllocStackImpl__Fi(&req);
    LoadLoFromBrx(task, stream);
    req.size = task->countA8 * 0x10;
    req.align = 0x10;
    task->allocAC = PvAllocSwCopyImpl__FiPv(&req, task->allocAC);
    req.size = task->countB0 * 0x18;
    req.align = 0x10;
    task->allocB4 = PvAllocSwCopyImpl__FiPv(&req, task->allocB4);
    s32 count = U8Read__18CBinaryInputStream(stream);
    task->count94 = count;
    req.size = count * 4;
    req.align = 0x10;
    task->clear98 = PvAllocSwClearImpl__Fi(&req);
    req.size = task->count94 * 4;
    req.align = 0x10;
    task->list90 = (s32 *)PvAllocSwImpl__Fi(&req);
    for (index = 0; index < task->count94; index++) {
        task->list90[index] = S32Read__18CBinaryInputStream(stream);
    }
    count = U8Read__18CBinaryInputStream(stream);
    task->countA0 = count;
    req.size = count * 4;
    req.align = 0x10;
    task->clearA4 = PvAllocSwClearImpl__Fi(&req);
    req.align = 0x10;
    req.size = task->countA0 * 4;
    task->list9C = (s32 *)PvAllocSwImpl__Fi(&req);
    for (secondIndex = 0; secondIndex < task->countA0; secondIndex++) {
        task->list9C[secondIndex] = S32Read__18CBinaryInputStream(stream);
    }
    Unknown1__18CBinaryInputStream(stream);
    CStackFrame_Destructor(frame, 2);
}
}
