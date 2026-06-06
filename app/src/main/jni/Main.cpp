#include <imgui.h>

// Глобальные или статические переменные для хранения состояния UI-элементов
bool mode1 = false;
bool mode2 = false;

bool param1 = false;
bool param2 = false;

bool option1 = false;
bool option2 = false;

float menuColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Начальный цвет (белый)

// Функция отрисовки главного окна меню
void DrawMyMenuWindow(bool* p_open) {
    // Создаем главное окно интерфейса
    ImGui::Begin("Главное Окно", p_open);

    // ==========================================
    // НАЧАЛО: Добавление панели вкладок (TabBar)
    // ==========================================
    if (ImGui::BeginTabBar("MyMainTabBar")) {

        // --- Игрок ---
        if (ImGui::BeginTabItem("Игрок")) {
            ImGui::Checkbox("Бесмертия", &mode1);
            ImGui::Checkbox("Спидхак", &mode2);
            ImGui::EndTabItem();
        }

        // --- Машина ---
        if (ImGui::BeginTabItem("Машина")) {
            ImGui::Checkbox("Бесмертия 1", &param1);
            ImGui::Checkbox("Спидхак 2", &param2);
            ImGui::EndTabItem();
        }

        // --- ВКЛАДКА 3 ---
        if (ImGui::BeginTabItem("Оружия")) {
            ImGui::Checkbox("Хитбоксы", &option1);
            ImGui::Checkbox("Антистан", &option2);
            ImGui::EndTabItem();
        }

        // --- Настройки ---
        if (ImGui::BeginTabItem("Настройки")) {
            // Кнопка закрытия окна (меняет состояние флага видимости)
            if (ImGui::Button("Закрыть")) {
                if (p_open != nullptr) {
                    *p_open = false; 
                }
            }
            
            ImGui::Spacing();
            
            // Ползунок выбора цвета (ColorEdit4 поддерживает RGBA каналы)
            ImGui::ColorEdit4("Цвет меню", menuColor);
            
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }
    // ==========================================
    // КОНЕЦ: Добавление панели вкладок
    // ==========================================

    ImGui::End();
}
