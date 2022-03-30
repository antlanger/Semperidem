#pragma once

#include "Semperidem/Core.h"

namespace Semperidem {

	//Events are currently BLOCKING, which means when an event occurs the whole application
	//stops and processes the event.

	//Difference between ENUM and ENUM CLASS
	//ENUM -> Basically a const static integer. Spills its contents into the enclosing scope. -> unscoped
	//ENUM CLASS -> Have their own scope. Make sure that the first element in any enum class aren't equal. -> scoped

	//Describes the event type
	//The events are implemented in the header files.
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/*
	* We have this categories, because we may want to filter.
	* We get all events from our application in some OnEvent-class, but for example we only want
	* the keyboard events.
	* We use the BIT, becuase an event can be included in multiple categories.
	*/
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

/* These macros exist, because we need GetEventType, GetNameand GetCategoryFlags implemented and it's an more compact way.
* GetStaticType -> We want to get the type of an event, the type will always be the event no matter what instance it is.
* GetEventType -> Non instance based, we need this for example when we have an event base-class and 
* we only have an reference/pointer to the event, to get the type of the event.
* 
* #type -> Value of the type like EventType::KeyPressed
* ##type -> Stringified version like "KeyPressed"
*/
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type; }\
								virtual EventType GetEventType() const override {return GetStaticType(); }\
								virtual const char* GetName() const override {return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }


//-------------------------------- EVENT CLASS -----------------------------------
	class SEMPERIDEM_API Event
	{
		friend class EventDispatcher;
	
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		/*
		* Method to determine if the given event is in this category.
		* Returns 0 or false if it doesn't belong to any category.
		* Returns true if it belongs to a category.
		*/
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		// Indicates if an event was handled or not
		bool m_Handled = false;
	};



//-------------------------------- DISPATCHER CLASS -----------------------------------
	/* Is used to dispatch events based on their type
	* When OnEvent is called we receive our event as a reference of any type.
	* An instance of the EventDispatcher is created.
	* The dispatch function is called several times, which is a standard function with T as parameter.
	* Returns a bool, true if the event was handled (type is present and function was called properly)
	* false if the type does not match any defined type
	*/
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	//For logging library to log events
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}