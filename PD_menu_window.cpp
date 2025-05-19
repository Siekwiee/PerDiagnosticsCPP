#pragma once  
#include <ImGui/imgui.h>  
#include <PD_menu_window.h>

void PerDiagnosticsMenu::ShowPerDiagnosticsMenu(bool* p_open)  
{  
    // Exceptionally add an extra assert here for people confused about initial Dear ImGui setup  
    // Most functions would normally just assert/crash if the context is missing.  
    IM_ASSERT(ImGui::GetCurrentContext() != NULL && "Missing Dear ImGui context. Refer to examples app!");  

    // Verify ABI compatibility between caller code and compiled version of Dear ImGui. This helps detects some build issues.  
    IMGUI_CHECKVERSION();  
    // You can make this window toggleable by passing a pointer to a bool as the second parameter.  
    ImGui::Begin("Per Diagnostics Menu");  

    // Example checkboxes  
    static bool s_connected_monitors = false;  
    static bool enableFeatureB = false;  
    static bool enableFeatureC = false;  

    ImGui::Checkbox("Enable Feature Connected Monitors", &s_connected_monitors);
    ImGui::Checkbox("Enable Feature B", &enableFeatureB);  
    ImGui::Checkbox("Enable Feature G", &enableFeatureC);  

    // You can use the checkbox states for logic in your app  
    // For example:  
    // if (s_connected_monitors) { /* Do something */ }  

    ImGui::End();  
}