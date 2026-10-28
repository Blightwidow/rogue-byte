struct PHYS {
    char pad0[0x80];
    float gravityX;
    float gravityY;
    float gravityZ;
    char pad1[0x14];
    int torque;
    char pad2[0x1C];
    int force;
};
struct SO {
    char pad[0xE8];
    PHYS *phys;
};
extern "C" void func_001F3590(SO *so)
{
    float *gravity = &so->phys->gravityX;
    gravity[0] = 0.0f;
    gravity[2] = -1750.0f;
    gravity[1] = 0.0f;
    so->phys->force = 3;
    so->phys->torque = 3;
}
