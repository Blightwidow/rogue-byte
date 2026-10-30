struct Vt_13FB40 { char pad0[8]; short d8; short i8; void (*fC)(void *, int, void *); char pad1[0x70 - 0x10]; short d70; short i70; void (*f74)(void *, void *, void *); };
struct Obj_13FB40 { char pad0[0xC]; Vt_13FB40 *vt; char pad1[0x50 - 0x10]; int f50; };
struct Sink_13FB40 { Vt_13FB40 *vt; int a; int b; };
struct World_13FB40 { char pad[0x3F0C]; int f3F0C; int f3F10; };
extern "C" {
void CBinaryInputStream_Read_thunk(void *, int, void *);
void CBinaryInputStream_Skip(void *, int);
int FIsCidDerivedFrom(int, int);
int MakeCloneId(int, int);
int PcnodeFindOrAddClonePath(int, int, int *);
int PloFindSwObject(void *, int, int, int);
int PloFindSwObject_thunk(void *, int, int, int);
Obj_13FB40 *PloNew(int, int, int, int);
int S16Read__18CBinaryInputStream(void *);
int S32Read__18CBinaryInputStream(void *);
int S8Read__18CBinaryInputStream(void *);
int func_0013FAD0(int, short *);
void func_001C9B08(void *, int, int, int);
extern World_13FB40 B_003DD490;
extern char D_002CBE38[];
void LoadSwObjectsFromBrx(int arg0, void *stream, Sink_13FB40 *arg2) {
    Sink_13FB40 empty;
    short ids[0x80];
    int cloneId;
    Obj_13FB40 *created;
    Obj_13FB40 *createdOther;
    int count;
    empty.vt = (Vt_13FB40 *)D_002CBE38;
    empty.a = -1;
    empty.b = -1;
    count = S16Read__18CBinaryInputStream(stream);
    if (count > 0) {
        do {
            int kind = S8Read__18CBinaryInputStream(stream);
            int flag;
            if (kind > 0 || (flag = kind < -2, flag != 0)) {
                CBinaryInputStream_Read_thunk(stream, kind * 2, ids);
                flag = kind < -2;
            }
            Sink_13FB40 *sink = arg2;
            int cid = S16Read__18CBinaryInputStream(stream);
            int id4 = S32Read__18CBinaryInputStream(stream);
            int s6 = S16Read__18CBinaryInputStream(stream);
            int skipLength = S32Read__18CBinaryInputStream(stream);
            if (flag == 0) {
                if (kind >= 0) {
                    if (kind == 0) goto block_21;
                    goto block_16;
                }
                cloneId = MakeCloneId(B_003DD490.f3F10, -1);
                PcnodeFindOrAddClonePath(B_003DD490.f3F0C, 1, &cloneId);
                if (kind == -2) {
                    if (PloFindSwObject_thunk(&B_003DD490, 0x405, id4, 0) == 0) goto block_14;
                    goto block_26;
                }
                if (PloFindSwObject(&B_003DD490, 0x805, id4, 0) == 0) {
block_14:
                    sink = &empty;
                    goto block_21;
                }
                goto block_26;
            }
block_16:
            if (func_0013FAD0(kind, ids) == 0) {
                if ((unsigned)(cid - 0x84) < 2U) {
                    created = PloNew(cid, arg0, id4, -1);
                    created->f50 = 1;
                    created->vt->f74((char *)created + created->vt->d70, stream, created);
                    if (arg2 != 0) {
                        arg2->vt->fC((char *)arg2 + arg2->vt->d8, 1, &created);
                    }
                } else {
block_26:
                    CBinaryInputStream_Skip(stream, skipLength);
                }
            } else {
block_21:
                if (FIsCidDerivedFrom(cid, 6) != 0) {
                    func_001C9B08(&B_003DD490, arg0, cid, id4);
                } else {
                    createdOther = PloNew(cid, arg0, id4, s6);
                    createdOther->vt->f74((char *)createdOther + createdOther->vt->d70, stream, createdOther);
                    if (sink != 0) {
                        sink->vt->fC((char *)sink + sink->vt->d8, 1, &createdOther);
                    }
                }
            }
        } while (--count != 0);
    }
}
}
