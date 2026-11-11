#include "types.h"

struct Menu;
void func_001574A0(s32 *);
void func_001D9878(struct Menu *);
extern s32 B_002DEA00;
extern struct Menu B_003D9E80;
extern struct Menu B_003DA0F0;
extern struct Menu B_003DA150;
extern s32 g_2dea28;

void UpdateRecyclable__3CGc(void) {
    func_001D9878(&B_003D9E80);
    func_001D9878(&B_003DA0F0);
    func_001D9878(&B_003DA150);
    func_001574A0(&B_002DEA00);
    func_001574A0(&g_2dea28);
}
