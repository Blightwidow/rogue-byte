struct OBJ { int a; int b; int pad; void *vt; };
extern "C" {
void *memset(void *, int, unsigned int);
void func_002562A8(void *);

extern char D_002CC1C0[];
extern char D_002CC240[];
extern char D_002CC2C0[];
extern char D_002CC340[];
extern char D_002CC3C0[];
extern char D_002CC440[];
extern char D_002CC4C0[];
extern char D_002CCE90[];
extern char D_002CDD40[];
extern char D_002CDDC0[];
extern char D_002CF7F8[];
extern char D_002CFA10[];
extern char D_002CFC20[];
extern char D_002CFCA0[];
extern char D_002CFD20[];
extern char D_002CFDA0[];
extern char D_002CFE20[];
extern char D_002CFF20[];
extern char D_002CFFA0[];
extern char D_002D0020[];
extern char D_002D00A0[];
extern char D_002D0120[];
extern char D_002D01A0[];
extern char D_002D0220[];
extern char D_002D02A0[];
extern char D_002D0320[];
extern char D_002D03A0[];
extern char D_002D0420[];
extern char D_002D04A0[];
extern char D_002D0520[];
extern char D_002D05A0[];
extern char D_002D0620[];
extern char D_002D06A0[];
extern char D_002D07B0[];
extern char D_002D0830[];
extern char D_002D08B0[];
extern char D_002D0930[];
extern char D_002D0A30[];
extern char D_002D0AB0[];
extern char D_002D4AF8[];
}

void *PgoalConstruct(int type, OBJ *obj, void *result)
{
    switch (type) {
    case 0x9C:
        memset(obj, 0, 0xB0);
        obj->a = 0;
        obj->vt = D_002D04A0;
        obj->b = 0;
        memset((char *)obj + 0x30, 0, 0x70);
        result = obj;
        break;
    case 0x9D:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002D0AB0;
        obj->b = 0;
        result = obj;
        break;
    case 0x9E:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002D0A30;
        obj->b = 0;
        result = obj;
        break;
    case 0x9F:
        memset(obj, 0, 0x60);
        obj->a = 0;
        obj->vt = D_002D07B0;
        obj->b = 0;
        result = obj;
        break;
    case 0xA1:
        memset(obj, 0, 0xC0);
        obj->a = 0;
        obj->vt = D_002D0930;
        obj->b = 0;
        result = obj;
        break;
    case 0xA2:
        memset(obj, 0, 0xC0);
        obj->a = 0;
        obj->vt = D_002D0830;
        obj->b = 0;
        result = obj;
        break;
    case 0xA3:
        memset(obj, 0, 0xC0);
        obj->a = 0;
        obj->vt = D_002D08B0;
        obj->b = 0;
        result = obj;
        break;
    case 0xA4:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002D0620;
        obj->b = 0;
        result = obj;
        break;
    case 0xA5:
        memset(obj, 0, 0x60);
        obj->a = 0;
        obj->vt = D_002D05A0;
        obj->b = 0;
        result = obj;
        break;
    case 0xA7:
        memset(obj, 0, 0xF0);
        obj->a = 0;
        obj->vt = D_002D06A0;
        obj->b = 0;
        result = obj;
        break;
    case 0xA9:
        memset(obj, 0, 0x60);
        obj->a = 0;
        obj->vt = D_002CF7F8;
        obj->b = 0;
        result = obj;
        break;
    case 0xAA:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002D0520;
        obj->b = 0;
        result = obj;
        break;
    case 0xAB:
        memset(obj, 0, 0xE0);
        obj->a = 0;
        obj->vt = D_002CFA10;
        obj->b = 0;
        result = obj;
        break;
    case 0xAE:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002D4AF8;
        obj->b = 0;
        result = obj;
        break;
    case 0xAC:
        memset(obj, 0, 0xA0);
        obj->a = 0;
        obj->vt = D_002D0320;
        obj->b = 0;
        result = obj;
        break;
    case 0xAF:
        memset(obj, 0, 0x60);
        obj->a = 0;
        obj->vt = D_002D02A0;
        obj->b = 0;
        result = obj;
        break;
    case 0xB0:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002D0420;
        obj->b = 0;
        result = obj;
        break;
    case 0xB1:
        memset(obj, 0, 0x70);
        obj->a = 0;
        obj->vt = D_002D03A0;
        obj->b = 0;
        result = obj;
        break;
    case 0xAD:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002D0220;
        obj->b = 0;
        result = obj;
        break;
    case 0xB2:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002D01A0;
        obj->b = 0;
        result = obj;
        break;
    case 0xB3:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002D0120;
        obj->b = 0;
        result = obj;
        break;
    case 0xB4:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002CDDC0;
        obj->b = 0;
        result = obj;
        break;
    case 0xB5:
        memset(obj, 0, 0x60);
        obj->a = 0;
        obj->vt = D_002CDD40;
        obj->b = 0;
        result = obj;
        break;
    case 0xA8:
        memset(obj, 0, 0xE0);
        obj->a = 0;
        obj->vt = D_002CC4C0;
        obj->b = 0;
        result = obj;
        break;
    case 0xC1:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002CC440;
        obj->b = 0;
        result = obj;
        break;
    case 0xC2:
        memset(obj, 0, 0xA0);
        obj->a = 0;
        obj->vt = D_002CC3C0;
        obj->b = 0;
        result = obj;
        break;
    case 0xC3:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002CC340;
        obj->b = 0;
        result = obj;
        break;
    case 0xC4:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002CC2C0;
        obj->b = 0;
        result = obj;
        break;
    case 0xC5:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002CC240;
        obj->b = 0;
        result = obj;
        break;
    case 0xB6:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002CCE90;
        obj->b = 0;
        result = obj;
        break;
    case 0xC6:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002CC1C0;
        obj->b = 0;
        result = obj;
        break;
    case 0xB7:
        memset(obj, 0, 0x70);
        obj->a = 0;
        obj->vt = D_002D00A0;
        obj->b = 0;
        result = obj;
        break;
    case 0xB8:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002D0020;
        obj->b = 0;
        result = obj;
        break;
    case 0xB9:
        memset(obj, 0, 0x40);
        obj->a = 0;
        obj->vt = D_002CFFA0;
        obj->b = 0;
        result = obj;
        break;
    case 0xBB:
        memset(obj, 0, 0x30);
        obj->a = 0;
        obj->vt = D_002CFF20;
        obj->b = 0;
        result = obj;
        break;
    case 0xBA:
        memset(obj, 0, 0xD0);
        obj->a = 0;
        obj->vt = D_002CFE20;
        obj->b = 0;
        func_002562A8((char *)obj + 0x40);
        func_002562A8((char *)obj + 0x60);
        func_002562A8((char *)obj + 0x80);
        result = obj;
        break;
    case 0xBD:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002CFD20;
        obj->b = 0;
        result = obj;
        break;
    case 0xBE:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002CFCA0;
        obj->b = 0;
        result = obj;
        break;
    case 0xBF:
        memset(obj, 0, 0x50);
        obj->a = 0;
        obj->vt = D_002CFC20;
        obj->b = 0;
        func_002562A8((char *)obj + 0x30);
        result = obj;
        break;
    case 0xC0:
        memset(obj, 0, 0x60);
        obj->a = 0;
        obj->vt = D_002CFDA0;
        obj->b = 0;
        result = obj;
        break;
    }
    return result;
}