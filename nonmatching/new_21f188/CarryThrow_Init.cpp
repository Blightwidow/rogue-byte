struct CT { int owner; int state; char pad0[0xC]; float f14; float f18; float f1C; float f20; float f24; float f28; char pad1[4]; float x30; char pad2[0x8C]; float x0; };
struct V3 { float x, y, z; };
void CarryThrow_Init(CT *c, int owner)
{
    V3 *omega = (V3 *)((char *)c + 0x30);
    V3 *aim = (V3 *)((char *)c + 0xC0);
    V3 *launch = (V3 *)((char *)c + 0xD0);
    c->f1C = 500.0f;
    c->f20 = 1500.0f;
    c->f24 = 1.5f;
    c->owner = owner;
    c->state = -1;
    c->f18 = c->f14 = 1.0f;
    c->f28 = 1000.0f;
    omega->x = 0.0f; omega->y = 0.0f; omega->z = 25.0f;
    aim->x = 1000.0f; aim->y = 0.0f; aim->z = 0.0f;
    launch->x = 42.0f; launch->y = -73.0f; launch->z = -50.0f;
}
