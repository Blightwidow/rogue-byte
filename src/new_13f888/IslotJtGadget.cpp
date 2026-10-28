#include "sly2.h"
struct JtSlot { int id; int pad[2]; };
struct Jt { char pad[0x1180]; JtSlot slots[3]; };
int IslotJtGadget(Jt *self, int id)
{
    for (int index = 0; index < 3; index++) {
        if (id == self->slots[index].id) return index;
    }
    return -1;
}
