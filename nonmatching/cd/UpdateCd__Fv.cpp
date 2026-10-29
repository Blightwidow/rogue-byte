extern "C" {
extern int g_2bd4c0;
extern int g_2a2e5c;
extern int g_2a2e60;
extern int B_003DD0E4;
extern unsigned char B_002DD680[];
extern char B_003DA4F0[];
extern unsigned RO_002A2E68[];
extern char RO_002A2E50[];
void func_001DD6C8(void *);
void func_001DD728(void *);
int func_001DD780(void *);
int sceCdRead(int, int, void *, void *);
}
int FValidCdMmode__Fv(void);
int FCdCompleted__Fi(int);

void UpdateCd__Fv(void)
{
    int lsn;
    int state = g_2bd4c0;
    switch (state) {
    case 3:
        if (B_003DD0E4) {
            if (!FValidCdMmode__Fv()) {
                func_001DD6C8(B_003DA4F0);
                g_2bd4c0 = 1;
            }
        }
        break;
    case 1:
        if (func_001DD780(B_003DA4F0)) {
            lsn = g_2a2e5c + 0xCA0;
            if (FValidCdMmode__Fv()) {
                if (sceCdRead(lsn, 1, B_002DD680, RO_002A2E50) == 1)
                    g_2bd4c0 = 2;
            }
        }
        break;
    case 2:
        if (FCdCompleted__Fi(0)) {
            int crc = 0xFFFFFFFF;
            unsigned char *p = B_002DD680;
            unsigned *table = RO_002A2E68;
            int n = 0x7FF;
            do {
                unsigned char b = *p;
                p++;
                n--;
                crc = *(unsigned long *)((char *)table + (((crc ^ b) & 0xFF) << 2)) ^ (crc >> 8);
            } while (n != -1);
            int next = 1;
            if (crc == (unsigned)g_2a2e60) {
                func_001DD728(B_003DA4F0);
                next = 3;
            }
            g_2bd4c0 = next;
        }
        break;
    }
}
