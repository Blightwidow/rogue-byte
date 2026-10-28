struct SMT { int pad0; int from; int to; unsigned grf; int pad10; int pad14; };
struct SM { char pad[0x58]; int csmt; SMT *asmt; };
extern "C" int func_001F0498(SM *, unsigned, int, int);
extern "C" SMT *PsmtChooseRandom(SM *, int, SMT **);
extern "C" SMT *PsmtChooseSmTowards(SM *psm, unsigned mask, int cur, int goal, int unused)
{
    int cgoal;
    if (cur == goal)
        cgoal = 1;
    else
        cgoal = func_001F0498(psm, mask, cur, goal);
    SMT *candidates[64];
    int ccandidate = 0;
    for (int ismt = 0; ismt < psm->csmt; ismt++) {
        SMT *psmt = &psm->asmt[ismt];
        if ((psmt->grf & mask) == 0)
            continue;
        if (psmt->from == cur) {
            if (func_001F0498(psm, mask, psmt->to, goal) == cgoal - 1) {
                candidates[ccandidate++] = psmt;
                continue;
            }
        }
        if ((psmt->grf & 1) != 0) {
            if (psmt->to == cur) {
                if (func_001F0498(psm, mask, psmt->from, goal) == cgoal - 1)
                    candidates[ccandidate++] = psmt;
            }
        }
    }
    if (ccandidate == 0)
        return 0;
    return PsmtChooseRandom(psm, ccandidate, candidates);
}
