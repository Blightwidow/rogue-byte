#include "sly2.h"
struct DZ { int dzk; int pad0[3]; float sdv; int pad1[3]; DZ *next; };
struct DLE { char *next; char *prev; };
struct DL { DZ *first; char *last; int offset; };
struct DLI { DL *list; DLE *current; int offset; DLI *next; };
struct DZG { char pad0[0xC]; DL pos; char pad1[0x18]; DL uncat; int cdzPos; };
extern DLI *g_2dd2fc;
void RemoveDlEntry(DL *, DZ *);
void AppendDlEntry(DL *, DZ *);
extern "C" void EnforceDzgDz__FP3DZGP2DZ(DZG *, DZ *);
void SolveDzgPrefilled(DZG *dzg)
{
    struct L { DLI iter; int pad[4]; } l;

    DL *list = &dzg->uncat;
    DLI **pg = &g_2dd2fc;
    l.iter.current = (DLE *)list;
    l.iter.list = list;
    asm volatile("" : : : "memory");
    DLI *head = *pg;
    int offset = list->offset;
    *pg = &l.iter;
    l.iter.next = head;
    asm volatile("" : : : "memory");
    DZ *first = dzg->uncat.first;
    l.iter.offset = offset;
    l.iter.current = (DLE *)((char *)first + offset);
    DZ *row = first;
    while (row != 0) {
        if (row->dzk == 1) {
            RemoveDlEntry(&dzg->uncat, row);
            AppendDlEntry(&dzg->pos, row);
            dzg->cdzPos = dzg->cdzPos + 1;
        }
        DZ *next = (DZ *)l.iter.current->next;
        l.iter.current = (DLE *)((char *)next + l.iter.offset);
        row = next;
    }
    EnforceDzgDz__FP3DZGP2DZ(dzg, 0);
    *pg = l.iter.next;
    while (true) {
        DZ *worst = 0;
        float worstSdv = -0.01f;
        for (DZ *scan = dzg->uncat.first; scan != 0; scan = scan->next) {
            if (scan->sdv < worstSdv) {
                worst = scan;
                worstSdv = scan->sdv;
            }
        }
        if (worst == 0)
            break;
        EnforceDzgDz__FP3DZGP2DZ(dzg, worst);
    }
}
