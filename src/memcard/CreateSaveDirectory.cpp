#include "sly2.h"
extern "C" int MakeMemcardDirectory(void *, const char *);
extern "C" int WriteMemcardFile(void *, const char *, const char *, int);
extern "C" int WriteIconSys(void *, const char *, const char *);
extern "C" int load_sly_icon_from_disc(void *, const char *);
extern "C" int CreateSaveDirectory(void *card)
{
    const char *directory = "/BASCUS-97316YAOTWTD!";
    int result = MakeMemcardDirectory(card, directory);
    if (result == 0) {
        const char *title = "Sly 2";
        result = WriteMemcardFile(card, "/BASCUS-97316YAOTWTD!/BASCUS-97316YAOTWTD!", title, 5);
        if (result == 0) {
            result = WriteIconSys(card, directory, title);
            if (result == 0)
                result = load_sly_icon_from_disc(card, directory);
        }
    }
    return result;
}
