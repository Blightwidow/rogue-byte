// SPDX-License-Identifier: GPL-3.0-or-later
struct Bytes16 { char bytes[16]; };
struct Bytes4 { char bytes[4]; };
struct Bytes8 { char bytes[8]; };
struct Bytes40 { char bytes[0x40]; };
struct Bytes144 { char bytes[0x144]; };
struct Header { int count; int type; int *target; unsigned length; };
struct Bytes16Half { char bytes[16]; } __attribute__((aligned(2)));
union HeaderCopy { Bytes16Half raw; Header header; };
struct Scratch { char *destination; unsigned length; };
struct Packet { int firstLength; int secondLength; char *firstDestination; char *secondDestination; unsigned char firstData[0x40]; unsigned char secondData[0x40]; };

extern "C" {
void *memcpy(void *, const void *, unsigned);
void iSignalSema(int);
extern char B_0044B300[];
extern int D_002C4A78;
extern unsigned D_002C4A80;
extern int D_002C49F8[32];

void func_00237740(int *self)
{
    int index = 0;
    if (D_002C4A80 != 0) {
        index = self[3];
    }
    D_002C4A78 = index;
    char *record = (char *)((unsigned)(B_0044B300 + index * 0x440) | 0x20000000);
    HeaderCopy copy;
    *(Bytes4 *)&copy.raw.bytes[0] = *(Bytes4 *)(record + 0);
    *(Bytes4 *)&copy.raw.bytes[4] = *(Bytes4 *)(record + 4);
    *(Bytes4 *)&copy.raw.bytes[8] = *(Bytes4 *)(record + 8);
    *(Bytes4 *)&copy.raw.bytes[12] = *(Bytes4 *)(record + 12);
    if (copy.header.count >= 0) {
        memcpy(copy.header.target, record + 0x10, copy.header.length);
    }
    Scratch scratch;
    switch (copy.header.type) {
    case 2: {
        Packet *packet = (Packet *)(record + 0x14);
        if (packet->firstLength > 0) {
            char *destination = packet->firstDestination;
            char *uncached = (char *)((unsigned)destination | 0x20000000);
            for (int i = 0; i < packet->firstLength; i++) {
                unsigned char value = packet->firstData[i];
                uncached[i] = value;
                destination[i] = value;
            }
        }
        if (packet->secondLength > 0) {
            char *destination = packet->secondDestination;
            char *uncached = (char *)((unsigned)destination | 0x20000000);
            for (int i = 0; i < packet->secondLength; i++) {
                unsigned char value = packet->secondData[i];
                uncached[i] = value;
                destination[i] = value;
            }
        }
        break;
    }
    case 11:
        if (*copy.header.target > 0) {
            char *destination;
            *(Bytes4 *)&destination = *(Bytes4 *)(record + 0x14);
            *(Bytes144 *)destination = *(Bytes144 *)(record + 0x18);
        }
        break;
    case 12: {
        char *destination;
        *(Bytes4 *)&destination = *(Bytes4 *)(record + 0x14);
        *(Bytes40 *)destination = *(Bytes40 *)(record + 0x18);
        break;
    }
    case 23:
    case 25:
    case 26:
        *(Bytes4 *)&scratch.destination = *(Bytes4 *)(record + 0x14);
        *(Bytes4 *)&scratch.length = *(Bytes4 *)(record + 0x18);
        if (scratch.length > 0x400) {
            scratch.length = 0x400;
        }
        memcpy(scratch.destination, record + 0x1C, scratch.length);
        break;
    }
    if (copy.header.count < 0) {
        int identifier = -copy.header.count;
        copy.header.count = identifier;
        for (int i = 0; i < 32; i++) {
            if (D_002C49F8[i] == identifier) {
                D_002C49F8[i] = -1;
                break;
            }
        }
    } else {
        iSignalSema(copy.header.count);
    }
}
}
