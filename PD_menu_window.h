#pragma once
#include <imgui/imgui.h>

class PerDiagnosticsMenu {
public:
    // Call this function each frame to show the diagnostics menu  
    static void ShowPerDiagnosticsMenu(bool* p_open);
};