typedef int s32;
typedef float f32;
struct Obj_1AD538 { char bytes[0x5464]; };
struct Cards_1AD538 { char head[0x24]; Obj_1AD538 saves[3]; Obj_1AD538 *current; };
struct Entry_1AD538 { char bytes[0x1C]; };
struct Table_1AD538 { char pad[0xC]; Entry_1AD538 entries[1]; };
struct Result_1AD538 { s32 pad0; f32 value; s32 pad8; s32 padC; };
extern "C" {
void CRef_Destruct(void *);
s32 RefGetGameSaveValue(void *, s32, void *);
s32 func_001ACC38(void *, s32);
s32 func_001B0078(void *);
extern char B_002E6550[];
extern Cards_1AD538 B_002E65E0;
extern Table_1AD538 B_003D9ED0;
extern char B_003DD490[];
void func_001AD538(void) {
    f32 values[3];
    Result_1AD538 result;
    char *entry;
    Obj_1AD538 *save;
    s32 index;
    s32 count;
    s32 mode;
    func_001ACC38(B_002E6550, 1);
    count = *(s32 *)((char *)&B_003D9ED0 + 0x24);
    if (count > 0) {
        save = B_002E65E0.saves;
        entry = (char *)&B_003D9ED0.entries[count];
        for (index = 0; index < 3; index++) {
            f32 value;
            RefGetGameSaveValue(&result, *(s32 *)(B_003DD490 + 0x3B1C), save);
            save++;
            value = result.value;
            CRef_Destruct(&result);
            values[index] = value;
        }
        mode = func_001B0078(&B_003D9ED0);
        switch (mode) {
        case 30:
            if (values[0] != 0.0f) {
                index = 1;
                while (index < 3) {
                    if (values[index] != 0.0f) {
                        index++;
                        continue;
                    }
                    *(s32 *)(entry + 0x14) = index;
                    break;
                }
            } else {
                *(s32 *)(entry + 0x14) = 0;
            }
            break;
        case 31:
            if (values[0] != 0.0f) {
                *(s32 *)(entry + 0x14) = 0;
            } else {
                index = 1;
                while (index < 3) {
                    if (values[index] != 0.0f) {
                        *(s32 *)(entry + 0x14) = index;
                        break;
                    }
                    index++;
                }
            }
            break;
        case 25: {
            Obj_1AD538 *current = B_002E65E0.current;
            if (current != 0) {
                *(s32 *)(entry + 0x14) = current - B_002E65E0.saves;
            }
            break;
        }
        }
    }
}
}
