#include "../main.h"
#include "../game/game.h"
#include "gui.h"

CGui::CGui()
{
    m_bInited = false;
    m_bIsOpen = false;
}

CGui::~CGui()
{
    if (m_bInited) {
        ImGui_ImplOpenGL3_Shutdown();
        if (ImGui::GetCurrentContext()) {
            ImGui::DestroyContext();
        }
    }
}

void CGui::Init()
{
    if (m_bInited) return;

    IMGUI_CHECKVERSION();
    if (ImGui::GetCurrentContext() == nullptr) {
        ImGui::CreateContext();
    }

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.Fonts->AddFontDefault();
    io.Fonts->Build();

    ImGui::StyleColorsDark();

    if (ImGui_ImplOpenGL3_Init("#version 300 es")) {
        m_bInited = true;
        gta_log("CGui::Init: ImGui + GLES3 OK");
    }
}

void CGui::Draw()
{
    if (!m_bInited) {
        Init();
        if (!m_bInited) return;
    }

    ImGuiIO& io = ImGui::GetIO();
    float screenW = io.DisplaySize.x;
    float screenH = io.DisplaySize.y;

    if (screenW <= 0 || screenH <= 0) {
        screenW = 1920.0f;
        screenH = 1080.0f;
    }

    ImGui::SetNextWindowPos(ImVec2(screenW * 0.43f, screenH * 0.02f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(140.0f, 45.0f));
    ImGuiWindowFlags btnFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                                ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
                                ImGuiWindowFlags_NoSavedSettings;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
    if (ImGui::Begin("CheatButtonWin", nullptr, btnFlags)) {
        if (ImGui::Button(m_bIsOpen ? "CLOSE" : "CHEATS", ImVec2(-1, -1))) {
            Toggle();
        }
    }
    ImGui::End();
    ImGui::PopStyleVar();

    if (!m_bIsOpen) return;

    ImGui::SetNextWindowPos(ImVec2(screenW * 0.5f, screenH * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(620.0f, 520.0f), ImGuiCond_Always);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10.0f);
    if (ImGui::Begin("GTA III Cheat Menu", &m_bIsOpen,
                     ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.4f, 1.0f), "Native CCheats");
        ImGui::Separator();
        ImGui::Spacing();

        if (ImGui::BeginTabBar("CheatMenuTabs")) {

            if (ImGui::BeginTabItem("Player")) {
                ImGui::Spacing();
                if (ImGui::Button("Full Health", ImVec2(280, 50)))       TriggerHealthCheat();
                ImGui::SameLine();
                if (ImGui::Button("Full Armor", ImVec2(280, 50)))        TriggerArmorCheat();

                ImGui::Spacing();
                if (ImGui::Button("Give All Weapons", ImVec2(280, 50)))  TriggerWeaponCheat();
                ImGui::SameLine();
                if (ImGui::Button("Weapons For All", ImVec2(280, 50)))   TriggerWeaponsForAllCheat();

                ImGui::Spacing();
                if (ImGui::Button("Change Player Model", ImVec2(280, 50))) TriggerChangePlayerCheat();
                ImGui::SameLine();
                if (ImGui::Button("Nasty Limbs", ImVec2(280, 50)))       TriggerNastyLimbsCheat();

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Text("Wanted Level:");
                if (ImGui::Button("Wanted +1", ImVec2(280, 40)))         TriggerWantedUpCheat();
                ImGui::SameLine();
                if (ImGui::Button("Wanted -1", ImVec2(280, 40)))         TriggerWantedDownCheat();

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("World")) {
                ImGui::Spacing();
                if (ImGui::Button("Blow Up All Cars", ImVec2(280, 50)))  TriggerBlowUpCarsCheat();
                ImGui::SameLine();
                if (ImGui::Button("Mayhem", ImVec2(280, 50)))            TriggerMayhemCheat();

                ImGui::Spacing();
                if (ImGui::Button("Everybody Attacks You", ImVec2(280, 50))) TriggerEverybodyAttacksCheat();
                ImGui::SameLine();
                if (ImGui::Button("Clear Cheats", ImVec2(280, 50)))      TriggerClearCheats();

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Text("Spawn:");
                if (ImGui::Button("Spawn Tank", ImVec2(280, 50)))        TriggerTankCheat();

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Time")) {
                ImGui::Spacing();
                if (ImGui::Button("Fast Time", ImVec2(280, 50)))         TriggerFastTimeCheat();
                ImGui::SameLine();
                if (ImGui::Button("Slow Time", ImVec2(280, 50)))         TriggerSlowTimeCheat();

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Text("Weather:");
                if (ImGui::Button("Sunny", ImVec2(135, 45)))             TriggerSunnyWeatherCheat();
                ImGui::SameLine();
                if (ImGui::Button("Cloudy", ImVec2(135, 45)))            TriggerCloudyWeatherCheat();

                ImGui::Spacing();
                if (ImGui::Button("Rainy", ImVec2(135, 45)))             TriggerRainyWeatherCheat();
                ImGui::SameLine();
                if (ImGui::Button("Foggy", ImVec2(135, 45)))             TriggerFoggyWeatherCheat();

                ImGui::Spacing();
                if (ImGui::Button("Fast Weather Cycle", ImVec2(280, 45))) TriggerFastWeatherCheat();

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Vehicle")) {
                ImGui::Spacing();
                if (ImGui::Button("Only Render Wheels", ImVec2(280, 50))) TriggerOnlyRenderWheelsCheat();
                ImGui::SameLine();
                if (ImGui::Button("Chitty Chitty Bang Bang", ImVec2(280, 50))) TriggerChittyCheat();

                ImGui::Spacing();
                if (ImGui::Button("Strong Grip", ImVec2(280, 50)))        TriggerStrongGripCheat();

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Money")) {
                ImGui::Spacing();
                if (ImGui::Button("Give $250,000", ImVec2(280, 50)))      TriggerMoneyCheat();

                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::TextDisabled("base: 0x%lX", (unsigned long)gta_3_base);
    }
    ImGui::End();
    ImGui::PopStyleVar();
}