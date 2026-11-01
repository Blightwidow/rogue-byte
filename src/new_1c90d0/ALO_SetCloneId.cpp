struct VT1CA308 { char pad[0xC8]; short delta; short index; void (*fn)(void *, int, int); };
struct LO1CA308 { char pad[0xC]; VT1CA308 *vt; char pad1[0x24 - 0x10]; LO1CA308 *next; };
struct ALO1CA308 { char pad[0x64]; LO1CA308 *child; };
extern "C" void LO_SetCloneId(ALO1CA308 *, int);
extern "C" void ALO_SetCloneId(ALO1CA308 *alo, int cloneId)
{
    int dead[4];
    (void)dead;
    LO_SetCloneId(alo, cloneId);
    for (LO1CA308 *child = alo->child; child != 0; child = child->next) {
        VT1CA308 *vt = child->vt;
        vt->fn((char *)child + vt->delta, cloneId, 0);
    }
}
