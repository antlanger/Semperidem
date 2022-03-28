#pragma once
#include "sipch.h"
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Semperidem {
	class SEMPERIDEM_API Application {
	public: 
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

