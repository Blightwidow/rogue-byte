struct SMPA20F7E0;
struct Movie20F7E0 { char padF8[0xF8]; struct Hud20F7E0 *hud; };
struct Hud20F7E0 { char pad0[0x14]; float value; };
struct Blot20F7E0 { Movie20F7E0 *movie; float velocity; int fresh; };
struct Hud2Owner20F7E0 { char pad0[0x3BA0]; Blot20F7E0 blots[4]; char pad3BD0[0x476C - 0x3BD0]; float tEmit; int emitStamp; };
extern "C" {
int FDrawBlotMovie(Movie20F7E0 *);
float GSmoothA__FffffP4SMPAPf(float, float, float, float, SMPA20F7E0 *, float *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
extern char D_002C3E88;
extern float D_002C3E80;
extern float g_2dded0[];
static inline float Clamp(float value, float low) { return value > low ? value : low; }
void UpdateSwHudBlots(Hud2Owner20F7E0 *owner)
{
    float level = 0.0f;
    for (int index = 0; index < 4; index++) {
        Blot20F7E0 *blot = &owner->blots[index];
        Movie20F7E0 *movie = blot->movie;
        if (movie == 0 || FDrawBlotMovie(movie) == 0) {
            blot->fresh = 1;
        } else {
            if (blot->fresh != 0) {
                movie->hud->value = level;
                blot->velocity = 0.0f;
                blot->fresh = 0;
            } else {
                movie->hud->value = GSmoothA__FffffP4SMPAPf(movie->hud->value, blot->velocity, level, g_2dded0[1], (SMPA20F7E0 *)&D_002C3E88, &blot->velocity);
            }
            level += D_002C3E80;
            if (index == 3) {
                int stamp = (int)Clamp(owner->tEmit - g_2dded0[0], 0.0f);
                if (stamp != owner->emitStamp) {
                    int kind = 0x31;
                    if (stamp & 1) kind = 0x30;
                    SetEmitterUnpositioned(NewEmitter(kind), 0);
                    owner->emitStamp = stamp;
                }
            }
        }
    }
}
}
