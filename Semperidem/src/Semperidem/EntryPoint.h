#pragma once

extern Semperidem::Application* Semperidem::CreateApplication();

#ifdef SI_PLATFORM_WINDOWS
	//That's our entry point
	int main(int argc, char** argv)
	{
		printf("Engine started");
		auto app = Semperidem::CreateApplication();
		app->Run();
		delete app;

		return 0;
	}
#endif // SI_PLATFORM_WINDOWS
