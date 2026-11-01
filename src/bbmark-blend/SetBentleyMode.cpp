#include "sly2.h"
struct BENTLEY135C20;
extern "C" {
void SetBentleyState(BENTLEY135C20 *, int);
void SetBentleyMode(BENTLEY135C20 *bentley, unsigned int mode)
{
    switch (mode) {
    case 0: SetBentleyState(bentley, 0); break;
    case 1: SetBentleyState(bentley, 2); break;
    case 2: SetBentleyState(bentley, 3); break;
    case 3: SetBentleyState(bentley, 4); break;
    case 4: SetBentleyState(bentley, 9); break;
    case 5: SetBentleyState(bentley, 10); break;
    case 6: SetBentleyState(bentley, 11); break;
    case 7: SetBentleyState(bentley, 12); break;
    case 8: SetBentleyState(bentley, 13); break;
    }
}
}
