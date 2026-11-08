// SPDX-License-Identifier: GPL-3.0-or-later
void CopyAb(void *, void *, unsigned int);
struct OSTRM {
    char *buf;
    int size;
    int pos;
    int fd;
    int total;
    int count;
    char data[0x400];
    void Flush();
    int CbWrite(void *, int);
};

static inline int MinInt(int first, int second) { return (first < second) ? first : second; }

// Retail tests buf, size and cb in a row and sends cb == 0 into the one inline `return 0` block that follows the
// second cb test (bnel over `b epilogue; v0 = 0`), so the first test is part of the && chain, not a return of its own
// (two `return 0`s get hoisted apart and the block disappears). The clamp is `movn cb, left, left < cb`: written as a
// plain `if` after the && chain, jump.c takes cb's earlier value from $a2 and emits `daddu; movz`; the inline min
// helper gives the clamp its own block and retail's movn.
int OSTRM::CbWrite(void *src, int cb)
{
    int done = 0;
    if (buf != 0 && size != 0 && cb != 0) {
        cb = MinInt(size - pos, cb);
    }
    if (cb == 0) return 0;
    if (buf != 0) {
        done = cb;
        CopyAb(buf + pos, src, cb);
        pos = pos + cb;
    } else {
        while (done < cb) {
            int left = cb - done;
            int space = 0x400 - count;
            int chunk = (space < left) ? space : left;
            if (chunk != 0) {
                CopyAb(data + count, (char *)src + done, chunk);
                done += chunk;
                count += chunk;
            }
            if (count == 0x400) Flush();
        }
    }
    total += done;
    return cb;
}
