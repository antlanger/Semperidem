#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Semperidem {
	class SEMPERIDEM_API Application {
	public: 
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

