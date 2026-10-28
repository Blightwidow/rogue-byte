#include "sly2.h"
struct COIN { char pad[0x1D0]; float f1D0, f1D4, f1D8, f1DC, f1E0, f1E4; char pad2[0x230 - 0x1E8]; float f230, f234; };
extern "C" void InitDprize(COIN *);
extern "C" void InitCoin__FP4COIN(COIN *coin)
{
    InitDprize(coin);
    coin->f1D8 = 35.0f;
    coin->f1DC = 40.0f;
    coin->f1D0 = 250.0f;
    coin->f1D4 = 50.0f;
    coin->f1E4 = 0.6f;
    coin->f1E0 = 0.75f;
    coin->f230 = 8.0f;
    coin->f234 = 10.0f;
}
