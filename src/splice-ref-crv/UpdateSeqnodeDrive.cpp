extern "C" int FSeqnodeRecordDone(char *, char *);
extern "C" void SetSeqnodeDrive(char *, int, int);
extern "C" void UpdateSeqnodeDrive(char *self)
{
    char *record = *(char **)(self + 0x40);
    if (record != 0 && FSeqnodeRecordDone(self, record) != 0) {
        int drive = 1;
        if (*(int *)(*(char **)(self + 0x40)) == 0x1D) drive = *(int *)(*(char **)(self + 0x40) + 0x10) == -1;
        if (drive != 0) {
            SetSeqnodeDrive(self, 0, 0);
        }
    }
}
