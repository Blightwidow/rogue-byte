struct Src { int pad0; int begin; int pad8; int end; };
struct Entry { short tag; short count; };
void func_0016D698(short tag, Src *src, Entry **cursor)
{
    Entry *out = (*cursor)++;
    out->tag = tag;
    out->count = (short)(((src->end - src->begin) >> 4) + 0x23);
}
