struct Entry_1DB520 { int id; char pad[0xC]; int link; float low; float high; int flags; };
struct VT_1DB520 {
    char pad0[0x50]; short delta50; short unused50; void (*fn50)(void *);
    short delta58; short unused58; void (*fn58)(void *);
    char pad1[0x188 - 0x60]; short delta188; short unused188; void (*fn188)(void *, int);
    short delta190; short unused190; void (*fn190)(void *);
};
struct Object_1DB520 { char pad[0xC]; VT_1DB520 *vt; };
struct Menu_1DB520 {
    char pad[0xC]; VT_1DB520 *vt; char pad1[0x20 - 0x10]; int dialog; Object_1DB520 *object; char pad2[0x40 - 0x28];
    int page; float clock; char pad3[0x4C - 0x48]; int entryCount; Entry_1DB520 *entries;
};
extern "C" void ClearHandsOff(void *, int);
extern "C" void GadgetMenu_RefreshFlags(Menu_1DB520 *);
extern "C" void GadgetMenu_SelectGadget(Menu_1DB520 *, int);
extern "C" void Menu_SetDialog(Menu_1DB520 *, int, int);
extern "C" Object_1DB520 *PloFindSwObject_thunk(void *, int, int, int);
extern "C" void SetClockRate(void *, int, float);
extern "C" void SetHandsOff(void *, int);
extern char B_003DD490[];
extern Entry_1DB520 D_002C2DE8[];
extern Entry_1DB520 D_002C3028[];
extern Entry_1DB520 D_002C3148[];
struct Clock_1DB520 { char pad[0x3C]; float rate; };
extern Clock_1DB520 g_2dded0;
extern const float g_2a79cc;
extern "C" void GadgetMenu_SetPage(Menu_1DB520 *self, int page) {
    if (page == self->page) {
        return;
    }
    if (self->page == -1) {
        SetClockRate(&g_2dded0, 0, 0.0f);
        SetHandsOff(B_003DD490, 0);
        self->vt->fn50((char *)self + self->vt->delta50);
    }
    GadgetMenu_SelectGadget(self, -1);
    self->page = page;
    self->clock = g_2dded0.rate;
    switch (page) {
    case -1: {
        Object_1DB520 *object = self->object;
        if (object != 0) {
            object->vt->fn190((char *)object + object->vt->delta190);
        }
        for (int index = 0; index < self->entryCount; index++) {
            self->entries[index].link = -1;
        }
        self->entryCount = 0;
        self->entries = 0;
        SetClockRate(&g_2dded0, 0, 1.0f);
        ClearHandsOff(B_003DD490, 0);
        self->vt->fn58((char *)self + self->vt->delta58);
        Menu_SetDialog(self, -1, -1);
        self->object = 0;
        self->dialog = -1;
        break;
    }
    case 0:
        self->dialog = 0x375;
        self->entryCount = 0x12;
        self->entries = D_002C2DE8;
        break;
    case 1:
        self->dialog = 0x376;
        self->entryCount = 9;
        self->entries = D_002C3028;
        break;
    case 2:
        self->dialog = 0x377;
        self->entryCount = 8;
        self->entries = D_002C3148;
        break;
    }
    if (self->page != -1) {
        GadgetMenu_RefreshFlags(self);
        Object_1DB520 *found = PloFindSwObject_thunk(B_003DD490, 5, self->dialog, 0);
        self->object = found;
        if (found == 0) {
            GadgetMenu_SetPage(self, -1);
            return;
        }
        found->vt->fn188((char *)found + found->vt->delta188, 0x318);
        float best = g_2a79cc;
        int bestId = -1;
        if (self->entryCount > 0) {
            Entry_1DB520 *entry = self->entries;
            int remaining = self->entryCount;
            do {
                remaining -= 1;
                if (entry->flags & 4) {
                    float sum = entry->low + entry->high;
                    if (sum < best) {
                        bestId = entry->id;
                        best = sum;
                    }
                }
                entry += 1;
            } while (remaining != 0);
        }
        GadgetMenu_SelectGadget(self, bestId);
    }
}
