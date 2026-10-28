struct CFileLocation { unsigned a; unsigned b; int mode; char pad[0x104]; void Clear(); };
struct SndRec { unsigned w0; unsigned w1; char pad[0x2C]; unsigned w34; unsigned w38; unsigned w3c; };
struct Snd {
    char pad0[0xA8];
    SndRec rec;
    char pad1[0xE8 - 0xA8 - sizeof(SndRec)];
    int bank;
    char pad2[0xC];
    int count;
    int *states;
};
extern "C" int snd_BankLoadByLoc(unsigned, int);
extern "C" void snd_ResolveBankXREFS();
extern "C" int func_002322A0(int, int);

void LoadSndBank(Snd *snd)
{
    if (snd->bank == 0) {
        CFileLocation loc;
        loc.mode = 2;
        loc.Clear();
        SndRec *rec = &snd->rec;
        int valid;
        if (!rec) valid = 0; else {
            unsigned x = rec->w1;
            unsigned y = rec->w3c;
            loc.mode = 2;
            loc.b = x ^ y;
            loc.a = (snd->rec.w0 ^ rec->w34) + 0xCA0;
            valid = x != y;
        }
        if (valid && loc.mode == 2)
            snd->bank = snd_BankLoadByLoc(loc.a, 0);
        snd_ResolveBankXREFS();
    }
    for (int i = 0; i < snd->count; i++) {
        if (snd->states[i] != 2 && func_002322A0(snd->bank, i) != 0)
            snd->states[i] = 2;
    }
}
