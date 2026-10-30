/* SPDX-License-Identifier: GPL-3.0-or-later */
struct ANIMREF_209C18 { char pad[0x10]; long key; char pad2[0x8]; };
struct GUARD_209C18 { char pad[0x4C0]; int count; char pad2[0xC]; ANIMREF_209C18 anims[1]; };
extern "C" ANIMREF_209C18 *PguardanimFind();
extern "C" void ResetAnimref(ANIMREF_209C18 *, GUARD_209C18 *);
extern "C" ANIMREF_209C18 *PguardanimEnsure(GUARD_209C18 *guard, long key) {
    ANIMREF_209C18 *anim = PguardanimFind();
    if (anim == 0) {
        ANIMREF_209C18 *added = &guard->anims[guard->count++];
        added->key = key;
        anim = added;
    }
    ResetAnimref(anim, guard);
    return anim;
}
