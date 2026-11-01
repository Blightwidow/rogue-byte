// SPDX-License-Identifier: GPL-3.0-or-later
struct SLOT_1D3FF0 { int current; int maximum; int unk8; };
struct OWNER_1D3FF0 { char pad0[0x574]; SLOT_1D3FF0 slots[1]; };
struct PICKUP_1D3FF0 { char pad0[0x150]; int state; char pad154[0x158 - 0x154]; int index; int amount; };
extern "C" void SetAmmopickupState(PICKUP_1D3FF0 *, int);
extern "C" void func_001D3FF0(OWNER_1D3FF0 *owner, PICKUP_1D3FF0 *pickup)
{
    if (pickup->state == 2) return;
    int amount = pickup->amount;
    SLOT_1D3FF0 *slot = &owner->slots[pickup->index];
    int sum = slot->current + amount;
    int maximum = slot->maximum;
    slot->current = maximum < sum ? maximum : sum;
    SetAmmopickupState(pickup, 2);
}
