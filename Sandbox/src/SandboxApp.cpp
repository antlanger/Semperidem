//Example call of the header file, which we created, so we don't have to use
//relative paths.
#include <Semperidem.h>

class SemperidemLayer : public Semperidem::Layer
{
public:
	SemperidemLayer() : Layer("Semperidem_Example_Layer ") {}

	void OnUpdate() override
	{
		SI_CLIENT_INFO("Semperidem_Example_Layer::Update");
	}

	void OnEvent(Semperidem::Event& event) override
	{
		SI_CLIENT_TRACE("{0}", event);
	}
};

class Sandbox : public Semperidem::Application
{
public:
	Sandbox() 
	{
		PushLayer(new SemperidemLayer());
	}

	~Sandbox() {}
};

Semperidem::Application* Semperidem::CreateApplication()
{
	return new Sandbox();
}