#include "sly2.h"
struct SW { char pad[0x4754]; float tL3; };
struct G2 { char pad[0x4A4]; int cL3; };
extern "C" SW B_003DD490;
extern "C" G2 B_002DDF40;
extern "C" float g_2dded0;
int IEpisodeCurrent();
void ShowCoinBlot(SW *);
void ShowClueBlot(SW *);
int CploFindSwObjectsByClass(SW *, int, int, int, int, int);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
void func_00140338()
{
    if (IEpisodeCurrent() != 0) {
        ShowCoinBlot(&B_003DD490);
        if (CploFindSwObjectsByClass(&B_003DD490, 0x605, 0x5F, 0, 0, 0) != 0)
            ShowClueBlot(&B_003DD490);
        SetEmitterUnpositioned(NewEmitter(0x32), 0);
        B_003DD490.tL3 = g_2dded0;
        B_002DDF40.cL3 = B_002DDF40.cL3 + 1;
    }
}
