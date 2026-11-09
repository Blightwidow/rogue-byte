// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA6A0-0X2CA8A0 (piece data/alo-missile), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ActivateAct();
extern "C" void ActivateActadj();
extern "C" void CloneAct();
extern "C" void DeactivateActadj();
extern "C" void GetActPositionGoal__FP3ACTfP6VECTORT2();
extern "C" void GetActadjGoal();
extern "C" void GetActadjPositionGoal();
extern "C" void GetActbankRotationGoal();
extern "C" void GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR();
extern "C" void GetActvalPositionGoal();
extern "C" void ReselectActadj();
extern "C" void func_0012CED8();
extern "C" void func_0012CF20();
extern "C" void func_0012CF28();
extern "C" void func_0012CF30();
extern "C" void func_0012D088();
extern "C" void func_0012D0D8();
extern "C" void func_0012D210();
extern "C" void func_0012DEF0();
extern "C" void func_0012DFE0();
extern "C" void func_0012E010();
extern "C" void func_0012E120();

// data-ok: retail's bytes at 0X2CA6A0
void *D_002CA6A0[16] = {0, 0, 0, (void *)func_0012E120, 0, (void *)func_0012CED8, 0, (void *)func_0012CF20, 0, (void *)func_0012CF28, 0, (void *)func_0012CF30, 0, (void *)CloneAct, 0, 0};

// data-ok: retail's bytes at 0X2CA6E0
void *D_002CA6E0[16] = {0, 0, 0, (void *)ActivateAct, 0, (void *)func_0012CED8, 0, (void *)func_0012CF20, 0, (void *)func_0012E010, 0, (void *)GetActvalPositionGoal, 0, (void *)CloneAct, 0, 0};

// data-ok: retail's bytes at 0X2CA720
void *D_002CA720[16] = {0, 0, 0, (void *)ActivateAct, 0, (void *)func_0012CED8, 0, (void *)func_0012CF20, 0, (void *)func_0012DEF0, 0, (void *)func_0012DFE0, 0, (void *)CloneAct, 0, 0};

// data-ok: retail's bytes at 0X2CA760
void *D_002CA760[16] = {0, 0, 0, (void *)ActivateActadj, 0, (void *)DeactivateActadj, 0, (void *)ReselectActadj, 0, (void *)GetActadjGoal, 0, (void *)GetActadjPositionGoal, 0, (void *)CloneAct, 0, 0};

// data-ok: retail's bytes at 0X2CA7A0
void *D_002CA7A0[16] = {0, 0, 0, (void *)ActivateAct, 0, (void *)func_0012CED8, 0, (void *)func_0012CF20, 0, (void *)GetActbankRotationGoal, 0, (void *)func_0012CF30, 0, (void *)CloneAct, 0, 0};

// data-ok: retail's bytes at 0X2CA7E0
void *D_002CA7E0[16] = {0, 0, 0, (void *)ActivateAct, 0, (void *)func_0012D210, 0, (void *)func_0012CF20, 0, (void *)GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR, 0, (void *)GetActPositionGoal__FP3ACTfP6VECTORT2, 0, (void *)CloneAct, 0, 0};

// data-ok: retail's bytes at 0X2CA820
void *D_002CA820[32] = {0, 0, 0, (void *)ActivateAct, 0, (void *)func_0012CED8, 0, (void *)func_0012CF20, 0, (void *)func_0012D088, 0, (void *)func_0012D0D8, 0, (void *)CloneAct, 0, 0, 0, 0, 0, (void *)ActivateAct, 0, (void *)func_0012CED8, 0, (void *)func_0012CF20, 0, (void *)func_0012CF28, 0, (void *)func_0012CF30, 0, (void *)CloneAct, 0, 0};
