#include "m2c_macros.h"

M2C_UNK AddPrimList__4GIFSiUl(); /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(); /* extern */
M2C_UNK GIFS_ListXYZ();   /* extern */
M2C_UNK ListUV__4GIFSii();         /* extern */
M2C_UNK PackAD__4GIFSll();         /* extern */
M2C_UNK func_0016D698();           /* extern */

void func_0016D6C8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s64 var_a1;
    s64 var_v0;

    AddPrimPack__4GIFSiiUl(0x200, 1, 0xE);
    func_0016D698(!(arg1 & 4) ? 5 : 4, arg0, arg2);
    if (arg1 & 0x200) {
        PackAD__4GIFSll(arg0, 0x4D, ((0xFFFC << 0x14) | 0x8000) << 0xA);
    } else if (!(arg1 & 0x100)) {
        var_a1 = (arg1 & 0x800000) ? 0x7FFFFFFF : 0xFFFFFFFF;
        if (arg1 & 0x400000) {
            var_a1 &= 0xFF7FFFFF;
        }
        if (arg1 & 0x200000) {
            var_a1 &= 0xFFBFFFFF;
        }
        if (arg1 & 0x100000) {
            var_a1 &= 0xFFDFFFFF;
        }
        if (arg1 & 0x80000) {
            var_a1 &= 0xFFEFFFFF;
        }
        if (arg1 & 0x40000) {
            var_a1 &= 0xFFF0FFFF;
        }
        if (arg1 & 0x20000) {
            var_a1 &= 0xFFFF7FFF;
        }
        var_v0 = var_a1 << 0x20;
        if (arg1 & 0x10000) {
            var_v0 = (var_a1 & 0xFFFFBFFF) << 0x20;
        }
        PackAD__4GIFSll(arg0, 0x4D, var_v0 | 0x02000000);
    } else {
        PackAD__4GIFSll(arg0, 0x4D, ((0x80000000 << 5) | 0x8000) << 0xA);
    }
    func_0016D698(!(arg1 & 1) ? 7 : 6, arg0, arg2);
    PackAD__4GIFSll(arg0, 7, 0xEA82 << 0x14);
    PackAD__4GIFSll(arg0, 0x15, 1);
    PackAD__4GIFSll(arg0, 0x3F, 0);
    PackAD__4GIFSll(arg0, 0x45, 0);
    PackAD__4GIFSll(arg0, 0x19, 0);
    PackAD__4GIFSll(arg0, 0x41, ((0xE000 << 0x1F) | 0x8000) << 0xA);
    PackAD__4GIFSll(arg0, 0x48, 0x31001);
    PackAD__4GIFSll(arg0, 0x43, 0x2A);
    PackAD__4GIFSll(arg0, 0x3B, 0x8000 << 0x18);
    PackAD__4GIFSll(arg0, 1, (0xC040 << 0x11) | 0x8080);
    PackAD__4GIFSll(arg0, 0, 0x356);
    AddPrimList__4GIFSiUl(arg0, 4, 0x5353);
    var_s0 = (arg1 & 0x40) ? 0 : 8;
    if (var_s0 < 0x200) {
        temp_v1 = ((arg1 & 0x10) ? 0 : 8) * 0x10;
        var_s4 = temp_v1 + 8;
        var_s3 = (var_s0 * 0x10) + 0x80;
        var_s2 = temp_v1 + 0x88;
        do {
            temp_a1 = var_s4;
            var_s4 += 0x100;
            ListUV__4GIFSii(arg0, temp_a1, 8);
            GIFS_ListXYZ(arg0, var_s0 * 0x10, 0, 0);
            var_s0 += 0x10;
            temp_a1_2 = var_s2;
            var_s2 += 0x100;
            ListUV__4GIFSii(arg0, temp_a1_2, 0x1C08);
            GIFS_ListXYZ(arg0, var_s3, 0x1C00, 0);
            var_s3 += 0x100;
        } while (var_s0 < 0x200);
    }
    AddPrimPack__4GIFSiiUl(arg0, 0x200, 1, 0xE);
    PackAD__4GIFSll(arg0, 0x41, ((0xE000 << 0x1E) | 0x8000) << 0xA);
}
