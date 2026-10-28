struct VT { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0xC]; VT *vt; };
struct Animref { int type; int unk4; Obj *pobj; };
extern "C" {
void RetractAsega(Obj *);
void RetractSma(Obj *);
void CancelJumper(Obj *);
void func_0020CA48(Obj *);
}

void StopAnimref(Animref *p)
{
    switch (p->type) {
    case -1:
        return;
    case 0:
        if (!p->pobj) return;
        RetractAsega(p->pobj);
        break;
    case 1:
        if (!p->pobj) return;
        RetractSma(p->pobj);
        break;
    case 2:
        if (!p->pobj) return;
        CancelJumper(p->pobj);
        break;
    case 3:
        if (!p->pobj) return;
        func_0020CA48(p->pobj);
        break;
    default:
        return;
    }
    Obj *pobj = p->pobj;
    pobj->vt->fn((char *)pobj + pobj->vt->delta);
    p->pobj = 0;
}
