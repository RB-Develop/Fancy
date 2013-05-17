#ifndef FANCY_GUI_BUILDER
#define FANCY_GUI_BUILDER

#include <list>
#include <Irrlicht/irrlicht.h>

namespace fancy {
	namespace gui {
		class Interface
		{
		public:
			Interface(irr::gui::IGUIEnvironment* gui, irr::video::IVideoDriver* driver);
			~Interface();

			void createButton(irr::s32 x, irr::s32 y, irr::s32 width, irr::s32 height, irr::s32 id, irr::gui::IGUIElement* parent, const wchar_t* text);
			void addEditBox(irr::s32 x, irr::s32 y, irr::s32 width, irr::s32 height, irr::s32 id, irr::gui::IGUIElement* parent, const wchar_t* text, bool border);
			void addImage(irr::io::path, int x, int y);

			void resetInterface();

			irr::gui::IGUIElement* getElementWithId(irr::s32 id);
		private:
			irr::gui::IGUIEnvironment* _guiEnv;
			irr::video::IVideoDriver* _driver;

			std::list<irr::gui::IGUIElement*> _interfaceElements;
		};
	}
}
#endif