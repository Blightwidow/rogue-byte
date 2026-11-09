// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BDD8C-0X2BDDE8 (piece data/dmas-dzg), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void AddBitmapUploads();
extern "C" void AddVifFlushaPacket();
extern "C" void DrawPassSetupCamera();
extern "C" void EnsureBlipVu1Code();
extern "C" void UploadRelightLights();
extern "C" void func_0013A858();
extern "C" void func_001681B0();
extern "C" void func_0016DA48();
extern "C" void func_0016DD58();
extern "C" void func_0016E228();
extern "C" void func_0016E380();
extern "C" void func_0016E3C8();
extern "C" void func_0016E400();
extern "C" void func_0016EA20();
extern "C" void func_001BE990();
extern "C" void func_001BE9E8();
extern "C" void func_00211A80();
extern "C" void func_00211C10();

// data-ok: retail's bytes at 0X2BDD8C
void *D_002BDD8C[23] = {(void *)func_0016E228, (void *)func_0016EA20, (void *)AddVifFlushaPacket, (void *)EnsureBlipVu1Code, (void *)func_0013A858, (void *)AddBitmapUploads, (void *)func_0016E380, (void *)UploadRelightLights, (void *)func_001681B0, (void *)func_00211A80, (void *)func_00211C10, (void *)func_0016DA48, (void *)func_0016DD58, (void *)func_0016DA48, (void *)func_0016DD58, (void *)func_001BE990, (void *)func_0016E228, (void *)func_001BE9E8, (void *)func_0016E228, (void *)DrawPassSetupCamera, (void *)func_0016E228, (void *)func_0016E3C8, (void *)func_0016E400};
