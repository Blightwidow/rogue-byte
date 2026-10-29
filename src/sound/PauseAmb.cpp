// SPDX-License-Identifier: GPL-3.0-or-later
struct AMB_1FB018 { char pad[0x4E]; short cPause; };
extern "C" void SetAmbGrf(AMB_1FB018 *, unsigned short, unsigned short);

extern "C" void PauseAmb(AMB_1FB018 *pamb)
{
    pamb->cPause++;
    if (pamb->cPause == 1) SetAmbGrf(pamb, 6, 2);
}
