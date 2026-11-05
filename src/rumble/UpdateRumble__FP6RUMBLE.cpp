struct RUMPAT { int crumins; };
struct RUMBLE { int nPort; int nSlot; int rums; RUMPAT *prumpat; int irumins; float dtRumble; float dtRumins; };
extern float g_2ddf10;
extern "C" int scePadSetActDirect(int, int, unsigned char *);
void SetRumbleRums(RUMBLE *, int);
void StopRumbleActuators(RUMBLE *);

void UpdateRumble(RUMBLE *prumble)
{
    float dt = g_2ddf10;
    switch (prumble->rums) {
    case 2: {
        float dtRumbleNow = prumble->dtRumble;
        if (0.0f < dtRumbleNow) {
            float dtRuminsLeft = prumble->dtRumins - dt;
            prumble->dtRumins = dtRuminsLeft;
            if (dtRuminsLeft <= 0.0f) {
                prumble->irumins = prumble->irumins + 1;
                if (prumble->irumins >= prumble->prumpat->crumins)
                    prumble->irumins = 0;
                unsigned char act[2];
                unsigned char *entry = (unsigned char *)prumble->prumpat + prumble->irumins * 8;
                act[0] = entry[4];
                act[1] = entry[5];
                scePadSetActDirect(prumble->nPort, prumble->nSlot, act);
                prumble->dtRumins = ((float *)((char *)prumble->prumpat + (prumble->irumins << 3)))[2];
            }
            prumble->dtRumble = prumble->dtRumble - dt;
        } else {
            SetRumbleRums(prumble, 3);
        }
        break;
    }
    case 3:
    case 4: {
        float dtRuminsNow = prumble->dtRumins;
        if (0.0f < dtRuminsNow) {
            StopRumbleActuators(prumble);
            prumble->dtRumins = prumble->dtRumins - dt;
        } else {
            SetRumbleRums(prumble, prumble->rums == 3);
        }
        break;
    }
    }
}
