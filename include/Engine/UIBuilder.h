#ifndef FANCY_UI_BUILDER
#define FANCY_UI_BUILDER

#include <Irrlicht/irrlicht.h>

typedef irr::gui::IGUIElement GUIElement;
typedef irr::gui::IGUIButton GUIButton;

class UIBuilder
{
private:
	irr::gui::IGUIEnvironment* guiEnv;
	int elementCount;
public:
	UIBuilder(irr::gui::IGUIEnvironment* gui);
	~UIBuilder();

	GUIButton* createButton(irr::s32 x, irr::s32 y, irr::s32 width, irr::s32 height, GUIElement* parent, const wchar_t* text);
	
};

#endif