// SPDX-License-Identifier: GPL-3.0-or-later
struct AMB { char pad[0x30]; float lmMin; float lmMax; };
extern "C" void SetAmbRange(AMB *pamb, float lmMin, float lmMax)
{
if (lmMax <= lmMin) lmMax = lmMin + 1.0f; pamb->lmMin = lmMin; pamb->lmMax = lmMax;
}
