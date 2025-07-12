if(Rainbow){
auto xRGB = (ASurviveHUD *)(g_LocalPlayer->Controller->CastToPlayerController()->MyHUD);

static float cnt = 0.0f;
static int colorIndex = 0;
static FLinearColor colorPattern[] = {
    FLinearColor(1.0f, 0.75f, 0.8f, 1.0f),  // Pink
    FLinearColor(0.0f, 0.0f, 1.0f, 1.0f),  // Blue
    FLinearColor(0.0f, 0.5f, 0.0f, 1.0f),  // Green
    FLinearColor(1.0f, 1.0f, 0.0f, 1.0f),  // Yellow
    FLinearColor(1.0f, 0.0f, 0.0f, 1.0f),  // Red
    FLinearColor(1.0f, 0.65f, 0.0f, 1.0f), // Orange
    FLinearColor(0.53f, 0.81f, 0.92f, 1.0f), // Sky Blue
    FLinearColor(0.0f, 0.5f, 0.0f, 1.0f),  // Green
    FLinearColor(1.0f, 1.0f, 0.0f, 1.0f),  // Yellow
    FLinearColor(1.0f, 0.0f, 0.0f, 1.0f)   // Red
};
if (cnt >= FLT_MAX) {
    cnt = 0.0f;
    colorIndex = 0;
} else {
    cnt += 0.10f;
   if ((int)(cnt * 10) % 10 == 0) {
        colorIndex = (colorIndex + 1) % (sizeof(colorPattern) / sizeof(colorPattern[0]));
    }
}
xRGB->HitPerform.HitBodyDrawColor = colorPattern[colorIndex];
xRGB->HitPerform.HitHeadDrawColor = colorPattern[colorIndex];
}

No Lag No Crash 🙂
Cr - @Mrkaushikhaxor