 static bool isLogin = false;
					 static std::string err;
					 static char s[64] = "";
             		 static bool loading = false;
					 static float progress = 0.0f;
                     static bool isComplete = false;
                     static float loading_angle = 0.0f;
                     static std::chrono::steady_clock::time_point login_start_time;	 
                     if (!isLogin) {
					 if (!loading) {
					 ImGui::PushItemWidth(-1);
	                 ImGui::InputText("##key", s, sizeof(s));
                     if (ImGui::OptButton1("Paste Key", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                     std::string key = getClipboardText();
                     strncpy(s, key.c_str(), sizeof(s));
                     }
                     if (ImGui::OptButton1("Login", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                     loading = true;
					 progress = 0.0f;
					 isComplete = false;
					 err.clear(); 
                     login_start_time = std::chrono::steady_clock::now();
                     }ImGui::PushFont(Social);
					 ImGui::Spacing();
					 ImGui::Spacing();
					 if(ImGui::OptButton3("V", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {//ImVec2(60, 45))){
					 OpenURL(OBFUSCATE("https://t.me/Mrkaushikhaxor"));}
					 ImGui::PopFont();
					 ImGui::Text("          Get Support / Help");
					 if (!err.empty() && err != "OK") {
                     ImGui::Text("Error: %s", err.c_str());
					 }
                     }else {
                     ImDrawList* draw_list = ImGui::GetWindowDrawList();
                     ImVec2 center = ImGui::GetCursorScreenPos();
                     center.x += 141.0f; //150.0f Offset x
                     center.y += 147.0f; //100.0f Offset y
                     float radius = 30.0f;       // Radius of the circle
                     int num_dots = 12;          // Number of dots
                     float dot_radius = 6.0f;    // Radius of each dot
                     float animation_speed = 2.0f; // Speed of rotation			 
					
					 ImGui::SetCursorPos( ImVec2(12, 83) );//15 / 90
                	 ImGui::MenuChild(OBFUSCATE(" Bypass Section "), ImVec2(277, 157) );{//600 , 310
					 RenderLoadingAnimation(draw_list, center, radius, num_dots, dot_radius, animation_speed);               
					 			 
					 if (!isComplete) {
                     ImGui::Text("Dowloading Bypass : %.0f%%", progress * 100.0f);
                     } else {
                     if (!err.empty() && err != "OK") {
                     ImGui::Text("Failed to fetch offset Err !");
					 }else{
                     ImGui::Text("Bypass apply successfully !");
                     }}
                     ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Black color
                     ImGui::ProgressBar(progress, ImVec2(-1.0f, 20.0f), "");
					 ImGui::PopStyleColor();		 
                     if (!isComplete) {
                     std::this_thread::sleep_for(std::chrono::milliseconds(80)); // Control speed
                     progress += 0.01f; // Increment progress
                     if (progress >= 1.0f) {
                     progress = 1.0f;
                     isComplete = true;
					 err = Login(s);
					 }}			 			
	                 ImGui::EndChild();}
					 				 				 
                     loading_angle += 0.05f;
                     if (loading_angle > IM_PI * 2.0f) {
                     loading_angle -= IM_PI * 2.0f;
                     }
                     auto current_time = std::chrono::steady_clock::now();
                     auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - login_start_time).count();
                     /*if (elapsed > 9000) {
					 err = Login(s);
                     if (err == "OK") {
                     isLogin = true;
					 }}
					 if (elapsed > 11000) {
					 loading = false;
					 }}}*/			
		             if (elapsed > 11000) { // Simulated timeout        
					 if (err.empty()) {
                     err = Login(s); // Retry login if no error
                     }
                     if (err != "OK") {
                     isComplete = false; // Allow retry for failed keys
                     } else {
                     isLogin = true; // Successful login
                     }
			         loading = false;}}}				 
                     if (isLogin) {
	                 if (bValid){
					 NEWMENU = true;
					 NEWMENUU = false;
}}}}
//}
ImGui::End();
ImGui::Render();



//new
	 static bool isLogin = false;
					 static std::string err;
					 static char s[64] = "";
					 static bool loading = false;
					 static bool showConnecting = false; // New state flag for "Connecting to server..."
                     static std::chrono::steady_clock::time_point connecting_start_time; // Timer for connecting message
					 static float progress = 0.0f;
                     static bool isComplete = false;
                     static float loading_angle = 0.0f;
                     static std::chrono::steady_clock::time_point login_start_time;	 
                     if (!isLogin) {
					 if (!loading) {
					 ImGui::PushItemWidth(-1);
	                 ImGui::InputText("##key", s, sizeof(s));
                     if (ImGui::OptButton1("Paste Key", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                     std::string key = getClipboardText();
                     strncpy(s, key.c_str(), sizeof(s));
                     }
                     if (ImGui::OptButton1("Login", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                     loading = true;
					 showConnecting = true; // Start showing "Connecting to server..."
					 connecting_start_time = std::chrono::steady_clock::now(); // Initialize timer
					 progress = 0.0f;
					 isComplete = false;
					 err.clear(); 
                     login_start_time = std::chrono::steady_clock::now();
                     }ImGui::PushFont(Social);
					 ImGui::Spacing();
					 if(ImGui::OptButton3("V", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {//ImVec2(60, 45))){
					 OpenURL(OBFUSCATE("https://t.me/Mrkaushikhaxor"));}
					 ImGui::PopFont();				 
                     static std::chrono::steady_clock::time_point error_start_time; // To track error display time
                     static bool showError = false;
                     if (!err.empty() && err != "OK") {
                     if (!showError) {
                     error_start_time = std::chrono::steady_clock::now();
                     showError = true;}
                     auto current_time = std::chrono::steady_clock::now();
                     auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - error_start_time).count();
                     if (elapsed < 3) {
                     ImGui::Text("          Error : %s", err.c_str());
                     } else {
                     err.clear();
                     showError = false;
                     }} else {
                     ImGui::Text("          Get Support / Help");                 
                     }}else {
					 if (showConnecting) {
					 ImGui::Spacing();
					 static std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
                     static int dot_count = 0;
                     auto ccurrent_time = std::chrono::steady_clock::now();
                     auto eelapsed = std::chrono::duration_cast<std::chrono::milliseconds>(ccurrent_time - start_time).count();
                     if (eelapsed > 500) {
                     dot_count = (dot_count + 1) % 4; // Cycle between 0, 1, 2, and 3 dots
                     start_time = ccurrent_time;}				 
                     std::string loading_text = " *Connecting to server";
                     for (int i = 0; i < dot_count; i++) {
                     loading_text += ".";}
                     ImGui::Text("%s", loading_text.c_str());
                     auto current_time = std::chrono::steady_clock::now();
                     auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - connecting_start_time).count();
                     if(elapsed > 2000) { // After 2 seconds, stop showing "Connecting to server..." 
                     showConnecting = false;
                     }} else {
                     ImDrawList* draw_list = ImGui::GetWindowDrawList();
                     ImVec2 center = ImGui::GetCursorScreenPos();
                     center.x += 141.0f; //150.0f Offset x
                     center.y += 147.0f; //100.0f Offset y
                     float radius = 30.0f;       // Radius of the circle
                     int num_dots = 12;          // Number of dots
                     float dot_radius = 6.0f;    // Radius of each dot
                     float animation_speed = 2.0f; // Speed of rotation			 
		 
					 ImGui::SetCursorPos( ImVec2(12, 83) );//15 / 90
                	 ImGui::MenuChild(OBFUSCATE(" Bypass Section "), ImVec2(277, 157) );{//600 , 310
					 RenderLoadingAnimation(draw_list, center, radius, num_dots, dot_radius, animation_speed);               
				     if (!isComplete) {
                     ImGui::Text("Dowloading Bypass : %.0f%%", progress * 100.0f);
                     } else {
                     if (!err.empty() && err != "OK") {
                     ImGui::Text("Failed to fetch offset Err !");
					 }else{
                     ImGui::Text("Bypass apply successfully !");
                     }}
                     ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Black color
                     ImGui::ProgressBar(progress, ImVec2(-1.0f, 20.0f), "");
					 ImGui::PopStyleColor();		 
                     if (!isComplete) {
                     std::this_thread::sleep_for(std::chrono::milliseconds(70)); // Control speed
                     progress += 0.0142857f; // Increment progress
                     if (progress >= 1.0f) {
                     progress = 1.0f;
                     isComplete = true;
					 err = Login(s);
					 }}			 
					 loading_angle += 0.05f;
                     if (loading_angle > IM_PI * 2.0f) {
                     loading_angle -= IM_PI * 2.0f;
                     }
	                 ImGui::EndChild();}                 
                     auto current_time = std::chrono::steady_clock::now();
                     auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - login_start_time).count();
		             if (elapsed > 11000) { // Simulated timeout        
					 if (err.empty()) {
                     err = Login(s); // Retry login if no error
                     }
                     if (err != "OK") {
                     isComplete = false; // Allow retry for failed keys
                     } else {
                     isLogin = true; // Successful login
                     }
			         loading = false;}}}}				 
                     if (isLogin) {
	                 if (bValid){


