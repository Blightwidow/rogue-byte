extern "C" int GetSoSelfImpactDamage(void* pso)
{
    return -*(signed char*)((unsigned char*)pso + 0x149);
}
