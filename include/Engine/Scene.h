#ifndef FANCY_SCENE
#define FANCY_SCENE

#include <Engine/Composite.h>

namespace fancy {
	namespace scene {

		class Scene : public object::Composite
		{
		public:
			virtual void update() = 0;
			virtual void init() {};
			virtual void handleMessage(unsigned int) {};
			virtual void addComponent(Component*);
			virtual void removeComponent(Component*);
		protected:
			Scene(const char*);
		};

	}
}
#endif