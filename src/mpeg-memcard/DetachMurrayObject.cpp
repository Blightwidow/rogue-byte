struct OBJ;
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct OBJ { char pad[0xC]; VT *vt; };
struct XF;
struct SOB { char pad0[0x58]; XF *pxfLinear; XF *pxfAngular; };
struct LOB { char pad[0x180]; SOB *pso; };
struct MURRAY { char pad0[0x13F0]; OBJ *pobject; int unk13F4; };
extern "C" void func_0012E460(void *);
extern "C" void SetXfKind(SOB *, XF *, int);
extern "C" void SetSoNoXpsAll(SOB *, int);
extern "C" void func_001A58D0(SOB *, int, int);
extern "C" void RecalcSwOxfFilterForObject(void *, MURRAY *);
extern "C" char B_003DD490[];
extern "C" float g_2dded0;
extern "C" void DetachMurrayObject(MURRAY *pmurray)
{
    char *base = (char *)pmurray;
    func_0012E460(base + 0x13F4);
    func_0012E460(base + 0x13F8);
    func_0012E460(base + 0x13FC);
    func_0012E460(base + 0x1400);
    func_0012E460(base + 0x1600);
    func_0012E460(base + 0x1604);
    func_0012E460(base + 0x1608);
    func_0012E460(base + 0x160C);
    func_0012E460(base + 0x1618);
    func_0012E460(base + 0x161C);
    func_0012E460(base + 0x1620);
    func_0012E460(base + 0x1624);
    OBJ *pobject = pmurray->pobject;
    if (pobject == 0)
        return;
    VT *vt = pobject->vt;
    vt->fn((char *)pobject + vt->delta, 6, 0, 0, 0, 0);
    SOB *pso = ((LOB *)pmurray->pobject)->pso;
    SetXfKind(pso, pso->pxfLinear, *(int *)(base + 0x1404));
    SetXfKind(pso, pso->pxfAngular, *(int *)(base + 0x1408));
    SetSoNoXpsAll(pso, 0);
    func_001A58D0(pso, 0, 0xF);
    *(SOB **)(base + 0x1430) = pso;
    *(float *)(base + 0x1434) = g_2dded0;
    RecalcSwOxfFilterForObject(B_003DD490, pmurray);
}
