struct ALLOCREQ { int size; int align; };
struct Stream_1EB2F0;
struct Shd_1EB2F0;
struct Tex_1EB2F0 { char pad0[6]; unsigned char tag; char pad1; Shd_1EB2F0 *owner; char pad2[0x14 - 0xC]; };
struct Part_1EB2F0 { int count; void *memory; };
struct Shd_1EB2F0 {
    char pad0[4]; unsigned char kind; unsigned char flags; char pad1[2]; int color8; int colorC; int color10; char pad2[3];
    unsigned char texCount; Tex_1EB2F0 *textures; int partCount; Part_1EB2F0 *parts; int tag24; int texture28;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream_1EB2F0 *, int, Shd_1EB2F0 *);
extern "C" void FilterColorRgba8_1ed278(void *);
extern "C" void LoadTexFromBrx__FP18CBinaryInputStreamP3TEX(Stream_1EB2F0 *, Tex_1EB2F0 *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" int S16Read__18CBinaryInputStream(Stream_1EB2F0 *);
extern int *B_003DD004;
extern "C" void LoadShdFromBrx(Stream_1EB2F0 *stream, Shd_1EB2F0 *shd) {
    ALLOCREQ request;
    CBinaryInputStream_Read_thunk(stream, 0x18, shd);
    FilterColorRgba8_1ed278(&shd->color8);
    FilterColorRgba8_1ed278(&shd->colorC);
    FilterColorRgba8_1ed278(&shd->color10);
    int textureIndex = S16Read__18CBinaryInputStream(stream);
    if (textureIndex >= 0) {
        shd->texture28 = B_003DD004[textureIndex];
    }
    int index = 0;
    request.align = 0x10;
    request.size = shd->texCount * 0x14;
    shd->textures = (Tex_1EB2F0 *)PvAllocSwClearImpl__Fi(&request);
    if (shd->texCount != 0) {
        int offset = 0;
        do {
            index += 1;
            Tex_1EB2F0 *texture = (Tex_1EB2F0 *)((char *)shd->textures + offset);
            offset += 0x14;
            LoadTexFromBrx__FP18CBinaryInputStreamP3TEX(stream, texture);
            texture->owner = shd;
        } while (index < shd->texCount);
    }
    shd->tag24 = shd->textures->tag;
    switch (shd->kind) {
    case 0:
    case 4:
    case 5:
    case 6:
        shd->partCount = 1;
        break;
    case 1:
    case 2:
        shd->partCount = 2;
        break;
    case 7:
        shd->partCount = (shd->flags & 0x20) ? 2 : 3;
        break;
    case 3:
        shd->partCount = 4;
        break;
    }
    request.align = 0x10;
    request.size = shd->partCount * 8;
    Part_1EB2F0 *parts = (Part_1EB2F0 *)PvAllocSwClearImpl__Fi(&request);
    shd->parts = parts;
    Part_1EB2F0 *cursor;
    switch (shd->kind) {
    case 0:
    case 4:
    case 5:
    case 6: {
        int vertices = shd->textures->owner->tag24 + 8;
        parts[0].count = vertices;
        request.size = vertices * 0x10;
        request.align = 0x10;
        parts[0].memory = PvAllocSwClearImpl__Fi(&request);
        return;
    }
    case 3: {
        int extra;
        if (!(shd->flags & 2)) {
            extra = 0;
        } else {
            extra = shd->textures->owner->tag24 + 2;
        }
        int vertices = extra + 6;
        cursor = &parts[1];
        parts[0].count = vertices;
        request.size = vertices * 0x10;
        request.align = 0x10;
        parts[0].memory = PvAllocSwClearImpl__Fi(&request);
        parts[1].count = 6;
        request.size = 0x60;
        request.align = 0x10;
        cursor->memory = PvAllocSwClearImpl__Fi(&request);
        parts[2].count = 8;
        cursor = &parts[2];
        request.size = 0x80;
        request.align = 0x10;
        cursor->memory = PvAllocSwClearImpl__Fi(&request);
        parts[3].count = 4;
        cursor = &parts[3];
        request.size = 0x40;
        request.align = 0x10;
        goto allocateLast;
    }
    case 2:
        parts[0].count = 5;
        cursor = &parts[1];
        request.size = 0x50;
        request.align = 0x10;
        parts[0].memory = PvAllocSwClearImpl__Fi(&request);
        parts[1].count = 5;
        request.size = 0x50;
        request.align = 0x10;
        goto allocateLast;
    case 1: {
        cursor = &parts[1];
        int vertices = shd->textures->owner->tag24 + 8;
        parts[0].count = vertices;
        request.size = vertices * 0x10;
        request.align = 0x10;
        parts[0].memory = PvAllocSwClearImpl__Fi(&request);
        parts[1].count = vertices;
        request.size = vertices * 0x10;
        request.align = 0x10;
        goto allocateLast;
    }
    case 7: {
        cursor = &parts[1];
        int vertices = shd->textures->owner->tag24 + 8;
        parts[0].count = vertices;
        int bytes = vertices * 0x10;
        request.size = bytes;
        request.align = 0x10;
        parts[0].memory = PvAllocSwClearImpl__Fi(&request);
        parts[1].count = vertices;
        request.size = bytes;
        request.align = 0x10;
        cursor->memory = PvAllocSwClearImpl__Fi(&request);
        cursor = &parts[2];
        if (!(shd->flags & 0x20)) {
            parts[2].count = vertices;
            request.size = bytes;
            request.align = 0x10;
            goto allocateLast;
        }
        return;
    }
    default:
        return;
    }
allocateLast:
    cursor->memory = PvAllocSwClearImpl__Fi(&request);
}
