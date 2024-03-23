#include "menu.h"

void menu::render()
{
    ImGuiIO& io = GetIO();
    ImGuiStyle& style = GetStyle();

    PushStyleColor(ImGuiCol_WindowBg, ImVec4(settings::menu::colors::window_bg[0], settings::menu::colors::window_bg[1], settings::menu::colors::window_bg[2], settings::menu::colors::window_bg[3]));
    PushStyleColor(ImGuiCol_PopupBg, ImVec4(settings::menu::colors::window_bg[0], settings::menu::colors::window_bg[1], settings::menu::colors::window_bg[2], settings::menu::colors::window_bg[3]));
    PushStyleColor(ImGuiCol_ChildBg, ImVec4(settings::menu::colors::child_bg[0], settings::menu::colors::child_bg[1], settings::menu::colors::child_bg[2], settings::menu::colors::child_bg[3]));
    PushStyleColor(ImGuiCol_Text, ImVec4(settings::menu::colors::text[0], settings::menu::colors::text[1], settings::menu::colors::text[2], settings::menu::colors::text[3]));
    PushStyleColor(ImGuiCol_FrameBg, ImVec4(settings::menu::colors::frame_bg[0], settings::menu::colors::frame_bg[1], settings::menu::colors::frame_bg[2], settings::menu::colors::frame_bg[3]));
    PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(settings::menu::colors::frame_hovered_bg[0], settings::menu::colors::frame_hovered_bg[1], settings::menu::colors::frame_hovered_bg[2], settings::menu::colors::frame_hovered_bg[3]));
    PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(settings::menu::colors::frame_active_bg[0], settings::menu::colors::frame_active_bg[1], settings::menu::colors::frame_active_bg[2], settings::menu::colors::frame_active_bg[3]));

    PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(720, 355));

    SetNextWindowPos(ImVec2(io.DisplaySize.x / 2.f, io.DisplaySize.y / 2.f), ImGuiCond_Once, ImVec2(0.5f, 0.5f));
    SetNextWindowSize(ImVec2(720, 355), ImGuiCond_Once);

    if (!Begin("Nixware", NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
        return;

    BeginTabBar("Tabs");

    if (BeginTabItem("Aimbot"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("Globals", child_size);
        {
            Checkbox("Enable", &settings::aimbot::globals::enable); custom::hotkey("Aimbot Hotkey", &settings::aimbot::globals::hotkey);
            Checkbox("Silent", &settings::aimbot::globals::silent);
            Checkbox("Automatic fire", &settings::aimbot::globals::automatic_fire);
            SliderFloat("Fov", &settings::aimbot::globals::fov, 0.f, 180.f, "%.1f", ImGuiSliderFlags_NoInput);
            Combo("Hitbox", &settings::aimbot::globals::hitbox, "Head\0" "Chest\0" "Stomach\0" "Hitscan\0");
            Combo("Priority", &settings::aimbot::globals::priority, "Fov\0" "Distance\0" "Health\0");
        }
        EndChild();

        SameLine();

        BeginChild("Accuracy", child_size);
        {
            Checkbox("Predict spread", &settings::aimbot::accuracy::predict_spread);
            Checkbox("Disable recoil", &settings::aimbot::accuracy::disable_recoil);
            SliderFloat("Backtrack", &settings::aimbot::accuracy::backtrack, 0.f, 1.f, "%.3f ms", ImGuiSliderFlags_NoInput);
            SliderFloat("Smooth", &settings::aimbot::accuracy::smooth, 0.f, 20.f, "%.1f", ImGuiSliderFlags_NoInput);
        }
        EndChild();

        SameLine();

        BeginChild("Visuals", child_size);
        {
            Checkbox("Fov", &settings::aimbot::visuals::fov); ColorEdit4("Fov", settings::aimbot::visuals::colors::fov, color_edit4_flags);
            Checkbox("Snaplines", &settings::aimbot::visuals::snaplines); ColorEdit4("Snaplines", settings::aimbot::visuals::colors::snaplines, color_edit4_flags);
            Checkbox("Backtrack", &settings::aimbot::visuals::backtrack);
        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("AntiAim"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("AntiAim", child_size);
        {

        }
        EndChild();

        SameLine();

        BeginChild("FakeLag's", child_size);
        {

        }
        EndChild();

        SameLine();

        BeginChild("Visuals", child_size);
        {

        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("Visuals"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("Players", child_size);
        {
            Checkbox("Enable", &settings::visuals::players::enable);
            Checkbox("Dormant", &settings::visuals::players::dormant);
            Checkbox("Box", &settings::visuals::players::box); ColorEdit4("Box Color", settings::visuals::players::colors::box, color_edit4_flags);
        }
        EndChild();


        SameLine();

        BeginChild("Entity", child_size);
        {
            Checkbox("Enable", &settings::visuals::entity::enable);
        }
        EndChild();

        SameLine();

        BeginChild("Misc", child_size);
        {

        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("Misc"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x)) / 2, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("Globals", child_size);
        {

        }
        EndChild();

        SameLine();

        BeginChild("Movement", child_size);
        {

        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("Lua"))
    {

        EndTabItem();
    }

    if (BeginTabItem("Settings"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("Info", child_size);
        {
            LabelText("Last update:", __DATE__);
        }
        EndChild();

        SameLine();

        BeginChild("Menu", child_size);
        {
            LabelText("WindowBg");       ColorEdit4("WindowBg", settings::menu::colors::window_bg, color_edit4_flags);
            LabelText("ChildBg");        ColorEdit4("ChildBg", settings::menu::colors::child_bg, color_edit4_flags);
            LabelText("Text");           ColorEdit4("Text", settings::menu::colors::text, color_edit4_flags);
            LabelText("FrameBg");        ColorEdit4("FrameBg", settings::menu::colors::frame_bg, color_edit4_flags);
            LabelText("FrameHoveredBg"); ColorEdit4("FrameHoveredBg", settings::menu::colors::frame_hovered_bg, color_edit4_flags);
            LabelText("FrameActiveBg");  ColorEdit4("FrameActiveBg", settings::menu::colors::frame_active_bg, color_edit4_flags);
            Checkbox("Custom loading screen", &settings::menu::custom_loading_screen);
        }
        EndChild();

        SameLine();

        BeginChild("Configs", child_size);
        {
            float column_width = GetColumnWidth() - 10.f;

            Button("Unload cheat", ImVec2(column_width, 35.f));
        }
        EndChild();

        EndTabItem();
    }

    EndTabBar();
    End();

    PopStyleColor(7);
    PopStyleVar();
}

void menu::custom::hotkey(const char* label, hotkey_t* hotkey)
{
    ImGuiWindow* window = GetCurrentWindow();
    if (window->SkipItems)
        return;

    SameLine();

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);

    const float width = GetColumnWidth();
    const ImVec2 pos = window->DC.CursorPos;

    char context_name[64] = { };
    sprintf(context_name, "HotKeyContext%s", label);

    char text[64] = { };
    const char* hotkeyText = (hotkey->key != 0 && g.ActiveId != id) ? key_names[hotkey->key] : (g.ActiveId == id) ? "WAIT KEY" : "NONE";
    ImFormatString(text, sizeof(text), "[  %s  ]", hotkeyText);

    const ImVec2 text_size = CalcTextSize(text, NULL, true);

    const ImRect total_bb(ImVec2(pos.x + width - (text_size.x + 10.f), pos.y - style.FramePadding.y), ImVec2(pos.x + width, pos.y + text_size.y));

    ItemSize(total_bb);
    if (!ItemAdd(total_bb, id))
        return;

    const bool hovered = ItemHoverable(total_bb, id);
    if (hovered)
        SetHoveredID(id);

    if (hovered && (g.IO.MouseClicked[0] || g.IO.MouseDoubleClicked[0]))
    {
        if (g.ActiveId != id)
        {
            memset(g.IO.MouseDown, 0, sizeof(g.IO.MouseDown));
            memset(g.IO.KeysDown, 0, sizeof(g.IO.KeysDown));
            hotkey->key = 0;
        }

        SetActiveID(id, window);
    }

    bool changed = false;
    if (int key = hotkey->key; g.ActiveId == id)
    {
        for (int n = 0; n < IM_ARRAYSIZE(g.IO.MouseDown); n++)
        {
            if (IsMouseDown(n))
            {
                switch (n)
                {
                case 0:
                    key = 1;
                    break;
                case 1:
                    key = 2;
                    break;
                case 2:
                    key = 4;
                    break;
                case 3:
                    key = 5;
                    break;
                case 4:
                    key = 6;
                    break;
                }

                changed = true;
                ClearActiveID();
            }
        }

        if (!changed)
        {
            for (int n = 8; n <= 165; n++)
            {
                if (IsKeyDown((ImGuiKey)n))
                {
                    key = n;
                    changed = true;
                    ClearActiveID();
                }
            }
        }

        if (IsKeyPressed(ImGuiKey_Escape))
        {
            hotkey->key = 0;
            ClearActiveID();
        }
        else
            hotkey->key = key;
    }

    RenderText(total_bb.Min, text);

    PushStyleColor(ImGuiCol_PopupBg, ImVec4(0, 0, 0, 0));
    PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(80, 65));
    PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 5));

    if (BeginPopupContextItem(context_name))
    {
        SetWindowPos(ImVec2(total_bb.Min.x, total_bb.Max.y));

        if (Selectable("Always on", hotkey->type == hotkey_t::always_on))
            hotkey->type = hotkey_t::always_on;

        if (Selectable("Hold", hotkey->type == hotkey_t::hold))
            hotkey->type = hotkey_t::hold;

        if (Selectable("Toggle", hotkey->type == hotkey_t::toggle))
            hotkey->type = hotkey_t::toggle;

        if (Selectable("Force disable", hotkey->type == hotkey_t::force_disable))
            hotkey->type = hotkey_t::force_disable;

        End();
    }

    PopStyleColor();
    PopStyleVar(2);
}