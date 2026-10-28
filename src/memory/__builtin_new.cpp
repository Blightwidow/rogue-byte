struct SwAllocRequest { int size; int alignment; };
void *PvAllocSwClearImpl__Fi(SwAllocRequest *request);
void *__builtin_new(unsigned size)
{
    SwAllocRequest request;
    request.size = size;
    request.alignment = 16;
    return PvAllocSwClearImpl__Fi(&request);
}
