extern "C" int FButtonPressedWithin(float);
int FVjoyButtonPressed() {
    return FButtonPressedWithin(0.0f) != 0;
}
