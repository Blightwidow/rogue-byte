#include "sly2.h"
struct TOGGLEREC { int oid; int oidParent; unsigned grfState; int nLevelRow; };
struct SW { char pad[0x3AFC]; int count; };
struct S8 { char b[8]; };
struct S16 { char b[16]; };
struct S32 { char b[32]; };
struct LO;
struct LOVTBL { char pad0[0x40]; short d0; short i0; void (*f0)(void *); short d1; short i1; void (*f1)(void *); };
struct LOBJ { char pad[0xC]; LOVTBL *vtbl; };
extern "C" SW B_003DD490;
extern "C" char RO_002A5220;
extern "C" char RO_002A5228;
extern "C" unsigned GrfOfState(int);
extern "C" unsigned GrfOfStates(int, int *);
extern "C" int IdCurrentLevel(void);
extern "C" LOBJ *PloFindSwObject_thunk(SW *, int, int, LOBJ *);
void ApplyTaskToggles(void *owner, int state, int count, TOGGLEREC *toggles)
{
    unsigned grfThis = GrfOfState(state);
    unsigned grfGroup;
    if ((unsigned)(state - 4) < 2) {
        int states[2];
        *(S8 *)states = *(S8 *)&RO_002A5220;
        grfGroup = GrfOfStates(2, states);
    } else {
        int states[4];
        *(S16 *)states = *(S16 *)&RO_002A5228;
        grfGroup = GrfOfStates(4, states);
    }
    for (int index = 0; index < count; index++) {
        TOGGLEREC *toggle = &toggles[index];
        if ((toggle->grfState & grfGroup) == 0)
            continue;
        if (toggle->nLevelRow != -1 && toggle->nLevelRow != IdCurrentLevel())
            continue;
        LOBJ *parent = PloFindSwObject_thunk(&B_003DD490, 5, toggle->oidParent, 0);
        LOBJ *object = PloFindSwObject_thunk(&B_003DD490, parent ? 4 : 5, toggle->oid, parent);
        if (object) {
            if ((toggle->grfState & grfThis) != 0)
                object->vtbl->f0((char *)object + object->vtbl->d0);
            else
                object->vtbl->f1((char *)object + object->vtbl->d1);
        }
    }
}
