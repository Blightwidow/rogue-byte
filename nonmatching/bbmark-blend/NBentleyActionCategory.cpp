struct BENTLEY_136CC0 { char pad[0x204]; int flag; char pad2[0x13D0 - 0x208]; int state; };
extern "C" int func_00143C78(void *);
extern "C" int NBentleyActionCategory(BENTLEY_136CC0 *pbentley)
{
    if (pbentley->flag != 0)
        return 0;
    switch (pbentley->state) {
    case 0xD:
        return 0;
    case 8:
        return 5;
    case 0xE:
        return 0xF;
    }
    return func_00143C78(pbentley);
}