#include "sly2.h"
struct LEASE { int a; };
struct SET { char pad[8]; int cclone; int icloneFree; };
struct POOL { char pad[0xE0]; SET *set; int fixed; LEASE *head; };
extern "C" int NGradeLease(POOL *, LEASE *);
extern "C" LEASE *PleaseFromIclone(POOL *, int);

LEASE *PleaseFindBest(POOL *pool, int gradeMin)
{
    LEASE *best;
    if (pool->fixed == 0 && pool->head != 0) {
        if (NGradeLease(pool, pool->head) < 3)
            return 0;
        best = pool->head;
    } else {
        int bestGrade = gradeMin;
        SET *set = pool->set;
        best = 0;
        for (int iclone = set->icloneFree; iclone < pool->set->cclone; iclone++) {
            LEASE *candidate = PleaseFromIclone(pool, iclone);
            int grade = NGradeLease(pool, candidate);
            if (grade >= bestGrade) {
                best = candidate;
                bestGrade = grade;
            }
        }
    }
    return best;
}
