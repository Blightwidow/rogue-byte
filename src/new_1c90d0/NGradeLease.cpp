#include "sly2.h"
struct LO { char pad[0x28]; unsigned long grfo; };
struct SET { int cpalo; LO **apalo; };
struct POOL { char pad[0xE0]; SET *set; };
struct LEASE { int locked; int owner; int fixed; };
extern "C" int IcloneFromLease(POOL *, LEASE *);
extern "C" int FIsLoInWorld(LO *);

int NGradeLease(POOL *pool, LEASE *lease)
{
    if (lease->fixed != 0)
        return 0;
    if (lease->locked == 0)
        return 4;
    int grade = 5;
    int iclone = IcloneFromLease(pool, lease);
    for (int index = 0; index < pool->set->cpalo; index++) {
        LO *lo = pool->set->apalo[iclone * pool->set->cpalo + index];
        int objectGrade;
        if (((int)(lo->grfo >> 60) & 1) != 0) {
            if (FIsLoInWorld(lo) != 0) {
                grade = 1;
                goto done;
            }
            objectGrade = 2;
        } else
            objectGrade = 3;
        if (objectGrade < grade)
            grade = objectGrade;
    }
done:
    return grade;
}
