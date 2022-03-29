#pragma once

#include "Semperidem/Core.h"
#include "Semperidem/Events/Event.h"

// Layers can be used for different types of actions.
// For example it can be used for Debug Drawing, which we heard in the presentation.
namespace Semperidem {

	class SEMPERIDEM_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		//Used to push a layer on the layer stack
		virtual void OnAttach() {}

		//Used to remove a layer from the layer stack
		virtual void OnDetach() {}

		//Called when the layer is updated -> call happens every frame
		virtual void OnUpdate() {}

		//When an event was triggered on the layer
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	private:
		// Info: Layer should not have names in distribution builds, 
		// because we should not address layers by names -> HERE FOR DEBUGGING
		std::string m_DebugName;
	};
}
