#pragma once
#include <ImGui/imgui.h>

namespace Ripterms::GUI
{
	const char* client_name = "k i r i c h o w    g h o s t";
	constexpr float HEADER_HEIGHT = 40.f;
	constexpr float HEADER_CAT_DISTANCE = 10.f;
	constexpr float CATEGORY_WIDTH = 100.0f;



	static ImVec2 category_button_size = ImVec2(100, 30);

	/* other style*/

	static bool ripterms_title = true;
	/* both are false by default but eh why not */
	static bool show_color_theming = false;
	static bool show_rounding_theming = false;

	/* color picker colors */
	static ImColor color_active_tab = ImColor(255, 0, 0, 133);
	static ImColor color_child_bg = ImColor(0, 0, 0, 79);
	static ImColor color_slider_grab = ImColor(143, 46, 46, 255);
	static ImColor color_frame_bg = ImColor(50, 50, 50, 80);
	static ImColor color_frame_bg_active = ImColor(35, 35, 35, 255);
	static ImColor color_frame_bg_hovered = ImColor(68, 64, 64, 255);
	static ImColor color_window_bg = ImColor(11, 14, 15, 255);
	static ImColor color_button = ImColor(50, 50, 50, 80);
	static ImColor color_button_active = ImColor(239, 73, 88, 255);
	static ImColor color_button_hovered = ImColor(173, 55, 65, 255);
	static ImColor color_text = ImColor(200, 200, 200, 255);
	static ImColor color_header = ImColor(78, 78, 78, 255);
	static ImColor color_header_active = ImColor(78, 78, 78, 255);
	static ImColor color_header_hovered = ImColor(78, 78, 78, 255);
	static ImColor color_checkmark = ImColor(143, 46, 46, 255);
	static ImColor color_border = ImColor(59, 59, 59, 255);
	static ImColor color_border_shadow = ImColor(0, 0, 0, 0);

	/* rounding */

	static float rounding_frame = 0.0f;
	static float rounding_window = 0.0f;
	static float rounding_child = 0.0f;
	static float rounding_grab = 0.0f;
	static float rounding_popup = 0.0f;
	static float rounding_scrollbar = 0.0f;
	static float rounding_tab = 0.0f;
}
