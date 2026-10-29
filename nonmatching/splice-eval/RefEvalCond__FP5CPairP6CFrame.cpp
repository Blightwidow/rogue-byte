#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_CopyConstruct();             /* extern */
M2C_UNK CRef_Destruct();                  /* extern */
M2C_UNK RefEval();                /* extern */
M2C_UNK SetTag__4CRef4TAGK();         /* extern */
M2C_UNK __as__4CRefRC4CRef();           /* extern */

s32 RefEvalCond__FP5CPairP6CFrame(s32 arg0, void *arg1, s32 arg2) {
    char sp[0x20];
    M2C_UNK sp14;
    s32 sp10;
    s32 sp20;
    s32 var_s2;
    void *temp_s1;
    void *var_a1;
    void *var_s0;
    void *var_s1;

    sp10 = -1;
    CRef_Destruct(sp, -1);
    SetTag__4CRef4TAGK(sp, 0x24);
    var_s0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0xC), void **, 0x10);
    if (var_s0 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s0, void **, 0xC);
            if (M2C_FIELD(temp_s1, s32 *, 8) == 0xB) {
                var_s2 = 1;
                goto block_12;
            }
            var_s2 = 0;
            RefEval(&sp20, temp_s1, arg2);
            __as__4CRefRC4CRef(&sp10, &sp20);
            CRef_Destruct(&sp20);
            if ((sp10 != 0x17) || (sp14 != 0)) {
                var_s2 = 1;
            }
            if (var_s2 == 0) {
                var_s0 = M2C_FIELD(var_s0, void **, 0x10);
            } else {
                if (M2C_FIELD(temp_s1, void **, 0x10) == NULL) {
                    __as__4CRefRC4CRef(sp, &sp10);
                }
block_12:
                if (var_s2 == 0) {
                    var_s0 = M2C_FIELD(var_s0, void **, 0x10);
                } else {
                    var_s1 = M2C_FIELD(temp_s1, void **, 0x10);
                    if (var_s1 != NULL) {
                        var_a1 = var_s1;
                        do {
                            RefEval(&sp20, var_a1, arg2);
                            __as__4CRefRC4CRef(sp, &sp20);
                            CRef_Destruct(&sp20);
                            var_s1 = M2C_FIELD(var_s1, void **, 0x10);
                            var_a1 = var_s1;
                        } while (var_s1 != NULL);
                    }
                    var_s0 = NULL;
                }
            }
        } while (var_s0 != NULL);
    }
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
    return arg0;
}
}
