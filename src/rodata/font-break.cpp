// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A8B80-0X2A9240 (piece rodata/font-break), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void BindTextBinocReadout();
extern "C" void BindTextCounts();
extern "C" void BindTextMarquee();
extern "C" void BindTextMenuRow();
extern char D_002C3EC0[];
extern char D_002C3EF0[];
extern char D_002C3F20[];
extern char D_002C3F50[];
extern char D_002C3F80[];
extern char D_002C3FB0[];
extern char D_002C3FE0[];
extern char D_002C4010[];
extern char D_002C4040[];
extern char D_002C4070[];
extern char D_3E0FB0[];
extern "C" void FormatCompletion();
extern "C" void FormatDialogButtons();
extern "C" void FormatDialogText();
extern "C" void FormatEpselPercent();
extern "C" void FormatEpselTime();
extern "C" void GetEpisodeNameText();
extern "C" void GetGadgetMenuText();
extern "C" void GetLootRowName();
extern "C" void GetLootRowPrice();
extern "C" void GetPercentCompleteText();
extern "C" void GetShopRowName();
extern "C" void GetShopRowPrice();
extern "C" void GetTitlePromptText();
extern "C" void GetTriangleHintText();
extern "C" void func_0015DA88();
extern "C" void func_001AD928();
extern "C" void func_001ADA20();
extern "C" void func_001ADBB8();
extern "C" void func_001ADC40();
extern "C" void func_001DCA30();
extern "C" void func_001DCAB0();
extern "C" void func_001DDE10();
extern "C" void func_001DDE58();
extern "C" void func_001DDEA0();
extern "C" void func_001DDF00();
extern "C" void func_00210EB0();
extern "C" void func_00210F80();
extern "C" void func_00211148();
extern "C" void func_002111F0();
extern "C" void func_00211348();
extern "C" void func_00211390();
extern "C" void func_002113B8();
extern "C" void func_00211420();

// data-ok: retail's bytes at 0X2A8B80
extern const unsigned int D_002A8B80[2] = {0x6e6b6e55, 0x6e776f};

// data-ok: retail's bytes at 0X2A8B88
extern const char D_002A8B88[8] = "     ";

// data-ok: retail's bytes at 0X2A8B90
extern void *const D_002A8B90[4] = {(void *)0x2cf, (void *)0x210ed8, (void *)D_3E0FB0, 0};

// data-ok: retail's bytes at 0X2A8BA0
extern void *const D_002A8BA0[4] = {(void *)0x2d0, (void *)BindTextCounts, 0, 0};

// data-ok: retail's bytes at 0X2A8BB0
extern void *const D_002A8BB0[4] = {(void *)0x2d1, (void *)func_00210F80, 0, 0};

// data-ok: retail's bytes at 0X2A8BC0
extern void *const D_002A8BC0[4] = {(void *)0x2d2, (void *)BindTextMenuRow, 0, 0};

// data-ok: retail's bytes at 0X2A8BD0
extern void *const D_002A8BD0[4] = {(void *)0x2d3, (void *)BindTextMenuRow, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8BE0
extern void *const D_002A8BE0[4] = {(void *)0x2d4, (void *)BindTextMenuRow, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8BF0
extern void *const D_002A8BF0[4] = {(void *)0x2d5, (void *)BindTextMenuRow, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8C00
extern void *const D_002A8C00[4] = {(void *)0x2d6, (void *)BindTextMenuRow, (void *)4, 0};

// data-ok: retail's bytes at 0X2A8C10
extern void *const D_002A8C10[4] = {(void *)0x2d7, (void *)BindTextMenuRow, (void *)5, 0};

// data-ok: retail's bytes at 0X2A8C20
extern void *const D_002A8C20[4] = {(void *)0x2d8, (void *)BindTextMenuRow, (void *)6, 0};

// data-ok: retail's bytes at 0X2A8C30
extern void *const D_002A8C30[4] = {(void *)0x2d9, (void *)BindTextMenuRow, (void *)7, 0};

// data-ok: retail's bytes at 0X2A8C40
extern void *const D_002A8C40[4] = {(void *)0x2da, (void *)BindTextMenuRow, (void *)8, 0};

// data-ok: retail's bytes at 0X2A8C50
extern void *const D_002A8C50[4] = {(void *)0x2db, (void *)BindTextMenuRow, (void *)9, 0};

// data-ok: retail's bytes at 0X2A8C60
extern void *const D_002A8C60[4] = {(void *)0x2dc, (void *)BindTextBinocReadout, 0, 0};

// data-ok: retail's bytes at 0X2A8C70
extern void *const D_002A8C70[4] = {(void *)0x2dd, (void *)func_00211148, 0, 0};

// data-ok: retail's bytes at 0X2A8C80
extern void *const D_002A8C80[4] = {(void *)0x2de, (void *)func_00211148, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8C90
extern void *const D_002A8C90[4] = {(void *)0x2df, (void *)func_002111F0, 0, 0};

// data-ok: retail's bytes at 0X2A8CA0
extern void *const D_002A8CA0[4] = {(void *)0x2e0, (void *)func_002111F0, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8CB0
extern void *const D_002A8CB0[4] = {(void *)0x2e1, (void *)func_002111F0, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8CC0
extern void *const D_002A8CC0[4] = {(void *)0x2e2, (void *)func_002111F0, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8CD0
extern void *const D_002A8CD0[4] = {(void *)0x2e3, (void *)func_002111F0, (void *)4, 0};

// data-ok: retail's bytes at 0X2A8CE0
extern void *const D_002A8CE0[4] = {(void *)0x2e4, (void *)func_002111F0, (void *)5, 0};

// data-ok: retail's bytes at 0X2A8CF0
extern void *const D_002A8CF0[4] = {(void *)0x2e5, (void *)func_00211348, 0, 0};

// data-ok: retail's bytes at 0X2A8D00
extern void *const D_002A8D00[4] = {(void *)0x2e6, (void *)func_00211348, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8D10
extern void *const D_002A8D10[4] = {(void *)0x2e7, (void *)func_00211348, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8D20
extern void *const D_002A8D20[4] = {(void *)0x2e8, (void *)func_00211348, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8D30
extern void *const D_002A8D30[4] = {(void *)0x2e9, (void *)func_00211348, (void *)4, 0};

// data-ok: retail's bytes at 0X2A8D40
extern void *const D_002A8D40[4] = {(void *)0x2ea, (void *)func_00211348, (void *)5, 0};

// data-ok: retail's bytes at 0X2A8D50
extern void *const D_002A8D50[4] = {(void *)0x2eb, (void *)func_00211348, (void *)6, 0};

// data-ok: retail's bytes at 0X2A8D60
extern void *const D_002A8D60[4] = {(void *)0x2ec, (void *)func_00211348, (void *)7, 0};

// data-ok: retail's bytes at 0X2A8D70
extern void *const D_002A8D70[4] = {(void *)0x2ed, (void *)func_00211348, (void *)8, 0};

// data-ok: retail's bytes at 0X2A8D80
extern void *const D_002A8D80[4] = {(void *)0x2ee, (void *)func_00211348, (void *)9, 0};

// data-ok: retail's bytes at 0X2A8D90
extern void *const D_002A8D90[4] = {(void *)0x2ff, (void *)func_00210EB0, (void *)D_002C3EC0, 0};

// data-ok: retail's bytes at 0X2A8DA0
extern void *const D_002A8DA0[4] = {(void *)0x300, (void *)func_00210EB0, (void *)D_002C3EF0, 0};

// data-ok: retail's bytes at 0X2A8DB0
extern void *const D_002A8DB0[4] = {(void *)0x301, (void *)func_00210EB0, (void *)D_002C3F20, 0};

// data-ok: retail's bytes at 0X2A8DC0
extern void *const D_002A8DC0[4] = {(void *)0x302, (void *)func_00210EB0, (void *)D_002C3F50, 0};

// data-ok: retail's bytes at 0X2A8DD0
extern void *const D_002A8DD0[4] = {(void *)0x303, (void *)func_00210EB0, (void *)D_002C3F80, 0};

// data-ok: retail's bytes at 0X2A8DE0
extern void *const D_002A8DE0[4] = {(void *)0x304, (void *)func_00210EB0, (void *)D_002C3FB0, 0};

// data-ok: retail's bytes at 0X2A8DF0
extern void *const D_002A8DF0[4] = {(void *)0x305, (void *)func_00210EB0, (void *)D_002C3FE0, 0};

// data-ok: retail's bytes at 0X2A8E00
extern void *const D_002A8E00[4] = {(void *)0x306, (void *)func_00210EB0, (void *)D_002C4010, 0};

// data-ok: retail's bytes at 0X2A8E10
extern void *const D_002A8E10[4] = {(void *)0x307, (void *)func_00210EB0, (void *)D_002C4040, 0};

// data-ok: retail's bytes at 0X2A8E20
extern void *const D_002A8E20[4] = {(void *)0x308, (void *)func_00210EB0, (void *)D_002C4070, 0};

// data-ok: retail's bytes at 0X2A8E30
extern void *const D_002A8E30[4] = {(void *)0x2ef, (void *)func_00211390, 0, 0};

// data-ok: retail's bytes at 0X2A8E40
extern void *const D_002A8E40[4] = {(void *)0x2f0, (void *)func_002113B8, 0, 0};

// data-ok: retail's bytes at 0X2A8E50
extern void *const D_002A8E50[4] = {(void *)0x37b, (void *)GetGadgetMenuText, 0, 0};

// data-ok: retail's bytes at 0X2A8E60
extern void *const D_002A8E60[4] = {(void *)0x37a, (void *)GetGadgetMenuText, 0, 0};

// data-ok: retail's bytes at 0X2A8E70
extern void *const D_002A8E70[4] = {(void *)0x43c, (void *)GetShopRowName, 0, 0};

// data-ok: retail's bytes at 0X2A8E80
extern void *const D_002A8E80[4] = {(void *)0x43d, (void *)GetShopRowName, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8E90
extern void *const D_002A8E90[4] = {(void *)0x43e, (void *)GetShopRowName, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8EA0
extern void *const D_002A8EA0[4] = {(void *)0x43f, (void *)GetShopRowName, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8EB0
extern void *const D_002A8EB0[4] = {(void *)0x440, (void *)GetShopRowName, (void *)4, 0};

// data-ok: retail's bytes at 0X2A8EC0
extern void *const D_002A8EC0[4] = {(void *)0x441, (void *)GetShopRowName, (void *)5, 0};

// data-ok: retail's bytes at 0X2A8ED0
extern void *const D_002A8ED0[4] = {(void *)0x442, (void *)GetShopRowPrice, 0, 0};

// data-ok: retail's bytes at 0X2A8EE0
extern void *const D_002A8EE0[4] = {(void *)0x443, (void *)GetShopRowPrice, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8EF0
extern void *const D_002A8EF0[4] = {(void *)0x444, (void *)GetShopRowPrice, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8F00
extern void *const D_002A8F00[4] = {(void *)0x445, (void *)GetShopRowPrice, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8F10
extern void *const D_002A8F10[4] = {(void *)0x446, (void *)GetShopRowPrice, (void *)4, 0};

// data-ok: retail's bytes at 0X2A8F20
extern void *const D_002A8F20[4] = {(void *)0x447, (void *)GetShopRowPrice, (void *)5, 0};

// data-ok: retail's bytes at 0X2A8F30
extern void *const D_002A8F30[4] = {(void *)0x436, (void *)func_001DCA30, 0, 0};

// data-ok: retail's bytes at 0X2A8F40
extern void *const D_002A8F40[4] = {(void *)0x435, (void *)func_001DCAB0, 0, 0};

// data-ok: retail's bytes at 0X2A8F50
extern void *const D_002A8F50[4] = {(void *)0x448, (void *)GetLootRowName, 0, 0};

// data-ok: retail's bytes at 0X2A8F60
extern void *const D_002A8F60[4] = {(void *)0x449, (void *)GetLootRowName, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8F70
extern void *const D_002A8F70[4] = {(void *)0x44a, (void *)GetLootRowName, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8F80
extern void *const D_002A8F80[4] = {(void *)0x44b, (void *)GetLootRowName, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8F90
extern void *const D_002A8F90[4] = {(void *)0x44c, (void *)GetLootRowName, (void *)4, 0};

// data-ok: retail's bytes at 0X2A8FA0
extern void *const D_002A8FA0[4] = {(void *)0x44d, (void *)GetLootRowName, (void *)5, 0};

// data-ok: retail's bytes at 0X2A8FB0
extern void *const D_002A8FB0[4] = {(void *)0x44e, (void *)GetLootRowPrice, 0, 0};

// data-ok: retail's bytes at 0X2A8FC0
extern void *const D_002A8FC0[4] = {(void *)0x44f, (void *)GetLootRowPrice, (void *)1, 0};

// data-ok: retail's bytes at 0X2A8FD0
extern void *const D_002A8FD0[4] = {(void *)0x450, (void *)GetLootRowPrice, (void *)2, 0};

// data-ok: retail's bytes at 0X2A8FE0
extern void *const D_002A8FE0[4] = {(void *)0x451, (void *)GetLootRowPrice, (void *)3, 0};

// data-ok: retail's bytes at 0X2A8FF0
extern void *const D_002A8FF0[4] = {(void *)0x452, (void *)GetLootRowPrice, (void *)4, 0};

// data-ok: retail's bytes at 0X2A9000
extern void *const D_002A9000[4] = {(void *)0x453, (void *)GetLootRowPrice, (void *)5, 0};

// data-ok: retail's bytes at 0X2A9010
extern void *const D_002A9010[4] = {(void *)0x2f1, (void *)BindTextMarquee, 0, 0};

// data-ok: retail's bytes at 0X2A9020
extern void *const D_002A9020[4] = {(void *)0x51b, (void *)GetEpisodeNameText, 0, 0};

// data-ok: retail's bytes at 0X2A9030
extern void *const D_002A9030[4] = {(void *)0x51c, (void *)func_001DDE58, 0, 0};

// data-ok: retail's bytes at 0X2A9040
extern void *const D_002A9040[4] = {(void *)0x51d, (void *)func_001DDE10, 0, 0};

// data-ok: retail's bytes at 0X2A9050
extern void *const D_002A9050[4] = {(void *)0x51e, (void *)func_001DDEA0, 0, 0};

// data-ok: retail's bytes at 0X2A9060
extern void *const D_002A9060[4] = {(void *)0x51f, (void *)func_001DDEA0, (void *)1, 0};

// data-ok: retail's bytes at 0X2A9070
extern void *const D_002A9070[4] = {(void *)0x520, (void *)func_001DDEA0, (void *)2, 0};

// data-ok: retail's bytes at 0X2A9080
extern void *const D_002A9080[4] = {(void *)0x521, (void *)func_001DDEA0, (void *)3, 0};

// data-ok: retail's bytes at 0X2A9090
extern void *const D_002A9090[4] = {(void *)0x522, (void *)func_001DDEA0, (void *)4, 0};

// data-ok: retail's bytes at 0X2A90A0
extern void *const D_002A90A0[4] = {(void *)0x523, (void *)func_001DDEA0, (void *)5, 0};

// data-ok: retail's bytes at 0X2A90B0
extern void *const D_002A90B0[4] = {(void *)0x524, (void *)func_001DDEA0, (void *)6, 0};

// data-ok: retail's bytes at 0X2A90C0
extern void *const D_002A90C0[4] = {(void *)0x525, (void *)func_001DDEA0, (void *)7, 0};

// data-ok: retail's bytes at 0X2A90D0
extern void *const D_002A90D0[4] = {(void *)0x526, (void *)func_001DDEA0, (void *)8, 0};

// data-ok: retail's bytes at 0X2A90E0
extern void *const D_002A90E0[4] = {(void *)0x527, (void *)func_001DDEA0, (void *)9, 0};

// data-ok: retail's bytes at 0X2A90F0
extern void *const D_002A90F0[4] = {(void *)0x528, (void *)func_001DDF00, 0, 0};

// data-ok: retail's bytes at 0X2A9100
extern void *const D_002A9100[4] = {(void *)0x529, (void *)func_001DDF00, (void *)1, 0};

// data-ok: retail's bytes at 0X2A9110
extern void *const D_002A9110[4] = {(void *)0x52a, (void *)func_001DDF00, (void *)2, 0};

// data-ok: retail's bytes at 0X2A9120
extern void *const D_002A9120[4] = {(void *)0x52b, (void *)func_001DDF00, (void *)3, 0};

// data-ok: retail's bytes at 0X2A9130
extern void *const D_002A9130[4] = {(void *)0x2f2, (void *)FormatDialogText, 0, 0};

// data-ok: retail's bytes at 0X2A9140
extern void *const D_002A9140[4] = {(void *)0x2f3, (void *)FormatDialogButtons, 0, 0};

// data-ok: retail's bytes at 0X2A9150
extern void *const D_002A9150[4] = {(void *)0x5cb, (void *)func_001AD928, 0, 0};

// data-ok: retail's bytes at 0X2A9160
extern void *const D_002A9160[4] = {(void *)0x5cc, (void *)FormatCompletion, 0, 0};

// data-ok: retail's bytes at 0X2A9170
extern void *const D_002A9170[4] = {(void *)0x5cd, (void *)func_001ADA20, 0, 0};

// data-ok: retail's bytes at 0X2A9180
extern void *const D_002A9180[4] = {(void *)0x5ce, (void *)func_001ADBB8, 0, 0};

// data-ok: retail's bytes at 0X2A9190
extern void *const D_002A9190[4] = {(void *)0x5cf, (void *)func_001ADC40, 0, 0};

// data-ok: retail's bytes at 0X2A91A0
extern void *const D_002A91A0[4] = {(void *)0x5d0, (void *)func_001ADC40, (void *)1, 0};

// data-ok: retail's bytes at 0X2A91B0
extern void *const D_002A91B0[4] = {(void *)0x5d1, (void *)func_001ADC40, (void *)2, 0};

// data-ok: retail's bytes at 0X2A91C0
extern void *const D_002A91C0[4] = {(void *)0x5d3, (void *)GetTitlePromptText, 0, 0};

// data-ok: retail's bytes at 0X2A91D0
extern void *const D_002A91D0[4] = {(void *)0x5d7, (void *)GetTriangleHintText, 0, 0};

// data-ok: retail's bytes at 0X2A91E0
extern void *const D_002A91E0[4] = {(void *)0x5d5, (void *)GetPercentCompleteText, 0, 0};

// data-ok: retail's bytes at 0X2A91F0
extern void *const D_002A91F0[4] = {(void *)0x52f, (void *)FormatEpselPercent, 0, 0};

// data-ok: retail's bytes at 0X2A9200
extern void *const D_002A9200[4] = {(void *)0x530, (void *)FormatEpselTime, 0, 0};

// data-ok: retail's bytes at 0X2A9210
extern void *const D_002A9210[4] = {(void *)0x2f4, (void *)func_00211420, 0, 0};

// data-ok: retail's bytes at 0X2A9220
extern void *const D_002A9220[4] = {(void *)0x5bf, (void *)func_0015DA88, (void *)1, 0};

// data-ok: retail's bytes at 0X2A9230
extern void *const D_002A9230[4] = {(void *)0x5c0, (void *)func_0015DA88, 0, 0};
