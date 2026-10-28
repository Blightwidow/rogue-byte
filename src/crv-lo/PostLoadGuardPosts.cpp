struct Post { int oid0; void *plo0; int oid1; void *plo1; int oid2; void *plo2; int oid3; void *plo3; int pad; };
struct Guard { char pad[0x1010]; int cpost; Post *apost; };
extern "C" {
extern char B_003DD490;
void PostGuardLoad(Guard *);
void *PloFindSwObject_thunk(char *, int, int, Guard *);
void PostLoadGuardPosts(Guard *pguard)
{
    int ipost = 0;
    PostGuardLoad(pguard);
    for (; ipost < pguard->cpost; ipost++) {
        Post *ppost = &pguard->apost[ipost];
        ppost->plo0 = PloFindSwObject_thunk(&B_003DD490, 4, ppost->oid0, pguard);
        ppost->plo1 = PloFindSwObject_thunk(&B_003DD490, 4, ppost->oid1, pguard);
        ppost->plo2 = PloFindSwObject_thunk(&B_003DD490, 4, ppost->oid2, pguard);
        ppost->plo3 = PloFindSwObject_thunk(&B_003DD490, 4, ppost->oid3, pguard);
    }
}
}
