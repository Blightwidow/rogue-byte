#include "sly2.h"
struct CFontBrx;
extern CFontBrx *B_002DE760;
extern CFontBrx *B_002DE9F0;
extern "C" void InitFonts();
void StartupFont()
{
    InitFonts();
    B_002DE760 = B_002DE9F0;
}
