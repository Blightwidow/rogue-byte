struct Obj_12D8D8;
struct VT_12D8D8 {
    char pad0[8];
    short deltaA;
    short unusedA;
    void (*fnA)(void *);
    short deltaB;
    short unusedB;
    void (*fnB)(void *);
};
struct Obj_12D8D8 {
    char pad0[0x18];
    VT_12D8D8 *vt;
};
struct Self_12D8D8 {
    char pad0[4];
    void *field4;
    void *field8;
    char padC[4];
    Obj_12D8D8 *next;
    char pad14[8];
    Obj_12D8D8 *current;
};
extern "C" void InvalidateXfSegment(void *, void *);
extern "C" void ReselectActadj(Self_12D8D8 *self) {
    if (self->current != self->next) {
        InvalidateXfSegment(self->field4, self->field8);
        Obj_12D8D8 *old = self->current;
        if (old != 0) {
            old->vt->fnB((char *)old + old->vt->deltaB);
        }
        Obj_12D8D8 *fresh = self->next;
        self->current = fresh;
        if (fresh != 0) {
            fresh->vt->fnA((char *)fresh + fresh->vt->deltaA);
        }
    }
}
