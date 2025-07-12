//@Mrkaushikhaxor
void savebyKaushik(const std::string& key) {
    std::ofstream file("/data/data/com.pubg.imobile/Kaushik.txt");
    if (file.is_open()) {
        file << key;
        file.close();}}
std::string loadkeyBykaushik() {
    std::ifstream file("/data/data/com.pubg.imobile/Kaushik.txt");
    std::string key;
    if (file.is_open()) {
        std::getline(file, key);
        file.close();}
    return key;}
                     static char s[256] = "";
                     static bool keyLoaded = false;
                     if (!keyLoaded) {
                     std::string savedKey = loadkeyBykaushik();
                     if (!savedKey.empty()) {
                     strncpy(s, savedKey.c_str(), sizeof(s));}
                     keyLoaded = true;}                 
                     if (ImGui::Button("Paste Key", ,ImVec2(60, 45))) {
                     std::string key = getClipboardText();
                     strncpy(s, key.c_str(), sizeof(s));
      savebyKaushik(key);
                     }


*Copy your Key 🔑 only once, no need to copy it again and again..

Cr - @Mrkaushikhaxor

⚠️ People Who Share Without Credit Are Sons Of Bitches 😏