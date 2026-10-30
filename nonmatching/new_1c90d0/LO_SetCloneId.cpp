struct VT_1CA118;
struct Obj_1CA118;
struct Node_1CA118 { int id; Node_1CA118 *next; int pad[2]; Obj_1CA118 *owner; };
struct Child_1CA118;
struct ChildVT_1CA118 { char pad[0xC8]; short delta; short unused; void (*fn)(void *, int, int, Child_1CA118 *); };
struct Child_1CA118 { char pad[0xC]; ChildVT_1CA118 *vt; };
struct VT_1CA118 { char pad[0xE0]; short delta; short unused; int (*fn)(void *, Child_1CA118 ***); };
struct Obj_1CA118 { char pad[0xC]; VT_1CA118 *vt; char pad2[0x3C - 0x10]; Node_1CA118 *path; };
struct SetEntry_1CA118 { int kind; char pad[0x68]; };
struct Sw_1CA118 { char pad[0x3F08]; SetEntry_1CA118 *sets; char *cnodes; };
extern "C" int CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" int IsetFromCloneId(int);
extern "C" Node_1CA118 *PcnodeFindOrAddClonePath(void *, int, int *, int *);
extern Sw_1CA118 B_003DD490;
extern "C" void LO_SetCloneId(Obj_1CA118 *self, int cloneId, int flag) {
    int path[16];
    int index = 16;
    Node_1CA118 *node = self->path;
    while (node != 0 && node->id != -1) {
        path[--index] = node->id;
        node = node->next;
    }
    path[--index] = cloneId;
    Node_1CA118 *newPath = PcnodeFindOrAddClonePath(B_003DD490.cnodes, 16 - index, &path[index], &path[index]);
    node = self->path;
    while (node->id != -1 && node->owner == self) {
        node->owner = 0;
        node = node->next;
    }
    node = newPath;
    while (node->id != -1 && B_003DD490.sets[IsetFromCloneId(node->id)].kind == 1 && node->owner == 0) {
        node->owner = self;
        node = node->next;
    }
    self->path = newPath;
    if (flag != 0) {
        struct { int head; Child_1CA118 **list; int tail[2]; } frame;
                CStackFrame_Construct(&frame);
        int count = self->vt->fn((char *)self + self->vt->delta, &frame.list);
        for (int i = 0; i < count;) {
            Child_1CA118 *child = frame.list[i++];
            child->vt->fn((char *)child + child->vt->delta, cloneId, 1, child);
        }
        CStackFrame_Destructor(&frame, 2);
    }
}
