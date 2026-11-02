struct REQ { int size; int align; };
struct FLOC { int hash; int slot; int kind; char path[0x104]; };
struct MOVIE { int a0; int a4; int a8; char pad[0x28]; int c34; int c38; int c3C; int c40; int start; int end; };
struct NODE { char pad0[0x40]; struct BLOTX *blot; int c44; int c48; NODE *next; };
struct BLOTX { char pad0[0x58]; int state; int pad5C; int time; };
struct BLOT { char pad0[0x50]; int d50; int d54; char pad58[0x68]; MOVIE *movie; };
struct COUNTERS { char pad[0xC]; int limit; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void CBinaryFileStream_Destructor(void *, int);
void CBinaryInputStream_ConstructFromBuffer(void *, int, void *, int);
int CBinaryFileStream_FOpenLocation(void *, FLOC *);
void Clear__13CFileLocation(FLOC *);
void *PvAllocStackImpl__Fi(REQ *);
void SetBlotBlots(BLOTX *, int);
int U16Read__18CBinaryInputStream(void *);
int U8Read__18CBinaryInputStream(void *);
void func_001179D8(void *, int, int);
int func_00233470(const void *, const void *, int);
void LoadMovieDictionary(BLOT *, void *, BLOT *, int *, int *);
void LoadMovieSprites(BLOT *, void *, BLOT *);
extern NODE *B_003E106C;
extern COUNTERS B_003E1C70;
extern int g_2be538;
}
struct STREAM { char bytes[0x70]; };
extern "C" void PrepareBlotMovie(BLOT *self)
{
    int latest = 0;
    NODE *node;
    BLOTX *blot;
    for (node = B_003E106C; node != 0; node = node->next) {
        blot = node->blot;
        if (blot->state != 0 && (blot->state != 1 || g_2be538 - blot->time < 2)) {
            int end = node->c48;
            latest = latest < end ? end : latest;
        }
    }
    for (node = B_003E106C; node != 0; node = node->next) {
        blot = node->blot;
        if (node->c44 >= latest && blot->state != 0) SetBlotBlots(blot, 0);
    }
    B_003E1C70.limit = latest;
    char frame[0x10];
    CStackFrame_Construct(frame);
    void *buffer;
    {
        REQ req;
        REQ *preq = &req;
        req.size = 0x10000;
        preq->align = 0x40;
        buffer = PvAllocStackImpl__Fi(preq);
    }
    STREAM stream;
    CBinaryInputStream_ConstructFromBuffer(&stream, 0x10000, buffer, 0);
    FLOC location;
    FLOC *ploc = &location;
    ploc->kind = 2;
    Clear__13CFileLocation(ploc);
    int valid;
    if (self->movie == 0) {
        valid = 0;
    } else {
        MOVIE *movie = self->movie;
        int x = movie->a4 ^ movie->c3C;
        int word = movie->a0 ^ movie->c34;
        ploc->kind = 2;
        word += 0xCA0;
        location.hash = word;
        location.slot = x;
        valid = x != 0;
    }
    if (valid == 0) goto cleanup;
    if (CBinaryFileStream_FOpenLocation(&stream, &location) == 0) goto cleanup;
    {
        func_001179D8(&stream, 0x4000, 0x70000000);
        char magic[4];
        magic[0] = U8Read__18CBinaryInputStream(&stream);
        magic[1] = U8Read__18CBinaryInputStream(&stream);
        magic[2] = U8Read__18CBinaryInputStream(&stream);
        magic[3] = U8Read__18CBinaryInputStream(&stream);
        int version = U16Read__18CBinaryInputStream(&stream);
        if (func_00233470(magic, "ZRB.", 4) != 0) goto cleanup;
        if (version == 6) goto body;
    }
cleanup:
    CBinaryFileStream_Destructor(&stream, 2);
    CStackFrame_Destructor(frame, 2);
    return;
body:
    self->movie->start = B_003E1C70.limit;
    LoadMovieDictionary(self, &stream, self, &self->d50, &self->d54);
    LoadMovieSprites(self, &stream, self);
    self->movie->end = B_003E1C70.limit;
    CBinaryFileStream_Destructor(&stream, 2);
    CStackFrame_Destructor(frame, 2);
}
