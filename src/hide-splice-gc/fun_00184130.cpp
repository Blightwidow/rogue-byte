struct VT { char pad[0x18]; short delta18; short index18; void (*fn18)(void *, int, int, int, int, int);
  short delta20; short index20; void (*fn20)(void *, int, void *); };
struct OBJ { char pad0[0xC]; VT *vptr; char pad10[0xFC]; int f10C; int f110; int f114; int f118; char a11C[0x40]; int f15C; char a160[4]; };
extern char B_003DD490[], B_002DEB30[];
extern "C" void TriggerRsmg(void *, int, void *, void *, int);
extern "C" void ApplyTaskStateRequests(void *, int, void *, void *);
extern "C" void StartJsg(int, int);

void func_00184130(OBJ *self, int jt)
{
    self->f10C = jt;
    VT *vt1 = self->vptr;
    vt1->fn20((char *)self + vt1->delta20, 6, self);
    TriggerRsmg(B_003DD490, self->f118, self->a11C, self, 1);
    ApplyTaskStateRequests(B_002DEB30, self->f15C, self->a160, self);
    VT *vt2 = self->vptr;
    vt2->fn18((char *)self + vt2->delta18, 5, 0, 0, 0, 0);
    if (self->f114)
        StartJsg(self->f114, jt);
}
