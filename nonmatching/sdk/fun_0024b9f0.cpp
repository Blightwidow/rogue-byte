extern "C" {
int func_00239450(void);
void func_002394A0(unsigned int, unsigned int);
struct Transfer {
    char pad0[0xEC];
    unsigned int baseAddress;
    char padF0[4];
    int strideSelect;
    int strideStep;
    char pad100[0x184 - 0xFC];
    int mode;
};
struct Stream {
    unsigned int address;
    int pad4;
    int pad8;
    int count;
    int sizeSelect;
};
void func_0024B9F0(Transfer *transfer, Stream *stream) {
    struct {
        Transfer *transfer;
        int passCount;
        unsigned int baseAddress;
    } state;
    state.transfer = transfer;
    unsigned int sourceAddress = stream->address & 0x0FFFFFFF;
    state.baseAddress = transfer->baseAddress & 0x0FFFFFFF;
    int blockBytes;
    int quadwordCount;
    int destinationStep;
    if (state.transfer->mode != 3) {
        int selector = state.transfer->strideSelect;
        if (selector != 0) {
            destinationStep = (selector >> 4) * 0xC0;
            blockBytes = (stream->sizeSelect >> 1) * 0x180;
            state.passCount = 2;
            quadwordCount = blockBytes >> 4;
            goto run;
        }
    }
    {
        int selector = state.transfer->strideSelect;
        blockBytes = stream->sizeSelect * 0x180;
        quadwordCount = blockBytes >> 4;
        if (selector != 0)
            destinationStep = (selector >> 4) * 0x180;
        else
            destinationStep = blockBytes;
        state.passCount = 1;
    }
run:
    int pass = 0;
    if (state.passCount != 0) {
        do {
            unsigned int destination = state.baseAddress;
            int index = 0;
            if (stream->count > 0) {
                do {
                    int busy = func_00239450();
                    *(volatile unsigned int *)0x1000D480 = 0;
                    *(volatile unsigned int *)0x1000D410 = sourceAddress;
                    *(volatile unsigned int *)0x1000D420 = quadwordCount;
                    *(volatile unsigned int *)0x1000D400 = 0x101;
                    if (busy != 0)
                        func_002394A0(0x1000D420, 0x1000D400);
                    index++;
                    while (*(volatile unsigned int *)0x1000D400 & 0x100) {
                    }
                    busy = func_00239450();
                    *(volatile unsigned int *)0x1000D080 = 0;
                    *(volatile unsigned int *)0x1000D010 = destination;
                    *(volatile unsigned int *)0x1000D020 = quadwordCount;
                    *(volatile unsigned int *)0x1000D000 = 0x100;
                    if (busy != 0)
                        func_002394A0(0x1000D020, 0x1000D000);
                    while (*(volatile unsigned int *)0x1000D000 & 0x100) {
                    }
                    while (*(volatile unsigned int *)0x1000D020 != 0) {
                    }
                    destination += destinationStep;
                    sourceAddress += blockBytes;
                } while (index < stream->count);
            }
            pass++;
            state.baseAddress += state.transfer->strideStep * 0xC0;
        } while (pass < state.passCount);
    }
}
}
