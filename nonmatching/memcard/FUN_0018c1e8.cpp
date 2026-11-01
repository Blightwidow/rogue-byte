extern "C" void Clear__13CFileLocation(void *);
struct L { int word0; int word1; int mode; char pad[0x110 - 12]; L() { mode = 2; Clear__13CFileLocation(this); } };
extern "C" int CFileLocation_Cb(void *);
struct S { int f0; int f4; char pad[0x2C]; int f34; int f38; int f3C; };

extern "C" int FUN_0018c1e8(S *source) {
 L location;
 int valid;
 if (source == 0) { valid = 0; } else { location.word0 = (source->f34 ^ source->f0) + 0xCA0; location.word1 = source->f4 ^ source->f3C; location.mode = 2; valid = location.word1 != 0; }
 int result = 0; if (valid) result = CFileLocation_Cb(&location); return result;
}
