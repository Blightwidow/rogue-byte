struct Stream_227380;
struct Obj_227380 { char pad[0xE0]; unsigned f0; char pad1[4]; char bspc[0x10]; char geom[1]; };
extern "C" {
void LoadXfmBaseFromBrx(Obj_227380 *, Stream_227380 *);
void CBinaryInputStream_ReadGeom(Stream_227380 *, void *);
void CBinaryInputStream_ReadBspc(Stream_227380 *, void *, void *);
unsigned U32Read__18CBinaryInputStream(Stream_227380 *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, Stream_227380 *);
void func_00227380(Obj_227380 *self, Stream_227380 *stream) {
    LoadXfmBaseFromBrx(self, stream);
    self->f0 = U32Read__18CBinaryInputStream(stream);
    CBinaryInputStream_ReadGeom(stream, self->geom);
    CBinaryInputStream_ReadBspc(stream, self->geom, self->bspc);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(self, stream);
}
}
