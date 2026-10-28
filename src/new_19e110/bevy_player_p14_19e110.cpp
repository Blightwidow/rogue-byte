struct CRV { char padE4[0xE4]; int unkE4; };
struct PLAYER { char pad0[0xC]; CRV *crv; char pad10[8]; int flag; };
extern "C" const float RO_002A6670;
extern "C" const float RO_002A6674;
extern "C" float SMinCrv(CRV *);
extern "C" float SMaxCrv(CRV *);

void bevy_player_p14_19e110(PLAYER *player, float *range)
{
    if (player->crv->unkE4) {
        range[0] = RO_002A6670;
        range[1] = RO_002A6674;
        return;
    }
    if (player->flag) {
        float low = SMinCrv(player->crv);
        float k35;
        asm("li.s %0, 35.0\n\tnop" : "=f" (k35));
        range[0] = low + k35;
        range[1] = SMaxCrv(player->crv) - 100.0f;
    } else {
        float low = SMinCrv(player->crv);
        float k100;
        asm("li.s %0, 100.0\n\tnop" : "=f" (k100));
        range[0] = low + k100;
        float high = SMaxCrv(player->crv);
        float k35;
        asm("li.s %0, 35.0\n\tnop" : "=f" (k35));
        range[1] = high - k35;
    }
}
