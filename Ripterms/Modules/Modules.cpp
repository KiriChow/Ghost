#include "Modules.h"
#include <bitset>

void Ripterms::Modules::IModule::run()
{
}

void Ripterms::Modules::IModule::renderGUI()
{
}

void Ripterms::Modules::IModule::disable()
{
}

void Ripterms::Modules::runAll()
{
	for (const std::pair<std::string, std::vector<IModule*>>& category : categories)
	{
		for (IModule* m : category.second)
		{
			m->run();
		}
	}
}

void Ripterms::Modules::cleanAll()
{
	bool should_disable = Ripterms::p_env != nullptr;
	for (const std::pair<std::string, std::vector<IModule*>>& category : categories)
	{
		for (IModule* m : category.second)
		{
			if (should_disable)m->disable();
			delete m;
		}
	}
}

void Ripterms::Modules::FastPlace::run()
{
	if (!enabled || !GetAsyncKeyState(VK_RBUTTON)) return;
	if (Ripterms::cache->theMinecraft.getRightClickDelayTimer() == 4)
	{
		Ripterms::cache->theMinecraft.setRightClickDelayTimer(tickDelay);
	}
}

void Ripterms::Modules::FastPlace::renderGUI()
{
	static bool display_options = false;
	ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(20.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(250.0f, ImGui::GetStyle().FramePadding.y));
	ImGui::Checkbox("Fast Place", &enabled);
	ImGui::PopStyleVar();
	if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) display_options = !display_options;
	ImGui::SameLine();
	ImGui::SetCursorPosX(ImGui::GetWindowWidth() - 30.0f);
	if (ImGui::ArrowButton("fastplaceopt", ImGuiDir_Down)) display_options = !display_options;
	if (display_options)
	{
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.0f);
		ImGui::BeginGroup();
		{
			ImGui::SliderInt("Tick Delay", &tickDelay, 0, 3);
		}
		ImGui::EndGroup();
	}
	ImGui::PopStyleVar();
}



void Ripterms::Modules::Xray::run()
{
	static Timer timer = std::chrono::milliseconds(300);
	if (GetAsyncKeyState(keyBind) && timer.isElapsed() && GetActiveWindow() == Ripterms::window)
	{
		enabled = !enabled;
	}
	static bool prev_enabled = false;
	if (!enabled)
	{
		if (prev_enabled)
		{
			disable();
			prev_enabled = false;
		}
		return;
	}
	if (!prev_enabled)
	{
		Ripterms::cache->EMPTY_MAP.put(String("xray_enabled"), String("1"));
		sendF3_A();
		prev_enabled = true;
	}
}

void Ripterms::Modules::Xray::renderGUI()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(20.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(250.0f, ImGui::GetStyle().FramePadding.y));
	ImGui::Checkbox("Xray", &enabled);
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();
}

void Ripterms::Modules::Xray::disable()
{
	Ripterms::cache->EMPTY_MAP.put(String("xray_enabled"), String("0"));
	sendF3_A();
}

void Ripterms::Modules::Xray::sendF3_A()
{
	std::thread([]
	{
		bool should_reopen_gui = false;
		if (Ripterms::GUI::draw)
		{
			Ripterms::GUI::draw = false;
			should_reopen_gui = true;
		}
		SendMessageA(Ripterms::window, WM_KEYDOWN, VK_F3, 0);
		SendMessageA(Ripterms::window, WM_KEYDOWN, 0x41, 0);
		struct LParam
		{
			short repeat : 1;
			char scanCode : 8;
			char isExtended : 1;
			char reserved : 4;
			char context : 1;
			char previous : 1;
			char transition : 1;
		};
		LParam param{ .repeat = 1, .previous = 1, .transition = 1 };
		LPARAM lparam{};
		memcpy(&lparam, &param, sizeof(LParam));
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		SendMessageA(Ripterms::window, WM_KEYUP, VK_F3, lparam);
		SendMessageA(Ripterms::window, WM_KEYUP, 0x41, lparam);
		SendMessageA(Ripterms::window, WM_KEYDOWN, VK_F3, 0);
		SendMessageA(Ripterms::window, WM_KEYUP, VK_F3, lparam);
		if (should_reopen_gui) Ripterms::GUI::draw = true;
	}).detach();
}
