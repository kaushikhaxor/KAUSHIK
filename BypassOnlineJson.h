// Tg - @Mrkaushikhaxor
std::string fetchBypassByKaushik(const std::string& url) {
    CURL* curl;
    CURLcode res;// Tg - @Mrkaushikhaxor
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {// Tg - @Mrkaushikhaxor
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {// Tg - @Mrkaushikhaxor
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

void applyPatches(const std::string& configJson) {
    try {
        json config = json::parse(configJson);

        for (const auto& patch : config["patches"]) {
            std::string type = patch["type"];
            std::string lib = patch["lib"];
            std::string offset = patch["offset"];

            if (type == "PATCH_LIB") {
                std::string data = patch["data"];
                PATCH_LIB(lib.c_str(), offset.c_str(), data.c_str());
                std::cout << "Applied PATCH_LIB on " << lib << " at " << offset << std::endl;
            } else if (type == "HOOK_LIB_NO_ORIG") {
                std::string hook = patch["hook"];
                HOOK_LIB_NO_ORIG(lib.c_str(), offset.c_str(), hook.c_str());
                std::cout << "Applied HOOK_LIB_NO_ORIG on " << lib << " at " << offset << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing or applying patches: " << e.what() << std::endl;
    }
}

void updateBypass() {// Tg - @Mrkaushikhaxor
    const std::string url = "https://yourserver.com/configs/Kaushik_Bypass.json";
    std::string configJson = fetchBypassByKaushik(url);
    if (!configJson.empty()) {
        applyPatches(configJson);
    } else {
        std::cerr << "Failed to fetch bypass config!" << std::endl;
    }
}





    OnlineByKaushik();// Tg - @Mrkaushikhaxor
    
    
    
    //json
    
    
    {
  "patches": [
    {
      "type": "PATCH_LIB",
      "lib": "libanogs.so",
      "offset": "0xB334E",
      "data": "00 00 A0 E3 1E FF 2F E1"
    }
  ]
}// Tg - @Mrkaushikhaxor