#include <Engine/GuiBuilder.h>

using namespace fancy::gui;

using namespace irr;
using namespace irr::core;
using namespace irr::gui;

GuiBuilder::GuiBuilder(IGUIEnvironment* gui) : guiEnv(gui)
{
	nElements = 0;
}

GuiBuilder::~GuiBuilder()
{
	guiEnv = NULL;
	delete &nElements;
}

IGUIButton* GuiBuilder::createButton(s32 x, s32 y, s32 width, s32 height, s32 id, GUIElement* parent, const wchar_t* text)
{
	return (guiEnv->addButton(rect<s32>(x, y, x+width, y+height), parent, id, text));
}