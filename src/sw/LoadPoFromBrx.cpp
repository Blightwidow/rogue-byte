struct CBinaryInputStream { void Unknown1(); };
extern "C" void CSo_LoadFromBrx(void *, CBinaryInputStream *);
extern "C" void LoadPoFromBrx(void *self, CBinaryInputStream *stream)
{
    CSo_LoadFromBrx(self, stream);
    stream->Unknown1();
}
