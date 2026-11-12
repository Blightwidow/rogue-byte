typedef struct {
    char pad0[0x12C];
    int error;
    char pad130[0xC];
    int field13C;
    char pad140[0x80];
    int field1C0;
    int field1C4;
    char pad1C8[0x6B0];
    int field878;
} MpegContext;

typedef struct {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
} SliceResult;

unsigned func_00252230(MpegContext *, int);
int func_00252148(MpegContext *, int);
void func_002544C0(MpegContext *, int);
void func_00254620(MpegContext *);
void func_00254628(MpegContext *);
int func_00251CE8(MpegContext *);
void func_0024FA90(MpegContext *, const char *, int);
void func_0024FA38(MpegContext *, const char *);

int func_00253518(MpegContext *context, int unused, int *firstRow, int *rowCount, SliceResult *result)
{
    int code;
    int count;

    context->error = 0;
    func_00254628(context);
    while (func_00252230(context, 0x18) != 1 && context->field878 == 0) {
        func_002544C0(context, 8);
    }
    code = func_00252230(context, 0x20);
    if ((unsigned)(code - 0x101) >= 0xAF) {
        func_0024FA90(context, "slice_start_code(0x%08x) out of range", code);
        return 2;
    }
    func_00254620(context);
    context->field1C4 = func_00252148(context, 5);
    if (func_00252148(context, 1) != 0) {
        func_00252148(context, 1);
        func_002544C0(context, 7);
        while (func_00252148(context, 1) != 0) {
            func_002544C0(context, 8);
        }
    }
    count = func_00251CE8(context);
    *rowCount = count;
    if (context->error != 0) {
        func_0024FA38(context, "_sceMpegSliceA0(): error happens");
        return 1;
    }
    *firstRow = ((code & 0xFF) - 1) * context->field13C + count - 1;
    *rowCount = 1;
    context->field1C0 = 1;
    result->field14 = 0;
    result->field10 = 0;
    result->field4 = 0;
    result->field0 = 0;
    result->field1C = 0;
    result->field18 = 0;
    result->fieldC = 0;
    result->field8 = 0;
    return 0;
}
