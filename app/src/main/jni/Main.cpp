#include <list>
#include <vector>
#include <cstring>
#include <pthread.h>
#include <thread>
#include <string>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>

// Підключаємо файли з папки Includes напряму
#include "Logger.h"
#include "obfuscate.h"
#include "Utils.h"
#include "Macros.h"

// Підключаємо файли меню та ImGui
#include "Menu/Menu.hpp"
#include "Menu/Jni.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

// Глобальные переменные для хранения состояния кнопок
bool godmode = false;
bool inf_run = false;
bool speedhack = false;
bool repair_car = false;
bool inf_ammo = false;
bool no_recoil = false;
float menuColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

// Главная функция отрисовки твоего меню
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
