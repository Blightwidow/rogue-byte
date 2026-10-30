typedef int s32;
struct Save_1ABB60 { char p0[0xFD50]; s32 slot; };
extern "C" s32 CheckCardStatus();
extern "C" s32 CreateSaveDirectory(Save_1ABB60 *);
extern "C" s32 WriteSaveSlot(Save_1ABB60 *, s32);
extern "C" void func_001ACC38(void *, s32);
extern char B_002E6550[];
extern "C" s32 func_001ABB60(Save_1ABB60 *save) {
    s32 result = CheckCardStatus();
    if (result == 0) {
        result = CreateSaveDirectory(save);
        if (result == 0) {
            result = WriteSaveSlot(save, save->slot);
        }
    }
    if (result != 0) {
        func_001ACC38(B_002E6550, 3);
    }
    return result;
}
