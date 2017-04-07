#include "Window_Menu.h"

Window_Menu::Window_Menu()
{
	btn_newObject = new Button(550, 550, 200, 50, "images/btn_newObject.png"); //criando botão NEW OBJECT
}

Window_Menu::~Window_Menu()
{
}

void Window_Menu::MousePressed(int x, int y, Window_Manager *window_manager)
{
	if (btn_newObject->TestClick(x, y))  //checando se o click foi dentro do botão NEW OBJECT
		window_manager->SetState(1);  //se sim, muda o estado para 1 (tela muda para editor de objetos)
}

void Window_Menu::Draw()
{
	btn_newObject->Draw(); //chamando função de desenho do botão NEW OBJECT
	ofDrawRectangle(10, 10, 502, 748); //retangulo branco representando onde os objetos aparecerão na tela de menu
}
