struct CBinaryInputStream {
    char pad0[0x10];
    int pos;       // 0x10
    int avail;     // 0x14
    char pad1[0x1C];
    int total;     // 0x34
    int buffer;    // 0x38
    char pad2[4];
    int done;      // 0x40
    int request;   // 0x44
    int remaining; // 0x48
    int base;      // 0x4C
    int lsn;       // 0x50
    int count;     // 0x54
    int filled;    // 0x58
    int current;   // 0x5C
    int next;      // 0x60
    void PumpCd();
};
extern "C" {
int sceCdGetError();
int sceCdGetReadPos();
int sceCdSync(int, int);
}
void ReadCdDirect__FUiUiPv(unsigned, unsigned, void *, int, ...);
static inline int ChunkOf(int quotient) {
    return quotient > 0x8000 ? (quotient & -0x8000) : (quotient & -0x800);
}
void CBinaryInputStream::PumpCd() {
    int quotient = total / count;
    pos += avail;
    avail = 0;
    int chunk = ChunkOf(quotient);
    if (filled > 0) {
        int nextCurrent = current + 1;
        int base0 = buffer;
        if (pos == base0 + nextCurrent * chunk) {
            int slot = nextCurrent % count;
            filled--;
            current = slot;
            pos = base0 + slot * chunk;
        }
    }
    do {
        if (request > 0) {
            int readPos = sceCdGetReadPos() + base;
            if (readPos >= request) readPos = request;
            if (done < readPos) {
                done = readPos;
            } else if (sceCdSync(1, request) == 0) {
                if (sceCdGetError() == 0) {
                    int size2 = request;
                    done = size2;
                    lsn += size2 / 0x800;
                    remaining -= size2;
                    request = 0;
                    base = 0;
                } else {
                    int offset = done;
                    int slotOffset = next * chunk;
                    int sector = lsn;
                    base = offset;
                    ReadCdDirect__FUiUiPv(sector + (offset / 0x800), ((request - offset) + 0x7FF & ~0x7FF) >> 11, (char *)buffer + slotOffset + offset, 0);
                }
            }
        }
        if (filled < count && request == 0) {
            int left = remaining;
            if (left > 0) {
                done = 0;
                int length = left >= chunk ? chunk : left;
                int nextSlot = (next + 1) % count;
                request = length;
                filled++;
                next = nextSlot;
                ReadCdDirect__FUiUiPv(lsn, (length + 0x7FF & ~0x7FF) >> 11, (char *)buffer + nextSlot * chunk, 0);
            }
        }
        if (filled == 0) {
            avail = 0;
        } else {
            int limit = chunk;
            if (filled == 1) limit = done;
            int left2 = limit - (pos - (buffer + current * chunk));
            if (left2 > 0xFFF) left2 = 0x1000; avail = left2;
        }
    } while (avail == 0 && remaining > 0);
}
