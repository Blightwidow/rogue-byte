/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Getter: returns the int at +0x244 of its argument. Retail is `jr $ra` with the `lw` in the delay slot; the 8 bytes were lumped with the epilogue
   of SelectCoinLootDef above (its `addiu $sp` delay slot and a padding `nop`) until the boundary was cut at 0x1C7B10. */
int func_001C7B10(char *self)
{
    return *(int *)(self + 0x244);
}
