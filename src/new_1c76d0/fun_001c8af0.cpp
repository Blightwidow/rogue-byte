// SPDX-License-Identifier: GPL-3.0-or-later
struct GAME_1C8AF0 { char pad[0x4764]; int cclue; int cclueMax; };
struct CLUE_1C8AF0 { char pad[0x190]; int n; char pad2[0x1F8 - 0x194]; int stream; };
extern GAME_1C8AF0 B_003DD490;
extern int B_003DD040;
extern "C" void ShowClueBlot(GAME_1C8AF0 *, int);
extern "C" void StartStream(int *, int, int);
extern "C" void func_001C8730(CLUE_1C8AF0 *, int);
extern "C" void func_001C8AF0(CLUE_1C8AF0 *pclue, int n)
{
    if (B_003DD490.cclue >= B_003DD490.cclueMax) {
        pclue->n = n;
        func_001C8730(pclue, 1);
        return;
    }
    ShowClueBlot(&B_003DD490, n);
    if (pclue->stream != -1)
        StartStream(&B_003DD040, pclue->stream, 1);
}
