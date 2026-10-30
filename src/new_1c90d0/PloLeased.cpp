struct Pool_1CB2E0 { int pad; int *clones; };
struct Obj_1CB2E0 { char pad[0xE0]; Pool_1CB2E0 *pool; int pad2; int lease; };
struct Obj_1CB2E0;
extern "C" int IcloneFromLease(Obj_1CB2E0 *, int);
extern "C" int PloLeased(Obj_1CB2E0 *self) {
    int lease = self->lease;
    if (lease == 0) {
        return 0;
    }
    return self->pool->clones[IcloneFromLease(self, lease)];
}
