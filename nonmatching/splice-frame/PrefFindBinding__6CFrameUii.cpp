// SPDX-License-Identifier: GPL-3.0-or-later
struct VARB { int pad0; int pad4; unsigned symid; char ref[8]; VARB *next; };
struct CFrame {
    int pad0;
    int pad4;
    int cparent;
    CFrame *aparent[4];
    VARB *pvarb;
    int visited;
    void *PrefFindBinding(unsigned, int);
};
void *CFrame::PrefFindBinding(unsigned symid, int recurse)
{
    visited = 1;
    void *result = 0;
    VARB *pbinding = pvarb;
    if (pbinding != 0) {
        do {
            if (pbinding->symid == symid) {
                result = pbinding->ref;
                goto done;
            }
            pbinding = pbinding->next;
        } while (pbinding != 0);
    }
    {
        if (recurse != 0) {
            if (cparent > 0) {
                register int index asm("$17");
                index = 0;
                CFrame **ppparent = aparent;
                do {
                    CFrame *pparent = *ppparent;
                    if (pparent->visited == 0) {
                        result = pparent->PrefFindBinding(symid, recurse);
                        if (result != 0)
                            break;
                    }
                    index++;
                    ppparent++;
                } while (index < cparent);
            }
        }
    }
done:
    visited = 0;
    return result;
}
