#include "menu.h"

void menu::render()
{
    ImGuiIO& io = GetIO();
    ImGuiStyle& style = GetStyle();

    PushStyleColor(ImGuiCol_WindowBg, ImVec4(settings::menu::colors::window_bg[0], settings::menu::colors::window_bg[1], settings::menu::colors::window_bg[2], settings::menu::colors::window_bg[3]));
    PushStyleColor(ImGuiCol_PopupBg, ImVec4(settings::menu::colors::window_bg[0], settings::menu::colors::window_bg[1], settings::menu::colors::window_bg[2], settings::menu::colors::window_bg[3]));
    PushStyleColor(ImGuiCol_ChildBg, ImVec4(settings::menu::colors::child_bg[0], settings::menu::colors::child_bg[1], settings::menu::colors::child_bg[2], settings::menu::colors::child_bg[3]));
    PushStyleColor(ImGuiCol_Text, ImVec4(settings::menu::colors::text[0], settings::menu::colors::text[1], settings::menu::colors::text[2], settings::menu::colors::text[3]));
    PushStyleColor(ImGuiCol_TextHovered, ImVec4(settings::menu::colors::text_hovered[0], settings::menu::colors::text_hovered[1], settings::menu::colors::text_hovered[2], settings::menu::colors::text_hovered[3]));
    PushStyleColor(ImGuiCol_TextActive, ImVec4(settings::menu::colors::text_active[0], settings::menu::colors::text_active[1], settings::menu::colors::text_active[2], settings::menu::colors::text_active[3]));
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
            Checkbox("Penetrate walls", &settings::aimbot::globals::penetrate_walls);
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
            Checkbox("Disable visual recoil", &settings::aimbot::accuracy::disable_visual_recoil);
            SliderFloat("Backtrack", &settings::aimbot::accuracy::backtrack, 0.f, 1.f, "%.3f ms", ImGuiSliderFlags_NoInput);
            SliderFloat("Smooth", &settings::aimbot::accuracy::smooth, 0.f, 20.f, "%.1f", ImGuiSliderFlags_NoInput);
        }
        EndChild();

        SameLine();

        BeginChild("Visuals", child_size);
        {
            Checkbox("Fov", &settings::aimbot::visuals::fov); ColorEdit4("Fov", settings::aimbot::visuals::colors::fov, color_edit4_flags);
            Checkbox("Snaplines", &settings::aimbot::visuals::snaplines); ColorEdit4("Snaplines", settings::aimbot::visuals::colors::snaplines, color_edit4_flags);
            Checkbox("Backtrack", &settings::aimbot::visuals::backtrack::enable); ColorEdit4("Backtrack", settings::aimbot::visuals::colors::backtrack, color_edit4_flags);
            Combo("Material", &settings::aimbot::visuals::backtrack::material_type, "Normal\0" "Flat\0" "Wireframe\0");
        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("AntiAim"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("Globals", child_size);
        {
            Checkbox("Enable", &settings::antiaim::globals::enable); custom::hotkey("AntiAim Hotkey", &settings::antiaim::globals::hotkey);
            Checkbox("Fake duck", &settings::antiaim::globals::fake_duck);
            Checkbox("At target", &settings::antiaim::globals::at_target);
            Checkbox("Invert yaw", &settings::antiaim::globals::invert_yaw);
            Combo("Yaw", &settings::antiaim::globals::yaw, "LBY\0");
            Combo("Pitch", &settings::antiaim::globals::pitch, "Down\0" "Up\0");
        }
        EndChild();

        SameLine();

        BeginChild("FakeLag's", child_size);
        {
            Checkbox("Enable", &settings::antiaim::fakelags::enable);
            SliderInt("Count", &settings::antiaim::fakelags::count, 1, 24, "%d", ImGuiSliderFlags_NoInput); /*sv_maxusrcmdprocessticks = 24*/
            Combo("Method", &settings::antiaim::fakelags::method, "On Ground\0" "In Air\0" "On Move\0" "On Stand\0" "Always\0");
        }
        EndChild();

        SameLine();

        BeginChild("Visuals", child_size);
        {
            Checkbox("Fake model", &settings::antiaim::visuals::fake_model::enable); ColorEdit4("Fake model", settings::antiaim::visuals::colors::fake_model, color_edit4_flags);
            Combo("Material", &settings::antiaim::visuals::fake_model::material_type, "Normal\0" "Flat\0" "Wireframe\0");
        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("Visuals"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        BeginChild("ESP", child_size);
        {
            static int type = 0;
            Combo("##ESP", &type, "Player\0" "Entity\0");

            switch (type)
            {
            case 0:
            {
                Checkbox("Enable", &settings::visuals::players::enable);
                Checkbox("Dormant", &settings::visuals::players::dormant);
                Checkbox("Box", &settings::visuals::players::box); ColorEdit4("Box", settings::visuals::players::colors::box, color_edit4_flags);
                Checkbox("Name", &settings::visuals::players::name); ColorEdit4("Name", settings::visuals::players::colors::name, color_edit4_flags);
                Checkbox("Rp team", &settings::visuals::players::rp_team); ColorEdit4("Rp team", settings::visuals::players::colors::rp_team, color_edit4_flags);
                Checkbox("User group", &settings::visuals::players::user_group); ColorEdit4("User group", settings::visuals::players::colors::user_group, color_edit4_flags);
                Checkbox("Weapon name", &settings::visuals::players::weapon_name); ColorEdit4("Weapon name", settings::visuals::players::colors::weapon_name, color_edit4_flags);
                Checkbox("Distance", &settings::visuals::players::distance); ColorEdit4("Distance", settings::visuals::players::colors::distance, color_edit4_flags);
                SliderInt("Render distance", &settings::visuals::players::render_distance, 100, 20000, "%d m", ImGuiSliderFlags_NoInput);
            }
            break;
            case 1:
            {
                Checkbox("Enable", &settings::visuals::entity::enable);
                Checkbox("Dormant", &settings::visuals::entity::dormant);
                Checkbox("Box", &settings::visuals::entity::box); ColorEdit4("Box", settings::visuals::entity::colors::box, color_edit4_flags);
                Checkbox("Name", &settings::visuals::entity::name); ColorEdit4("Name", settings::visuals::entity::colors::name, color_edit4_flags);
                Checkbox("Distance", &settings::visuals::entity::distance); ColorEdit4("Distance", settings::visuals::entity::colors::distance, color_edit4_flags);

                if (BeginCombo("List", "..."))
                {
                    for (auto item : settings::visuals::entity::list.items())
                    {
                        bool temp = item.value();
                        Selectable(item.key().c_str(), &temp, ImGuiSelectableFlags_DontClosePopups);
                        item.value() = temp;
                    }

                    EndCombo();
                }

                SliderInt("Render distance", &settings::visuals::entity::render_distance, 100, 20000, "%d m", ImGuiSliderFlags_NoInput);
            }
            break;
            }
        }
        EndChild();

        SameLine();

        BeginChild("Chams", child_size);
        {

        }
        EndChild();

        SameLine();

        BeginChild("World", child_size);
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
            Checkbox("ThirdPerson", &settings::miscellaneous::globals::third_person::enable); custom::hotkey("Third person Hotkey", &settings::miscellaneous::globals::third_person::hotkey);
            SliderInt("ThirdPerson Distance", &settings::miscellaneous::globals::third_person::distance, 10, 200);
        }
        EndChild();

        SameLine();

        BeginChild("Movement", child_size);
        {
            Checkbox("Bunny hop", &settings::miscellaneous::movement::bhop);
            Checkbox("Air strafe", &settings::miscellaneous::movement::air_strafe);
        }
        EndChild();

        EndTabItem();
    }

    if (BeginTabItem("Lua"))
    {
        ImVec2 child_size = ImVec2((GetColumnWidth() - (style.ItemSpacing.x * 2)) / 3, GetWindowHeight() - (GetCursorPosY() + style.ItemInnerSpacing.y * 2));

        static int selected_item = -1;
        static char search_buffer[256] = "";

        std::vector<std::string> file_list = { "autodance", "exechack :)", "hitlog", "test", "rehack" };

        BeginChild("Scripts", child_size);
        {
            float column_width = GetColumnWidth();

            PushItemWidth(column_width - 10.f);
            InputText("Search", search_buffer, sizeof(search_buffer));

            if (BeginListBox("##Files", ImVec2(0, GetWindowHeight() - (GetCursorPosY() + 10.f))))
            {
                for (int i = 0; i < file_list.size(); i++)
                {
                    if (Selectable(file_list[i].c_str(), selected_item == i, 0, ImVec2(column_width, 0)))
                        selected_item = i;
                }

                EndListBox();
            }

            PopItemWidth();
        }
        EndChild();

        SameLine();

        BeginChild("Action", child_size);
        {
            float column_width = GetColumnWidth();

            if (selected_item != -1 && selected_item < file_list.size())
            {
                std::string path = "C:/nixware/lua/" + file_list[selected_item] + ".lua";

                LabelText(file_list[selected_item].c_str());
                LabelText("Last update:", "18 Apr 2024 23:52");

                Button("Load script", ImVec2(column_width - 10.f, 35.f));
            }
        }
        EndChild();

        SameLine();

        BeginChild("Misc", child_size);
        {
            Checkbox("Dumper", &settings::lua::miscellaneous::dumper);
        }
        EndChild();

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
            LabelText("TextHovered");    ColorEdit4("TextHovered", settings::menu::colors::text_hovered, color_edit4_flags);
            LabelText("TextActive");     ColorEdit4("TextActive", settings::menu::colors::text_active, color_edit4_flags);
            LabelText("FrameBg");        ColorEdit4("FrameBg", settings::menu::colors::frame_bg, color_edit4_flags);
            LabelText("FrameHoveredBg"); ColorEdit4("FrameHoveredBg", settings::menu::colors::frame_hovered_bg, color_edit4_flags);
            LabelText("FrameActiveBg");  ColorEdit4("FrameActiveBg", settings::menu::colors::frame_active_bg, color_edit4_flags);
            Checkbox("Custom loading screen", &settings::menu::custom_loading_screen);
        }
        EndChild();

        SameLine();

        BeginChild("Configs", child_size);
        {
            float column_width = GetColumnWidth();

            Button("Unload cheat", ImVec2(column_width - 10.f, 35.f));
        }
        EndChild();

        EndTabItem();
    }

    EndTabBar();
    End();

    PopStyleColor(9);
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
    ImFormatString(context_name, sizeof(context_name), "HotKeyContext%s", label);

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