struct LOBITS { long pad : 48; long f48 : 4; long f52 : 4; unsigned long f56 : 1; unsigned long f57 : 1; unsigned long f58 : 1; };
extern "C" {
void *AppendSlEntry(void *, void *);
void CFramePtr_Assign(char *, int *);
void CFrame_DeletingDestructor(int *, int);
void CRef_Destruct(void *);
void ClearSl(void *);
void ClearSle(void *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
int FreeSlotheapPv(void *, void *);
void PframeClone(int **, int, char *);
void PsidebagClone(int **, int, char *);
char *PvAllocSwCopyImpl__FiPv(int *, char *);
void SidebagPtr_Assign(char *, int *);
int UnlinkSidebagNode(int *);
int UnlinkVarbNode(int *);
void VarbPtr_Destructor(void *, int);
void func_00128148(void *);
void *func_0015E3C0(void *, int);
int func_00258178(int);
int func_00259A88(int);
extern char B_003DD490[];
extern char B_004520D0[];
extern char B_00452148[];
extern char g_2dd598[];
void CLo_Clone(char *self, char *source);
}
void CLo_Clone(char *self, char *source) {
    struct Holder { int *pointer; int pad[3]; } holder;
    int request[2];
    func_00128148(g_2dd598);
    int sourceSidebag = *(int *)(source + 4);
    if (sourceSidebag != 0) {
        PsidebagClone(&holder.pointer, sourceSidebag, self);
        int *sidebag;
        SidebagPtr_Assign(self + 4, holder.pointer);
        sidebag = holder.pointer;
        if (sidebag != 0) {
            int remaining = *sidebag - 1;
            *sidebag = remaining;
            if (remaining == 0) {
                int *varb = (int *)sidebag[2];
                if (varb != 0) {
                    int varbRemaining = *varb - 1;
                    *varb = varbRemaining;
                    if (varbRemaining == 0) {
                        VarbPtr_Destructor(varb + 0x5, 2);
                        CRef_Destruct(varb + 0x3);
                        UnlinkVarbNode(varb);
                        FreeSlotheapPv(B_004520D0, varb);
                    }
                }
                UnlinkSidebagNode(sidebag);
                FreeSlotheapPv(B_00452148, sidebag);
            }
        }
        func_00258178(*(int *)(self + 4));
    }
    int sourceFrame = *(int *)source;
    if (sourceFrame != 0) {
        PframeClone(&holder.pointer, sourceFrame, self);
        CFramePtr_Assign(self, holder.pointer);
        int *frame = holder.pointer;
        if (frame != 0) {
            int frameRemaining = *frame - 1;
            *frame = frameRemaining;
            if (frameRemaining == 0) {
                CFrame_DeletingDestructor(frame, 3);
            }
        }
        func_00259A88(*(int *)self);
    }
    *(float *)(self + 0x38) = *(float *)(source + 0x38);
    LOBITS *destinationBits = (LOBITS *)(self + 0x28);
    LOBITS *sourceBits = (LOBITS *)(source + 0x28);
    destinationBits->f52 = sourceBits->f52;
    destinationBits->f57 = sourceBits->f57;
    destinationBits->f48 = sourceBits->f48;
    destinationBits->f58 = sourceBits->f58;
    int sourceLink = *(int *)(source + 0x40);
    if ((sourceLink ^ 1) & 1) {
        sourceLink = *(int *)sourceLink;
    }
    int selfLink = *(int *)(self + 0x40);
    int cleared = sourceLink & ~1;
    if ((selfLink ^ 1) & 1) {
        *(int *)selfLink = cleared | (*(int *)selfLink & 1);
    } else {
        *(int *)(self + 0x40) = cleared | (selfLink & 1);
    }
    *(int *)(self + 0x34) = *(int *)(source + 0x34);
    char *destination;
    char *sourceData = source + 0x50;
    if (*(int *)(B_003DD490 + 0x3F10) != -2) {
        destination = self + 0x50;
        *(int *)(self + 0x3C) = *(int *)(source + 0x3C);
    } else {
        char *node = *(char **)(source + 0x3C);
        destination = self + 0x50;
        if (node != 0 && *(char **)(node + 0x10) == source) {
            request[0] = 0x28;
            do {
                request[1] = 0x10;
                char *copy = PvAllocSwCopyImpl__FiPv(request, node);
                *(char **)(copy + 0x10) = self;
                ClearSle(copy + 0xC);
                ClearSle(copy + 0x14);
                ClearSl(copy + 0x18);
                AppendSlEntry(*(char **)(copy + 4) + 0x18, copy);
                AppendSlEntry(func_0015E3C0(B_003DD490, *(int *)(copy + 8)), copy);
                node = *(char **)(node + 4);
                if (node == 0) {
                    break;
                }
                if (*(char **)(node + 0x10) != source) {
                    break;
                }
                request[0] = 0x28;
            } while (1);
        }
    }
    char *vtable = *(char **)(self + 0xC);
    char *(*getInfo)(char *) = *(char *(**)(char *))(vtable + 0x34);
    CopyAb__FPvT0Ui(destination, sourceData, *(int *)(getInfo(self + *(short *)(vtable + 0x30)) + 0xC) - 0x50);
}
