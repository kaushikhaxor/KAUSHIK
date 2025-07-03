//================= PESTE THIS CODE ON IMGUI/IMGUI.WEDGET.CPP/CHECKBOX PERMITION UP IN PESTE HERE ====================\\

bool ImGui::StarButton(const char* label, bool* v)
{
    ImGuiWindow* window = GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = CalcTextSize(label, NULL, true);

    const float square_sz = GetFrameHeight();
    const ImVec2 pos = window->DC.CursorPos;
    const ImRect total_bb(pos, pos + ImVec2(square_sz + (label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f), label_size.y + style.FramePadding.y * 2.0f));
    ItemSize(total_bb, style.FramePadding.y);
    if (!ItemAdd(total_bb, id))
    {
        IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags | ImGuiItemStatusFlags_Checkable | (*v ? ImGuiItemStatusFlags_Checked : 0));
        return false;
    }

    bool hovered, held;
    bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);
    if (pressed)
    {
        *v = !(*v);
        MarkItemEdited(id);
    }

    const ImRect check_bb(pos, pos + ImVec2(square_sz, square_sz));
RenderNavHighlight(total_bb, id);

const float pad = ImMax(1.0f, IM_FLOOR(square_sz / 6.0f));
const float size = square_sz - pad * 2.0f;
const ImVec2 center = check_bb.GetCenter();
const float radius = size / 2.0f;
const int num_points = 8; // Set the number of points to 8 for an octagon shape
const float angle_step = 2.0f * IM_PI / num_points;
ImVector<ImVec2> points;
points.reserve(num_points);
for (int i = 0; i < num_points; i++)
{
    const float angle = angle_step * i + angle_step / 2.0f;
    const ImVec2 point(center.x + cos(angle) * radius, center.y + sin(angle) * radius);
    points.push_back(point);
}
window->DrawList->AddPolyline(points.Data, points.Size, GetColorU32((held && hovered) ? ImGuiCol_FrameBgActive : hovered ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg), true, style.FrameRounding);
ImU32 check_col = GetColorU32(ImGuiCol_CheckMark);
bool mixed_value = (g.LastItemData.InFlags & ImGuiItemFlags_MixedValue) != 0;
if (mixed_value)
{  
    ImVec2 pad(ImMax(1.0f, IM_FLOOR(square_sz / 3.6f)), ImMax(1.0f, IM_FLOOR(square_sz / 3.6f)));
    window->DrawList->AddRectFilled(check_bb.Min + pad, check_bb.Max - pad, check_col, style.FrameRounding);
}
else if (*v)
{
        const float pad = ImMax(1.0f, IM_FLOOR(square_sz / 6.0f));
    const float size = square_sz - pad * 17.0f;
    const ImVec2 center = check_bb.GetCenter();
    const float outer_radius = size / 20.0f;
    const float inner_radius = outer_radius * 5.0f;
    const int num_points = 5;
    const float angle_step = IM_PI / num_points;
    ImVector<ImVec2> points;
    points.reserve(num_points * 2);
    for (int i = 0; i < num_points * 2; i++)
    {
        const float radius = (i % 2 == 0) ? outer_radius : inner_radius;
        const float angle = angle_step * i + ImGui::GetTime(); 
        const ImVec2 point(center.x + cos(angle) * radius, center.y + sin(angle) * radius);
        points.push_back(point);
    }
    window->DrawList->AddConvexPolyFilled(points.Data, points.Size, check_col);
}
ImVec2 label_pos = ImVec2(check_bb.Max.x + style.ItemInnerSpacing.x, check_bb.Min.y + style.FramePadding.y);
if (g.LogEnabled)
    LogRenderedText(&label_pos, mixed_value ? "[~]" : *v ? "[x]" : "[ ]");
    if (label_size.x > 0.0f)
        RenderText(label_pos, label);
    IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags | ImGuiItemStatusFlags_Checkable | (*v ? ImGuiItemStatusFlags_Checked : 0));
    return pressed;
}

//============================== PRIVATE DON'T LEAK OK ===================\\