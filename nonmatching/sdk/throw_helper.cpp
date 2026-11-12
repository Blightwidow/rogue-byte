extern "C" {
struct frame_state {
    char pad0[4];
    int *ehPointer;
    char pad1[0x29A - 8];
    unsigned short retaddrColumn;
    char saved[0x4F];
} __attribute__((aligned(8)));
struct eh_context {
    int handlerLabel;
    int pad4;
    int ehInfoValue;
    int tableIndex;
};
void __terminate(void);
void __unwinding_cleanup(void);
void copy_reg(int, frame_state *, frame_state *);
int find_exception_handler(int, int *, int, int, int *);
long *get_reg_addr(unsigned short, frame_state *, frame_state *);
frame_state *next_stack_level(int, frame_state *, frame_state *);
int old_find_exception_handler(int, int *);
static inline int getReturnAddress(frame_state *udata, frame_state *subUdata) {
    return (int)*get_reg_addr(udata->retaddrColumn, udata, subUdata);
}
int throw_helper(eh_context *eh, int pc, frame_state *myUdata, frame_state **udataPointer) {
    frame_state *udata = *udataPointer;
    frame_state ustruct;
    frame_state *subUdata = &ustruct;
    int savedPc = pc;
    int handler = 0;
    int handlerPointer = 0;
    int pcPointer = 0;
    frame_state savedUstruct;
    int newEhModel;
    int cleanup = 0;
    int onlyCleanup = 0;
    int rethrow = 0;
    int savedState = 0;
    int ehInfo = eh->ehInfoValue;
    if (eh->tableIndex != 0)
        rethrow = 1;
    handler = 0;
    for (;;) {
        frame_state *previous = udata;
        udata = next_stack_level(pc, udata, subUdata);
        subUdata = previous;
        if (!udata)
            break;
        if (udata->ehPointer == 0)
            newEhModel = 0;
        else
            newEhModel = *udata->ehPointer == 0xFFFFFFFE;
        if (rethrow) {
            rethrow = 0;
            handler = find_exception_handler(eh->tableIndex, udata->ehPointer, ehInfo, 1, &cleanup);
            eh->tableIndex = 0;
        } else if (newEhModel) {
            handler = find_exception_handler(pc, udata->ehPointer, ehInfo, 0, &cleanup);
        } else {
            handler = old_find_exception_handler(pc, udata->ehPointer);
        }
        if (handler) {
            if (cleanup) {
                if (!savedState) {
                    savedUstruct = *udata;
                    handlerPointer = handler;
                    pcPointer = pc;
                    savedState = 1;
                    onlyCleanup = 1;
                }
            } else {
                onlyCleanup = 0;
                break;
            }
        }
        pc = getReturnAddress(udata, subUdata) - 1;
    }
    if (savedState) {
        udata = &savedUstruct;
        handler = handlerPointer;
        pc = pcPointer;
        if (onlyCleanup)
            __unwinding_cleanup();
    }
    if (!handler)
        __terminate();
    eh->handlerLabel = handler;
    int handlerPc = pc;
    if (pc == savedPc) {
        udata = myUdata;
    } else {
        frame_state *previous;
        *udata = *myUdata;
        pc = savedPc;
        do {
            previous = udata;
            udata = next_stack_level(pc, udata, subUdata);
            subUdata = previous;
            for (int index = 0; index < 0x4F; index++)
                if (index != udata->retaddrColumn && udata->saved[index])
                    copy_reg(index, udata, myUdata);
            pc = getReturnAddress(udata, subUdata) - 1;
        } while (pc != handlerPc);
    }
    *udataPointer = udata;
    return handler;
}
}
