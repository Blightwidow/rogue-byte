#include "sly2.h"
struct CRef { int a; union { float g; int n; }; int c; int d; };
struct EPSEL { char pad0[0x110]; int episode; int pad1; int last; char pad2[0xC]; int row; };
extern int D_002BE26C;
extern int D_002BE270;
extern int B_003E0FE8[];
extern int B_003D4A60;
extern int B_003E100C[];
extern char B_002DFC00;
static inline int PathAt(int *base, int index) { return base[index]; }
extern "C" void PostBlotLoad(EPSEL *);
extern "C" void RefGetGameSaveValue(CRef *, int, int *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetEpselMode(EPSEL *, int, int);
extern "C" void func_00187E78(char *);
extern "C" void PostEpselLoad(EPSEL *pepsel)
{
    PostBlotLoad(pepsel);
    pepsel->last = 8;
    if (D_002BE26C == 0) {
        do {
            CRef ref;
            RefGetGameSaveValue(&ref, B_003E0FE8[pepsel->last], &B_003D4A60);
            float dtPlayed = ref.g;
            CRef_Destruct(&ref);
            if (dtPlayed != 0.0f)
                break;
            int percent = 0;
            int *percentbase = &B_003E0FE8[9];
            int ppath = PathAt(percentbase, pepsel->last - 1);
            if (ppath != 0) {
                RefGetGameSaveValue(&ref, ppath, &B_003D4A60);
                percent = ref.n;
                CRef_Destruct(&ref);
            }
            if (99 < percent)
                break;
            pepsel->last--;
            if (pepsel->last < 2)
                break;
        } while (D_002BE26C == 0);
    }
    if (D_002BE270 == -1) {
        pepsel->episode = pepsel->last;
        SetEpselMode(pepsel, 0, -1);
    } else {
        pepsel->row = D_002BE270;
        pepsel->episode = 0;
        D_002BE270 = -1;
        SetEpselMode(pepsel, 8, 0);
    }
    func_00187E78(&B_002DFC00);
}
