#include "sly2.h"
struct BIS;
#include "alloc.h"
struct B8 { char b[8]; };
struct OIDB { B8 q[8]; };
struct OIDV { int pad0[2]; int w8; char pad[0x38 - 0xC]; int w38; int w3C; };
struct ENT {
    OIDB oid;
    int ref40;
    ENT *next;
    int ref48;
    int f4C;
    float f50;
    int count;
    void *data;
};
struct REC { char pad[0x40]; int id; REC *next; };
struct SNDOBJ {
    char pad0[0x18];
    int nmap;
    char pad1[0xA8 - 0x1C];
    OIDB oid;
    int bank;
    ENT *ents;
    REC *recs;
    void *amb;
    int nbank;
    int *banks;
    int *map;
    char pad2[0x1D0 - 0x104];
    int nstream;
    int streams[6];
    char pad3[0x228 - 0x1EC];
    char ambTarget[1];
};
extern "C" {
int S8Read__18CBinaryInputStream(BIS *);
int S16Read__18CBinaryInputStream(BIS *);
int S32Read__18CBinaryInputStream(BIS *);
int U8Read__18CBinaryInputStream(BIS *);
float F32Read__18CBinaryInputStream(BIS *);
int CBinaryInputStream_Read_thunk(BIS *, int, void *);
void func_00118458(BIS *, void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *NewStreamAmb(void *, int);
void func_00259B48(void *, void *);
void snd_UnloadBank(int);
int snd_FlushSoundCommands(void);
extern int B_002E1E54;
}
static inline void *AllocClear(ALLOCREQ *request, int size)
{
    request->cb = size;
    request->cbAlign = 0x10;
    return PvAllocSwClearImpl__Fi(request);
}
static inline void *AllocPlain(ALLOCREQ *request, int size)
{
    request->cb = size;
    request->cbAlign = 0x10;
    return PvAllocSwImpl__Fi(request);
}
static inline int OidEqual(const OIDV *a, const OIDV *b)
{
    if (a == b) return 1;
    if (b == 0) return 0;
    return (a->w8 ^ a->w38) == (b->w8 ^ b->w38);
}
void LoadSndFromBrx(SNDOBJ *snd, BIS *stream)
{
    OIDB oid;
    ALLOCREQ req;
    OIDB tmp;
    func_00118458(stream, &oid);
    if (!OidEqual((OIDV *)&oid, (OIDV *)&snd->oid)) {
        snd->oid = oid;
        if (snd->bank != 0) {
            snd_UnloadBank(snd->bank);
            while (snd_FlushSoundCommands() != 0) {
            }
            snd->bank = 0;
        }
    }
    snd->nbank = S16Read__18CBinaryInputStream(stream);
    snd->banks = (int *)AllocClear(&req, snd->nbank * 4);
    for (int ibank = 0; ibank < snd->nbank; ibank++) {
        int *slot = snd->banks + ibank;
        *slot = S8Read__18CBinaryInputStream(stream);
    }
    snd->nmap = S16Read__18CBinaryInputStream(stream);
    snd->map = (int *)AllocPlain(&req, snd->nmap * 4);
    memset(snd->map, -1, snd->nmap * 4);
    for (int imap = 0; imap < snd->nbank; imap++) {
        snd->map[S16Read__18CBinaryInputStream(stream)] = imap;
    }
    snd->nstream = S16Read__18CBinaryInputStream(stream);
    if (snd->nstream > 0) {
        void *header = AllocClear(&req, 0x40);
        snd->amb = header;
        func_00118458(stream, header);
        void *amb = NewStreamAmb(snd->amb, 4);
        func_00259B48(snd->ambTarget, amb);
    }
    memset(snd->streams, -1, 0x18);
    for (int istream = 0; istream < snd->nstream; istream++) {
        snd->streams[istream] = S16Read__18CBinaryInputStream(stream);
    }
    int ntrack = U8Read__18CBinaryInputStream(stream);
    int pick = 0;
    for (int itrack = 0; itrack < ntrack; itrack++) {
        pick = (U8Read__18CBinaryInputStream(stream) ^ B_002E1E54) == 0 ? itrack : pick;
    }
    struct { int count; ENT *items; } list;
    list.count = S32Read__18CBinaryInputStream(stream);
    list.items = (ENT *)AllocClear(&req, list.count * 0x5C);
    int entIndex;
    for (entIndex = 0; entIndex < list.count; entIndex++) {
        ENT *ent = list.items + entIndex;
        ent->ref40 = S16Read__18CBinaryInputStream(stream);
        ent->ref48 = S16Read__18CBinaryInputStream(stream);
        for (int index = 0; index < ntrack; index++) {
            func_00118458(stream, &tmp);
            int a = S8Read__18CBinaryInputStream(stream);
            float f = F32Read__18CBinaryInputStream(stream);
            if (index == pick) {
                ent->oid = tmp;
                ent->f4C = a;
                ent->f50 = f;
            }
        }
        ent->count = S32Read__18CBinaryInputStream(stream);
        req.cb = ent->count * 8;
        req.cbAlign = 0x10;
        ent->data = PvAllocSwImpl__Fi(&req);
        CBinaryInputStream_Read_thunk(stream, ent->count * 8, ent->data);
        snd->ents = ent;
        ent->next = snd->ents;
    }
    int nrec = S32Read__18CBinaryInputStream(stream);
    REC *rec = (REC *)AllocClear(&req, nrec * 0x48);
    if (nrec > 0) {
        do {
            nrec--;
            rec->id = S16Read__18CBinaryInputStream(stream);
            func_00118458(stream, rec);
            rec->next = snd->recs;
            snd->recs = rec;
            rec++;
        } while (nrec != 0);
    }
}
