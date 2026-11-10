#include "bentley.h"
extern "C" int func_00135FF0(BENTLEY *pbentley)
{
    switch (pbentley->state) {
    case 0:
    case 1:
    case 5:
    case 7:
        return 1;
    }
    return 0;
}