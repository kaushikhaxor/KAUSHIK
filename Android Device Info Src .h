std::string androidVersion = getDeviceProperty("ro.build.version.release");
    std::string DeviceModel = getDeviceProperty("ro.product.model");
    std::string deviceInfo = "ANDROID > " + androidVersion + DeviceModel;

draw->AddText(NULL,((float)density / 12.0f), ImVec2((float)glWidth / 2.0f - 60, 650.0f),IM_COL32(0, 255, 0, 255), deviceInfo.c_str());
}


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), 128, pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string getDeviceProperty(const std::string& property) {
    std::string command = "getprop " + property;
    return exec(command.c_str());
}
