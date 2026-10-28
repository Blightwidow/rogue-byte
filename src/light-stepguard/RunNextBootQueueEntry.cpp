// SPDX-License-Identifier: GPL-3.0-or-later
struct SW;
struct ENTRY { int kind; int a4; int a8; int aC; int a10; int a14; int a18; };
struct BOOTQ { int cEntry; ENTRY aentry[16]; int iEntryNext; };
struct MQ { char pad[0x108]; int fSkippable; };
struct CARD { char pad[0x44]; int state; };
extern SW B_003DD490;
extern MQ B_002F66B0;
extern char B_002DEB30;
extern CARD B_002E6550;
extern char D_002BFCA0;
extern "C" {
int FBootQueueHasEntries(BOOTQ *);
void QueueMovie(MQ *, int);
void RequestTransition(SW *, void *, int, int, int, int);
void RestartAtTaskOid(void *, int, int);
void func_001ACC38(CARD *, int);
void RunNextBootQueueEntry(BOOTQ *);
}
extern "C" void RunNextBootQueueEntry__FP5BOOTQ(BOOTQ *pq)
{
    if (!FBootQueueHasEntries(pq))
        return;
    ENTRY *pentry = &pq->aentry[pq->iEntryNext++];
    switch (pentry->kind) {
    case 0:
    case 1: {
        MQ *pmq = &B_002F66B0;
        QueueMovie(pmq, pentry->a4);
        if (pentry->kind == 1)
            pmq->fSkippable = pentry->kind;
        RequestTransition(&B_003DD490, &D_002BFCA0, 0x189, -1, 0, -1);
        break;
    }
    case 2:
        RequestTransition(&B_003DD490, (void *)pentry->a8, pentry->aC, -1, pentry->a10, 0x30A);
        break;
    case 3:
        RestartAtTaskOid(&B_002DEB30, pentry->a14, pentry->a18);
        break;
    case 5:
        if (B_002E6550.state == 0)
            func_001ACC38(&B_002E6550, 1);
        RunNextBootQueueEntry(pq);
        break;
    }
}
