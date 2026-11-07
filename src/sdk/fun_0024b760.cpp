// SPDX-License-Identifier: GPL-3.0-or-later
struct MpegState {
    char pad0[0x184];
    int mode;
};
struct MpegHandle {
    char pad0[0x40];
    MpegState *state;
};
extern "C" {
void func_0024B148(MpegHandle *handle, int first, int second);
void func_0024B2B8(MpegHandle *handle, int first, int second);
void func_0024B760(MpegHandle *handle, int first, int second) {
    if (handle->state->mode != 3) {
        func_0024B2B8(handle, first, second);
    } else {
        func_0024B148(handle, first, second);
    }
}
}
