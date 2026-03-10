#include "menuManager.hpp"

MenuManager::MenuManager()
{
    frame->menuLayout = new AuthenticationMenu();
}
void MenuManager::display()
{
    while(frame->menuLayout)
    {
        outputHandler << frame->display();
        while(true)
        {
            Triplet<bool,char,SpecialKey> input = inputHandler.handleInput();
            if(input.first)
            {
                handleInputTransmission({input.second,input.third});
                break;
            }
        }
    }
}
void MenuManager::handleInputTransmission(Pair<char,SpecialKey> input)
{
    if(!frame->focused->handleInput(input))
    {
        UILayout* parentLayout = frame->focused->parentLayout;
        while(parentLayout)
        {
            if(parentLayout->handleMovement(input, frame->focused))
            {
                break;
            }
            parentLayout = parentLayout->parentLayout;
        }
    }
}
