struct Player_1D9DF8 {
    char pad0[0xDFC]; int maxHealth; int *health;
    char pad1[0x10C8 - 0xE04]; int x10C8; char pad2[0x10EC - 0x10CC]; int x10EC;
    char pad3[0x1300 - 0x10F0]; int powerMax;
};
struct Meter_1D9DF8 {
    char pad0[0x20]; float f20; float f24; float f28; float f2C; unsigned state; Player_1D9DF8 *player; void *blot;
    int id3C; int id40; int id44; int id48; int id4C;
};
extern "C" int FBlotLabelPlaying(void *, int);
extern "C" int FFloatsNear__Ffff(float, float, float);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" float GSmooth__FfffP3SMPPf(float, float, float, void *, float *);
extern "C" int GetJtPower(void *);
extern "C" void *PpoSwFocusBase(void *);
extern "C" void SeekBlotLabel(void *, int, float);
extern "C" void SetMeterState(Meter_1D9DF8 *, int);
extern char B_003DD490[];
extern char D_002C3248[];
extern float g_2dded4;
extern "C" void UpdateMeter(Meter_1D9DF8 *self) {
    if (self->blot == 0) {
        return;
    }
    Player_1D9DF8 *previous = self->player;
    self->player = 0;
    Player_1D9DF8 *focus = (Player_1D9DF8 *)PpoSwFocusBase(B_003DD490);
    if (focus != 0 && FIsBasicDerivedFrom(focus, 0x34) != 0) {
        self->player = focus;
    }
    if (self->player == 0) {
        float zero = 0.0f;
        self->f24 = zero;
        self->f20 = zero;
        self->f2C = zero;
        self->f28 = zero;
        if (previous != 0) {
            SetMeterState(self, 0);
        }
        return;
    }
    if (previous != self->player) {
        if (previous == 0) {
            SetMeterState(self, 3);
        } else {
            SetMeterState(self, 5);
        }
        int first;
        int second;
        int third;
        int fourth;
        int fifth;
        if (FIsBasicDerivedFrom(self->player, 0x35) != 0) {
            first = 0x33D; second = 0x33E; third = 0x33F; fourth = 0x340; fifth = 0x341;
            goto storeIds;
        }
        if (FIsBasicDerivedFrom(self->player, 0x37) != 0) {
            first = 0x347; second = 0x348; third = 0x349; fourth = 0x34A; fifth = 0x34B;
            goto storeIds;
        }
        if (FIsBasicDerivedFrom(self->player, 0x36) != 0) {
            first = 0x342; second = 0x343; third = 0x344; fourth = 0x345; fifth = 0x346;
        storeIds:
            self->id3C = first;
            self->id40 = second;
            self->id44 = third;
            self->id48 = fourth;
            self->id4C = fifth;
        }
        Player_1D9DF8 *player = self->player;
        float health = (float)*player->health / (float)player->maxHealth;
        self->f24 = health;
        self->f20 = health;
        float power = (float)GetJtPower(player) / (float)self->player->powerMax;
        self->f2C = power;
        self->f28 = power;
    }
    switch (self->state) {
    case 1:
    case 6:
    case 7: {
        Player_1D9DF8 *player = self->player;
        self->f24 = (float)*player->health / (float)player->maxHealth;
        float power = (float)GetJtPower(player) / (float)self->player->powerMax;
        self->f2C = power;
        if (*self->player->health > 0) {
            float shown = self->f20;
            float goal = self->f24;
            if (goal < shown) {
                SetMeterState(self, 2);
                return;
            }
            if (!(shown < goal)) {
                if (FFloatsNear__Ffff(self->f28, power, 0.0001f) != 0) {
                    Player_1D9DF8 *current = self->player;
                    if (current->x10EC != 4) {
                        if (current->x10C8 != -1) {
                            SetMeterState(self, 6);
                            return;
                        }
                        SetMeterState(self, 1);
                        return;
                    }
                    SetMeterState(self, 7);
                    return;
                }
                SetMeterState(self, 4);
                return;
            }
            SetMeterState(self, 3);
            return;
        }
        SetMeterState(self, 0);
        return;
    }
    case 2:
        if (FBlotLabelPlaying(self->blot, self->id40) == 0) {
            SetMeterState(self, 3);
        }
        break;
    case 5:
        if (FBlotLabelPlaying(self->blot, self->id44) == 0) {
            SetMeterState(self, 1);
        }
        break;
    case 0: {
        Player_1D9DF8 *player = self->player;
        self->f24 = (float)*player->health / (float)player->maxHealth;
        float goal = self->f24;
        self->f2C = (float)GetJtPower(player) / (float)self->player->powerMax;
        if (self->f20 < goal) {
            self->f20 = goal;
            SeekBlotLabel(self->blot, 0x34F, 1.0f - goal);
            float power = self->f2C;
            self->f28 = power;
            SeekBlotLabel(self->blot, 0x350, 1.0f - power);
            SetMeterState(self, 1);
        }
        break;
    }
    case 3: {
        Player_1D9DF8 *player = self->player;
        float shown = self->f20;
        float goal = (float)*player->health / (float)player->maxHealth;
        self->f24 = goal;
        if (shown < goal) {
            self->f20 = goal;
        } else {
            self->f20 = GSmooth__FfffP3SMPPf(shown, goal, g_2dded4, D_002C3248, 0);
        }
        SeekBlotLabel(self->blot, 0x34F, 1.0f - self->f20);
        if (FFloatsNear__Ffff(self->f20, self->f24, 0.0001f) != 0) {
            SetMeterState(self, 1);
        }
        break;
    }
    case 4: {
        float shown = self->f28;
        float goal = (float)GetJtPower(self->player) / (float)self->player->powerMax;
        self->f2C = goal;
        if (shown < goal) {
            self->f28 = goal;
        } else {
            self->f28 = GSmooth__FfffP3SMPPf(shown, goal, g_2dded4, D_002C3248, 0);
        }
        SeekBlotLabel(self->blot, 0x350, 1.0f - self->f28);
        if (FFloatsNear__Ffff(self->f28, self->f2C, 0.0001f) != 0) {
            SetMeterState(self, 1);
        }
        break;
    }
    }
}
