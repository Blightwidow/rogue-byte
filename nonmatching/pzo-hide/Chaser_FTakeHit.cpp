struct Chaser_1811B8 { char pad[0x184]; int health; char pad2[0x38]; int state; };
extern "C" {
void Chaser_SetState(Chaser_1811B8 *, int);
void bevy_camera_follow_activity(void *, int, Chaser_1811B8 *);
int func_0017F1D0(Chaser_1811B8 *);
extern char B_002DEB30;
int Chaser_FTakeHit(Chaser_1811B8 *self) {
    if (self->state == 4) {
        return 0;
    }
    if (func_0017F1D0(self) == 0) {
        return 0;
    }
    int health = self->health;
    if (health >= 0) {
        if (health <= 0) {
            bevy_camera_follow_activity(&B_002DEB30, 0x18, self);
        }
        Chaser_SetState(self, 4);
    }
    return 1;
}
}
