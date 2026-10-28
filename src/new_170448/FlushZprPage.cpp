struct CHUNK { int start; int end; CHUNK *next; };
struct ZPR { char pad[4]; int cur; char pad2[4]; CHUNK *free[8]; int count; CHUNK chunks[1]; };
extern "C" int ICeilLog2(int);
extern "C" void FlushZprPage(ZPR *zpr)
{
    if ((zpr->cur & 0x7F) != 0) {
        CHUNK *chunk = &zpr->chunks[zpr->count++];
        chunk->start = zpr->cur;
        int end = (zpr->cur + 0x7F) & -0x80;
        zpr->cur = end;
        chunk->end = end;
        int iclass = ICeilLog2(end - chunk->start);
        chunk->next = zpr->free[iclass];
        zpr->free[iclass] = chunk;
    }
}
