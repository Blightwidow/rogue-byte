#include "sly2.h"
struct Obstacle { char pad0[0x1A0]; QW posMin; QW posMax; char pad1[0x1DC - 0x1C0]; void *pathzone; };
struct Pathzone {
    char pad0[0xF8];
    int cobstacle;
    int cslot;
    int cep;
    void *aepX;
    void *aepY;
    void **aslot;
    char pad1[0x114 - 0x110];
    int stamp;
};
struct Sw { char pad[0x3D70]; int stamp; };
extern Sw B_003DD490;
extern "C" {
int CobstacleFindPathzoneBox(Pathzone *, void *, QW, QW, int, void **);
int func_001BD8A8(Obstacle *, void *);
void MergeObstacles(int, void **);
void GrowPathzoneSlots(Pathzone *);
void InsertPathzoneEndpoints(int, void *, int, float, float);
}
extern "C" void AddPathzoneObstacle(Pathzone *pathzone, Obstacle *obstacle)
{
    void *apobstacle[32];
    void *pair[2];
    int cobstacle = CobstacleFindPathzoneBox(pathzone, 0, obstacle->posMin, obstacle->posMax, 0x20, apobstacle);
    for (int iobstacle = 0; iobstacle < cobstacle; iobstacle++) {
        if (func_001BD8A8(obstacle, apobstacle[iobstacle])) {
            pair[0] = obstacle;
            pair[1] = apobstacle[iobstacle];
            MergeObstacles(2, pair);
            return;
        }
    }
    if (pathzone->cobstacle >= pathzone->cslot)
        GrowPathzoneSlots(pathzone);
    int islot = 0;
    ++pathzone->cobstacle;
    while (islot < pathzone->cobstacle && pathzone->aslot[islot] != 0)
        islot++;
    pathzone->aslot[islot] = obstacle;
    InsertPathzoneEndpoints(pathzone->cep, pathzone->aepX, islot, ((float *)&obstacle->posMin)[0], ((float *)&obstacle->posMax)[0]);
    InsertPathzoneEndpoints(pathzone->cep, pathzone->aepY, islot, ((float *)&obstacle->posMin)[1], ((float *)&obstacle->posMax)[1]);
    obstacle->pathzone = pathzone;
    pathzone->cep += 2;
    pathzone->stamp = ++B_003DD490.stamp;
}
