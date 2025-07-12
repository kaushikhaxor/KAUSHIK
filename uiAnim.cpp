#define kaushik(x, y) ((x) < (y) ? (x) : (y))
#define black(a) I/*Code by @mrkaushikhaxor*/mColor(0.f, 0.f, 0.f, a)                 
/*Code by @mrkaushikhaxor*/                                               
// Mrkaushikhaxor function that creates black circle and line effects
void Mrkaushikhaxor(ImD/*Code by @mrkaushikhaxor*/rawList* d, ImVec2 a, ImVec2 b, ImVec2 sz, float t) {
    static float fl;
    if ((haxor() % 100) == 0) fl = t;  // Higher frequency for effect triggering

    if ((t - fl) > 0) {
        auto ft = 0.25f;  // Animation duration for fade-out effect
        d->AddRect/*Code by @mrkaushikhaxor*/Filled(a, b, /*Code by @mrkaushikhaxor*/black((ft - (t - fl)) / ft));  // Draw the fade-out black rectangle
    }
    for (int i = 0; i < 1000; ++i) {  // Increased quantity of effects
        unsigned h = ImGui::GetID(d + i + int(t / 4));
        auto f = fmodf(t + fmodf(h / 777.f, 99), 99);
        auto tx = h % (i/*Code by @mrkaushikhaxor*/nt)sz.x;  // Calculate x position
        auto ty = h % (int)sz.y;  // Calculate y position

        if (f < 1) {
            // Increase line thickness for bold lines
            auto py = ty - 1500 * (1 - f);  // Adjusted height for falling effect
            d->AddLine(
                {a.x + tx, a.y + py}, 
                {a./*Code by @mrkaushikhaxor*/x + tx, a.y + kaushik(py + 20, ty)}, 
                black(0.7f), 
                2.0f  // Line thickness
            );  // Bold line with transparency
        }
        else if (f < 1.5f) {
            // Increase circle radius significantly
            float radius = (f - 1) * 10 + h % 10;  // Larger radius for circles
            d->AddCir/*Code by @mrkaushikhaxor*/cle(
                {a.x + tx, a.y + ty}, 
                radius, 
                black(1.0f - (f - 1) * 0.5f), 
                8  // Number of segments for smooth circles
            );  // Draw larger black circles
        }
    }
}
// Add in ui
ImDrawList* draw_list = ImGui::GetWindowDrawList();
ImVec2 pos = ImGui::Ge/*Code by @mrkaushikhaxor*/tCursorScreenPos();
ImV/*Code by @mrkaushikhaxor*/ec2 size = ImGui::GetWindowSize();  // Get the actual window size

float time = ImGui:/*Code by @mrkaushikhaxor*/:GetTime();  // Get current time for animation
Mrkaushikhaxor(draw_list, pos, ImVec2(pos.x + siz/*Code by @mrkaushikhaxor*/e.x, pos.y + size.y), size, time);