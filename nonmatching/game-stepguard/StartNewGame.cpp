#include "sly2.h"
struct CRef {
    int tagk; int n; int pad[2];
    CRef() {}
    CRef(const CRef &other);
    ~CRef();
};
extern "C" CRef *CRef_CopyConstruct(CRef *, const CRef *);
extern "C" void CRef_Destruct(CRef *);
inline CRef::CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
inline CRef::~CRef() { CRef_Destruct(this); }
extern "C" CRef RefSetGameSaveValue(void *, CRef, void *);
extern "C" void bevy_player_p18_gadget_refill(void *, int);
extern "C" void StartGameFromSave(void *);
extern "C" void *B_003E0FAC;
extern "C" char B_003D4A60[];
extern "C" void *g_2e1e40;
extern "C" void *g_2dd5bc;
extern "C" void *g_2f7900;

void StartNewGame()
{
    {
        CRef zero;
        zero.tagk = 0x16;
        zero.n = 0;
        RefSetGameSaveValue(B_003E0FAC, zero, B_003D4A60);
    }
    if (g_2e1e40) bevy_player_p18_gadget_refill(g_2e1e40, 1);
    if (g_2dd5bc) bevy_player_p18_gadget_refill(g_2dd5bc, 1);
    if (g_2f7900) bevy_player_p18_gadget_refill(g_2f7900, 1);
    StartGameFromSave(B_003D4A60);
}
