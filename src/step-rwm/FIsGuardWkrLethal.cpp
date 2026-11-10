#include "stepguard.h"
extern "C" {
int FIsGuardWkrLethal(STEPGUARD *self, char *other) {
    if (-*(int *)(other + 0x10) < self->field_0x338) return 0;
    switch (*(int *)(other + 0xC)) {
    case 0: case 1: case 0x80000: case 0x100000:
        return 0;
    }
    return 1;
}
}
