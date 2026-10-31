typedef signed char s8; typedef short s16; typedef int s32;
typedef int s128 __attribute__((mode(TI)));
extern "C" {
struct OBJ_213C68;
struct VT_213C68 { char pad[8]; short delta; short unused; void *(*fn)(char *, int, int); };
struct OBJ_213C68 { VT_213C68 *vt; };
void func_00213C68(char *arg0, char *arg1) {
    if (*(s128 **)(arg0 + 0xF8) == 0) {
        OBJ_213C68 *obj = *(OBJ_213C68 **)(arg0 + 0xC4);
        VT_213C68 *vt = obj->vt;
        *(void **)(arg0 + 0xF8) = vt->fn((char *)obj + vt->delta, 0x20, 0x1F);
    }
    s128 *dst = *(s128 **)(arg0 + 0xF8);
    dst[0] = *(s128 *)arg1;
    dst[1] = *(s128 *)(arg1 + 0x10);
}
}
