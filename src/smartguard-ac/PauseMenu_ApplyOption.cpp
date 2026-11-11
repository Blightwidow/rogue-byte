#include "sly2.h"
#include "cref.h"
struct GS;
extern "C" {
CRef RefSetGameSaveValue(void *path, const CRef &ref, GS *pgs);
void PauseMenu_SetState(int, int);
void ApplyOptionsFromSave(GS *);
extern GS B_003D4A60;
struct SWG { char pad[0x3B40]; void *pathA; void *pathB; };
extern SWG B_003DD490;
extern void *B_003E0FC0, *B_003E0FC4, *B_003E0FC8, *B_003E0FCC, *B_003E0FD8, *B_003E0FDC, *B_003E0FE0;
extern float B_003DD18C, B_003DD190;
extern float RO_002F6468, RO_002F646C;
extern int g_2c2d8c;
}
static inline void SetSaveValue(void *path, CRef ref)
{
    RefSetGameSaveValue(path, ref, &B_003D4A60);
}
static inline void SetSaveBool(void *path, int fBool)
{
    CRef ref;
    ref.m_tagk = TAGK_Bool;
    ref.m_tag.m_bool = fBool;
    SetSaveValue(path, ref);
}
static inline void SetSaveS32(void *path, int n)
{
    CRef ref;
    ref.m_tagk = TAGK_S32;
    ref.m_tag.m_n = n;
    SetSaveValue(path, ref);
}
static inline void SetSaveF32(void *path, float g)
{
    CRef ref;
    ref.m_tagk = TAGK_F32;
    ref.m_tag.m_g = g;
    SetSaveValue(path, ref);
}
extern "C" void PauseMenu_ApplyOption(int menu, int *option)
{
    switch (*option) {
    case 0x67:
        SetSaveF32(B_003E0FC4, 1.0f - B_003DD190);
        PauseMenu_SetState(menu, 9);
        break;
    case 0x68:
        SetSaveF32(B_003E0FC8, 1.0f - B_003DD18C);
        PauseMenu_SetState(menu, 9);
        break;
    case 0x3F:
        SetSaveF32(B_003DD490.pathA, RO_002F6468 - 636.0f);
        SetSaveF32(B_003DD490.pathB, RO_002F646C - 50.0f);
        PauseMenu_SetState(menu, 9);
        break;
    case 0x4E:
        SetSaveS32(B_003E0FC0, 0);
        break;
    case 0x4D:
        SetSaveS32(B_003E0FC0, 2);
        break;
    case 0x4C:
        SetSaveS32(B_003E0FC0, 1);
        break;
    case 0x4F:
    case 0x50:
        SetSaveBool(B_003E0FCC, *option == 0x4F);
        break;
    case 0x48:
    case 0x49:
    {
        int high = *option == 0x49;
        if (high) g_2c2d8c = 3;
        else g_2c2d8c = 2;
        SetSaveBool(B_003E0FD8, high);
    }
        break;
    case 0x51:
    case 0x52:
        SetSaveBool(B_003E0FDC, *option == 0x52);
        break;
    case 0x53:
    case 0x54:
        SetSaveBool(B_003E0FE0, *option == 0x54);
        break;
    }
    ApplyOptionsFromSave(&B_003D4A60);
}
