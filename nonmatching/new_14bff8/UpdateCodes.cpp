struct CODE {
    int pad0;
    int cgrfSequence;
    void (*pfnAction)(int);
    int nArg;
    int igrfMatched;
    int fRemove;
};
struct CODELIST;
struct SLI {
    CODELIST *psl;
    int ppv;
    int ibSle;
    SLI *next;
};
struct CODELIST {
    CODE *first;
    int pad4;
    int ibSle;
    float tFire;
};
extern "C" {
extern float g_2ddf0c;
extern SLI *g_2dd2f8;
void RemoveSlEntry(void *, void *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
void UnmarkAll__10CSplotheap(void *);
}

void UpdateCodes(CODELIST *list)
{
    if (list->tFire != 0.0f) {
        if (list->tFire <= g_2ddf0c) {
            SLI sli;
            CODE *best;
            CODE *code;
            int ibSle;
            sli.psl = list;
            code = list->first;
            best = 0;
            ibSle = list->ibSle;
            sli.ibSle = ibSle;
            sli.next = g_2dd2f8;
            sli.ppv = (int)code + ibSle;
            g_2dd2f8 = &sli;
            while (code) {
                if (code->fRemove) {
                    RemoveSlEntry(list, code);
                    code->igrfMatched = 0;
                    code->fRemove = 0;
                } else if (code->igrfMatched >= code->cgrfSequence) {
                    if (best == 0 || best->cgrfSequence < code->cgrfSequence)
                        best = code;
                }
                CODE *next = *(CODE **)sli.ppv;
                sli.ppv = (int)next + sli.ibSle;
                code = next;
            }
            if (best) {
                SetEmitterUnpositioned(NewEmitter(0x34), 0);
                best->pfnAction(best->nArg);
            }
            UnmarkAll__10CSplotheap(list);
            list->tFire = 0.0f;
            g_2dd2f8 = sli.next;
        }
    }
}
