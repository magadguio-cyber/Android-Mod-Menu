#include <jni.h>
#include <string>

// Підключаємо тільки чистий ImGui
#include "imgui.h"
#include "imgui_internal.h"

// Глобальні змінні для меню
bool godmode = false;
bool inf_run = false;
bool speedhack = false;
bool repair_car = false;
bool inf_ammo = false;
bool no_recoil = false;
float menuColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

// Головна функція малювання твого меню
void DrawMyMenuWindow(bool* p_open) {
    if (!p_open || !*p_open) return;

    ImGui::Begin("Главное Окно", p_open);

    if (ImGui::BeginTabBar("MyMainTabBar")) {
        
        if (ImGui::BeginTabItem("Игрок")) {
            ImGui::Checkbox("Бессмертие", &godmode);
            ImGui::Checkbox("Спидхак бег", &inf_run);
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Машина")) {
            ImGui::Checkbox("Спидхак авто", &speedhack);
            ImGui::Checkbox("Починка машины", &repair_car);
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Оружие")) {
            ImGui::Checkbox("Хитбоксы", &inf_ammo);
            ImGui::Checkbox("Антиотдача", &no_recoil);
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Настройки")) {
            if (ImGui::Button("Закрыть")) {
                if (p_open != nullptr) {
                    *p_open = false;
                }
            }
            ImGui::Spacing();
            ImGui::ColorEdit4("Цвет меню", menuColor);
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();
}

// Обов'язкова системна функція ініціалізації для Android
extern "C" JNIEXPORT jstring JNICALL
Java_com_gta_sa_MainActivity_stringFromJNI(JNIEnv* env, jobject /* thiz */) {
    std::string hello = "Menu Initialized";
    return env->NewStringUTF(hello.c_str());
}
