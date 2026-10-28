struct VT { char pad[8]; short d1; short i1; void (*f1)(void *); short d2; short i2; void (*f2)(void *); short d3; short i3; void (*f3)(void *); };
struct ACT { char pad0[0x10]; ACT *next; int unk; VT *vt; };
struct ALO;
struct XF { char pad0[0x90]; ACT *top; };
void InvalidateXfSegment(ALO *, XF *);
static inline void CallF1(ACT *a) { a->vt->f1((char *)a + a->vt->d1); }
static inline void CallF2(ACT *a) { a->vt->f2((char *)a + a->vt->d2); }
static inline void CallF3(ACT *a) { a->vt->f3((char *)a + a->vt->d3); }

extern "C" void RemoveXfAct(ALO *palo, XF *pxf, ACT *pact)
{
    ACT *pactTopOld = pxf->top;
    ACT **ppactLink = &pxf->top;
    for (ACT *pactCur = pactTopOld; pactCur != 0; pactCur = pactCur->next) {
        if (pactCur == pact) {
            *ppactLink = pactCur->next;
            if (pxf->top != pactTopOld) {
                InvalidateXfSegment(palo, pxf);
                CallF2(pactTopOld);
                if (pxf->top != 0)
                    CallF1(pxf->top);
            } else if (pactTopOld != 0) {
                CallF3(pactTopOld);
            }
            return;
        }
        ppactLink = &pactCur->next;
    }
}
