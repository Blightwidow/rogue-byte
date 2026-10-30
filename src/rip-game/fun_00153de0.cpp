// SPDX-License-Identifier: GPL-3.0-or-later
struct SENSORENTRY_153DE0 { int state; int arg; char pad[8]; };
struct SENSOR_153DE0 { char pad[0xFC]; int centry; SENSORENTRY_153DE0 aentry[1]; };
extern "C" int NNextSensorState(SENSOR_153DE0 *, int, int);
extern "C" void SetSensorEntryState(SENSOR_153DE0 *, SENSORENTRY_153DE0 *, int);
extern "C" void func_00153DE0(SENSOR_153DE0 *psensor)
{
    for (int i = 0; i < psensor->centry; i++) {
        SENSORENTRY_153DE0 *pentry = &psensor->aentry[i];
        SetSensorEntryState(psensor, pentry, NNextSensorState(psensor, pentry->state, pentry->arg));
    }
}
