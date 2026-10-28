struct B8 { char b[8]; };
struct MEMCARD { char pad0[4]; int threadId; B8 pmf; int busy; };
struct THREADPARAM { int attr; void *entry; void *stack; int stackSize; void *gp; int priority; int pad[6]; };
extern "C" void SetMemcardThreadHighPrio__FP7MEMCARD(MEMCARD *);
extern "C" void MemcardThreadMain();
extern "C" int CreateThread(THREADPARAM *);
extern "C" void func_002355E0(int, MEMCARD *);
void *memset(void *, int, unsigned int);
extern char B_002E2080[], B_002E5270[];
extern int B_004425D8;

void CreateMemcardThread__FP7MEMCARDii(MEMCARD *card, long pmfArg)
{
    struct F { long pmf; long pad; THREADPARAM param; } f;
    f.pmf = pmfArg;
    SetMemcardThreadHighPrio__FP7MEMCARD(card);
    card->pmf = *(B8 *)&f.pmf;
    card->busy = 0x21;
    memset(&f.param, 0, 0x30);
    f.param.entry = (void *)MemcardThreadMain;
    f.param.stack = B_002E2080;
    f.param.stackSize = 0x4000;
    f.param.gp = B_002E5270;
    f.param.priority = 3;
    int id = CreateThread(&f.param);
    card->threadId = id;
    char *pb = (char *)&B_004425D8; *(int *)pb = id;
    func_002355E0(card->threadId, card);
}
