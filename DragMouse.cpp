if(KaushikSettings::First_Ui){
                     ImGui::SetNextWindowSize(ImVec2(FloatingWindowWidth, 470));
					 if (ImGui::Begin(MOD_NAME.c_str(),&KaushikSettings::First_Ui,ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize)){
					 static int menuPageIndex = 0;  
    static float dragStartX = 0.0f;  
    static bool isDragging = false;  

    ImGui::MenuChild(OBFUSCATE("--- GG MENU --- "), ImVec2(600, 310)); {  
        #include "Kaushik/BgLineAnimation.h"  

        // Drag/swipe detection  
        ImVec2 mousePos = ImGui::GetIO().MousePos;  
        bool mouseDown = ImGui::IsMouseDown(0);  
        bool mouseReleased = ImGui::IsMouseReleased(0);  

        if (ImGui::IsWindowHovered()) {  
            if (mouseDown && !isDragging) {  
                isDragging = true;  
                dragStartX = mousePos.x;  
            }  

            if (isDragging && mouseReleased) {  
                float dragDeltaX = mousePos.x - dragStartX;  

                if (fabs(dragDeltaX) > 80.0f) {  
                    if (dragDeltaX < 0 && menuPageIndex < 1) {  
                        menuPageIndex++; // Swipe left  
                    }  
                    else if (dragDeltaX > 0 && menuPageIndex > 0) {  
                        menuPageIndex--; // Swipe right  
                    }  
                }  

                isDragging = false;  
            }  
        }  

        // -------------------------  
        // PAGE 1 CONTENT  
        // -------------------------  
        if (menuPageIndex == 0) {  
          if (ImGui::BeginTable("page1", 3)) {
					 ImGui::TableNextColumn();
					 ImGui::Spacing();
					 
				     ImGui::Spacing();
					 ImGui::PushFont(Social);
					 ImGui::SetCursorPos(ImVec2( 310 - 15 - 50 - 30 - 20,  260));
					 if(ImGui::OptButton2("V", ImVec2(50, 35), false)){
				     std::string fullURL = "https://t.me/" + UserName;
                     OpenURL(fullURL.c_str());}
				     ImGui::SetCursorPos(ImVec2( 310 - 15 - 20,  260));               
                     if(ImGui::OptButton2("W", ImVec2(50, 35), false)){
					 OpenURL(OBFUSCATE("https://youtube.com/shorts/ByVonzqiF20?si=9FqHTZUvmS0OOBef"));}         
				     ImGui::SetCursorPos(ImVec2( 310 + 15 + 50 - 20, 260));               
                     if(ImGui::OptButton2("F", ImVec2(50, 35), false)){
					 OpenURL(OBFUSCATE("https://discord.com/invite/ygS5ry2k"));} 
				     ImGui::PopFont();
					 
				     }
				     
				     else if (menuPageIndex == 1) {  
				     
				     
				     }
				     ImGui::EndChild();}
				     
				      ImGui::Spacing();
					 if(KaushikSettings::CheatEnabled1){
					 if(ImGui::OptButton1(OBFUSCATE("[ Tap to activate cheat ]"),ImVec2(600, 45))) {				 
					 KaushikSettings::ActiveAllesp = true; 
					 KaushikSettings::CheatEnabled2 = true;}}
					 if(KaushikSettings::CheatEnabled2){
					 KaushikSettings::CheatEnabled1 = false;		 
					 if(ImGui::OptButton1(OBFUSCATE(" Tap To Remove DataBases "),ImVec2(600, 45))) {
					 }}
					 for (auto &i: items_data) {
                     int itemCount = 0;
                     for (auto &item: i[("Items")]) {
                     item[("itemName")].get<std::string>().c_str();
                     Items[item[("itemId")].get<int>()] = true;-
                     itemCount++;
                     if (itemCount % 4 != 0 && &item != &i[("Items")].back()) {
				     }}}
				     
                     ImGui::End();
					 }
					 }
					 
					 
					 
					