extern "C" {
struct SemaParam_2370A8 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
struct Packet_2370A8 { char pad0[0x14]; Packet_2370A8 *self; int field18; void *client; int command; };
struct Client_2370A8 { Packet_2370A8 *packet; int field4; int semaphore; char padC[4]; int field10; char pad14[0x10]; int field24; };
int CreateSema(SemaParam_2370A8 *);
void DeleteSema(int);
void WaitSema(int);
Packet_2370A8 *func_00236C28(void *);
void func_00236CD0(Packet_2370A8 *);
int func_0023AFA8(unsigned int, Packet_2370A8 *, int, int, int, int);
extern char B_0044A600[];
int sceSifBindRpc(Client_2370A8 *client, int serverId, int mode) {
    SemaParam_2370A8 param;
    Packet_2370A8 *packet;
    client->field10 = 0;
    client->field24 = 0;
    packet = func_00236C28(B_0044A600);
    if (packet == 0) {
        return -1;
    }
    client->packet = packet;
    client->field4 = packet->field18;
    packet->command = serverId;
    packet->self = packet;
    packet->client = client;
    if ((mode & 1) == 0) {
        param.initCount = 1;
        param.name = "SceSifrpcBind";
        param.maxCount = 0;
        client->semaphore = CreateSema(&param);
        if (client->semaphore < 0) {
            func_00236CD0(packet);
            return -3;
        }
        if (func_0023AFA8(0x80000009, packet, 0x40, 0, 0, 0) == 0) {
            func_00236CD0(packet);
            DeleteSema(client->semaphore);
            return -2;
        }
        WaitSema(client->semaphore);
        DeleteSema(client->semaphore);
        return 0;
    }
    client->semaphore = -1;
    if (func_0023AFA8(0x80000009, packet, 0x40, 0, 0, 0) == 0) {
        func_00236CD0(packet);
        return -2;
    }
    return 0;
}
}
