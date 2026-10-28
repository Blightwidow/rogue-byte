#include "sly2.h"
struct GADGET { char pad[0x150]; int state; };
extern "C" int FGadgetObjActive(GADGET *pgadget)
{
    int state = pgadget->state;
    if (state < 3) {
        if (state > 0)
            return 1;
    }
    return 0;
}
