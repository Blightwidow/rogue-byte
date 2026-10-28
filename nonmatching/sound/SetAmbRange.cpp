struct AMB { char pad[0x30]; float lmMin; float lmMax; };
extern "C" void SetAmbRange(AMB *pamb, float lmMin, float lmMax)
{
    pamb->lmMax = lmMax;
    if (lmMax <= lmMin) { lmMax = lmMin + 1.0f; pamb->lmMax = lmMax; }
    pamb->lmMin = lmMin;
}
