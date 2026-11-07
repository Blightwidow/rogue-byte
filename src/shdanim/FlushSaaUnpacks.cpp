// SPDX-License-Identifier: GPL-3.0-or-later
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct SaaUnpack { char pad0[0x10]; SaaUnpack *next; };
struct Saa { char pad0[0x2C]; int pending; char pad30[4]; SaaUnpack *unpacks; char pad38[8]; Saa *next; };
extern "C" {
void func_001EC718(SaaUnpack *);
extern Saa *B_003E159C;
void FlushSaaUnpacks(void) {
    VECTOR vector;
    Saa *saa = B_003E159C;
    SaaUnpack *unpack;
    if (saa != 0) {
        do {
            if (saa->pending != 0) {
                unpack = saa->unpacks;
                saa->pending = 0;
                if (unpack != 0) {
                    do {
                        func_001EC718(unpack);
                        unpack = unpack->next;
                    } while (unpack != 0);
                }
            }
            saa = saa->next;
        } while (saa != 0);
    }
}
}
