struct ONZE { float uAmpl, gFreq, gPhase, uRandom; };
struct ONZ { int pad0[3]; unsigned conze; ONZE aonze[4]; };
void AddOnzOnze(ONZ *ponz, float uAmpl, float gFreq, float gPhase, float uRandom)
{
    unsigned conze = ponz->conze;
    if (conze < 4) {
        ponz->conze = conze + 1;
        ONZE *ponze = &ponz->aonze[conze];
        ponze->uAmpl = uAmpl;
        ponze->gFreq = gFreq;
        ponze->gPhase = gPhase;
        ponze->uRandom = uRandom;
    }
}
