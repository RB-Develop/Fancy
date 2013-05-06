#include <Engine/UIBuilder.h>

using namespace irr;
using namespace core;
using namespace gui;

UIBuilder::UIBuilder(IGUIEnvironment* gui) : guiEnv(gui)
{
	elementCount = 0;
	guiEnv = gui;
}

UIBuilder::~UIBuilder()
{
	guiEnv = NULL;
	delete &elementCount;
}

IGUIButton* UIBuilder::createButton(s32 x, s32 y, s32 width, s32 height, s32 id, GUIElement* parent, const wchar_t* text)
{
	return (guiEnv->addButton(rect<s32>(x, y, x+width, y+height), parent, id, text));
}