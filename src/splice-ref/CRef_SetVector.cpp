typedef int QW __attribute__((mode(TI)));
extern "C" {
void CRef_Destruct(char *);
QW *PvAllocSlotheapImpl(void *);
extern char B_00452188[];
char *CRef_SetVector(char *self, QW value)
{
    CRef_Destruct(self);
    *(int *)self = 0x1A;
    QW *vec = PvAllocSlotheapImpl(B_00452188);
    *(int *)((char *)vec + 0x10) = 0;
    *(QW **)(self + 4) = vec;
    *(int *)((char *)vec + 0x10) = *(int *)((char *)vec + 0x10) + 1;
    **(QW **)(self + 4) = value;
    return self;
}
}
