struct Entry_3DA798 { int a, b; unsigned int address; int c, d; };
extern Entry_3DA798 B_003DA798[];
extern "C" void func_001EC740(int first, int last, unsigned int length, unsigned int from, unsigned int to)
{
    unsigned int end = from + length;
    for (int index = first; index < last; index++) {
        Entry_3DA798 *entry = &B_003DA798[index];
        if (entry->address >= from && entry->address < end)
            entry->address = to + (entry->address - from);
    }
}
