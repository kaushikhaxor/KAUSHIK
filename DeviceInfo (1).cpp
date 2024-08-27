/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Https://t.me/KaushikCracking
 */
// Add Tools.cpp
const char *Tools::GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(OBFUSCATE("android/content/Context"));
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, OBFUSCATE("getContentResolver"), OBFUSCATE("()Landroid/content/ContentResolver;"));
    jclass settingSecureClass = env->FindClass(OBFUSCATE("android/provider/Settings$Secure"));
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, OBFUSCATE("getString"), OBFUSCATE("(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;"));

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(OBFUSCATE("android_id")));
    return env->GetStringUTFChars(str, 0);
}

const char *Tools::GetDeviceModel(JNIEnv *env) {
	jclass buildClass = env->FindClass(OBFUSCATE("android/os/Build"));
	jfieldID modelId = env->GetStaticFieldID(buildClass, OBFUSCATE("MODEL"), OBFUSCATE("Ljava/lang/String;"));
	
	auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
	return env->GetStringUTFChars(str, 0);
}

const char *Tools::GetDeviceBrand(JNIEnv *env) {
	jclass buildClass = env->FindClass(OBFUSCATE("android/os/Build"));
	jfieldID modelId = env->GetStaticFieldID(buildClass, OBFUSCATE("BRAND"), OBFUSCATE("Ljava/lang/String;"));
	
	auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
	return env->GetStringUTFChars(str, 0);
}

const char *Tools::GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(OBFUSCATE("java/util/UUID"));

    auto len = strlen(uuid);

    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, OBFUSCATE("nameUUIDFromBytes"), OBFUSCATE("([B)Ljava/util/UUID;"));
    jmethodID toStringMethod = env->GetMethodID(uuidClass, OBFUSCATE("toString"), OBFUSCATE("()Ljava/lang/String;"));

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}
/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Https://t.me/KaushikCracking
 */

//add In Tools.h
std::string RandomString(const int len);
const char *GetAndroidID(JNIEnv *env, jobject context);
	const char *GetDeviceModel(JNIEnv *env);
	const char *GetDeviceBrand(JNIEnv *env);
	const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid);
	
	
	
	/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Https://t.me/KaushikCracking
 */
	
	//Add In Main.cpp
	std::string deviceBrandModel() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    
        std::string b;// = Tools::GetDeviceBrand(env);
        //b += " - ";
        b += Tools::GetDeviceModel(env);
    
    vm->DetachCurrentThread();

    return b;
}

/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Https://t.me/KaushikCracking
 */

                 std::string b = deviceBrandModel();
                       ImGui::Text("%s", b.c_str());