struct Pool_1CB250 { int kind; int *clones; };
struct Obj_1CB250 { char pad[0xE0]; Pool_1CB250 *pool; };
extern "C" int IcloneFromLease(Obj_1CB250 *, int);
extern "C" int PleaseAcquire(Obj_1CB250 *, int);
extern "C" int PloLeaseCloneObject(Obj_1CB250 *self, int flag) {
    int kind = self->pool->kind;
    if (kind == 1) {
        int lease = PleaseAcquire(self, flag ? kind : 2);
        if (lease != 0) {
            return self->pool->clones[IcloneFromLease(self, lease)];
        }
    }
    return 0;
}
