extern "C" {
extern int StopAmb(void *, float); extern int VirtualRefPtr_Assign(void **, int);
void StopSwAmbSfx(int arg0, int arg1, int arg2, void **arg3) {
    void *obj = *arg3;
    if (obj != 0 && (arg1 == -1 || *(int *)((char *)obj + 0x60) == arg1)) {
        StopAmb(obj, 0.0f);
        VirtualRefPtr_Assign(arg3, 0);
    }
}

}
