struct ASEG; enum OID { OID_dummy };
float TFindAsegLabel(ASEG *, OID);
struct PAIR { float t; float dt; };
void FillBlAmrsg(int cbBl, int cbl, void *abl, int ibMrsg, int coid, OID *aoid)
{
    int i;
    for (int ibl = 0; ibl < cbl; ibl++) {
        char *pbl = (char *)abl + ibl * cbBl;
        char *paseg = *(char **)(pbl + 4);
        if (paseg == 0)
            continue;
        PAIR *p = (PAIR *)(pbl + ibMrsg);
        PAIR *amrsg = p;
        OID *oid = aoid;
        for (i = 0; i < coid; i++) {
            p->t = TFindAsegLabel((ASEG *)paseg, aoid[i]);
            p++;
        }
        p = amrsg;
        PAIR *prev = p + (coid - 1);
        for (i = 0; i < coid; i++) {
            float dt = p->t - prev->t;
            prev->dt = dt;
            if (dt < 0.0f)
                prev->dt = dt + *(float *)(paseg + 0x74);
            prev = p;
            p++;
        }
    }
}
