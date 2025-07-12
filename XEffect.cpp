if (ggxhit) {
    auto MyHUD = (ASurviveHUD *)g_LocalController->MyHUD;
    if (MyHUD) {
        auto XHitAddr = *(uintptr_t *)((uintptr_t)MyHUD + 0x5a0);

        static float angle = 0.0f; // Keep track of the rotation angle
        float radius = 9999.0f;   // Define the radius of movement
        angle += 0.04f; // Speed of rotation (increase for faster movement)
       if (angle > 360.0f) {
            angle -= 360.0f;
        }
        float xPos = radius * cos(angle);
        float yPos = radius * sin(angle);
        *(float *)(XHitAddr + 0x10) = xPos; // X-axis position
        *(float *)(XHitAddr + 0x50) = yPos; // Y-axis position
        *(float *)(XHitAddr + 0x90) = -xPos; // Mirror for Z or other axis
        *(float *)(XHitAddr + 0xD0) = -yPos; // Mirror for Z or other axis
    }
}

Cr - Kaushik