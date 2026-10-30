typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64;
#define NULL 0
struct Vt_231768 { char pad[0x188]; s16 delta; s16 pad2; s32 (*method)(void *, s32); };
struct Xfm_231768 { char pad[0xC]; Vt_231768 *vt; char pad2[0x40]; s32 field50; char pad3[0xC]; };
extern "C" {
s32 S16Read__18CBinaryInputStream(void *);
s32 U32Read__18CBinaryInputStream(void *);
void CBinaryInputStream_ReadMatrix4(void *, void *);
void InvalidateXfmMatWorld(void *);
s32 SetLoGrfzon(void *, s32);
void LoadXfmBaseFromBrx(Xfm_231768 *self, void *stream) {
    s32 value = S16Read__18CBinaryInputStream(stream);
    Vt_231768 *vt = self->vt;
    self->field50 = vt->method((char *)self + vt->delta, value);
    CBinaryInputStream_ReadMatrix4(stream, (char *)self + 0x60);
    InvalidateXfmMatWorld(self);
    SetLoGrfzon(self, U32Read__18CBinaryInputStream(stream));
}
}
