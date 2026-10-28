int GetStreamAmbKind(void* arg0) {
    int v1 = *(int*)(((char*)arg0) + 0x3B8);
    int a0 = 1;
    int v0 = 2;
    v1 = v1 & 4;
    if (v1 == 0) {
        v0 = a0;
    }
    return v0;
}
