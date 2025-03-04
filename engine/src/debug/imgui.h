#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

typedef struct theme {
    float m_Alpha;
    float m_DisabledAlpha;
    ImVec2 m_WindowPadding;
    float m_WindowRounding;
    float m_WindowBorderSize;
    ImVec2 m_WindowMinSize;
    ImVec2 m_WindowTitleAlign;
    ImGuiDir m_WindowMenuButtonPosition;
    float m_ChildRounding;
    float m_ChildBorderSize;
    float m_PopupRounding;
    float m_PopupBorderSize;
    ImVec2 m_FramePadding;
    float m_FrameRounding;
    float m_FrameBorderSize;
    ImVec2 m_ItemSpacing;
    ImVec2 m_ItemInnerSpacing;
    ImVec2 m_CellPadding;
    float m_IndentSpacing;
    float m_ColumnsMinSpacing;
    float m_ScrollbarSize;
    float m_ScrollbarRounding;
    float m_GrabMinSize;
    float m_GrabRounding;
    float m_TabRounding;
    float m_TabBorderSize;
    float m_TabMinWidthForCloseButton;
    ImGuiDir m_ColorButtonPosition;
    ImVec2 m_ButtonTextAlign;
    ImVec2 m_SelectableTextAlign;

    // Colors
    ImVec4 m_Text;
    ImVec4 m_TextDisabled;
    ImVec4 m_WindowBg;
    ImVec4 m_ChildBg;
    ImVec4 m_PopupBg;
    ImVec4 m_Border;
    ImVec4 m_BorderShadow;
    ImVec4 m_FrameBg;
    ImVec4 m_FrameBgHovered;
    ImVec4 m_FrameBgActive;
    ImVec4 m_TitleBg;
    ImVec4 m_TitleBgActive;
    ImVec4 m_TitleBgCollapsed;
    ImVec4 m_MenuBarBg;
    ImVec4 m_ScrollbarBg;
    ImVec4 m_ScrollbarGrab;
    ImVec4 m_ScrollbarGrabHovered;
    ImVec4 m_ScrollbarGrabActive;
    ImVec4 m_CheckMark;
    ImVec4 m_SliderGrab;
    ImVec4 m_SliderGrabActive;
    ImVec4 m_Button;
    ImVec4 m_ButtonHovered;
    ImVec4 m_ButtonActive;
    ImVec4 m_Header;
    ImVec4 m_HeaderHovered;
    ImVec4 m_HeaderActive;
    ImVec4 m_Separator;
    ImVec4 m_SeparatorHovered;
    ImVec4 m_SeparatorActive;
    ImVec4 m_ResizeGrip;
    ImVec4 m_ResizeGripHovered;
    ImVec4 m_ResizeGripActive;
    ImVec4 m_Tab;
    ImVec4 m_TabHovered;
    ImVec4 m_TabActive;
    ImVec4 m_TabUnfocused;
    ImVec4 m_TabUnfocusedActive;
    ImVec4 m_PlotLines;
    ImVec4 m_PlotLinesHovered;
    ImVec4 m_PlotHistogram;
    ImVec4 m_PlotHistogramHovered;
    ImVec4 m_TableHeaderBg;
    ImVec4 m_TableBorderStrong;
    ImVec4 m_TableBorderLight;
    ImVec4 m_TableRowBg;
    ImVec4 m_TableRowBgAlt;
    ImVec4 m_TextSelectedBg;
    ImVec4 m_DragDropTarget;
    ImVec4 m_NavHighlight;
    ImVec4 m_NavWindowingHighlight;
    ImVec4 m_NavWindowingDimBg;
    ImVec4 m_ModalWindowDimBg;
} theme;

theme load_theme(const char* path);
void set_theme(theme new_theme);