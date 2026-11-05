/* SPDX-License-Identifier: GPL-3.0-or-later */
extern "C" long CsgsMatchGrfsgs(long wanted, long have) {
    long matched = wanted & have;
    if (matched != wanted) {
        return 0;
    }
    int count = 0;
    while (matched != 0) {
        matched &= matched - 1;
        count += 1;
    }
    return count;
}
