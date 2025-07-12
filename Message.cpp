static bool showConnecting = false; // New state flag for "Connecting to server..."
                     static std::chrono::steady_clock::time_point connecting_start_time; // Timer for connecting message
     
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