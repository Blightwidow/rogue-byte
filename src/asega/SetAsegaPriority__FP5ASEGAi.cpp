struct XfAct { int pad0; void *xf; int field8; int priority; };
struct XfActNode { char pad0[4]; void *xf; int field8; int priority; char pad10[0x18]; XfActNode *next; };
struct ASEGA { char pad[0x34]; XfActNode *firstAct; };
extern "C" void ResortXfActList(void *, int);
extern "C" void SetAsegaPriority__FP5ASEGAi(ASEGA *asega, int priority) {
    for (XfActNode *node = asega->firstAct; node; node = node->next) {
        node->priority = priority;
        ResortXfActList(node->xf, node->field8);
    }
}
