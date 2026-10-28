#include "sly2.h"
struct SPRITE { char pad[0x30]; };
struct BLOT { char pad[0x84]; SPRITE* sprites; };
struct HANDLE { char pad[0x20]; void* held; };
struct CHAR { int unk0; int type; BLOT* blot; int unkC; int isprite; HANDLE* handle; };
struct SLOT { char pad[0x58]; int instance; };
extern "C" void StopSpriteInstance(SPRITE*, int);
extern "C" void func_001BED18(void*);
extern "C" void InitDepthSlot(SLOT*);
extern "C" void func_002158C0(CHAR* pchar, SLOT* pslot)
{
    switch (pchar->type) {
    case 4:
        StopSpriteInstance(&pchar->blot->sprites[pchar->isprite], pslot->instance);
        break;
    case 6:
        if (pchar->handle != 0) {
            void* held = pchar->handle->held;
            if (held != 0)
                func_001BED18(held);
            pchar->handle = 0;
        }
        break;
    }
    InitDepthSlot(pslot);
}
