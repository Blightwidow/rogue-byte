extern "C" {
char *PjsgeAllocJsg(void *, int, int);
void SetMethod__4CRefP7CMethod(void *self, int first, int second) {
    char *record = PjsgeAllocJsg(self, 0x21, 0);
    *(int *)(record + 0x10) = first;
    *(int *)(record + 0x14) = second;
}
}
