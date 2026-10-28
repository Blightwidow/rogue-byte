#include "sly2.h"
struct SMA;
enum OID { OID_NONE };
extern "C" int FSmaRetracted(SMA *);
extern "C" void func_001F1448(void *, void *, int, int, void *);
extern "C" int OidFromICheer(int);
void SetSmaGoal(SMA *, OID);
struct CROWD { int oid; int oidCheer; SMA *link; int level; float threshold[3]; };
struct RHYTHM { char pad[0x288]; float smooth; char pad2[0x2A8 - 0x28C]; int count; CROWD crowd[1]; };
extern "C" void UpdateRhythmCrowd(RHYTHM *rhythm)
{
    for (int i = 0; i < rhythm->count; i++) {
        CROWD *crowd = &rhythm->crowd[i];
        if (!crowd->link) continue;
        if (FSmaRetracted(crowd->link)) {
            func_001F1448(0, 0, -1, 0, &crowd->link);
            crowd->level = -1;
        } else {
            for (int k = 0; k < 3; k++) {
                if (crowd->threshold[k] <= rhythm->smooth) {
                    SetSmaGoal(crowd->link, (OID)OidFromICheer(k));
                    crowd->level = k;
                    break;
                }
            }
        }
    }
}
