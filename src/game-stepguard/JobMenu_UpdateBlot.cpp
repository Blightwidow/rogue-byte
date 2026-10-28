struct BLOT { char pad[0x58]; int nBlots; };
struct ROW { int pobj; int label; int labelDone; };
struct JOBMENU {
    char pad0[0x24];
    BLOT *pblot;
    char pad1[0x40 - 0x28];
    int page;
    char pad2[4];
    int cent;
    ROW aent[17];
    int isel;
};
extern "C" {
void SwitchBlotLabel(BLOT *, int, void *);
int FEndTaskComplete(int);
int FTaskComplete(int);
}

void JobMenu_UpdateBlot(JOBMENU *pjobmenu)
{
    if (pjobmenu->pblot->nBlots != 2)
        return;
    for (int irow = 0; irow < pjobmenu->cent; irow++) {
        ROW *prow = &pjobmenu->aent[irow];
        int labelRow = (irow == pjobmenu->isel) ? 0x4FD + irow : 0x4E9 + irow;
        SwitchBlotLabel(pjobmenu->pblot, labelRow, &prow->label);
        int fComplete = 0;
        switch (pjobmenu->page) {
        case 0:
            fComplete = FEndTaskComplete(prow->pobj);
            break;
        case 1:
            fComplete = FTaskComplete(prow->pobj);
            break;
        }
        SwitchBlotLabel(pjobmenu->pblot, fComplete != 0 ? 0x507 + irow : -1, &prow->labelDone);
    }
}
