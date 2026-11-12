#include "types.h"
extern "C" {
extern const char RO_002AB220[];
extern const char RO_002AB228[];
s32 func_002401D8(s32, const char *);
u8 *func_0023F240(u8 *, s32 *);
u8 *func_0023F288(u8 *, s32 *);
u32 strlen(const char *);
}

struct UnalignedWord {
    s32 value __attribute__((packed));
};

extern "C" s32 func_0023F938(u8 *arg0, s32 *arg1) {
    s32 nestedLength;
    s32 result;
    u8 *end;
    u8 *cursor;
    arg1[0] = (s32)arg0 - *(s32 *)(arg0 + 4) + 13;
    if (func_002401D8(arg1[0], RO_002AB220) != 0 && func_002401D8(arg1[0], RO_002AB228) != 0 && *(s8 *)arg1[0] != 0x7A) {
        result = 0;
    } else {
        end = (u8 *)arg1[0] + strlen((const char *)arg1[0]);
        cursor = end + 1;
        if (func_002401D8(arg1[0], RO_002AB228) == 0) {
            arg1[1] = ((UnalignedWord *)cursor)->value;
            cursor = end + 5;
        } else {
            arg1[1] = 0;
        }
        cursor = func_0023F288(func_0023F240(cursor, &arg1[2]), &arg1[3]);
        arg1[4] = *cursor;
        cursor++;
        if (*(s8 *)arg1[0] == 0x7A) {
            cursor = func_0023F240(cursor, &nestedLength) + nestedLength;
        }
        result = (s32)cursor;
    }
    return result;
}
