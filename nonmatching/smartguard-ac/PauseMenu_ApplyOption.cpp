struct SAVEVAL {
    int tag;
    union { int n; float g; };
    int p2, p3;
    SAVEVAL() {}
    SAVEVAL(int tagArg, int nArg) { tag = tagArg; n = nArg; }
    SAVEVAL(int tagArg, float gArg) { tag = tagArg; g = gArg; }
    SAVEVAL(const SAVEVAL &other);
    ~SAVEVAL();
};
extern "C" {
void CRef_CopyConstruct(SAVEVAL *, const SAVEVAL *);
void CRef_Destruct(SAVEVAL *);
void RefSetGameSaveValue(SAVEVAL *, int, SAVEVAL *, void *);
void PauseMenu_SetState(int, int);
void ApplyOptionsFromSave(void *);
extern char B_003D4A60[];
struct SWG { char pad[0x3B40]; int pathA; int pathB; };
extern SWG B_003DD490;
extern int B_003E0FC0, B_003E0FC4, B_003E0FC8, B_003E0FCC, B_003E0FD8, B_003E0FDC, B_003E0FE0;
extern float B_003DD18C, B_003DD190;
extern float RO_002F6468, RO_002F646C;
extern int g_2c2d8c;
}
inline SAVEVAL::SAVEVAL(const SAVEVAL &other) { CRef_CopyConstruct(this, &other); }
inline SAVEVAL::~SAVEVAL() { CRef_Destruct(this); }
static inline void SetSaveInt(int path, int tag, int n)
{
    SAVEVAL value(tag, n);
    SAVEVAL copy(value);
    SAVEVAL result;
    RefSetGameSaveValue(&result, path, &copy, B_003D4A60);
}
static inline void SetSaveFloat(int path, int tag, float g)
{
    SAVEVAL value(tag, g);
    SAVEVAL copy(value);
    SAVEVAL result;
    RefSetGameSaveValue(&result, path, &copy, B_003D4A60);
}
extern "C" void PauseMenu_ApplyOption(int menu, int *option)
{
    switch (*option) {
    case 0x67:
        SetSaveFloat(B_003E0FC4, 0x16, 1.0f - B_003DD190);
        PauseMenu_SetState(menu, 9);
        break;
    case 0x68:
        SetSaveFloat(B_003E0FC8, 0x16, 1.0f - B_003DD18C);
        PauseMenu_SetState(menu, 9);
        break;
    case 0x3F:
        SetSaveFloat(B_003DD490.pathA, 0x16, RO_002F6468 - 636.0f);
        SetSaveFloat(B_003DD490.pathB, 0x16, RO_002F646C - 50.0f);
        PauseMenu_SetState(menu, 9);
        break;
    case 0x4E:
        SetSaveInt(B_003E0FC0, 0x15, 0);
        break;
    case 0x4D:
        SetSaveInt(B_003E0FC0, 0x15, 2);
        break;
    case 0x4C:
        SetSaveInt(B_003E0FC0, 0x15, 1);
        break;
    case 0x4F:
    case 0x50:
        SetSaveInt(B_003E0FCC, 0x17, *option == 0x4F);
        break;
    case 0x48:
    case 0x49:
    {
        int high = *option == 0x49;
        if (high) g_2c2d8c = 3;
        else g_2c2d8c = 2;
        SetSaveInt(B_003E0FD8, 0x17, high);
    }
        break;
    case 0x51:
    case 0x52:
        SetSaveInt(B_003E0FDC, 0x17, *option == 0x52);
        break;
    case 0x53:
    case 0x54:
        SetSaveInt(B_003E0FE0, 0x17, *option == 0x54);
        break;
    }
    ApplyOptionsFromSave(B_003D4A60);
}
