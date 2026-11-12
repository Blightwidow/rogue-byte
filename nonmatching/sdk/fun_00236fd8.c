/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef struct Request {
    int field00[5];
    int field14;
    int field18;
    int field1C;
    int field20;
} Request;
typedef struct Entry {
    int field00[2];
    int field08;
} Entry;
typedef struct Packet {
    int field00[5];
    int field14;
    int field18;
    int field1C;
    int field20;
    Entry *field24;
    int field28;
} Packet;
extern Packet *func_00236CF0(int);
extern Entry *func_00236F48(int, int);
extern int func_0023AFE8(unsigned int, void *, int, int, int, int);
extern int func_0023A7F8(int, void *, void *);
extern void func_00236F98(void);
void func_00236FD8(Request *request, int arg1)
{
    Packet *packet;
    Entry *entry;
    int requestField1C;
    int requestField14;

    packet = func_00236CF0(arg1);
    requestField14 = request->field14;
    requestField1C = request->field1C;
    packet->field1C = requestField1C;
    packet->field14 = requestField14;
    packet->field20 = 0x80000009;
    entry = func_00236F48(request->field20, arg1);
    packet->field24 = entry;
    if (entry == 0) {
        packet->field28 = 0;
    } else {
        packet->field28 = entry->field08;
    }
    if (func_0023AFE8(0x80000008, packet, 0x40, 0, 0, 0) == 0) {
        func_0023A7F8(0x800, func_00236F98, packet);
    }
}
