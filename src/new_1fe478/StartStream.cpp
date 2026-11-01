struct VT_1FE5F0 { char pad[8]; short delta; short index; void (*fn)(void *); };
struct Obj_1FE5F0 { char pad[0xC]; VT_1FE5F0 *vt; };
struct Rec_1FE5F0 { char pad[0x48]; int oid; char pad4c[0x54 - 0x4C]; int f54; };
struct Stream_1FE5F0 { char pad[0x200]; void *amb; char pad204[0x22C - 0x204]; Obj_1FE5F0 *aplo[6]; int f244; int f248; int f24C; };
extern "C" void StopStream(Stream_1FE5F0 *);
extern "C" Rec_1FE5F0 *func_001FCFA0(Stream_1FE5F0 *, int);
extern "C" void *NewStreamAmb(Rec_1FE5F0 *, int);
extern "C" void func_00259B48(void *, void *);
extern "C" void func_00227728(void *, int, int);
extern "C" Obj_1FE5F0 *PloFindSwObjectByClass(void *, int, int, int);
extern "C" int func_001FD0C0(Stream_1FE5F0 *, int);
extern "C" Obj_1FE5F0 *PsmaFindAlo(Obj_1FE5F0 *, int);
extern "C" char B_003DD490;
extern "C" char B_004435F0;
extern "C" void *StartStream(Stream_1FE5F0 *stream, int id, int noSubtitle)
{
    StopStream(stream);
    Rec_1FE5F0 *rec = func_001FCFA0(stream, id);
    if (rec == 0)
        return 0;
    void *amb = NewStreamAmb(rec, 0);
    func_00259B48(&stream->amb, amb);
    stream->f244 = 0;
    stream->f248 = 0;
    stream->f24C = 0;
    if (noSubtitle == 0)
        func_00227728(&B_004435F0, id, rec->oid);
    if (rec->oid == -1 || rec->f54 == 0)
        return stream->amb;
    Obj_1FE5F0 *plo = PloFindSwObjectByClass(&B_003DD490, 5, rec->oid, 0);
    if (plo == 0)
        return stream->amb;
    for (int i = 0; i < 6; i++) {
        if (i == 3)
            stream->aplo[3] = plo;
        else
            stream->aplo[i] = PsmaFindAlo(plo, func_001FD0C0(stream, i));
        Obj_1FE5F0 *obj = stream->aplo[i];
        if (obj) {
            VT_1FE5F0 *vt = obj->vt;
            vt->fn((char *)obj + vt->delta);
        }
    }
    return stream->amb;
}
