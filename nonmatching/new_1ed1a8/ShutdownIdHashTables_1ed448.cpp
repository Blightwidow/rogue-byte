/* SPDX-License-Identifier: GPL-3.0-or-later */
extern int B_003DD00C;
extern int B_003DD010;
extern int B_003DD014;
extern int B_003DD018;
extern "C" void ShutdownIdHashTables_1ed448() { B_003DD010 = 0; B_003DD018 = 0; B_003DD014 = 0; B_003DD00C = 0; }
