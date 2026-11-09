// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA900-0X2CA9F0 (piece data/new_12ae28), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void EvaluateAcrb();
extern "C" void EvaluateAcrc();
extern "C" void LoadAcrbFromBrx();
extern "C" void LoadAcrcFromBrx();
extern "C" void bevy_anim_keys_axis_segment();
extern "C" void func_0012B4F0();
extern "C" void func_0012B520();
extern "C" void func_0012B738();
extern "C" void func_0012BA98();
extern "C" void func_0012BBD0();
extern "C" void func_0012BE68();
extern "C" void func_0012BF30();
extern "C" void func_0012C440();
extern "C" void func_0012C570();
extern "C" void func_0012C768();
extern "C" void func_0012CA68();
extern "C" void func_0023C820();

// data-ok: retail's bytes at 0X2CA900
void *D_002CA900[10] = {0, 0, 0, (void *)func_0012C570, 0, (void *)func_0012C768, 0, (void *)func_0012CA68, 0, 0};

// data-ok: retail's bytes at 0X2CA928
void *D_002CA928[10] = {0, 0, 0, (void *)func_0012BF30, 0, (void *)bevy_anim_keys_axis_segment, 0, (void *)func_0012C440, 0, 0};

// data-ok: retail's bytes at 0X2CA950
void *D_002CA950[10] = {0, 0, 0, (void *)func_0012BA98, 0, (void *)func_0012BBD0, 0, (void *)func_0012BE68, 0, 0};

// data-ok: retail's bytes at 0X2CA978
void *D_002CA978[10] = {0, 0, 0, (void *)LoadAcrbFromBrx, 0, (void *)func_0012B738, 0, (void *)EvaluateAcrb, 0, 0};

// data-ok: retail's bytes at 0X2CA9A0
void *D_002CA9A0[20] = {0, 0, 0, (void *)LoadAcrcFromBrx, 0, (void *)func_0012B520, 0, (void *)EvaluateAcrc, 0, 0, 0, 0, 0, (void *)func_0012B4F0, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, 0};
