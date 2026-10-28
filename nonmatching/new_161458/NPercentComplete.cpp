#include "sly2.h"
struct ALLOCREQ { int size; int align; };
struct TASK { char pad0[0x54]; int state; char pad1[0x48]; int dependents; };
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
struct SW { char pad[0x3AFC]; int count; };
extern "C" SW B_003DD490;
int NPercentComplete(void)
{
    char frame[16];
    int total = 0;
    int closed = 0;
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    int align = 0x10;
    preq->size = B_003DD490.count << 2;
    preq->align = align;
    TASK **tasks = (TASK **)PvAllocStackClearImpl__Fi(preq);
    int found = CploFindSwObjectsByClass(&B_003DD490, 5, 0x85, 0, B_003DD490.count, tasks);
    for (int i = 0; i < found; i++) {
        TASK *task = tasks[i];
        if (task->dependents != 0) {
            total++;
            if (task->state == 3)
                closed++;
        }
    }
    if (closed == 0) {
        CStackFrame_Destructor(frame, 2);
        return 0;
    }
    if (closed == total) {
        CStackFrame_Destructor(frame, 2);
        return 100;
    }
    int raw = closed * 100 / total;
    int result = 1;
    if (raw > 0) {
        result = 99;
        if (raw < 100)
            result = raw;
    }
    CStackFrame_Destructor(frame, 2);
    return result;
}
