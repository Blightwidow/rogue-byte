struct GuardAnim { char pad0[0x10]; long key; char pad1[8]; };
struct GuardOwner { char pad[0x4C0]; int count; char pad2[0xC]; GuardAnim anims[1]; };
GuardAnim *PguardanimFind(GuardOwner *owner, long key)
{
    int count = owner->count;
    GuardAnim *anim = owner->anims;
    int index = 0;
    if (count > 0) {
        do {
            index++;
            if (anim->key == key) return anim;
            anim++;
        } while (index < count);
    }
    return 0;
}
