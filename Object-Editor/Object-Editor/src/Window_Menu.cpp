#include "Window_Menu.h"

Window_Menu::Window_Menu()
{
	btn_newObject = new Button(100, 100, 100, 100, "images/new.png"); //criando botão de novo objeto
}

Window_Menu::~Window_Menu()
{
}

void Window_Menu::MousePressed(int x, int y, Window_Manager *window_manager)
{
	btn_newObject->TestClick(x, y); //checando se o click foi dentro do botão de novo objeto
}

void Window_Menu::Draw()
{
	btn_newObject->Draw();
}
