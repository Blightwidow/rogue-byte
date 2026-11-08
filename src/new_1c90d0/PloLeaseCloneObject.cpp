struct Pool_1CB250 { int kind; int *clones; };
struct Obj_1CB250 { char pad[0xE0]; Pool_1CB250 *pool; };
extern "C" int IcloneFromLease(Obj_1CB250 *, int);
extern "C" int PleaseAcquire(Obj_1CB250 *, int);

// Retail tests pool->kind against 1 with one branch to the shared `return 0`, picks the
// grade with `movn a1,v0,a2` (1 when flag is set, else 2) and re-copies self into a0
// before PleaseAcquire. Guard clauses with early returns and a literal `flag ? 1 : 2`
// give that shape; the nested-if form reusing `kind` as the grade drops the a0 copy.
extern "C" int PloLeaseCloneObject(Obj_1CB250 *self, int flag) {
    if (self->pool->kind != 1) return 0;
    int lease = PleaseAcquire(self, flag ? 1 : 2);
    if (lease == 0) return 0;
    return self->pool->clones[IcloneFromLease(self, lease)];
}
