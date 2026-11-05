struct SO { char pad0[0x148]; unsigned long flags; };
extern "C" void RecalcSoLocked(SO *);
extern "C" void func_001F7F48(SO *self, int enable)
{
    unsigned long flags = self->flags;
    if (enable != ((int)(flags >> 34) & 1)) {
        self->flags = (flags & ~(1UL << 34)) | ((unsigned long)(enable & 1) << 34);
        RecalcSoLocked(self);
    }
}
