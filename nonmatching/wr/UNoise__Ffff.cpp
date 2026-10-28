#include "sly2.h"
extern "C" float g_2dded0;
float UNoise__Fi(int);
extern "C" float UNoise__Ffff(float gFreq, float gPhase, float uRandom)
{
    float gPosition = (gFreq + gFreq) * g_2dded0 + gPhase;
    int nLattice = (int)gPosition;
    float uLeft = UNoise__Fi(nLattice);
    float uRight = UNoise__Fi(nLattice + 1);
    if (nLattice & 1) {
        uLeft = uLeft * uRandom;
        uRight = uRandom * (uRight - 1.0f) + 1.0f;
    } else {
        uRight = uRight * uRandom;
        uLeft = uRandom * (uLeft - 1.0f) + 1.0f;
    }
    float uFraction = gPosition - (float)nLattice;
    return uLeft + (uRight - uLeft) * (uFraction * uFraction * (3.0f - (uFraction + uFraction)));
}
