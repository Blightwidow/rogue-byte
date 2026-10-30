struct CRef { int tagk; int n; int pad[2]; };
extern "C" {
void CPairPtr_Destructor(char *, int);
void CRef_Destruct(CRef *);
int FreeSlotheapPv(void *, int *);
void PpairSerializeIn(int **, int);
int *PvAllocSwClearImpl__Fi(CRef *);
int PvAllocSwImpl__Fi(CRef *);
void RunSpliceBlockEntry(CRef *, char *, int *, int);
int U32Read__18CBinaryInputStream(int);
void Unknown1__18CBinaryInputStream(int);
int UnlinkPairNode(int *);
void func_00128148(void *);
extern int B_003E1C34;
extern char B_004520A8;
extern char g_2dd598;
void ReadSpliceBlock(char *arg0, int arg1, int arg2) {
    CRef ref;
    CRef work;
    int count = U32Read__18CBinaryInputStream(arg2);
    if (count != 0) {
        int index = 0;
        ref.tagk = 0x10;
        ref.n = 0x10;
        int *block = PvAllocSwClearImpl__Fi(&ref);
        ref.tagk = -1;
        block[0] = arg1;
        block[1] = count;
        work.tagk = count * 8;
        work.n = 0x10;
        block[2] = PvAllocSwImpl__Fi(&work);
        if (count > 0) {
            do {
                int *slot = (int *)(block[2] + index * 8);
                PpairSerializeIn((int **)&work, arg2);
                int *pair = *(int **)&work;
                if (pair != 0) {
                    *pair = *pair + 1;
                }
                slot[0] = (int)pair;
                slot[1] = 0;
                if (B_003E1C34 != 0) {
                    Unknown1__18CBinaryInputStream(arg2);
                    Unknown1__18CBinaryInputStream(arg2);
                    Unknown1__18CBinaryInputStream(arg2);
                }
                if (pair != 0) {
                    int remaining = *pair - 1;
                    *pair = remaining;
                    if (remaining == 0) {
                        CPairPtr_Destructor((char *)pair + 0x10, 2);
                        CRef_Destruct((CRef *)(pair + 2));
                        UnlinkPairNode(pair);
                        FreeSlotheapPv(&B_004520A8, pair);
                    }
                }
                index += 1;
            } while (index < count);
        }
        index = 0;
        if (count > 0) {
            int entry = 0;
            do {
                RunSpliceBlockEntry(&work, arg0, block, entry);
                index += 1;
                CRef_Destruct(&work);
                entry = index;
            } while (index < count);
        }
        *(int **)(arg0 + 0x39E8) = block;
        block[3] = *(int *)(arg0 + 0x39EC);
        *(int **)(arg0 + 0x39EC) = block;
        func_00128148(&g_2dd598);
        CRef_Destruct(&ref);
    }
}
}
