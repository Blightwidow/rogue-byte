#include "sly2.h"
struct ONZE { float uAmpl, gFreq, gPhase, uRandom; };
struct ONZ { float gMin, gMax, uBias; int conze; ONZE aonze[1]; };
float UNoise(float, float, float);
float UBias(float, float);
float GFromOnz(ONZ *ponz)
{
    int ionze = 0;
    float uNoiseSum = 0.0f;
    float uAmplSum = 0.0f;
    if (ponz->conze > 0) {
        ONZE *ponze = ponz->aonze;
        do {
            ionze++;
            float uNoise = UNoise(ponze->gFreq, ponze->gPhase, ponze->uRandom);
            float uAmpl = ponze->uAmpl;
            ponze++;
            uNoiseSum += uAmpl * uNoise;
            uAmplSum += uAmpl;
        } while (ionze < ponz->conze);
    }
    float u = UBias(uNoiseSum / uAmplSum, ponz->uBias);
    return ponz->gMin + u * (ponz->gMax - ponz->gMin);
}
