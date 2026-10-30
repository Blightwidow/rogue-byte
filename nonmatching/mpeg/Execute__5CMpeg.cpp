#include "sly2.h"
struct REQ_1B3BD0 { int size; int align; };
struct FLOC_1B3BD0 { int hash; int slot; int kind; char path[0x104]; };
struct SAVE_1B3BD0 { char pad[0xFD50]; int current; };
struct STREAM_1B3BD0 { char bytes[0x30]; };
struct MOVIE_1B3BD0 { int a0; int a4; int a8; char pad[0x28]; int c34; int c38; int c3C; };
extern "C" {
int CBinaryAsyncStream_FOpenLocation(STREAM_1B3BD0 *, FLOC_1B3BD0 *);
void CMpeg_Start(void *, STREAM_1B3BD0 *);
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void Clear__13CFileLocation(FLOC_1B3BD0 *);
int Close__18CBinaryAsyncStream(STREAM_1B3BD0 *);
int FJoyButtonPressed(void *, int, int);
void Finish__5CMpeg(void *);
void MarkClockTick__FP5CLOCK(void *, int);
void *PvAllocStackClearImpl__Fi(REQ_1B3BD0 *);
void UpdateCd__Fv();
void UpdateJoy__FP3JOY(void *);
void UpdateSave__FP4SAVE(void *);
void Update__5CMpeg(void *);
void __18CBinaryAsyncStreamPv(STREAM_1B3BD0 *, int, void *);
void func_001325B8(STREAM_1B3BD0 *, int);
int sceMpegIsEnd(void *);
extern char B_002DFC00[];
extern SAVE_1B3BD0 B_002E65E0;
extern int B_002F68F8;
extern int D_002C0268;
extern MOVIE_1B3BD0 RO_002A3968;
extern MOVIE_1B3BD0 RO_002A39A8;
extern char g_2bd4c0[];
extern char g_2dded0[];
}
#define F(type, base, off) (*(type *)((char *)(base) + (off)))
static inline int SameMovie(MOVIE_1B3BD0 *left, MOVIE_1B3BD0 *right)
{
    int result;
    if (left == right) {
        result = 1;
    } else if (left == 0) {
        result = 0;
    } else if (right != 0) {
        result = (left->a8 ^ left->c38) == (right->a8 ^ right->c38);
    } else {
        result = 0;
    }
    return result;
}

extern "C" void Execute__5CMpeg(void *self, MOVIE_1B3BD0 *movie)
{
    char frame[0x10];
    REQ_1B3BD0 req;
    STREAM_1B3BD0 stream;
    FLOC_1B3BD0 location;
    REQ_1B3BD0 *preq = &req;

    CStackFrame_Construct(frame);
    req.size = 0x41FC00;
    preq->align = 0x40;
    void *buffer = PvAllocStackClearImpl__Fi(preq);
    F(void *, self, 0x110) = buffer;
    __18CBinaryAsyncStreamPv(&stream, 0x80000, buffer);
    location.kind = 2;
    Clear__13CFileLocation(&location);
    int valid;
    if (movie != 0) {
        int slot = movie->a4;
        int other = movie->c3C;
        location.kind = 2;
        location.hash = (movie->a0 ^ movie->c34) + 0xCA0;
        location.slot = slot ^ other;
        valid = slot != other;
    } else {
        valid = 0;
    }
    if (valid != 0 && CBinaryAsyncStream_FOpenLocation(&stream, &location) != 0) {
        CMpeg_Start(self, &stream);
        while (sceMpegIsEnd((char *)self + 0x118) == 0) {
            MarkClockTick__FP5CLOCK(g_2dded0, 1);
            UpdateJoy__FP3JOY(B_002DFC00);
            if (B_002E65E0.current == 0)
                UpdateSave__FP4SAVE(&B_002E65E0);
            int skippable = 0;
            if (SameMovie(movie, &RO_002A3968) != 0 || SameMovie(movie, &RO_002A39A8) != 0)
                skippable = B_002F68F8 != 0;
            int allowed = (D_002C0268 != 0) ? 1 : skippable;
            if (allowed != 0) {
                if ((FJoyButtonPressed(B_002DFC00, 0x91F, allowed) != 0 ? 1 : 0) != 0) {
                    F(int, self, 0x108) = 0;
                    break;
                }
            }
            if (location.kind != 2 || (UpdateCd__Fv(), F(int, g_2bd4c0, 0) == 3))
                Update__5CMpeg(self);
            else
                break;
        }
        if (SameMovie(movie, &RO_002A39A8) != 0)
            B_002F68F8 = 1;
        Finish__5CMpeg(self);
        Close__18CBinaryAsyncStream(&stream);
    }
    F(int, self, 0x110) = 0;
    func_001325B8(&stream, 2);
    CStackFrame_Destructor(frame, 2);
}
