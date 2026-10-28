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

int OSTRM::CbWrite(void *src, int cb)
{
    int done = 0;
    if (buf != 0) {
        if (size != 0) {
            if (cb == 0) return 0;
            int left = size - pos;
            if (left < cb) cb = left;
        }
    }
    if (cb != 0) {
        if (buf != 0) {
            done = cb;
            CopyAb(buf + pos, src, cb);
            pos = pos + cb;
        } else if (cb > 0) {
            do {
                int left = cb - done;
                int space = 0x400 - count;
                int chunk = (space < left) ? space : left;
                if (chunk != 0) {
                    CopyAb(data + count, (char *)src + done, chunk);
                    done += chunk;
                    count += chunk;
                }
                if (count == 0x400) Flush();
            } while (done < cb);
        }
        total += done;
        return cb;
    }
    return 0;
}
