#include "Window_Menu.h"

Window_Menu::Window_Menu()
{
	btn_newObject = new Button(550, 550, 100, 50, "images/new.png"); //criando botão de novo objeto
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
	btn_newObject->Draw(); //chamando função de desenho do botão de novo objeto
	ofDrawRectangle(10, 10, 502, 748); //retangulo branco representando onde os objetos aparecerão na tela inicial
}
