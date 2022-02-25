#include <Semperidem.h>
//So we don't have to use relative paths

class Sandbox : public Semperidem::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Semperidem::Application* Semperidem::CreateApplication()
{
	return new Sandbox();
}