#include "sly2.h"
struct CARD { int port; int slot; char pad8[4]; int fileCount; char pad10[0xC]; int freeBlocks; char pad20[4]; char slots[3][0x5464]; };
extern "C" {
int sceMcGetEntSpace(int, int, const char *);
int McSync(void *, int, int, int *);
int FUN_0018c1e8(const char *);
int CreateSaveDirectory(CARD *);
int InitAndWriteSaveSlot(CARD *, char *);
void BuildSlotFilePath(CARD *, char *, char *);
void DeleteMemcardFile(CARD *, const char *);
void func_001ACC38(void *, int);
extern char B_002E6550[];
extern const char RO_002A38E8[];
extern const char RO_002A6BB0[];
extern const char RO_002A6BC8[];
}
extern "C" int CreateSaveFilesOnCard(CARD *card)
{
    int spaceFree;
    char path[0x50];
    int result = McSync((char *)card + 0xFD5C, sceMcGetEntSpace(card->port, card->slot, "/"), 0x12, &spaceFree);
    if (result == 0) {
        int need = 1;
        if (spaceFree == 0)
            need = 2;
        need += 5;
        need += (FUN_0018c1e8(RO_002A38E8) + 0x3FF) / 0x400;
        need += 0x42;
        result = 1;
        if (card->freeBlocks >= need) {
            result = CreateSaveDirectory(card);
            char *pslot = card->slots[0];
            if (result == 0) {
                int index = 0;
                do {
                    result = InitAndWriteSaveSlot(card, pslot);
                    index++;
                    if (result != 0)
                        break;
                    pslot += 0x5464;
                } while (index < 3);
                if (result == 0) {
                    if (card->fileCount < 5)
                        card->fileCount = 5;
                    return result;
                }
                pslot = card->slots[0];
            }
            int count = 2;
            do {
                char *pthis = pslot;
                pslot += 0x5464;
                BuildSlotFilePath(card, pthis, path);
                DeleteMemcardFile(card, path);
                count--;
            } while (count >= 0);
            DeleteMemcardFile(card, "/BASCUS-97316YAOTWTD!/icon.sys");
            DeleteMemcardFile(card, "/BASCUS-97316YAOTWTD!/memcard_icon.ico");
            DeleteMemcardFile(card, RO_002A6BC8);
            DeleteMemcardFile(card, RO_002A6BB0);
        }
        if (result == 0)
            return 0;
    }
    func_001ACC38(B_002E6550, 3);
    return result;
}
