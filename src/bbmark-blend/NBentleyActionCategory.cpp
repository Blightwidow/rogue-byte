#include "bentley.h"
extern "C" int func_00143C78(void *);
extern "C" int NBentleyActionCategory(BENTLEY *pbentley)
{
    if (pbentley->field_0x204 != 0)
        return 0;
    switch (pbentley->state) {
    case 0xD:
        return 0;
    case 8:
        return 5;
    case 0xE:
        return 0xF;
    }
    return func_00143C78(pbentley);
}