//Example call of the header file, which we created, so we don't have to use
//relative paths.
#include <Semperidem.h>


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