struct CRef;
extern "C" int CRef_CopyConstruct(CRef *, const CRef *);
extern "C" void CRef_Destruct(CRef *);
struct CRef {
    int tagk;
    int n;
    CRef(int tag, int value) { tagk = tag; n = value; }
    CRef() { tagk = -1; }
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
    CRef &operator=(const CRef &);
};
struct BASE { int pad0[3]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();  virtual void *GetKey(); };
struct BOOTY { char pad[0x158]; struct { int pad; int oid; } *pinfo; void *pplo; };
struct SAVEDATA { int pad; struct { char pad[0xC]; unsigned short tag; } *ptag; };
struct LOOT { char pad[0x194]; void *pbooty; };
struct JT : BASE { char pad1[0x18 - 0x10]; int idSave; char pad2[0x11A8 - 0x1C]; BOOTY *ploot; };
struct PLO { char pad[0x180]; int tag; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
CRef func_001D8B20(const CRef &, ...);
CRef func_001D8A38(const char *, const char *, char *, int);
CRef RefSetGameSaveValue(int, CRef, void *);
int IdCurrentLevel();
int LootId(void *);
int PpathCrfodbLoot(void *);
int PpathFindBootyOid(int);
int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
SAVEDATA *func_00143AF0(void *, int);
int *func_002109B8(int);
int memcmp(const void *, const void *, unsigned);
int sprintf(char *, const char *, ...);
extern char B_003D4A60[];
extern char B_003DD490[];
extern char RO_002A4D50[], RO_002A4DB0[], RO_002A4DC0[], RO_002A4DC8[];
static inline void SetSaveInt(int path, int number)
{
    CRef value(0x15, number);
    RefSetGameSaveValue(path, value, B_003D4A60);
}
void UpdateJtLootSave(JT *self, int mode, LOOT *loot)
{
    char frame[0x10];
    CStackFrame_Construct(frame);
    switch (mode) {
    case 0: {
        int lootId = loot->pbooty != 0 ? LootId(loot->pbooty) : -1;
        CRef ref = func_001D8B20(CRef(0x15, lootId), self->GetKey(), RO_002A4DB0, 0);
        if (self->ploot == 0) {
            int path = PpathCrfodbLoot(loot);
            SetSaveInt(path, self->idSave);
        } else {
            if (loot->pbooty == 0) {
                int oid = PpathFindBootyOid(self->idSave);
                SetSaveInt(oid, -1);
            }
            int path = PpathCrfodbLoot(loot);
            SetSaveInt(path, LootId(self->ploot));
        }
        break;
    }
    case 1: {
        int oid = PpathFindBootyOid(self->idSave);
        if (oid != 0) {
            SetSaveInt(oid, -1);
        }
        CRef ref = func_001D8B20(CRef(0x15, -1), self->GetKey(), RO_002A4DB0, 0);
        int number = self->ploot->pinfo->oid;
        if (number != -1) {
            char buffer[0x20];
            sprintf(buffer, RO_002A4D50, number);
            ref = func_001D8A38(RO_002A4DC0, RO_002A4DC8, buffer, 0);
            ref = func_001D8B20(CRef(0x15, ref.n + 1), RO_002A4DC0, RO_002A4DC8, buffer, 0);
        }
        break;
    }
    case 2: {
        SAVEDATA *psave = func_00143AF0(self, LootId(self->ploot));
        int level = IdCurrentLevel();
        if (psave != 0 && level != -1) {
            int *plevel = func_002109B8(level);
            int fMatch = 0;
            if (*plevel >= 4) {
                if (memcmp(((void **)psave)[1], ((void **)plevel)[1], 8) == 0)
                    fMatch = 1;
            }
            if (fMatch != 0) {
                PLO *aplo[8];
                int count = CploFindSwObjectsByClass(B_003DD490, 5, 0x25, 0, 0xF, aplo);
                for (int index = 0; index < count; index++) {
                    if (aplo[index]->tag == psave->ptag->tag) {
                        self->ploot->pplo = aplo[index];
                        break;
                    }
                }
            }
        }
        break;
    }
    }
    CStackFrame_Destructor(frame, 2);
}
}
