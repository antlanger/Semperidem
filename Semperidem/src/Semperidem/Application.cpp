#include "Application.h"
#include "Semperidem/Events/ApplicationEvent.h"
#include "Semperidem/Log.h"

namespace Semperidem {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SI_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SI_CLIENT_TRACE(e);
		}

		while (true);
	}
}
