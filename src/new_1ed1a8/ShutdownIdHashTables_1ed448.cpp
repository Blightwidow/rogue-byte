/* SPDX-License-Identifier: GPL-3.0-or-later */
extern int *B_003DD010;
extern int *B_003DD018;
extern int B_003DD00C;
extern int B_003DD014;
/*
 * Retail zeroes the two table pointers (B_003DD010, B_003DD018) and the two
 * counts (B_003DD00C, B_003DD014), with lui registers v1,a0,a1,v0 and the
 * 0C store last. The tables are int pointers and the counts ints, as in
 * InitIdHashTables_1ed3a8 (which allocates them); written with those types
 * and the counts cleared in one chained assignment, mirroring the init
 * function, gcc allocates and schedules exactly as retail.
 */
extern "C" void ShutdownIdHashTables_1ed448()
{
    B_003DD010 = 0;
    B_003DD018 = 0;
    B_003DD00C = B_003DD014 = 0;
}
