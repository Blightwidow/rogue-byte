#include "sly2.h"
struct ALLOCREQ { int size; int align; };
struct TASK { char pad[0x94]; int cprereq; char pad2[0xFC - 0x98]; int visit; };
struct SW { char pad[0x3AFC]; int count; };
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
extern "C" void VisitTaskInOrder(TASK *, int *, TASK **, int, int);
extern "C" SW B_003DD490;
void OrderTasks(int *pctask, TASK ***paptask)
{
    *pctask = 0;
    ALLOCREQ req;
    int align = 0x10;
    req.size = B_003DD490.count << 2;
    *paptask = (TASK **)PvAllocStackClearImpl__Fi((req.align = align, &req));
    char frame[16];
    CStackFrame_Construct(frame);
    int bytes = B_003DD490.count << 2;
    req.align = align;
    req.size = bytes;
    TASK **all = (TASK **)PvAllocStackClearImpl__Fi(&req);
    int found = CploFindSwObjectsByClass(&B_003DD490, 5, 0x85, 0, B_003DD490.count, all);
    for (int i = 0; i < found; i++)
        all[i]->visit = 0;
    for (int i = 0; i < found; i++) {
        TASK *task = all[i];
        if (task->cprereq == 0)
            VisitTaskInOrder(task, pctask, *paptask, 0, 0);
    }
    CStackFrame_Destructor(frame, 2);
}
