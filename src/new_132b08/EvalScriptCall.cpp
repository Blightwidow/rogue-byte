#include "types.h"
extern "C" {

struct CRef;
void RefEval(struct CRef *);
void __as__4CRefRC4CRef(s32, struct CRef *);
void CRef_Destruct(struct CRef *);

void EvalScriptCall(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x10];
    RefEval((struct CRef *)sp);
    if (arg3 != 0) {
        __as__4CRefRC4CRef(arg3, (struct CRef *)sp);
    }
    CRef_Destruct((struct CRef *)sp);
}
}
