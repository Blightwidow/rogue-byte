struct Bytes48_22B220 { unsigned char b[0x48]; };
extern "C" {
static inline int Equal_22B220(char *lhs, char *rhs) {
    if (lhs == rhs) return 1;
    if (rhs == 0) return 0;
    if (lhs != 0) return (*(int *)(rhs + 8) ^ *(int *)(rhs + 0x38)) == (*(int *)(lhs + 8) ^ *(int *)(lhs + 0x38));
    return 0;
}
int PloFindSwObject_thunk(void *, int, int, int);
int SetSwLoadRequest(void *, int *);
void SetWipeWipes(void *, int);
extern char B_003DD490[];
extern char B_003E10D0[];
void ActivateWipe(char *self, int *request, int arg2, int arg3) {
    switch (*(int *)self) {
    case 2:
        SetWipeWipes(self, 0);
    default: {
        char *other = (char *)request + 4;
        int equal = Equal_22B220(other, B_003E10D0);
        int flags = *request;
        if (equal != 0) {
            flags = flags | 2;
        } else {
            flags = flags & ~2;
        }
        *request = flags;
        int found = PloFindSwObject_thunk(B_003DD490, 0x405, arg2, 0);
        *(int *)(self + 0x54) = found;
        if (found == 0) {
            SetSwLoadRequest(B_003DD490, request);
            return;
        }
        *(int *)(self + 4) = 1;
        *(Bytes48_22B220 *)(self + 8) = *(Bytes48_22B220 *)request;
        *(int *)(self + 0x58) = arg2;
        SetWipeWipes(self, arg3);
    }
    case 1:
    case 3:
        return;
    }
}
}
