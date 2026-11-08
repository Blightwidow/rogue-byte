struct TASK { char pad0[0x54]; int state; char pad1[0x14]; int done; };
struct FTASK { char pad0[0x94]; int cprereq; TASK **aprereq; };
extern "C" int FTaskPrerequisitesDone(FTASK *ptask)
{
    int result = 1;
    int index = 0;
    if (index < ptask->cprereq) {
        TASK **ppreq = ptask->aprereq;
        do {
            TASK *preq = *ppreq;
            int state = preq->state;
            result = 0;
            if (state >= 2 || (state == 1 && preq->done != 0))
                result = 1;
            ppreq++;
            index++;
            if (result == 0)
                break;
        } while (index < ptask->cprereq);
    }
    return result;
}
