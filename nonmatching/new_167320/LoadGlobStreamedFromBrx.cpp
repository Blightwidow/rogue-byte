#include "sly2.h"
struct BIS;
struct REQ { int size; int align; };
struct REC { char pad0[1]; char count; char pad2[0xA]; int base; };
struct REC2 { char pad0[0x18]; char *arr; };
struct UNP { unsigned short w[0x20]; };
struct L {
    char vifs[0x30];
    int frame0;
    char pad44[0xC];
    REQ req;
    char pad58[8];
    int frame1;
    UNP *punpack;
    int dmaOut;
};
extern "C" {
void __4VIFS(void *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void AllocStack__4DMASi(void *, int);
void AddDmaCnt__4DMAS(void *);
char U8Read__18CBinaryInputStream(BIS *);
int U16Read__18CBinaryInputStream(BIS *);
int S16Read__18CBinaryInputStream(BIS *);
int S32Read__18CBinaryInputStream(BIS *);
void *PvAllocSwClearImpl__Fi(REQ *);
void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int, UNP **);
void AddVifStcycl__4VIFSii(void *, int, int);
void VIFS_AddVifUnpackFromStream(void *, int, int, BIS *, int);
void AddVifStrow__4VIFSP2QW(void *, void *);
void AddVifStmask__4VIFSUi(void *, int);
void AddVifMscal__4VIFSPv(void *, void *);
void EndDmaCnt__4DMAS(void *);
void AddDmaRet__4DMAS(void *);
void DMAS_DetachCopyPermanent(void *, void *, void *, void *);
void *PshdFromIndex(int);
int func_001EC688(void *, int, int, void *);
void func_001699E8(void *, REC *, REC2 *, int, int, int, int, int, BIS *);
extern char B_002DEB60[];
extern int D_002BE540[];
extern int D_002BE558[];
extern char VU1_START_0[];
extern char D_00001910[];
extern char D_00001A68[];
}
extern "C" void LoadGlobStreamedFromBrx(char *glob, REC *rec, REC2 *rec2, int unused, int arg4, int arg5, BIS *stream)
{
    L l;
    int count = 0;
    *(unsigned long *)(glob + 0x50) |= 0x8000L << 18;
    __4VIFS(l.vifs);
    CStackFrame_Construct(&l.frame0);
    AllocStack__4DMASi(l.vifs, 0x2000);
    AddDmaCnt__4DMAS(l.vifs);
    char nrec = U8Read__18CBinaryInputStream(stream);
    rec->count = nrec;
    l.req.size = nrec * 0x50;
    l.req.align = 0x10;
    rec2->arr = (char *)PvAllocSwClearImpl__Fi(&l.req);
    int offset = 0;
    for (; count < rec->count; count++) {
        char *pentry = rec2->arr + offset;
        offset += 0x50;
        *(int *)pentry = S32Read__18CBinaryInputStream(stream);
        *(int *)(pentry + 8) = S16Read__18CBinaryInputStream(stream);
    }
    int base = 0x1B;
    if (rec->count != 0) {
        rec->base = 0x1B;
        base = rec->count * 4 + 0x1B;
    }
    int index = 0;
    int ncmd = S16Read__18CBinaryInputStream(stream);
    if (ncmd > 0) {
        do {
            CStackFrame_Construct(&l.frame1);
            UnpackHelper__4VIFS3UPKiiPiPPUi(l.vifs, 0xD, 4, 0xA, 0, &l.punpack);
            memset(l.punpack, 0, 0x20);
            switch (index) {
            case 0:
                l.punpack->w[0] |= 1;
                if (ncmd == 1)
                    l.punpack->w[0] |= 8;
                break;
            case 1:
                l.punpack->w[0] |= 2;
                break;
            }
            if (rec->count != 0)
                l.punpack->w[0] |= 4;
            int cursor = base;
            int slot = 0;
            l.punpack->w[1] = cursor;
            int next = index + 1;
            char *pshd = (char *)PshdFromIndex(U16Read__18CBinaryInputStream(stream));
            if (*(int *)(pshd + 0x1C) > 0) {
                do {
                    l.punpack->w[slot + 0xA] = cursor;
                    cursor += func_001EC688(pshd, slot, cursor, l.vifs);
                    slot++;
                } while (slot < *(int *)(pshd + 0x1C));
            }
            int nverts = U8Read__18CBinaryInputStream(stream);
            AddVifStcycl__4VIFSii(l.vifs, 1, 2);
            VIFS_AddVifUnpackFromStream(l.vifs, 8, nverts, stream, cursor + 1);
            l.punpack->w[4] = cursor;
            cursor += nverts * 2;
            l.punpack->w[5] = cursor;
            if (rec->count != 0) {
                slot = 0;
                int nweights = U8Read__18CBinaryInputStream(stream);
                if (nweights > 0) {
                    do {
                        l.punpack->w[slot + 0xC] = rec->base + U8Read__18CBinaryInputStream(stream) * 4;
                        slot++;
                    } while (slot < nweights);
                }
                int short4 = nweights < 4;
                if (slot < 4) {
                    do {
                        l.punpack->w[slot + 0xC] = l.punpack->w[0xC];
                        slot++;
                    } while (slot < 4);
                }
                if (short4) {
                    AddVifStrow__4VIFSP2QW(l.vifs, B_002DEB60);
                    AddVifStmask__4VIFSUi(l.vifs, D_002BE540[nweights]);
                }
                VIFS_AddVifUnpackFromStream(l.vifs, D_002BE558[nweights], nverts, stream, l.punpack->w[4]);
                if (short4)
                    AddVifStmask__4VIFSUi(l.vifs, 0);
            }
            index = next;
            AddVifStcycl__4VIFSii(l.vifs, 1, 1);
            int ncolors = U8Read__18CBinaryInputStream(stream);
            VIFS_AddVifUnpackFromStream(l.vifs, 0xE, ncolors, stream, cursor);
            l.punpack->w[6] = cursor;
            cursor += ncolors;
            l.punpack->w[7] = cursor;
            cursor += 1;
            l.punpack->w[8] = cursor;
            l.punpack->w[9] = cursor;
            AddVifMscal__4VIFSPv(l.vifs, VU1_START_0);
            AddVifMscal__4VIFSPv(l.vifs, D_00001910);
            AddVifMscal__4VIFSPv(l.vifs, D_00001A68);
            CStackFrame_Destructor(&l.frame1, 2);
        } while (index < ncmd);
    }
    EndDmaCnt__4DMAS(l.vifs);
    AddDmaRet__4DMAS(l.vifs);
    DMAS_DetachCopyPermanent(l.vifs, (char *)rec + 0x10, &l.dmaOut, (char *)rec2 + 0x10);
    func_001699E8(glob, rec, rec2, arg4, arg5, 0, 0, 0, stream);
    CStackFrame_Destructor(&l.frame0, 2);
}
