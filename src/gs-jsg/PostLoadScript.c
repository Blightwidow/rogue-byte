#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK ResolveScriptObjects(s32);                  /* extern */

void PostLoadScript(s32 arg0) {
    PostLoLoad();
    ResolveScriptObjects(arg0);
}
