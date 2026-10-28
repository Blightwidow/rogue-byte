struct Animref { int kind; void *pv; int pad8; int n; };
extern char B_003DD490;
extern "C" {
void LoadDirAnimSet(void *);
void LoadJumpAnim(void *, void *);
void *PloFindSwObject_thunk(void *, int, void *, void *);
int CidGetBasic(void *);
void *PeaFindAsegLabel(void *, int);
void *func_0020C010(int);
void func_0020BD78(void *);
}

void BindAnimref(Animref *ref, void *context)
{
    if (ref->kind != 2) {
        if (ref->kind == 3) {
            LoadDirAnimSet(ref->pv);
            return;
        }
    } else {
        LoadJumpAnim(ref->pv, context);
        return;
    }
    void *plo = PloFindSwObject_thunk(&B_003DD490, 4, ref->pv, context);
    if (plo != 0) {
        switch (CidGetBasic(plo)) {
        case 0x6D:
            if (PeaFindAsegLabel(plo, 0x22) != 0) {
                ref->kind = 2;
                ref->pv = func_0020C010(0x40);
                func_0020BD78(ref->pv);
                *(void **)((char *)ref->pv + 4) = plo;
                LoadJumpAnim(ref->pv, context);
                if (ref->n == -1) ref->n = 0;
            } else {
                ref->pv = plo;
                ref->kind = 0;
            }
            return;
        case 0x6F:
            ref->kind = 1;
            ref->pv = plo;
            if (ref->n == -1) ref->n = 0;
            return;
        default:
            ref->kind = -1;
            return;
        }
    }
    ref->kind = -1;
}
