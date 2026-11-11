// SPDX-License-Identifier: GPL-3.0-or-later
#include "vu0inline.h"
#include "sly2.h"
struct ACT { char pad[0x148]; unsigned long flags; };
struct GEOM { char pad0[0x40]; int unk40; char pad44[8]; ACT *act; char pad50[0x10]; QW pos; char pad70[0x18]; float unk88; };
struct OWNER { char pad0[0x9E0]; char sub9E0[1]; char pad9E1[0x6AB]; int unk108C; char pad1090[0x178]; };
struct TARGET { char pad0[0xEC]; int unkEC; char padF0[0x1C]; float unk10C; char pad110[0x74]; float unk184; char pad188[0x14]; int unk19C; };
struct ENTRY { OWNER *owner; char pad4[4]; int state; char padC[8]; TARGET *target; int index; char pad1C[4]; float value; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" QW PosLoWorld(void *);
extern "C" float atan2f(float, float);
extern "C" void AddSafePointOnMember(void *, int, float);
extern "C" void AddSafePointOnGeom(void *, int, QW);
union QUADVECTOR { QW quad; float lane[4]; };
void func_001942F0(ENTRY *entry)
{
    switch (entry->state) {
    case 3:
        if (entry->target->unk19C != 0)
            return;
        AddSafePointOnMember(entry->owner->sub9E0, entry->index, entry->value);
        break;
    case 4:
        if (entry->target->unkEC != 0)
            return;
        AddSafePointOnMember(entry->owner->sub9E0, entry->index, 0.0f);
        break;
    case 0:
    case 13:
        if (FIsBasicDerivedFrom(entry->target, 0xC)) {
            if (entry->target->unk19C != 0)
                return;
            AddSafePointOnMember(entry->owner->sub9E0, entry->index, entry->value);
        } else if (FIsBasicDerivedFrom(entry->target, 0x26)) {
            if (entry->target->unkEC != 0)
                return;
            AddSafePointOnMember(entry->owner->sub9E0, entry->index, 0.0f);
        } else {
            float scale;
            if (FIsBasicDerivedFrom(entry->target, 0x22)) {
                if (entry->target->unkEC != 0)
                    return;
                scale = entry->target->unk10C;
            } else {
                scale = entry->target->unk184;
            }
            QW ownerPosition = PosLoWorld(entry->owner);
            QW targetPosition = PosLoWorld(entry->target);
            QUADVECTOR difference;
            difference.quad = VectorSub(ownerPosition, targetPosition);
            float angle = atan2f(difference.lane[1], difference.lane[0]) * scale;
            AddSafePointOnMember(entry->owner->sub9E0, entry->index, angle);
        }
        break;
    default: {
        GEOM *geom = *(GEOM **)((char *)entry->owner + 0x208);
        if (geom) {
            float level = geom->unk88;
            if (0.7f < level) {
                if (!(geom->act->flags & 0x20000000UL)) {
                    if (entry->owner->unk108C == 0)
                        AddSafePointOnGeom(entry->owner->sub9E0, geom->unk40, geom->pos);
                }
            }
        }
        break;
    }
    }
}
