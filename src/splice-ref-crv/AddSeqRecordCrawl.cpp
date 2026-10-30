extern "C" {
char *PjsgeAllocJsg(void *, int);
void AddSeqRecordCrawl(void *self, int first, int unused, int third, float amountA, float amountB) {
    char *record = PjsgeAllocJsg(self, 0x29);
    *(int *)(record + 0x10) = first;
    *(float *)(record + 0x14) = amountA;
    *(float *)(record + 0x18) = amountB;
    *(int *)(record + 0x1C) = third;
}
}
