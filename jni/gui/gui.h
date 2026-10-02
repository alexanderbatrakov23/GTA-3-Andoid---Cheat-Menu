#pragma once

#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_opengl3.h"

class CGui
{
public:
    CGui();
    ~CGui();

    void Init();
    void Draw();
    void Toggle() { m_bIsOpen = !m_bIsOpen; }

    bool m_bInited = false;
    bool m_bIsOpen = false;
};

extern CGui* pGui;