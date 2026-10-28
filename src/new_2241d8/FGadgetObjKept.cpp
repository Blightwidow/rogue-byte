#include "sly2.h"
struct GADGET { char pad[0x15C]; int kind; };
extern "C" int FGadgetObjKept(GADGET *pgadget)
{
 int kind = pgadget->kind;
 if (kind != 7 && kind != 0xb) return 0; return 1;
}
