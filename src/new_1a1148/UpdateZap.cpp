struct Owner { char pad[0x1030]; int asega; };
struct ZAP { Owner *owner; int state; };
extern "C" int FAsegaGone(int);
extern "C" void ZapContinue(ZAP *);
extern "C" void UpdateZap(ZAP *zap)
{
    int state;
    do {
        state = zap->state;
        if (FAsegaGone(zap->owner->asega))
            ZapContinue(zap);
    } while (zap->state != -1 && zap->state != state);
}
