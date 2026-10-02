#pragma once

#include <stdint.h>

#define OFFSET_WeaponCheat                  0x235684
#define OFFSET_HealthCheat                  0x23573C
#define OFFSET_TankCheat                    0x2357A4
#define OFFSET_ClearCheats                  0x235A50
#define OFFSET_BlowUpCarsCheat              0x235A70
#define OFFSET_ChangePlayerCheat            0x235B08
#define OFFSET_MayhemCheat                  0x235C78
#define OFFSET_EverybodyAttacksPlayerCheat  0x235D34
#define OFFSET_WeaponsForAllCheat           0x235E74
#define OFFSET_FastTimeCheat                0x235EB0
#define OFFSET_SlowTimeCheat                0x235EF8
#define OFFSET_MoneyCheat                   0x235F44
#define OFFSET_ArmourCheat                  0x235F98
#define OFFSET_WantedLevelUpCheat           0x235FCC
#define OFFSET_WantedLevelDownCheat         0x23602C
#define OFFSET_SunnyWeatherCheat            0x23605C
#define OFFSET_CloudyWeatherCheat           0x236088
#define OFFSET_RainyWeatherCheat            0x2360B4
#define OFFSET_FoggyWeatherCheat            0x2360E0
#define OFFSET_FastWeatherCheat             0x23610C
#define OFFSET_OnlyRenderWheelsCheat        0x236148
#define OFFSET_ChittyChittyBangBangCheat    0x236184
#define OFFSET_StrongGripCheat              0x2361C0
#define OFFSET_NastyLimbsCheat              0x2361FC
#define OFFSET_Render2dStuff                0x220800

void TriggerWeaponCheat();
void TriggerHealthCheat();
void TriggerArmorCheat();
void TriggerMoneyCheat();
void TriggerTankCheat();
void TriggerClearCheats();
void TriggerBlowUpCarsCheat();
void TriggerChangePlayerCheat();
void TriggerMayhemCheat();
void TriggerEverybodyAttacksCheat();
void TriggerWeaponsForAllCheat();
void TriggerFastTimeCheat();
void TriggerSlowTimeCheat();
void TriggerWantedUpCheat();
void TriggerWantedDownCheat();
void TriggerSunnyWeatherCheat();
void TriggerCloudyWeatherCheat();
void TriggerRainyWeatherCheat();
void TriggerFoggyWeatherCheat();
void TriggerFastWeatherCheat();
void TriggerOnlyRenderWheelsCheat();
void TriggerChittyCheat();
void TriggerStrongGripCheat();
void TriggerNastyLimbsCheat();