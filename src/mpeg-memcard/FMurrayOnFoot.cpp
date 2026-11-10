#include "murray.h"
extern "C" int FMurrayOnFoot(MURRAY *self)
{
 int s = self->state;
 switch (s) { case 0: case 1: case 9: case 10: return 1; } return 0;
}
