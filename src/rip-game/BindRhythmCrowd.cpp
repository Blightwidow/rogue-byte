#include "sly2.h"
extern "C" char B_003DD490;
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" void func_001F1448(void *, void *, int, int, void *);
extern "C" int ICheerFromOid(int);
extern "C" float GRandInRange(float, float);
struct CROWD { int oid; int oidCheer; int link; int level; float threshold[3]; };
struct RHYTHM { char pad[0x234]; float scoreMin; float scoreMax; char pad2[0x2A8 - 0x23C]; int count; CROWD crowd[1]; };
extern "C" void BindRhythmCrowd(RHYTHM *rhythm)
{
    float third = __builtin_fabsf(rhythm->scoreMax - rhythm->scoreMin) * 0.33333334f;
    float half = third * 0.5f;
    for (int i = 0; i < rhythm->count; i++) {
        CROWD *crowd = &rhythm->crowd[i];
        void *object = PloFindSwObject_thunk(&B_003DD490, 4, crowd->oid, rhythm);
        if (!object) continue;
        void *machine = PloFindSwObject_thunk(&B_003DD490, 1, 0x625, object);
        if (!machine) continue;
        func_001F1448(machine, object, crowd->oidCheer, 0, &crowd->link);
        crowd->level = ICheerFromOid(crowd->oidCheer);
        float value = rhythm->scoreMax;
        for (int k = 0; k < 2; k++) {
            value -= third;
            crowd->threshold[k] = GRandInRange(value - half, value + half);
        }
        crowd->threshold[2] = rhythm->scoreMin;
    }
}
