#include "main.h"

CGui* pGui = nullptr;

void InstallCallHooks();

extern "C" JNIEXPORT void JNICALL
Java_com_rockstar_gta3_GTA3_sendTouchEvent(JNIEnv* env, jclass clazz, jint action, jfloat x, jfloat y) {
    if (ImGui::GetCurrentContext() == nullptr) return;
    ImGuiIO& io = ImGui::GetIO();
    io.MousePos = ImVec2(x, y);

    if (action == 0 || action == 2) {
        io.MouseDown[0] = true;
    } else if (action == 1 || action == 3) {
        io.MouseDown[0] = false;
    }
}

void* InitThread(void* arg)
{
    gta_log("InitThread started, waiting for libR1.so initialization...");
    sleep(2);

    pGui = new CGui();
    InstallCallHooks();

    return nullptr;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    gta_log("libcheatmenu.so started...");

    gta_3_base = find_library("libR1.so");
    if (!gta_3_base)
    {
        gta_log("libR1.so not found!");
        return JNI_VERSION_1_6;
    }
    gta_log("libR1.so base: 0x%lX", (unsigned long)gta_3_base);

    pthread_t thread;
    pthread_create(&thread, nullptr, InitThread, nullptr);

    return JNI_VERSION_1_6;
}
