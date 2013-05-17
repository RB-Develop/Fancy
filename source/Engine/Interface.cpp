#include <Engine/Interface.h>

using namespace fancy::gui;

using namespace irr;
using namespace irr::core;
using namespace irr::gui;
using namespace irr::video;

Interface::Interface(IGUIEnvironment* gui, IVideoDriver* driver) : _guiEnv(gui), _driver(driver)
{
}

Interface::~Interface()
{
	_guiEnv = NULL;	
}

void Interface::createButton(s32 x, s32 y, s32 width, s32 height, s32 id, IGUIElement* parent, const wchar_t* text)
{
	_interfaceElements.push_back(_guiEnv->addButton(rect<s32>(x, y, x+width, y+height), parent, id, text));
}

void Interface::addEditBox(irr::s32 x, irr::s32 y, irr::s32 width, irr::s32 height, s32 id, irr::gui::IGUIElement* parent, const wchar_t* text, bool border)
{
	_interfaceElements.push_back(_guiEnv->addEditBox(text, rect<s32>(x, y, x+width, y+height), border, parent, id));
}

void Interface::addImage(io::path path, int x, int y)
{
	_interfaceElements.push_back(_guiEnv->addImage(_driver->getTexture(path), position2d<int>(x, y)));
}

void Interface::resetInterface()
{
	std::list<IGUIElement*>::iterator iter;

	for(iter = _interfaceElements.begin(); iter != _interfaceElements.end(); iter++)
	{
		(*iter)->remove();
	}
	_interfaceElements.clear();
}

IGUIElement* Interface::getElementWithId(s32 id)
{
	std::list<IGUIElement*>::iterator iter;

	for(iter = _interfaceElements.begin(); iter != _interfaceElements.end(); iter++)
	{
		if((*iter)->getID() == id)
		{
			return *iter;
		}
	}
}