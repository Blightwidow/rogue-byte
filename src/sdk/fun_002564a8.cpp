// Behaviour: stores the 128-bit value arg1 at *arg0 and returns arg0.
typedef int QW __attribute__((mode(TI)));
extern "C" QW *func_002564A8(QW *arg0, QW arg1) { *arg0 = arg1; return arg0; }
