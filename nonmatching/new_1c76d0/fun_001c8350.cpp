// SPDX-License-Identifier: GPL-3.0-or-later
struct VAULT1C8350 { char pad0[0x180]; int state; char pad1[0x198 - 0x184]; int target; int jsg; char pad2[0x1F0 - 0x1A0]; int goal; };
extern "C" {
int FIsJsgActive(int);
void SetVaultOpen(int);
void UpdateSo(VAULT1C8350 *);
void func_001C84D8(VAULT1C8350 *);
void func_001C8730(void);
void func_001C8350(VAULT1C8350 *vault)
{
    UpdateSo(vault);
    int state = vault->state;
    for (;;) {
        switch (state) {
        case 1:
            if (vault->jsg == 0 || FIsJsgActive(vault->jsg) == 0)
                func_001C8730();
            break;
        case 2:
            if (vault->jsg == 0 || FIsJsgActive(vault->jsg) == 0) {
                if (vault->target == vault->goal)
                    func_001C8730();
                else
                    func_001C8730();
            } else {
                func_001C84D8(vault);
            }
            break;
        case 3:
            if (vault->jsg == 0 || FIsJsgActive(vault->jsg) == 0) {
                SetVaultOpen(1);
                func_001C8730();
            }
            break;
        case 4:
            if (vault->jsg == 0 || FIsJsgActive(vault->jsg) == 0)
                func_001C8730();
            break;
        }
        if (vault->state == state)
            break;
        state = vault->state;
    }
}
}
