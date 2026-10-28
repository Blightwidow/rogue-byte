struct PHYS {
    char pad0[0xA0];
    int torque;
    char pad1[0x1C];
    int force;
};
struct SO {
    char pad[0xE8];
    PHYS *phys;
};
extern "C" int FIsSoLocked(SO *so)
{
    int result = 0;
    PHYS *phys = so->phys;
    if (phys == 0 || (phys->force == 3 && phys->torque == 3))
        result = 1;
    return result;
}
