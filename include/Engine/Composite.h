#ifndef FANCY_COMPOSITE
#define FANCY_COMPOSITE

#include "Component.h"
#include <list>

namespace fancy {
	namespace object {

		class Composite : public Component
		{
		public:
			virtual ~Composite()
			{
				for (std::list<Component*>::iterator i = components.begin(); i != components.end(); ++i)
				{
					delete *i;
				}
			}

			virtual void update()
			{
				for (std::list<Component*>::iterator i = components.begin(); i != components.end(); ++i)
				{
					(*i)->update();
				}
			}

			virtual void handleMessage(unsigned int message, void* data)
			{
				std::list<Component*>::iterator i;
				for (i = components.begin(); i != components.end(); ++i)
				{
					(*i)->handleMessage(message, data);
				}
				delete *i;
			}

			virtual void addComponent(Component* component) 
			{
				components.push_back(component);
			}
			virtual void removeComponent(Component* component)
			{
				components.remove(component);
			}
		protected:
			Composite(const char* name) : Component(name) {};
		private:
			std::list<Component*> components;
		};

	}
}
#endif