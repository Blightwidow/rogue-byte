struct PathUser { char pad[0xC]; void *path; float s; };
extern "C" void GetPathPosFromS(void *, void *, int, float);
void func_0019E9D8(PathUser *self, void *out)
{
    GetPathPosFromS(self->path, out, 0, self->s);
}
