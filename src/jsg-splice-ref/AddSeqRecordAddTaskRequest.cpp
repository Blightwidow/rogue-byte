extern "C" {
char *PjsgeAllocJsg(void *, int, int);
void AddSeqRecordAddTaskRequest(void *self, int first, int second) {
    char *record = PjsgeAllocJsg(self, 0x11, 1);
    *(int *)(record + 0x10) = first;
    *(int *)(record + 0x14) = second;
}
}
