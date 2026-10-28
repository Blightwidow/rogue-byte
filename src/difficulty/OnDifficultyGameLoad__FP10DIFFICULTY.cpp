#include "sly2.h"
struct DIFFICULTY;
void OnDifficultyGameLoad(DIFFICULTY *difficulty)
{
    memset(difficulty, 0, 0x18);
}
