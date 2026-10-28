struct Root { void* top; };
struct Lo { char pad0[0x14]; Root* root; char pad1[0x200 - 0x18]; Lo* owner; };
extern "C" int FIsBasicDerivedFrom(void*, int);
extern "C" void* func_00174898(Lo* obj)
{
    if (!obj) return 0;
    if (FIsBasicDerivedFrom(obj->root->top, 0x38)) return obj->root->top;
    if (FIsBasicDerivedFrom(obj, 0x4F)) {
        if (FIsBasicDerivedFrom(obj->owner->root->top, 0x38)) return obj->owner->root->top;
        return 0;
    }
    return 0;
}
