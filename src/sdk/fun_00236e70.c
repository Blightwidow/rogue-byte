/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef struct Request {
    int field00[4];
    unsigned int flags;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
} Request;
typedef struct Packet {
    int field00[5];
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
} Packet;
extern Packet *func_00236D20(int, unsigned int);
extern Packet *func_00236CF0(int);
extern int func_0023AFE8(unsigned int, void *, int, int, int, int);
extern int func_0023A7F8(int, void *, void *);
extern void func_00236E30(void);
void func_00236E70(Request *request, int arg1)
{
    Packet *packet;
    int field14;
    int field1C;
    if (request->flags & 4) {
        packet = func_00236D20(arg1, request->flags >> 16);
    } else {
        packet = func_00236CF0(arg1);
    }
    /* Choice: both request fields are read into locals before the first store to packet. Retail loads field14 and field1C ahead of every store
       (gcc keeps a load below an earlier store that may alias it, so the source has to read first). The locals hold real values the code reads and
       then stores, the "bind it to a local first" form; they are not a variable that only moves a register (docs/contributing/exceptions.md). */
    field14 = request->field14;
    field1C = request->field1C;
    packet->field14 = field14;
    packet->field1C = field1C;
    packet->field20 = 0x8000000C;
    packet->field24 = request->field20;
    packet->field28 = request->field24;
    packet->field2C = request->field28;
    if (func_0023AFE8(0x80000008, packet, 0x40, request->field20, request->field24, request->field28) == 0) {
        func_0023A7F8(0x800, func_00236E30, packet);
    }
}
