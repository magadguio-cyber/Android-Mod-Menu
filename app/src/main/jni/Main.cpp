#include <jni.h>
#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

// ===== ЗМІННІ =====
bool godmode       = false;
bool inf_run       = false;
bool speedhack     = false;
bool repair_car    = false;
bool inf_ammo      = false;
bool no_recoil     = false;
bool inf_money     = false;
bool auto_farm     = false;
bool esp_players   = false;
bool fast_anim     = false;
float menuColor[4] = { 0.1f, 0.6f, 1.0f, 1.0f };
float speedValue   = 1.5f;

// ===== МЕНЮ =====
void DrawBlackRussiaMenu(bool* p_open) {
    if (!p_open || !*p_open) return;

    ImGui::SetNextWindowSize(ImVec2(380, 420), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(10, 30), ImGuiCond_FirstUseEver);
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive,
        ImVec4(menuColor[0], menuColor[1], menuColor[2], menuColor[3]));

    ImGui::Begin("Black Russia Mod Menu v1.0", p_open);

    if (ImGui::BeginTabBar("MainTabs")) {

        // ===== ИГРОК =====
        if (ImGui::BeginTabItem("Игрок")) {
            ImGui::Text("--- Игрок ---");
            ImGui::Checkbox("Бессмертие",       &godmode);
            ImGui::Checkbox("Бесконечный бег",  &inf_run);
            ImGui::Checkbox("Быстрая анимация", &fast_anim);
            ImGui::Separator();
            ImGui::Text("Скорость");
            ImGui::SliderFloat("##speed", &speedValue, 0.5f, 5.0f);
            ImGui::Checkbox("Спидхак",          &speedhack);
            ImGui::EndTabItem();
        }

        // ===== МАШИНА =====
        if (ImGui::BeginTabItem("Машина")) {
            ImGui::Text("--- Машина ---");
            ImGui::Checkbox("Починка машины",   &repair_car);
            ImGui::Checkbox("Нет урона машины", &godmode);
            ImGui::EndTabItem();
        }

        // ===== ОРУЖИЕ =====
        if (ImGui::BeginTabItem("Оружие")) {
            ImGui::Text("--- Оружие ---");
            ImGui::Checkbox("Бесконечные патроны", &inf_ammo);
            ImGui::Checkbox("Без отдачи",          &no_recoil);
            ImGui::EndTabItem();
        }

        // ===== СЕРВЕР =====
        if (ImGui::BeginTabItem("Сервер")) {
            ImGui::Text("--- Black Russia ---");
            ImGui::Checkbox("Бесконечные деньги", &inf_money);
            ImGui::Checkbox("Авто-фарм",          &auto_farm);
            ImGui::Checkbox("ESP Игроки",         &esp_players);
            ImGui::EndTabItem();
        }

        // ===== НАСТРОЙКИ =====
        if (ImGui::BeginTabItem("Настройки")) {
            ImGui::Text("Цвет меню");
            ImGui::ColorEdit4("##color", menuColor);
            ImGui::Separator();
            if (ImGui::Button("Закрыть меню", ImVec2(150, 35))) {
                if (p_open) *p_open = false;
            }
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::PopStyleColor();
    ImGui::End();
}

// ===== JNI ІНІЦІАЛІЗАЦІЯ =====
extern "C" JNIEXPORT jstring JNICALL
Java_com_blackrussia_MainMenu_stringFromJNI(JNIEnv* env, jobject /* thiz */) {
    std::string hello = "BlackRussia Menu Loaded";
    return env->NewStringUTF(hello.c_str());
}
