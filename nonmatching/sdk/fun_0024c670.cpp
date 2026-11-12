// SPDX-License-Identifier: GPL-3.0-or-later
typedef unsigned int u32;

#define IPU_CMD ((volatile u32 *)0x10002000)
#define IPU_CTRL ((volatile u32 *)0x10002010)
#define DMA3_CHCR ((volatile u32 *)0x1000B000)
#define DMA3_MADR ((volatile u32 *)0x1000B010)
#define DMA3_QWC ((volatile u32 *)0x1000B020)
#define DMA4_CHCR ((volatile u32 *)0x1000B400)
#define DMA4_MADR ((volatile u32 *)0x1000B410)
#define DMA4_QWC ((volatile u32 *)0x1000B420)
#define DMA_STAT ((volatile u32 *)0x1000E010)

struct DecoderMessage {
    int command;
    int field4[7];
};

struct TransferState {
    u32 quadwordCount;
    u32 address;
    int field8[2];
};

struct Picture {
    u32 address;
    int field4[2];
    int macroblockWidth;
    int macroblockHeight;
};

struct Decoder {
    char field0[0xEC];
    u32 outputAddress;
    char fieldF0[0x828 - 0xF0];
    int busy;
    u32 lastCommand;
    char field830[0x868 - 0x830];
    int semaphore;
};

extern "C" {
void func_0024B670(int semaphore, DecoderMessage *message);
void FlushCache(int mode);
int AddDmacHandler_2(int channel, int (*handler)(int), int next, void *argument);
int func_0024CC90(int channel);
void func_00235248(int channel);
void func_002351E0(int channel);
int func_00239450(void);
void func_002394A0(void);
void RemoveDmacHandler(int channel, int handlerId);
void func_0024C4B0(Decoder *decoder, u32 outputAddress, int macroblockCount);
}

static inline void IssueCommand(Decoder *decoder, u32 command)
{
    *IPU_CMD = command;
    decoder->lastCommand = command & 0xF0000000;
    u32 opcode = command & 0xF0000000;
    if (opcode == 0x20000000 || opcode == 0x30000000 || opcode == 0x40000000)
        decoder->busy = 0;
    else
        decoder->busy = 1;
}

static inline void DecodeSmall(Decoder *decoder, u32 outputAddress, int macroblockCount)
{
    DecoderMessage message;
    int quadwordCount = macroblockCount << 6;
    while ((int)*IPU_CTRL < 0)
        ;
    int interruptsWereEnabled = func_00239450();
    *DMA3_MADR = outputAddress & 0x0FFFFFFF;
    *DMA3_QWC = quadwordCount;
    *DMA3_CHCR = 0x100;
    if (interruptsWereEnabled != 0)
        func_002394A0();
    IssueCommand(decoder, macroblockCount | 0x70000000);
    message.command = 4;
    func_0024B670(decoder->semaphore, &message);
    while ((*DMA3_CHCR >> 8) & 1)
        ;
    while ((int)*IPU_CTRL < 0)
        ;
}

extern "C" void func_0024C670(Decoder *decoder, Picture *picture)
{
    DecoderMessage message;
    TransferState transfer;
    int macroblockCount = picture->macroblockWidth * picture->macroblockHeight;
    message.command = 2;
    func_0024B670(decoder->semaphore, &message);
    if (((u32 *)0x10002010)[0] & 0x4000)
        *(u32 *)0x10002010 = 0x40000000;
    while ((int)*IPU_CTRL < 0)
        ;
    IssueCommand(decoder, 0);
    while ((int)*IPU_CTRL < 0)
        ;
    FlushCache(0);
    transfer.address = picture->address & 0x0FFFFFFF;
    transfer.quadwordCount = macroblockCount * 0x18;
    if (transfer.quadwordCount > 0xFFFF) {
        int handlerId = AddDmacHandler_2(4, func_0024CC90, 0, &transfer);
        *DMA_STAT = 0x10;
        func_00235248(4);
        int interruptsWereEnabled = func_00239450();
        *DMA4_MADR = transfer.address;
        *DMA4_QWC = 0xFFFF;
        *DMA4_CHCR = 0x101;
        if (interruptsWereEnabled != 0)
            func_002394A0();
        transfer.address = (transfer.address + 0xFFFF0) & 0x0FFFFFFF;
        transfer.quadwordCount -= 0xFFFF;
        if (macroblockCount < 0x400)
            DecodeSmall(decoder, decoder->outputAddress, macroblockCount);
        else
            func_0024C4B0(decoder, decoder->outputAddress, macroblockCount);
        func_002351E0(4);
        RemoveDmacHandler(4, handlerId);
    } else {
        int interruptsWereEnabled = func_00239450();
        *DMA4_MADR = picture->address & 0x0FFFFFFF;
        *DMA4_QWC = transfer.quadwordCount;
        *DMA4_CHCR = 0x101;
        if (interruptsWereEnabled != 0)
            func_002394A0();
        transfer.quadwordCount = 0;
        if (macroblockCount < 0x400)
            DecodeSmall(decoder, decoder->outputAddress, macroblockCount);
        else
            func_0024C4B0(decoder, decoder->outputAddress, macroblockCount);
    }
    message.command = 3;
    func_0024B670(decoder->semaphore, &message);
}
