#include "m2c_macros.h"

M2C_UNK FindHudLabelBlot(M2C_UNK *);                /* extern */
M2C_UNK InitMeter(M2C_UNK *);                       /* extern */
M2C_UNK JobMenu_PostLoad(M2C_UNK *);                /* extern */
M2C_UNK MemcardMenu_PostLoad(M2C_UNK *);            /* extern */
M2C_UNK Menu_PostLoad(M2C_UNK *);                   /* extern */
M2C_UNK func_001A3020(M2C_UNK *);                   /* extern */
M2C_UNK func_001AE928(M2C_UNK *);                   /* extern */
M2C_UNK func_001DD690(M2C_UNK *);                   /* extern */
extern M2C_UNK B_002E1E60;
extern M2C_UNK B_002E6550;
extern M2C_UNK B_002E65A0;
extern M2C_UNK B_003D9E80;
extern M2C_UNK B_003D9ED0;
extern M2C_UNK B_003DA0C0;
extern M2C_UNK B_003DA0F0;
extern M2C_UNK B_003DA150;
extern M2C_UNK B_003DA3C0;
extern M2C_UNK B_003DA4F0;
extern M2C_UNK B_003DA530;

void ShutdownSplice__Fv(void) {
    InitMeter(&B_003D9E80);
    func_001AE928(&B_003D9ED0);
    func_001A3020(&B_002E1E60);
    Menu_PostLoad(&B_003DA0F0);
    Menu_PostLoad(&B_003DA150);
    FindHudLabelBlot(&B_003DA0C0);
    JobMenu_PostLoad(&B_003DA3C0);
    MemcardMenu_PostLoad(&B_002E6550);
    Menu_PostLoad(&B_002E65A0);
    func_001DD690(&B_003DA4F0);
    Menu_PostLoad(&B_003DA530);
}
