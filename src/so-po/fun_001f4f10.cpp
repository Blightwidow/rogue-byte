#include "sly2.h"
struct PMF { long v; } __attribute__((packed));
struct LNK { int data; LNK *next; };
struct OXA { char pad[0x64]; LNK *link; int pad2; int pending; };
#include "so.h"
extern "C" char B_003DD490[];
extern PMF RO_002A8278;
extern "C" void QueueSwCallbackOnce(char *, SO *, long, int);
#define PM (RO_002A8278.v)

void func_001F4F10(SO *so)
{
    OXA *oxa = so->poxa;
    if (oxa->pending != 0) {
        QueueSwCallbackOnce(B_003DD490, so, PM, 0);
    } else if ((so->grfso & 0x3000000UL) != 0) {
        for (LNK *link = oxa->link; link != 0; link = link->next) {
            if (link->data != 0) {
                QueueSwCallbackOnce(B_003DD490, so, PM, 0);
                break;
            }
        }
    }
}
