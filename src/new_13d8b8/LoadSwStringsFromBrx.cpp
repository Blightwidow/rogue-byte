struct ALLOCREQ { int cb; int cbAlign; };
struct STRING13DF80 { int id; char text[4]; };
struct SW13DF80 { char pad[0x4640]; int cstring; STRING13DF80 *astring; };
extern "C" {
extern int B_002E1E54;
extern char B_003E1C20[];
extern char g_2dd590[];
int U8Read__18CBinaryInputStream(void *);
int S16Read__18CBinaryInputStream(void *);
void Unknown1__18CBinaryInputStream(void *);
void func_00118380(void *, void *, char *, int);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void ResolveStringTable(char *);
void LoadSwStringsFromBrx(SW13DF80 *sw, void *stream)
{
    int ilanguage = 0;
    int clanguage = U8Read__18CBinaryInputStream(stream);
    for (int index = 0; index < clanguage; index++) {
        if (U8Read__18CBinaryInputStream(stream) == B_002E1E54)
            ilanguage = index;
    }
    sw->cstring = S16Read__18CBinaryInputStream(stream);
    ALLOCREQ req;
    req.cb = sw->cstring * 8;
    req.cbAlign = 0x10;
    sw->astring = (STRING13DF80 *)PvAllocSwImpl__Fi(&req);
    for (int istring = 0; istring < sw->cstring; istring++) {
        STRING13DF80 *pstring = &sw->astring[istring];
        pstring->id = S16Read__18CBinaryInputStream(stream);
        for (int index = 0; index < clanguage; index++) {
            if (index == ilanguage)
                func_00118380(stream, pstring->text, g_2dd590, 0x2E);
            else
                Unknown1__18CBinaryInputStream(stream);
        }
    }
    ResolveStringTable(B_003E1C20);
}
}
