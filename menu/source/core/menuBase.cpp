#include "menuBase.hpp"

UIHeader::UIHeader(String menuName)
    : menuName(menuName) {}

void UIHeader::setMenuName(String menuName)
{
    this->menuName = menuName;
}
String UIHeader::getMenuName()
{
    return menuName;
}

OutputString& UIHeader::display()
{
    String headerShortcuts = " BACK[:b] - QUIT[:q] - HOME[:h] - MANUAL[:m] - FIX[:fx] ";
    String headerMenuNameCentered = "";

    unsigned int centerPos = (headerShortcuts.size() - menuName.size()) / 2;

    for(size_t i=0;i<(headerShortcuts.size() - menuName.size());i++) {
        headerMenuNameCentered += '_';
    }
    headerMenuNameCentered.insert(centerPos, menuName);

    oString <<  "| Messenger |"<<headerShortcuts<<ConsoleCode::NLINE <<
                "|___________|"<<headerMenuNameCentered<<ConsoleCode::NLINE;
    return oString;
}
