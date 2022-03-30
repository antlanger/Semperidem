#pragma once
#include "sipch.h"
#include "Core.h"
#include "Semperidem/Events/Event.h"
#include "Semperidem/Events/ApplicationEvent.h"
#include "Semperidem/LayerStack.h"
#include "Window.h"

namespace Semperidem {
	class SEMPERIDEM_API Application {
	public: 
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& event);
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

