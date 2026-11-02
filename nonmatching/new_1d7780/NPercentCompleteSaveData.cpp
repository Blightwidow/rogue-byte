struct CRef { int tagk; int n; int p2; int p3; };
struct ENT { short sym; signed char kind; unsigned char count; unsigned short offset; short pad[2]; };
struct TBL { int count; ENT *ents; };
extern "C" {
extern int B_003DD490[];
extern int D_002C2DC0[];
extern const char RO_002A78F0[];
void CRef_Destruct(CRef *);
void RefGetGameSaveValue(CRef *, int, unsigned char *);
int SymidFindSymtab(void *, const char *);
int NPercentCompleteSaveData(TBL *tbl, unsigned char *save)
{
    int total = 0;
    int possible = 0;
    int *pweight = D_002C2DC0;
    int *pid = B_003DD490 + 0x3B7C / 4;
    int index = 8;
    do {
        int weight = *pweight;
        int id = *pid;
        possible += weight * 100;
        if (id != 0) {
            CRef ref;
            RefGetGameSaveValue(&ref, id, save);
            int n = ref.n;
            CRef_Destruct(&ref);
            total += n * weight;
        }
        pweight++;
        index--;
        pid++;
    } while (index >= 0);
    possible += 0xD0;
    int symid = SymidFindSymtab((char *)tbl + 8, RO_002A78F0);
    int i = 0;
    if (tbl->count > 0) {
        int offset = 0 * 10;
loop:
        int next = i + 1;
        ENT *ent = (ENT *)((char *)tbl->ents + offset);
        if (ent->kind == 4) {
            i = next;
            if (ent->sym == symid) {
                unsigned char *bits = save + ent->offset;
                int count = ent->count;
                if (count != 0) {
                    int j = 0;
                    if (count != 0) {
                        do {
                            int bit = (1 << (j % 8)) & 0xFF;
                            int has = bits[j / 8] & bit;
                            j++;
                            if (has) total += 0x1A;
                        } while (j < count);
                    }
                } else {
                    if (*bits != 0) total += 0x1A;
                }
                goto tail;
            }
        } else {
tail:
            i = next;
        }
        if (i < tbl->count) {
            offset = i * 10;
            goto loop;
        }
    }
    int result = 0;
    if (total != 0) {
        result = 100;
        if (total != possible) {
            int pct = total * 100 / possible;
            result = 1;
            if (pct > 0) result = pct <= 99 ? pct : 99;
        }
    }
    return result;
}
}
