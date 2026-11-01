struct VTable116D28 {
    char pad[0x18];
    short delta;
    short index;
    void (*function)(char *, int);
};
struct Object116D28 {
    VTable116D28 *vtable;
};
struct Holder116D28 {
    int first;
    int second;
    int third;
    int unk0xC;
    int unk0x10;
    Object116D28 *object;
};
void func_00116D28(Holder116D28 *self)
{
    Object116D28 *object = self->object;
    object->vtable->function((char *)object + object->vtable->delta, self->first);
    self->first = 0;
    self->third = 0;
    self->second = 0;
}
