// 0x15E938 PloFindSwObject_thunk
extern "C" {
typedef struct LO LO;
typedef struct SW SW;
LO* PloFindSwObject(SW* psw, int grffso, int oid, LO* ploContext, void* pownerContext);
LO* PloFindSwObject_thunk(SW* psw, int grffso, int oid, LO* ploContext);
}

LO* PloFindSwObject_thunk(SW* psw, int grffso, int oid, LO* ploContext)
{
    return PloFindSwObject(psw, grffso, oid, ploContext, (void*)0);
}
