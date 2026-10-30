extern "C" {
char *PjsgeAllocJsg(void *, int);
void AddSeqRecordClimb(void *self, int first, int unused, int third, float amount) {
    char *record = PjsgeAllocJsg(self, 0x1A);
    *(int *)(record + 0x10) = first;
    *(float *)(record + 0x14) = amount;
    *(int *)(record + 0x18) = third;
}
}
