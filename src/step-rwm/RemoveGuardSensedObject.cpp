struct Entry_208860 { int w[4]; };
struct Sensor_208860 { char pad[0xFC]; int count; Entry_208860 entries[1]; };
extern "C" {
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
Entry_208860 *PentryFindSensorLo(Sensor_208860 *);
void RemoveGuardSensedObject(char *arg0) {
    Entry_208860 *entry = PentryFindSensorLo(*(Sensor_208860 **)(arg0 + 0xF64));
    Sensor_208860 *sensor = *(Sensor_208860 **)(arg0 + 0xF64);
    int count = sensor->count;
    Entry_208860 *limit = &sensor->entries[count - *(int *)(arg0 + 0x3A4)];
    if ((entry != 0) && (entry < limit)) {
        sensor->count = count - 1;
        CopyAb__FPvT0Ui(entry, entry + 1, ((*(Sensor_208860 **)(arg0 + 0xF64))->count - (entry - sensor->entries)) * 0x10);
    }
}
}
