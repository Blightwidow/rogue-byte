// SPDX-License-Identifier: GPL-3.0-or-later
struct SEQVT { char pad[8]; short deltaAddRef; short idxAddRef; void (*fnAddRef)(void *); short deltaRelease; short idxRelease; void (*fnRelease)(void *); };
struct REC { int kind; int busy; };
struct SEQNODE { char pad0[0xC]; SEQVT *vt; char pad1[0x18]; REC *precFirst; REC *precLast; REC *precCur; };
extern "C" void StartNextSeqnodeRecord(SEQNODE *);
extern "C" int FSeqnodeStopped(SEQNODE *);
extern "C" void UpdateSeqnodeDrive(SEQNODE *);
extern "C" int FSeqnodeRecordDone(SEQNODE *, REC *);
extern "C" void StopSeqnode(SEQNODE *);

struct REF {
    SEQNODE *p;
    REF(SEQNODE *q) { p = q; p->vt->fnAddRef((char *)p + p->vt->deltaAddRef); }
    ~REF() { p->vt->fnRelease((char *)p + p->vt->deltaRelease); }
};

extern "C" void RunSeqnode(SEQNODE *pseqnode)
{
    REF ref(pseqnode);
    if (pseqnode->precCur != 0)
        goto check;
    pseqnode->precCur = pseqnode->precFirst;
start:
    StartNextSeqnodeRecord(pseqnode);
    if (FSeqnodeStopped(pseqnode))
        return;
    goto check;
update:
    UpdateSeqnodeDrive(pseqnode);
    goto start;
check:
    if (!(pseqnode->precCur > pseqnode->precLast)) {
        if (pseqnode->precCur->busy != 0)
            goto update;
        if (FSeqnodeRecordDone(pseqnode, pseqnode->precCur))
            goto update;
    }
    UpdateSeqnodeDrive(pseqnode);
    if (pseqnode->precCur > pseqnode->precLast)
        StopSeqnode(pseqnode);
}
