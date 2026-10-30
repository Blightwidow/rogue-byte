extern "C" {
void DecrementSwBinocCount(char *);
void DecrementSwShowCount(char *);
void RemoveGrfusr__Fi(int);
void func_00187E08(void *, int);
extern char B_002DFC00;

void ClearHandsOff(char *arg0, int arg1) {
    int count = *(int *)(arg0 + 0x3D78) - 1;
    *(int *)(arg0 + 0x3D78) = count;
    if (count == 0) {
        RemoveGrfusr__Fi(2);
        func_00187E08(&B_002DFC00, 8);
    }
    if (arg1 & 1) {
        DecrementSwShowCount(arg0);
    }
    if (arg1 & 2) {
        DecrementSwBinocCount(arg0);
    }
}
}
