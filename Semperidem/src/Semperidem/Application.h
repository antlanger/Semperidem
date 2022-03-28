#pragma once
#include "sipch.h"
#include "Core.h"
#include "Events/Event.h"
#include "Semperidem/Events/ApplicationEvent.h"
#include "Window.h"

namespace Semperidem {
	class SEMPERIDEM_API Application {
	public: 
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& event);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& event);
	};

	Application* CreateApplication();
}

