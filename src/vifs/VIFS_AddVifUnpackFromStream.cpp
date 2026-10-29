extern "C" {
typedef int s32;
typedef unsigned int u32;
void CBinaryInputStream_Read_thunk(void *stream, s32, s32);
void UnpackHelper__4VIFS3UPKiiPiPPUi(void *thisVifs, void *upk, s32, s32, s32 *, u32 **);

void VIFS_AddVifUnpackFromStream(void *thisVifs, void *upk, s32 arg2, void *stream, s32 arg4) {
    s32 sp0;
    s32 sp4;

    UnpackHelper__4VIFS3UPKiiPiPPUi(thisVifs, upk, arg2, arg4, &sp0, (u32 **)&sp4);
    CBinaryInputStream_Read_thunk(stream, sp0, sp4);
}
}
