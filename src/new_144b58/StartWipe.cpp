struct WIPE { char pad0[0x160]; int hAsega; int a164; int a168; int a16C; int a170; };
struct OBJ { char pad0[0x40]; unsigned tag; };
extern "C" char B_003DD490;
extern "C" OBJ *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" void ApplyAsegToHandle(float, float, void *, WIPE *, unsigned, int *);
extern "C" void SetWipeState(WIPE *, int);
void StartWipe(WIPE *wipe, int oid, int arg)
{
    wipe->a170 = arg;
    wipe->a16C = 1;
    wipe->a168 = 1;
    wipe->a164 = 1;
    OBJ *obj = PloFindSwObject_thunk(&B_003DD490, 1, oid, wipe);
    if (obj != 0) {
        unsigned tag = obj->tag;
        if (!(tag & 1))
            *(unsigned *)tag |= 0x100;
        else
            obj->tag = tag | 0x100;
        ApplyAsegToHandle(0.0f, 1.0f, obj, wipe, 4, &wipe->hAsega);
        SetWipeState(wipe, 0);
    }
}
