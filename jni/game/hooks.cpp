#include "../main.h"
#include "game.h"
#include "../vendor/imgui/imgui_impl_opengl3.h"
#include <GLES2/gl2.h>

extern CGui* pGui;

typedef void (*CheatFunc_t)();

static void CallCheat(uintptr_t offset, const char* name)
{
    if (!gta_3_base) {
        gta_log("[%s] ERROR: gta_3_base == 0", name);
        return;
    }
    if (offset == 0) {
        gta_log("[%s] ERROR: offset == 0", name);
        return;
    }

    CheatFunc_t fn = (CheatFunc_t)(gta_3_base + offset);
    gta_log("[%s] calling %p (base=0x%lX + off=0x%lX)",
            name, (void*)fn, (unsigned long)gta_3_base, (unsigned long)offset);
    fn();
}

void TriggerWeaponCheat()                { CallCheat(OFFSET_WeaponCheat, "WeaponCheat"); }
void TriggerHealthCheat()                { CallCheat(OFFSET_HealthCheat, "HealthCheat"); }
void TriggerArmorCheat()                 { CallCheat(OFFSET_ArmourCheat, "ArmourCheat"); }
void TriggerMoneyCheat()                 { CallCheat(OFFSET_MoneyCheat, "MoneyCheat"); }
void TriggerTankCheat()                  { CallCheat(OFFSET_TankCheat, "TankCheat"); }
void TriggerClearCheats()                { CallCheat(OFFSET_ClearCheats, "ClearCheats"); }
void TriggerBlowUpCarsCheat()            { CallCheat(OFFSET_BlowUpCarsCheat, "BlowUpCarsCheat"); }
void TriggerChangePlayerCheat()          { CallCheat(OFFSET_ChangePlayerCheat, "ChangePlayerCheat"); }
void TriggerMayhemCheat()                { CallCheat(OFFSET_MayhemCheat, "MayhemCheat"); }
void TriggerEverybodyAttacksCheat()      { CallCheat(OFFSET_EverybodyAttacksPlayerCheat, "EverybodyAttacksPlayerCheat"); }
void TriggerWeaponsForAllCheat()         { CallCheat(OFFSET_WeaponsForAllCheat, "WeaponsForAllCheat"); }
void TriggerFastTimeCheat()              { CallCheat(OFFSET_FastTimeCheat, "FastTimeCheat"); }
void TriggerSlowTimeCheat()              { CallCheat(OFFSET_SlowTimeCheat, "SlowTimeCheat"); }
void TriggerWantedUpCheat()              { CallCheat(OFFSET_WantedLevelUpCheat, "WantedLevelUpCheat"); }
void TriggerWantedDownCheat()            { CallCheat(OFFSET_WantedLevelDownCheat, "WantedLevelDownCheat"); }
void TriggerSunnyWeatherCheat()          { CallCheat(OFFSET_SunnyWeatherCheat, "SunnyWeatherCheat"); }
void TriggerCloudyWeatherCheat()         { CallCheat(OFFSET_CloudyWeatherCheat, "CloudyWeatherCheat"); }
void TriggerRainyWeatherCheat()          { CallCheat(OFFSET_RainyWeatherCheat, "RainyWeatherCheat"); }
void TriggerFoggyWeatherCheat()          { CallCheat(OFFSET_FoggyWeatherCheat, "FoggyWeatherCheat"); }
void TriggerFastWeatherCheat()           { CallCheat(OFFSET_FastWeatherCheat, "FastWeatherCheat"); }
void TriggerOnlyRenderWheelsCheat()      { CallCheat(OFFSET_OnlyRenderWheelsCheat, "OnlyRenderWheelsCheat"); }
void TriggerChittyCheat()                { CallCheat(OFFSET_ChittyChittyBangBangCheat, "ChittyChittyBangBangCheat"); }
void TriggerStrongGripCheat()            { CallCheat(OFFSET_StrongGripCheat, "StrongGripCheat"); }
void TriggerNastyLimbsCheat()            { CallCheat(OFFSET_NastyLimbsCheat, "NastyLimbsCheat"); }

void (*Render2dStuffOrig)(void) = nullptr;

void Render2dStuffHook(void)
{
    if (Render2dStuffOrig) Render2dStuffOrig();

    if (!pGui) return;

    pGui->Init();
    if (!pGui->m_bInited) return;

    GLint viewport[4] = {0};
    glGetIntegerv(GL_VIEWPORT, viewport);
    if (viewport[2] > 0 && viewport[3] > 0) {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float)viewport[2], (float)viewport[3]);
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    pGui->Draw();

    ImGui::Render();

    ImDrawData* draw_data = ImGui::GetDrawData();
    if (draw_data) {
        ImGui_ImplOpenGL3_RenderDrawData(draw_data);
    }
}

void InstallCallHooks()
{
    DobbyHook((void*)(gta_3_base + OFFSET_Render2dStuff), (void*)Render2dStuffHook, (void**)&Render2dStuffOrig);
}