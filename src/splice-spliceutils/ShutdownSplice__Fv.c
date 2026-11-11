#include "types.h"

struct Menu;
struct HudLabelBlot;
void InitMeter(struct Menu *);
void func_001AE928(s32 *);
void func_001A3020(s32 *);
void Menu_PostLoad(struct Menu *);
void FindHudLabelBlot(struct HudLabelBlot *);
void JobMenu_PostLoad(struct Menu *);
void MemcardMenu_PostLoad(struct Menu *);
void func_001DD690(struct Menu *);
extern s32 B_002E1E60;
extern struct Menu B_002E6550;
extern struct Menu B_002E65A0;
extern struct Menu B_003D9E80;
extern s32 B_003D9ED0;
extern struct HudLabelBlot B_003DA0C0;
extern struct Menu B_003DA0F0;
extern struct Menu B_003DA150;
extern struct Menu B_003DA3C0;
extern struct Menu B_003DA4F0;
extern struct Menu B_003DA530;

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
