#include "jt.h"
extern "C" {
int JT_FLethalHit(JT *self, char *hit) {
    if (-*(int *)(hit + 0x10) < self->field_0xDFC) return 0;
    switch (*(int *)(hit + 0xC)) {
    case 0:
    case 1:
    case 0x80000:
    case 0x100000:
        return 0;
    }
    return 1;
}
}
