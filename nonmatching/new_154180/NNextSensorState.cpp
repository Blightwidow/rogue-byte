#include "sly2.h"
struct SENSOR { char pad0[0xE4]; char *plist; int e8; int e8b; };
struct VTL { char pad[0x268]; short delta; short pad2; int (*fn)(void *); };
struct LO { char pad0[0xC]; VTL *vptr; };
extern "C" {
void *PpoSwFocusBase(void *);
int FIsLoInWorld(void *);
int FIsBasicDerivedFrom(void *, int);
int FSwBinocActive(void *);
QW PosLoWorld(void *);
QW func_00153E60(void *);
QW ConvertAloPos(void *, void *, QW);
int ClsgClipEdgeToBsp(void *, int, QW, QW, int, void *);
int func_00227C90(int, QW);
int func_00154770(void *, void *);
int FSensorSightBlocked(void *, void *);
}
extern char B_003DD490[];
extern char *B_003E1480;

int NNextSensorState(char *psensor, char *plo, int nstate)
{
    char lsg[0x180];
    QW pos;
    char *pfocus = (char *)PpoSwFocusBase(B_003DD490);
    if (plo == 0 || !FIsLoInWorld(plo))
        { nstate = 0; goto done; }
    if (FIsBasicDerivedFrom(plo, 0x32)) {
        LO *plow = (LO *)plo;
        VTL *vt = plow->vptr;
        if (((int (*)(void *))*(int *)((char *)vt + 0x26C))((char *)plo + vt->delta) == 2)
            { nstate = 0; goto done; }
    }
    if (FIsBasicDerivedFrom(plo, 0x34) && pfocus && FIsBasicDerivedFrom(pfocus, 0x46))
        { nstate = 0; goto done; }
    if (FSwBinocActive(B_003DD490))
        { nstate = 0; goto done; }
    if (*(int *)(psensor + 0xF4))
        { nstate = 0; goto done; }
    if (FIsBasicDerivedFrom(plo, 0x34) && *(int *)(plo + 0x11AC))
        { nstate = 0; goto done; }
    if (*(int *)(psensor + 0xF0))
        { nstate = 1; goto done; }
    if (FIsBasicDerivedFrom(plo, 0x33)) {
        QW base = PosLoWorld(plo);
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2\n\tvadd.xyzw vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m" (pos) : "m" (*(QW *)(plo + 0x240)), "r" (base));
    } else {
        pos = PosLoWorld(plo);
    }
    for (char *psw = B_003E1480; psw; psw = *(char **)(psw + 0x130)) {
        QW a = func_00153E60(psensor);
        QW b = ConvertAloPos(0, psw, a);
        QW c = ConvertAloPos(0, psw, pos);
        if (ClsgClipEdgeToBsp(*(void **)(psw + 0xEC), 0x7FFFFFFF, b, c, 4, lsg) > 0)
            { nstate = 0; goto done; }
    }
    switch (nstate) {
    case 0:
        {
            char *plist = *(char **)(psensor + 0xE4);
            if (plist) {
                char *pnode = *(char **)(plist + 0x64);
                while (pnode) {
                    if (*(char **)(pnode + 0xC) == plo) {
                        if (*(int *)pnode) { nstate = 1; goto done; }
                        break;
                    }
                    pnode = *(char **)(pnode + 4);
                }
            }
            if (!func_00227C90(*(int *)(psensor + 0xE8), pos)) { nstate = 0; goto done; }
            {
                int a0 = *(int *)(psensor + 0xEC);
                if (a0 != 0 && !func_00227C90(a0, pos)) { nstate = 0; goto done; }
            }
            if ((*(int *)(psensor + 0xF8) & 1) == 0 && func_00154770(psensor, plo) != 0) { nstate = 0; goto done; }
            nstate = 1;
            if (!(*(int *)(psensor + 0xF8) & 2))
                nstate = FSensorSightBlocked(psensor, plo) == 0;
        }
        break;
    case 1:
        {
            int a0 = *(int *)(psensor + 0xEC);
            if (a0 == 0 || func_00227C90(a0, pos)) {
                if (func_00227C90(*(int *)(psensor + 0xE8), pos)) {
                    if (*(int *)(psensor + 0xF8) & 8) {
                        if (FSensorSightBlocked(psensor, plo)) nstate = 0;
                    }
                } else {
                    nstate = 2;
                }
            } else {
                nstate = 0;
            }
        }
        break;
    case 2:
        {
            int a0 = *(int *)(psensor + 0xEC);
            if (a0 != 0 && !func_00227C90(a0, pos)) {
                nstate = 0;
            } else if (func_00227C90(*(int *)(psensor + 0xE8), pos)) {
                if (*(int *)(psensor + 0xF8) & 2) {
                    nstate = 1;
                } else if (FSensorSightBlocked(psensor, plo)) {
                    return nstate;
                } else {
                    nstate = 1;
                }
            } else {
                if (*(int *)(psensor + 0xF8) & 8) {
                    if (FSensorSightBlocked(psensor, plo)) nstate = 0;
                }
            }
        }
        break;
    }
done:
    return nstate;
}
