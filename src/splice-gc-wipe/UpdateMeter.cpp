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
static inline void SetMeterIds(Meter_1D9DF8 *self, int first, int second, int third, int fourth, int fifth)
{
    self->id3C = first;
    self->id40 = second;
    self->id44 = third;
    self->id48 = fourth;
    self->id4C = fifth;
}
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
        if (FIsBasicDerivedFrom(self->player, 0x35) != 0)
            SetMeterIds(self, 0x33D, 0x33E, 0x33F, 0x340, 0x341);
        else if (FIsBasicDerivedFrom(self->player, 0x37) != 0)
            SetMeterIds(self, 0x347, 0x348, 0x349, 0x34A, 0x34B);
        else if (FIsBasicDerivedFrom(self->player, 0x36) != 0)
            SetMeterIds(self, 0x342, 0x343, 0x344, 0x345, 0x346);
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
        if (*self->player->health <= 0) {
            SetMeterState(self, 0);
            break;
        }
        float shown = self->f20;
        float goal = self->f24;
        if (goal < shown) {
            SetMeterState(self, 2);
        } else if (shown < goal) {
            SetMeterState(self, 3);
        } else if (FFloatsNear__Ffff(self->f28, power, 0.0001f) == 0) {
            SetMeterState(self, 4);
        } else if (self->player->x10EC == 4) {
            SetMeterState(self, 7);
        } else if (self->player->x10C8 != -1) {
            SetMeterState(self, 6);
        } else {
            SetMeterState(self, 1);
        }
        break;
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
        self->f2C = (float)GetJtPower(player) / (float)self->player->powerMax;
        if (self->f20 < self->f24) {
            self->f20 = self->f24;
            SeekBlotLabel(self->blot, 0x34F, 1.0f - self->f24);
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
        float goal = (float)GetJtPower(self->player) / (float)self->player->powerMax;
        float shown = self->f28;
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
