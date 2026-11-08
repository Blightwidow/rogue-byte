// SPDX-License-Identifier: GPL-3.0-or-later
struct CHASER { char pad[0x184]; int health; char pad2[0x38]; int state; };
extern "C" {
void Chaser_SetState(CHASER *, int);
void bevy_camera_follow_activity(void *, int, CHASER *);
int func_0017F1D0(CHASER *, int *);
extern char B_002DEB30;

// Retail never touches $a1 before `jal func_0017F1D0`, and func_0017F1D0 reads
// its second argument (`daddu $s1,$a1`, `lw 0x44($s1)`), as Mount_FTakeHit
// passes its message through: this vtable slot takes (this, pmsg) and forwards
// pmsg. With the one-argument form the extra live pseudo was missing and the
// state load and the constant 4 swapped $v0/$v1.
int Chaser_FTakeHit(CHASER *pchaser, int *pmsg) {
    if (pchaser->state == 4) {
        return 0;
    }
    if (func_0017F1D0(pchaser, pmsg) == 0) {
        return 0;
    }
    int health = pchaser->health;
    if (health >= 0) {
        if (health <= 0) {
            bevy_camera_follow_activity(&B_002DEB30, 0x18, pchaser);
        }
        Chaser_SetState(pchaser, 4);
    }
    return 1;
}
}
