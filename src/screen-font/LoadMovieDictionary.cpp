#include "sly2.h"
struct SLOTHEAP;
struct BLOT { char pad[0xC4]; SLOTHEAP *heap; };
struct CBinaryInputStream { unsigned short U16Read(); };
extern int D_002C40A4;
extern void *PvAllocSlotheapClearImpl__FP8SLOTHEAP(SLOTHEAP *, int, int);
extern "C" void LoadMovieCharacter(BLOT *, CBinaryInputStream *, void *, int, void *);

void LoadMovieDictionary(BLOT *blot, CBinaryInputStream *stream, void *owner, int *count, void **array)
{
    *count = stream->U16Read();
    int tag = D_002C40A4 ? 0x13 : 0x11;
    *array = PvAllocSlotheapClearImpl__FP8SLOTHEAP(blot->heap, (*count + 1) << 6, tag);
    for (int index = 1; index <= *count; index++)
        LoadMovieCharacter(blot, stream, owner, *count, *array);
}
