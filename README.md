# GTA III Android — Native Cheat Menu

Модификация для Android-версии **Grand Theft Auto III** (Rockstar Games),
добавляющая внутриигровое чит-меню на **Dear ImGui** с прямым вызовом
нативных функций игры.
---

## Возможности

- **24 чита** из оригинального `CCheat` класса, вызываются напрямую через оффсеты
- **ImGui-меню** с вкладками: Player / World / Time / Vehicle / Money
- **Плавающая кнопка CHEATS** в верхней части экрана
- **Тач-управление** через JNI
- **Хук рендера** через `Render2dStuff`
- Работает на **arm64-v8a**, Android 5.0+ (API 21)

### Список читов

| Чит | Описание |
|-----|----------|
| Full Health | Восстанавливает здоровье игрока |
| Full Armor | Выдаёт броню |
| Give All Weapons | Выдаёт всё оружие |
| Weapons For All | Выдаёт оружие всем NPC |
| Change Player Model | Меняет модель игрока |
| Nasty Limbs | Включает «расчленёнку» |
| Wanted +1 / -1 | Изменяет уровень розыска |
| Blow Up All Cars | Взрывает все машины |
| Mayhem | Включает режим хаоса |
| Everybody Attacks You | NPC атакуют игрока |
| Clear Cheats | Сбрасывает все активные читы |
| Spawn Tank | Спавнит танк рядом с игроком |
| Fast / Slow Time | Ускоряет / замедляет время |
| Sunny / Cloudy / Rainy / Foggy | Устанавливает погоду |
| Fast Weather Cycle | Быстрая смена погоды |
| Only Render Wheels | Рендерит только колёса машин |
| Chitty Chitty Bang Bang | Машины летают |
| Strong Grip | Улучшенное сцепление |
| Give $250,000 | Выдаёт деньги |


**Ключевые компоненты:**

- **Dobby** — для inline-хука нативной функции рендера
- **Dear ImGui** — UI поверх игры через OpenGL ES 3
- **dl_iterate_phdr** — корректное получение базового адреса `.so`
- **JNI** — проброс тач-событий из Java в native

---


---

## 🔧 Сборка

### Требования

- **Android NDK r21e** (или новее)
- **arm64-v8a** устройство или эмулятор

### Команды

```bash
# Windows
cd C:\path\to\cheatmenu
C:\android-ndk-r21e\ndk-build.cmd clean
C:\android-ndk-r21e\ndk-build.cmd

