#include "sly2.h"
extern "C" void BuildDrawEnvGifs(int, void *, int, void *, int);
extern "C" void BuildFrameTextureGifs();
extern "C" int g_2be598;
extern "C" int g_2be59c;
extern "C" char B_002DF740[], B_002DF800[], B_002DF880[], B_002DF940[], B_002DF9C0[], B_002DFA80[];

void BuildAllDrawEnvGifs()
{
    BuildDrawEnvGifs(0xc, B_002DF740, 8, B_002DF800, 0);
    BuildDrawEnvGifs(0xc, B_002DF880, 8, B_002DF940, g_2be598);
    BuildDrawEnvGifs(0xc, B_002DF9C0, 8, B_002DFA80, g_2be59c);
    BuildFrameTextureGifs();
}
