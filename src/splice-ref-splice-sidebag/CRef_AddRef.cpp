struct VT { char pad[8]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct CRef { int tagk; int *p; };
extern "C" void CRef_AddRef(CRef *pref)
{
    switch (pref->tagk) {
    case 27:
        pref->p[0x10]++;
        break;
    case 26:
    case 28:
        pref->p[4]++;
        break;
    case 29:
        pref->p[2]++;
        break;
    case 30:
        pref->p[3]++;
        break;
    case 33: {
        OBJ *pobj = (OBJ *)pref->p;
        if (pobj != 0)
            pobj->vt->fn((char *)pobj + pobj->vt->delta);
        break;
    }
    case 31:
    case 32:
    case 34:
        pref->p[0]++;
        break;
    }
}
