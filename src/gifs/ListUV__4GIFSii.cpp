extern "C" int CheckReg__4GIFSii(void *, int, int);

void ListUV__4GIFSii(char *arg0, int arg1, int arg2) {
    char *temp_v1;
    long value;

    CheckReg__4GIFSii(arg0, 0, 3);
    value = (long)arg1 | (long)(arg2 << 16);
    temp_v1 = *(char **)(arg0 + 0xC);
    *(char **)(arg0 + 0xC) = temp_v1 + 8;
    *(long *)temp_v1 = value;
}
