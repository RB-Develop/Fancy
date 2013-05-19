#ifndef FANCY_SCENE
#define FANCY_SCENE

#include <Engine/Composite.h>

namespace fancy {
	namespace scene {

		class Scene : public object::Composite
		{
		public:
			virtual void update() = 0;
			virtual void init() = 0;
			virtual void requestNextScene() = 0;
			virtual void notify(void* data) = 0;

			virtual void addComponent(Component*);
			virtual void removeComponent(Component*);
		protected:
			Scene(const char*);
		};

	}
}
#endif