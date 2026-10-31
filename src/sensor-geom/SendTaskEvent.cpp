struct OBJ_165170 { char pad[0xC]; void *vt; };
struct VT_165170 { char pad[0x18]; short delta; short unused; void (*fn)(void *, int, int, int, int **, int); };
extern "C" {
int FTaskRunning(OBJ_165170 *);
void SendTaskEvent(OBJ_165170 *task, int first, int second) {
    int *pointers[2] __attribute__((aligned(16)));
    int values[2];
    values[0] = first;
    values[1] = second;
    if (FTaskRunning(task)) {
        pointers[0] = &values[0];
        pointers[1] = &values[1];
        VT_165170 *vt = (VT_165170 *)task->vt;
        vt->fn((char *)task + vt->delta, 0x11, 0, 2, pointers, 0);
    }
}
}
