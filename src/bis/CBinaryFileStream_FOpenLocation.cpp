struct Loc { unsigned sector; unsigned count; int kind; };
struct CBinaryInputStream { unsigned FOpenSector(unsigned, unsigned); };
struct CBinaryFileStream : CBinaryInputStream { unsigned FOpenLocation(Loc *); };
unsigned CBinaryFileStream::FOpenLocation(Loc *loc)
{
    unsigned result = 0;
    if (loc->kind == 2)
        result = FOpenSector(loc->sector, loc->count);
    return result;
}
