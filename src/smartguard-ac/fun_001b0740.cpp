extern char B_002DEB30;
extern char B_003DD490;
extern char B_003D9ED0;
extern char D_002C01D0;
extern char D_002C01F0;
extern char D_002C0210;

struct MENUITEM {
    char pad[0x1C];
    unsigned grf;
};

extern "C" {
void bevy_camera_follow_activity(void *, int, int);
void *PpoSwFocusBase(void *);
int CidGetBasic(void *);
void PauseMenu_Push(void *, int, int, int, void *);
}

void func_001B0740(MENUITEM *pitem)
{
    bevy_camera_follow_activity(&B_002DEB30, 0x29, 0);
    void *ppoFocus = PpoSwFocusBase(&B_003DD490);
    int cid = CidGetBasic(ppoFocus);
    char *pmenudef;
    switch (cid) {
    case 0x35:
        pmenudef = &D_002C01D0;
        break;
    case 0x37:
        pmenudef = &D_002C01F0;
        break;
    case 0x36:
        pmenudef = &D_002C0210;
        break;
    default:
        return;
    }
    PauseMenu_Push(&B_003D9ED0, 0, 0, 0, pmenudef);
    if (pitem != 0)
        pitem->grf |= 2;
}
