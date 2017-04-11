#include "Window_Menu.h"

Window_Menu::Window_Menu()
{
	btn_newObject = new Button(550, 550, 200, 50, "images/btn_newObject.png"); //criando bot�o NEW OBJECT
}

Window_Menu::~Window_Menu()
{
}

void Window_Menu::MousePressed(int x, int y, Window_Manager *window_manager)
{
	if (btn_newObject->TestClick(x, y))  //se click dentro do bot�o NEW OBJECT, muda a tela para editor de objetos
		window_manager->SetState(1);
}

void Window_Menu::Draw()
{
	btn_newObject->Draw(); //chamando fun��o de desenho do bot�o NEW OBJECT
	ofDrawRectangle(10, 10, 502, 748); //retangulo branco representando onde os objetos aparecer�o na tela de menu
}
