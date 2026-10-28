struct DL { void *pfirst; void *plast; int ibDle; };
struct SVT { char pad0[8]; short d8; short i8; void (*fn8)(char *); short d10; short i10; void (*fn10)(char *); };
struct SEQNODE { char pad0[0xC]; SVT *vt; char pad1[0x14 - 0x10]; char *powner; char pad2[0x9C - 0x18]; int fCamMove; };
extern char g_2dded0[];
extern "C" {
int FSeqnodeStopped(SEQNODE *);
void RemoveDlEntry(void *, SEQNODE *);
void ReleaseSeqnodeAnim(SEQNODE *);
void func_001E53D8(SEQNODE *);
void ReleaseSeqnodeSma(SEQNODE *);
void func_001E5468(SEQNODE *);
void ReleaseSeqnodeBinoc(SEQNODE *);
void DetachAllSeqnodeObjects(SEQNODE *);
void func_001E5570(SEQNODE *);
void SetClockRate(void *, int, float);
void SetSeqnodeDrive(SEQNODE *, int, int);
void func_001E4F20(SEQNODE *, int);
void func_001E5000(SEQNODE *, int);
void SetSeqnodeHandsOff(SEQNODE *, int, int);
void StopAmb(void *, float);
void VirtualRefPtr_Assign(void *, void *);
void StopSeqnodeCameraMove(SEQNODE *, int);
}

void StopSeqnode(SEQNODE *pseqnode)
{
    if (FSeqnodeStopped(pseqnode) != 0)
        return;
    SEQNODE *volatile psn = pseqnode;
    void **pamb = (void **)((char *)pseqnode + 0xEC);
    asm volatile("");
    pseqnode->vt->fn8((char *)pseqnode + pseqnode->vt->d8);
    RemoveDlEntry(pseqnode->powner + 0x5C, pseqnode);
    ReleaseSeqnodeAnim(pseqnode);
    func_001E53D8(pseqnode);
    ReleaseSeqnodeSma(pseqnode);
    func_001E5468(pseqnode);
    ReleaseSeqnodeBinoc(pseqnode);
    DetachAllSeqnodeObjects(pseqnode);
    func_001E5570(pseqnode);
    SetClockRate(g_2dded0, 6, 1.0f);
    SetSeqnodeDrive(pseqnode, 0, 0);
    func_001E4F20(pseqnode, 0);
    func_001E5000(pseqnode, 0);
    SetSeqnodeHandsOff(pseqnode, 0, 0);
    if (*pamb != 0) {
        StopAmb(*pamb, 0.0f);
        VirtualRefPtr_Assign(pamb, 0);
    }
    if (pseqnode->fCamMove != 0)
        StopSeqnodeCameraMove(pseqnode, 1);
    pseqnode->vt->fn10((char *)pseqnode + pseqnode->vt->d10);
    SEQNODE *again = psn;
    again->vt->fn10((char *)again + again->vt->d10);
}
