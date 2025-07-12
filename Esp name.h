std::string credit1  = OBFUSCATE("                                ©-Telegram Dm -> @Mrkaushikhaxor");
       auto textSize = ImGui::CalcTextSize2(credit1.c_str(), 0, ((float)density / 10.5f));
       ImVec2 textPos = {((float)glWidth / 2) - (textSize.x / 2), 25};
       draw->AddText(Injector, ((float) density / 10.5f), textPos, IM_COL32(255, 255, 255, 255), credit1.c_str());
    static float lastClickTime = 0.0f;
       float currentTime = ImGui::GetTime();
       ImVec2 mousePos = ImGui::GetMousePos();
       if (mousePos.x >= textPos.x && mousePos.x <= textPos.x + textSize.x &&
       mousePos.y >= textPos.y && mousePos.y <= textPos.y + textSize.y) {
       if (ImGui::IsMouseClicked(0)) {
       if (!NEWMENU) {
       if (currentTime - lastClickTime < 0.3f) {
       NEWMENU = true;
       }
       lastClickTime = currentTime;
       } else {
       NEWMENU = false;
       }}}