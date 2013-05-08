#ifndef FANCY_GUI_BUILDER
#define FANCY_GUI_BUILDER

#include <Irrlicht/irrlicht.h>

namespace fancy {
	namespace gui {

		typedef irr::gui::IGUIElement GUIElement;
		typedef irr::gui::IGUIButton GUIButton;

		class GuiBuilder
		{
		private:
			irr::gui::IGUIEnvironment* guiEnv;
			int nElements;
		public:
			GuiBuilder(irr::gui::IGUIEnvironment* gui);
			~GuiBuilder();

			GUIButton* createButton(irr::s32 x, irr::s32 y, irr::s32 width, irr::s32 height, irr::s32 id, GUIElement* parent, const wchar_t* text);

		};
	}
}
#endif