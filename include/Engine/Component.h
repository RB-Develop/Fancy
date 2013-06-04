#ifndef FANCY_BASE_COMP
#define FANCY_BASE_COMP

#include <Irrlicht/irrlicht.h>

namespace fancy {
	namespace object {

		class Component
		{
		public:
			virtual ~Component() {};

			const char* getName() { return _name; }

			virtual void update() {};
			virtual void handleMessage(unsigned int, void* data = 0) { };
		protected:
			Component(const char*) {};
		private:
			const char* _name;
		}; 
	}
}

#endif

