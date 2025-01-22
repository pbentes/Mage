#include "imgui.h"

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>

#include <toml.hpp>
#include <toml/get.hpp>
#include <toml/parser.hpp>

ImVec4 rgba_string_to_imvec4(const std::string& rgbaString) {
    std::vector<float> values;
    std::stringstream ss(rgbaString);
    std::string item;

    std::getline(ss, item, '(');

    while (std::getline(ss, item, ',')) {
        try {
            if (!item.empty() && item.back() == ')') {
                item.pop_back();
            }

            float value = std::stof(item);
            if (value > 1.0f) {
                value /= 255.0f;
            }
            values.push_back(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << e.what() << '\n';
            return ImVec4(0, 0, 0, -1);
        }
    }

    if (values.size() != 4) {
        std::cerr << "Invalid RGBA string format.\n";
        return ImVec4(0, 0, 0, -1);
    }

    return ImVec4(values[0], values[1], values[2], values[3]);
}

ImVec2 float_vector_to_imvec2(std::vector<float> vector) {
    return ImVec2(vector[0], vector[1]);
}

ImGuiDir string_to_imgui_dir(std::string directionString) {
    if (directionString == "Right")
        return ImGuiDir_Right;

    return ImGuiDir_Left;
}

theme load_theme(const char* path) {
    auto th = toml::parse(path);
    std::map<std::string, std::string> colors = toml::find<std::map<std::string, std::string>>(th, "colors");

    return theme {
        .m_Alpha                     = toml::find<float>(th, "alpha"),
        .m_DisabledAlpha             = toml::find<float>(th, "disabledAlpha"),
        .m_WindowPadding             = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "windowPadding")),
        .m_WindowRounding            = toml::find<float>(th, "windowRounding"),
        .m_WindowBorderSize          = toml::find<float>(th, "windowBorderSize"),
        .m_WindowMinSize             = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "windowMinSize")),
        .m_WindowTitleAlign          = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "windowTitleAlign")),
        .m_WindowMenuButtonPosition  = string_to_imgui_dir(toml::find<std::string>(th, "windowMenuButtonPosition")),
        .m_ChildRounding             = toml::find<float>(th, "childRounding"),
        .m_ChildBorderSize           = toml::find<float>(th, "childBorderSize"),
        .m_PopupRounding             = toml::find<float>(th, "popupRounding"),
        .m_PopupBorderSize           = toml::find<float>(th, "popupBorderSize"),
        .m_FramePadding              = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "framePadding")),
        .m_FrameRounding             = toml::find<float>(th, "frameRounding"),
        .m_FrameBorderSize           = toml::find<float>(th, "frameBorderSize"),
        .m_ItemSpacing               = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "itemSpacing")),
        .m_ItemInnerSpacing          = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "itemInnerSpacing")),
        .m_CellPadding               = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "cellPadding")),
        .m_IndentSpacing             = toml::find<float>(th, "indentSpacing"),
        .m_ColumnsMinSpacing         = toml::find<float>(th, "columnsMinSpacing"),
        .m_ScrollbarSize             = toml::find<float>(th, "scrollbarSize"),
        .m_ScrollbarRounding         = toml::find<float>(th, "scrollbarRounding"),
        .m_GrabMinSize               = toml::find<float>(th, "grabMinSize"),
        .m_GrabRounding              = toml::find<float>(th, "grabRounding"),
        .m_TabRounding               = toml::find<float>(th, "tabRounding"),
        .m_TabBorderSize             = toml::find<float>(th, "tabBorderSize"),
        .m_TabMinWidthForCloseButton = toml::find<float>(th, "tabMinWidthForCloseButton"),
        .m_ColorButtonPosition       = string_to_imgui_dir(toml::find<std::string>(th, "colorButtonPosition")),
        .m_ButtonTextAlign           = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "buttonTextAlign")),
        .m_SelectableTextAlign       = float_vector_to_imvec2(toml::find<std::vector<float>>(th, "selectableTextAlign")),

        .m_Text                  = rgba_string_to_imvec4(colors["Text"]),
        .m_TextDisabled          = rgba_string_to_imvec4(colors["TextDisabled"]),
        .m_WindowBg              = rgba_string_to_imvec4(colors["WindowBg"]),
        .m_ChildBg               = rgba_string_to_imvec4(colors["ChildBg"]),
        .m_PopupBg               = rgba_string_to_imvec4(colors["PopupBg"]),
        .m_Border                = rgba_string_to_imvec4(colors["Border"]),
        .m_BorderShadow          = rgba_string_to_imvec4(colors["BorderShadow"]),
        .m_FrameBg               = rgba_string_to_imvec4(colors["FrameBg"]),
        .m_FrameBgHovered        = rgba_string_to_imvec4(colors["FrameBgHovered"]),
        .m_FrameBgActive         = rgba_string_to_imvec4(colors["FrameBgActive"]),
        .m_TitleBg               = rgba_string_to_imvec4(colors["TitleBg"]),
        .m_TitleBgActive         = rgba_string_to_imvec4(colors["TitleBgActive"]),
        .m_TitleBgCollapsed      = rgba_string_to_imvec4(colors["TitleBgCollapsed"]),
        .m_MenuBarBg             = rgba_string_to_imvec4(colors["MenuBarBg"]),
        .m_ScrollbarBg           = rgba_string_to_imvec4(colors["ScrollbarBg"]),
        .m_ScrollbarGrab         = rgba_string_to_imvec4(colors["ScrollbarGrab"]),
        .m_ScrollbarGrabHovered  = rgba_string_to_imvec4(colors["ScrollbarGrabHovered"]),
        .m_ScrollbarGrabActive   = rgba_string_to_imvec4(colors["ScrollbarGrabActive"]),
        .m_CheckMark             = rgba_string_to_imvec4(colors["CheckMark"]),
        .m_SliderGrab            = rgba_string_to_imvec4(colors["SliderGrab"]),
        .m_SliderGrabActive      = rgba_string_to_imvec4(colors["SliderGrabActive"]),
        .m_Button                = rgba_string_to_imvec4(colors["Button"]),
        .m_ButtonHovered         = rgba_string_to_imvec4(colors["ButtonHovered"]),
        .m_ButtonActive          = rgba_string_to_imvec4(colors["ButtonActive"]),
        .m_Header                = rgba_string_to_imvec4(colors["Header"]),
        .m_HeaderHovered         = rgba_string_to_imvec4(colors["HeaderHovered"]),
        .m_HeaderActive          = rgba_string_to_imvec4(colors["HeaderActive"]),
        .m_Separator             = rgba_string_to_imvec4(colors["Separator"]),
        .m_SeparatorHovered      = rgba_string_to_imvec4(colors["SeparatorHovered"]),
        .m_SeparatorActive       = rgba_string_to_imvec4(colors["SeparatorActive"]),
        .m_ResizeGrip            = rgba_string_to_imvec4(colors["ResizeGrip"]),
        .m_ResizeGripHovered     = rgba_string_to_imvec4(colors["ResizeGripHovered"]),
        .m_ResizeGripActive      = rgba_string_to_imvec4(colors["ResizeGripActive"]),
        .m_Tab                   = rgba_string_to_imvec4(colors["Tab"]),
        .m_TabHovered            = rgba_string_to_imvec4(colors["TabHovered"]),
        .m_TabActive             = rgba_string_to_imvec4(colors["TabActive"]),
        .m_TabUnfocused          = rgba_string_to_imvec4(colors["TabUnfocused"]),
        .m_TabUnfocusedActive    = rgba_string_to_imvec4(colors["TabUnfocusedActive"]),
        .m_PlotLines             = rgba_string_to_imvec4(colors["PlotLines"]),
        .m_PlotLinesHovered      = rgba_string_to_imvec4(colors["PlotLinesHovered"]),
        .m_PlotHistogram         = rgba_string_to_imvec4(colors["PlotHistogram"]),
        .m_PlotHistogramHovered  = rgba_string_to_imvec4(colors["PlotHistogramHovered"]),
        .m_TableHeaderBg         = rgba_string_to_imvec4(colors["TableHeaderBg"]),
        .m_TableBorderStrong     = rgba_string_to_imvec4(colors["TableBorderStrong"]),
        .m_TableBorderLight      = rgba_string_to_imvec4(colors["TableBorderLight"]),
        .m_TableRowBg            = rgba_string_to_imvec4(colors["TableRowBg"]),
        .m_TableRowBgAlt         = rgba_string_to_imvec4(colors["TableRowBgAlt"]),
        .m_TextSelectedBg        = rgba_string_to_imvec4(colors["TextSelectedBg"]),
        .m_DragDropTarget        = rgba_string_to_imvec4(colors["DragDropTarget"]),
        .m_NavHighlight          = rgba_string_to_imvec4(colors["NavHighlight"]),
        .m_NavWindowingHighlight = rgba_string_to_imvec4(colors["NavWindowingHighlight"]),
        .m_NavWindowingDimBg     = rgba_string_to_imvec4(colors["NavWindowingDimBg"]),
        .m_ModalWindowDimBg      = rgba_string_to_imvec4(colors["ModalWindowDimBg"]),
    };
}

void set_theme(theme* new_theme) {
    ImGuiStyle& style = ::ImGui::GetStyle();
    
    style.Alpha                     = new_theme->m_Alpha;
    style.DisabledAlpha             = new_theme->m_DisabledAlpha;
    style.WindowPadding             = new_theme->m_WindowPadding;
    style.WindowRounding            = new_theme->m_WindowRounding;
    style.WindowBorderSize          = new_theme->m_WindowBorderSize;
    style.WindowMinSize             = new_theme->m_WindowMinSize;
    style.WindowTitleAlign          = new_theme->m_WindowTitleAlign;
    style.WindowMenuButtonPosition  = new_theme->m_WindowMenuButtonPosition;
    style.ChildRounding             = new_theme->m_ChildRounding;
    style.ChildBorderSize           = new_theme->m_ChildBorderSize;
    style.PopupRounding             = new_theme->m_PopupRounding;
    style.PopupBorderSize           = new_theme->m_PopupBorderSize;
    style.FramePadding              = new_theme->m_FramePadding;
    style.FrameRounding             = new_theme->m_FrameRounding;
    style.FrameBorderSize           = new_theme->m_FrameBorderSize;
    style.ItemSpacing               = new_theme->m_ItemSpacing;
    style.ItemInnerSpacing          = new_theme->m_ItemInnerSpacing;
    style.CellPadding               = new_theme->m_CellPadding;
    style.IndentSpacing             = new_theme->m_IndentSpacing;
    style.ColumnsMinSpacing         = new_theme->m_ColumnsMinSpacing;
    style.ScrollbarSize             = new_theme->m_ScrollbarSize;
    style.ScrollbarRounding         = new_theme->m_ScrollbarRounding;
    style.GrabMinSize               = new_theme->m_GrabMinSize;
    style.GrabRounding              = new_theme->m_GrabRounding;
    style.TabRounding               = new_theme->m_TabRounding;
    style.TabBorderSize             = new_theme->m_TabBorderSize;
    style.TabMinWidthForCloseButton = new_theme->m_TabMinWidthForCloseButton;
    style.ColorButtonPosition       = new_theme->m_ColorButtonPosition;
    style.ButtonTextAlign           = new_theme->m_ButtonTextAlign;
    style.SelectableTextAlign       = new_theme->m_SelectableTextAlign;
    
    style.Colors[ImGuiCol_Text]                  = new_theme->m_Text;
    style.Colors[ImGuiCol_TextDisabled]          = new_theme->m_TextDisabled;
    style.Colors[ImGuiCol_WindowBg]              = new_theme->m_WindowBg;
    style.Colors[ImGuiCol_ChildBg]               = new_theme->m_ChildBg;
    style.Colors[ImGuiCol_PopupBg]               = new_theme->m_PopupBg;
    style.Colors[ImGuiCol_Border]                = new_theme->m_Border;
    style.Colors[ImGuiCol_BorderShadow]          = new_theme->m_BorderShadow;
    style.Colors[ImGuiCol_FrameBg]               = new_theme->m_FrameBg;
    style.Colors[ImGuiCol_FrameBgHovered]        = new_theme->m_FrameBgHovered;
    style.Colors[ImGuiCol_FrameBgActive]         = new_theme->m_FrameBgActive;
    style.Colors[ImGuiCol_TitleBg]               = new_theme->m_TitleBg;
    style.Colors[ImGuiCol_TitleBgActive]         = new_theme->m_TitleBgActive;
    style.Colors[ImGuiCol_TitleBgCollapsed]      = new_theme->m_TitleBgCollapsed;
    style.Colors[ImGuiCol_MenuBarBg]             = new_theme->m_MenuBarBg;
    style.Colors[ImGuiCol_ScrollbarBg]           = new_theme->m_ScrollbarBg;
    style.Colors[ImGuiCol_ScrollbarGrab]         = new_theme->m_ScrollbarGrab;
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = new_theme->m_ScrollbarGrabHovered;
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = new_theme->m_ScrollbarGrabActive;
    style.Colors[ImGuiCol_CheckMark]             = new_theme->m_CheckMark;
    style.Colors[ImGuiCol_SliderGrab]            = new_theme->m_SliderGrab;
    style.Colors[ImGuiCol_SliderGrabActive]      = new_theme->m_SliderGrabActive;
    style.Colors[ImGuiCol_Button]                = new_theme->m_Button;
    style.Colors[ImGuiCol_ButtonHovered]         = new_theme->m_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]          = new_theme->m_ButtonActive;
    style.Colors[ImGuiCol_Header]                = new_theme->m_Header;
    style.Colors[ImGuiCol_HeaderHovered]         = new_theme->m_HeaderHovered;
    style.Colors[ImGuiCol_HeaderActive]          = new_theme->m_HeaderActive;
    style.Colors[ImGuiCol_Separator]             = new_theme->m_Separator;
    style.Colors[ImGuiCol_SeparatorHovered]      = new_theme->m_SeparatorHovered;
    style.Colors[ImGuiCol_SeparatorActive]       = new_theme->m_SeparatorActive;
    style.Colors[ImGuiCol_ResizeGrip]            = new_theme->m_ResizeGrip;
    style.Colors[ImGuiCol_ResizeGripHovered]     = new_theme->m_ResizeGripHovered;
    style.Colors[ImGuiCol_ResizeGripActive]      = new_theme->m_ResizeGripActive;
    style.Colors[ImGuiCol_Tab]                   = new_theme->m_Tab;
    style.Colors[ImGuiCol_TabHovered]            = new_theme->m_TabHovered;
    style.Colors[ImGuiCol_TabActive]             = new_theme->m_TabActive;
    style.Colors[ImGuiCol_TabUnfocused]          = new_theme->m_TabUnfocused;
    style.Colors[ImGuiCol_TabUnfocusedActive]    = new_theme->m_TabUnfocusedActive;
    style.Colors[ImGuiCol_PlotLines]             = new_theme->m_PlotLines;
    style.Colors[ImGuiCol_PlotLinesHovered]      = new_theme->m_PlotLinesHovered;
    style.Colors[ImGuiCol_PlotHistogram]         = new_theme->m_PlotHistogram;
    style.Colors[ImGuiCol_PlotHistogramHovered]  = new_theme->m_PlotHistogramHovered;
    style.Colors[ImGuiCol_TableHeaderBg]         = new_theme->m_TableHeaderBg;
    style.Colors[ImGuiCol_TableBorderStrong]     = new_theme->m_TableBorderStrong;
    style.Colors[ImGuiCol_TableBorderLight]      = new_theme->m_TableBorderLight;
    style.Colors[ImGuiCol_TableRowBg]            = new_theme->m_TableRowBg;
    style.Colors[ImGuiCol_TableRowBgAlt]         = new_theme->m_TableRowBgAlt;
    style.Colors[ImGuiCol_TextSelectedBg]        = new_theme->m_TextSelectedBg;
    style.Colors[ImGuiCol_DragDropTarget]        = new_theme->m_DragDropTarget;
    style.Colors[ImGuiCol_NavHighlight]          = new_theme->m_NavHighlight;
    style.Colors[ImGuiCol_NavWindowingHighlight] = new_theme->m_NavWindowingHighlight ;
    style.Colors[ImGuiCol_NavWindowingDimBg]     = new_theme->m_NavWindowingDimBg;
    style.Colors[ImGuiCol_ModalWindowDimBg]      = new_theme->m_ModalWindowDimBg;
    style.Colors[ImGuiCol_DockingPreview]        = new_theme->m_TabActive;
    style.Colors[ImGuiCol_DockingEmptyBg]        = new_theme->m_WindowBg;
}