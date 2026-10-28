struct PAIR { int pad[3]; int n; PAIR *next; };
struct CRef { int tagk; float *ptr; int pad; PAIR *pair; };
struct CFrame;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_SetF32(CRef *, float);
void CRef_SetVectorPtr(CRef *, void *);
}
extern "C" CRef *RefOpGetElement(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refElement;
    refElement.tagk = -1;
    PAIR *pair = aref->pair;
    switch (aref->tagk) {
    case 0x1B: {
        int row = pair->n;
        if (carg == 2) {
            CRef_SetVectorPtr(&refElement, aref->ptr + row * 4);
        } else {
            PAIR *next = pair->next;
            CRef_SetF32(&refElement, (aref->ptr + row * 4)[next->n]);
        }
        break;
    }
    case 0x1A:
    case 0x1C:
    case 0x1D:
        {
            int index = pair->n;
            CRef_SetF32(&refElement, aref->ptr[index]);
        }
        break;
    case 0x1E:
        {
            int index = pair->n;
            CRef_SetF32(&refElement, aref->ptr[index]);
        }
        break;
    default:
        break;
    }
    CRef_CopyConstruct(pret, &refElement);
    CRef_Destruct(&refElement);
    return pret;
}
