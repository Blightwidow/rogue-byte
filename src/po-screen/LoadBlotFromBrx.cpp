#include "sly2.h"
struct BIS;
struct REQ { int size; int align; };
extern "C" void LoadLoFromBrx(void *, BIS *);
extern "C" int S8Read__18CBinaryInputStream(BIS *);
extern "C" float F32Read__18CBinaryInputStream(BIS *);
extern "C" unsigned U32Read__18CBinaryInputStream(BIS *);
extern "C" void *PvAllocSwClearImpl__Fi(REQ *);
extern "C" void func_00118458(BIS *, void *);
extern "C" void AppendSlEntry(void *, void *);
extern "C" void LoadMovieDictionary(void *, BIS *, void *, void *, void *);
extern "C" void LoadMovieSprites(void *, BIS *, void *);
extern "C" char B_003E1C70[], B_003E106C[], B_003E1C80[];
struct BLOT { char pad0[0x50]; int f50; int f54; int state; char pad1[0x14]; int label0; int label1; int label2; int cur; char pad2[0x10]; float dwell; unsigned height; unsigned width; char pad3[0x20]; unsigned f_bc; void *record; void *alloc; };
void LoadBlotFromBrx(BLOT *blot, BIS *stream)
{
    blot->label0 = 0x310;
    blot->label1 = 0x30F;
    blot->label2 = 0x311;
    LoadLoFromBrx(blot, stream);
    int streamed = S8Read__18CBinaryInputStream(stream);
    blot->dwell = F32Read__18CBinaryInputStream(stream);
    blot->height = U32Read__18CBinaryInputStream(stream);
    blot->width = U32Read__18CBinaryInputStream(stream);
    blot->f_bc = U32Read__18CBinaryInputStream(stream);
    if (streamed) {
        blot->state = 0;
        REQ request;
        request.size = 0x50;
        request.align = 0x10;
        blot->alloc = B_003E1C70;
        void *record = PvAllocSwClearImpl__Fi(&request);
        blot->record = record;
        *(BLOT **)((char *)record + 0x40) = blot;
        func_00118458(stream, blot->record);
        AppendSlEntry(B_003E106C, blot->record);
    } else {
        blot->state = 1;
        blot->alloc = B_003E1C80;
        LoadMovieDictionary(blot, stream, blot, &blot->f50, &blot->f54);
        LoadMovieSprites(blot, stream, blot);
    }
    blot->cur = -1;
}
