struct Bis;
struct ALLOCREQ { int size; int align; };
struct VT { short delta; short index; void *(*fn)(void *, int); };
struct GEOM { int word[6]; };
struct SOREC {
    void *shape; void *owner; float field8; int fieldC;
    int field10; short field14; unsigned long flagA : 1; unsigned long flagB : 1; unsigned long flagC : 1;
    int field18; int field1C; char pad20[0x48]; int field68[4]; GEOM geomSource; GEOM geomCopy; char padA8[8];
};
struct SO {
    char pad0[0xC]; char *vtable; char pad10[0x30]; int *field40; char pad44[0x74];
    int fieldB8; char padBC[0x24]; int recordCount; SOREC *records; void *momint;
};
struct MOMINT { char pad0[0xD0]; float field_d0; char padD4[0xC]; };
extern "C" {
int U32Read__18CBinaryInputStream(Bis *);
int S8Read__18CBinaryInputStream(Bis *);
int S16Read__18CBinaryInputStream(Bis *);
int S32Read__18CBinaryInputStream(Bis *);
float F32Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void LoadAloFromBrx(SO *, Bis *);
void LoadGlobsetFromBrx(void *, SO *, Bis *);
void CBinaryInputStream_ReadGeom(Bis *, GEOM *);
void CBinaryInputStream_ReadBspc(Bis *, GEOM *, void *);
void CBinaryInputStream_ReadMatrix(Bis *, void *);
void CloneGeom(GEOM *, int, GEOM *);
void AddSoGeomsToOxa(SO *);
void AdjustSoMomint__FP2SOf(SO *, float);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(SO *, Bis *);
void func_001F2500(SO *);
void LoadSwObjectsFromBrx(SO *, Bis *, int);
int SetLoGrfzon(SO *, int);
extern char D_002C44F0[];
}
extern "C" void CSo_LoadFromBrx(SO *pso, Bis *pbis)
{
    int index = 0;
    SOREC *rec;
    ALLOCREQ req;
    LoadAloFromBrx(pso, pbis);
    int grfzon = U32Read__18CBinaryInputStream(pbis);
    LoadGlobsetFromBrx((char *)pso + 0x80, pso, pbis);
    VT *vtA = (VT *)(pso->vtable + 0x1F8);
    int extra = ((int (*)(void *))vtA->fn)((char *)pso + vtA->delta);
    int count = S16Read__18CBinaryInputStream(pbis);
    req.size = (count + extra) * 0xB0;
    req.align = 0x10;
    pso->recordCount = count;
    pso->records = (SOREC *)PvAllocSwClearImpl__Fi(&req);
    if (pso->recordCount > 0) {
        do {
            rec = &pso->records[index];
            rec->owner = pso;
            int shapeId = S16Read__18CBinaryInputStream(pbis);
            VT *vtB = (VT *)(pso->vtable + 0x198);
            rec->shape = vtB->fn((char *)pso + vtB->delta, shapeId);
            rec->fieldC = S32Read__18CBinaryInputStream(pbis);
            rec->flagA = S8Read__18CBinaryInputStream(pbis);
            rec->flagB = S8Read__18CBinaryInputStream(pbis);
            rec->field8 = F32Read__18CBinaryInputStream(pbis);
            CBinaryInputStream_ReadGeom(pbis, &rec->geomSource);
            GEOM *geomUsed;
            if (rec->shape == 0) {
                rec->shape = D_002C44F0;
                rec->geomCopy = rec->geomSource;
                geomUsed = &rec->geomCopy;
            } else {
                CloneGeom(&rec->geomSource, 0, &rec->geomCopy);
                geomUsed = &rec->geomCopy;
            }
            CBinaryInputStream_ReadBspc(pbis, geomUsed, rec->field68);
            index++;
            rec->field18 = U32Read__18CBinaryInputStream(pbis);
            rec->field14 = S16Read__18CBinaryInputStream(pbis);
            rec->field1C = S16Read__18CBinaryInputStream(pbis);
            rec->flagC = S8Read__18CBinaryInputStream(pbis);
        } while (index < pso->recordCount);
    }
    index = pso->recordCount;
    if (index < index + extra) {
        int offset = index * 0xB0;
        do {
            index++;
            rec = (SOREC *)((char *)pso->records + offset);
            rec->field14 = -10;
            offset += 0xB0;
        } while (index < pso->recordCount + extra);
    }
    AddSoGeomsToOxa(pso);
    if (pso->recordCount > 0) {
        req.size = 0xE0;
        req.align = 0x10;
        MOMINT *momint = (MOMINT *)PvAllocSwClearImpl__Fi(&req);
        pso->momint = momint;
        momint->field_d0 = F32Read__18CBinaryInputStream(pbis);
        CBinaryInputStream_ReadMatrix(pbis, momint);
        AdjustSoMomint__FP2SOf(pso, 1.0f);
        VT *vtC = (VT *)(pso->vtable + 0x200);
        ((void (*)(void *))vtC->fn)((char *)pso + vtC->delta);
    }
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(pso, pbis);
    if (pso->fieldB8 != 0) {
        int *flags = pso->field40;
        if (((unsigned)flags ^ 1) & 1) {
            *flags |= 8;
        } else {
            pso->field40 = (int *)((int)flags | 8);
        }
    }
    func_001F2500(pso);
    LoadSwObjectsFromBrx(pso, pbis, 0);
    SetLoGrfzon(pso, grfzon);
}
