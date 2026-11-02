struct T1 { int v[7][6]; };
struct T2 { int v[25]; };
struct REQ { int a; char pad4[0xC]; short b; char pad12[0xE]; short c; char pad22[6]; int d; char pad2c[4]; };
struct SELF { char pad0[0xE8]; int e8; char padec[0x4C]; int f138; };
struct SELF2 { char pad0[0x64]; int f64; };
extern "C" {
int NRandInRange(int, int);
int func_001FD028(void *, int);
short func_001FD070(void *, int);
void func_002322F0(REQ *);
void *memset(void *, int, unsigned);
extern T1 RO_002A82A8;
extern T2 RO_002A8350;
void func_001FEED0(SELF *self)
{
    if (((SELF2 *)self)->f64 == 0) {
        T1 table1 = RO_002A82A8;
        T2 table2 = RO_002A8350;
        REQ request;
        int column = NRandInRange(0, 5);
        int row = table2.v[0xC + self->f138];
        self->f138 = self->f138 + table1.v[row][column];
        memset(&request, 0, 0x30);
        request.d = 0x13;
        request.a = self->e8;
        request.b = func_001FD070(self, func_001FD028(self, 0x28));
        request.c = self->f138 * 0x7F;
        func_002322F0(&request);
    }
}
}
