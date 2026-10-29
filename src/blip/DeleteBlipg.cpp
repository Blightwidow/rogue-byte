typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {
extern char B_003DD490[];
s32 PdlFromSwCid(char *sw, s32 cid);
void RemoveSlEntry(s32 pdl, s32 arg1);
void FreeSlotheapPv(char *heap, s32 p);

void DeleteBlipg(s32 arg0) {
    char *base = B_003DD490;
    RemoveSlEntry(PdlFromSwCid(base, 0x1C), arg0);
    FreeSlotheapPv(base + 0x4070, arg0);
}

}
