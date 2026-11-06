struct Object { char pad0[0x68]; float radians; };
void func_0020AF08(struct Object *object, float degrees) {
    object->radians = degrees * 0.017453294f;
}
