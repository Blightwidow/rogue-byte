/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "alloc.h"
struct MOVIE { unsigned record[0x11]; int start; int end; };
struct CFileLocation { unsigned hash; unsigned slot; unsigned kind; unsigned field0C; char path[0x100]; void Clear(); int Set(const MOVIE *movie)
    {
        if (movie == 0) return 0;
        unsigned slotNew = movie->record[1] ^ movie->record[0xF];
        unsigned hashNew = movie->record[0] ^ movie->record[0xD];
        kind = 2;
        hash = hashNew + 0xCA0;
        slot = slotNew;
        return slotNew != 0;
    }
};
struct BLOTX { char pad0[0x58]; int state; int pad5C; int time; };
struct NODE { char pad0[0x40]; BLOTX *blot; int first; int last; NODE *next; };
struct BLOT { char pad0[0x50]; int field50; int field54; char pad58[0x68]; MOVIE *movie; };
struct COUNTERS { char pad[0xC]; int limit; };
struct STREAM { char bytes[0x70]; };
extern "C" {
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void CBinaryFileStream_Destructor(STREAM *, int);
void CBinaryInputStream_ConstructFromBuffer(STREAM *, int, void *, int);
int CBinaryFileStream_FOpenLocation(STREAM *, CFileLocation *);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void SetBlotBlots(BLOTX *, int);
int U16Read__18CBinaryInputStream(STREAM *);
int U8Read__18CBinaryInputStream(STREAM *);
void func_001179D8(STREAM *, int, int);
int func_00233470(const void *, const void *, int);
void LoadMovieDictionary(BLOT *, STREAM *, BLOT *, int *, int *);
void LoadMovieSprites(BLOT *, STREAM *, BLOT *);
extern NODE *B_003E106C;
extern COUNTERS B_003E1C70;
extern int g_2be538;
}
/* Retail: two passes over the movie-blot list (one `node` in $s0 for both loops), the newest end frame kept with slt/movn and
 * stored to B_003E1C70+0xC in Construct's delay slot; then a stack frame, a 0x10000 stack buffer and a file stream at sp+0x20.
 * The request (sp+0x10) and the four magic bytes share one slot: they are scoped to separate blocks. The file location is set
 * by the CFileLocation::Set inline seen in load_file_from_disc (kind 2, slot = r1^r15, hash = (r0^r13)+0xCA0). The failure
 * path (two destructors, then the epilogue) comes before the load path, as with the shared `fail` label.
 * NEAR 24: the only difference is $s1/$s2 swapped. Global allocation orders `latest` (10 weighted refs over 78 insns) before
 * the gcse-hoisted &stream pseudo (13 refs over 116 insns); retail gives &stream $s1. Max forms, `continue` forms, an inline
 * test and inline helpers for either loop did not flip it. */
extern "C" void PrepareBlotMovie(BLOT *pblot)
{
    int latest = 0;
    NODE *node;
    BLOTX *blot;
    for (node = B_003E106C; node != 0; node = node->next) {
        blot = node->blot;
        if (blot->state != 0 && (blot->state != 1 || g_2be538 - blot->time < 2)) {
            int last = node->last;
            latest = latest < last ? last : latest;
        }
    }
    for (node = B_003E106C; node != 0; node = node->next) {
        blot = node->blot;
        if (node->first >= latest && blot->state != 0) SetBlotBlots(blot, 0);
    }
    B_003E1C70.limit = latest;
    char frame[0x10];
    CStackFrame_Construct(frame);
    void *buffer;
    {
        ALLOCREQ request;
        ALLOCREQ *req = &request;
        request.cb = 0x10000;
        req->cbAlign = 0x40;
        buffer = PvAllocStackImpl__Fi(req);
    }
    STREAM stream;
    CBinaryInputStream_ConstructFromBuffer(&stream, 0x10000, buffer, 0);
    CFileLocation location;
    CFileLocation *loc = &location;
    loc->kind = 2;
    loc->Clear();
    if (!location.Set(pblot->movie)) goto fail;
    if (CBinaryFileStream_FOpenLocation(&stream, &location) == 0) goto fail;
    {
        func_001179D8(&stream, 0x4000, 0x70000000);
        char magic[4];
        magic[0] = U8Read__18CBinaryInputStream(&stream);
        magic[1] = U8Read__18CBinaryInputStream(&stream);
        magic[2] = U8Read__18CBinaryInputStream(&stream);
        magic[3] = U8Read__18CBinaryInputStream(&stream);
        int version = U16Read__18CBinaryInputStream(&stream);
        if (func_00233470(magic, "ZRB.", 4) != 0) goto fail;
        if (version == 6) goto load;
    }
fail:
    CBinaryFileStream_Destructor(&stream, 2);
    CStackFrame_Destructor(frame, 2);
    return;
load:
    pblot->movie->start = B_003E1C70.limit;
    LoadMovieDictionary(pblot, &stream, pblot, &pblot->field50, &pblot->field54);
    LoadMovieSprites(pblot, &stream, pblot);
    pblot->movie->end = B_003E1C70.limit;
    CBinaryFileStream_Destructor(&stream, 2);
    CStackFrame_Destructor(frame, 2);
}
