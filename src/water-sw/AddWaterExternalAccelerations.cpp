struct SO;
struct VTable { char pad[0x240]; short delta; short index; void (*function)(void *, void *, float); };
struct SO { char pad[0xC]; VTable *vtable; };
struct XA { char pad[4]; SO *target; };
void AddWaterExternalAccelerations(void *water, XA *xa, float dt)
{
    SO *target = xa->target;
    VTable *vtable = target->vtable;
    vtable->function((char *)target + vtable->delta, water, dt);
}
