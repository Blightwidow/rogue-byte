#include "sly2.h"

struct EXPL_VT_15C150 { char pad[0x19C]; void (*fn)(char *, char *); };
struct EXPL_OBJ_15C150 { char pad[0x198]; short offset; };

void ExplodeExpl(char *arg0)
{
    char sp[0x40];
    memset(sp, 0, 0x40);
    char *obj = *(char **)(arg0 + 0xC);
    ((EXPL_VT_15C150 *)obj)->fn(arg0 + ((EXPL_OBJ_15C150 *)obj)->offset, sp);
}
