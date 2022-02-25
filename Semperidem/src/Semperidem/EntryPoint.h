#pragma once

//Here we define our entry point of the client application.
//At the moment we only support Windows.
//Our "Application" is created externally in the application.

extern Semperidem::Application* Semperidem::CreateApplication();

#ifdef SI_PLATFORM_WINDOWS
	int main(int argc, char** argv)
	{
		//Initialize Logger 
		Semperidem::Log::Init();
		SI_CORE_WARN("This is a warn log!");
		SI_CLIENT_INFO("This is a info log!");

		//Create Application
		printf("Engine started...");
		auto app = Semperidem::CreateApplication();
		app->Run();
		delete app;

		return 0;
	}
#endif // SI_PLATFORM_WINDOWS
