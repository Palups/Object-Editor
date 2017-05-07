#include "Window_Menu.h"

Window_Menu::Window_Menu()
{
	btn_newObject = new Button(520, 706, 200, 50, "images/btn_newObject.png"); //criando botão NEW OBJECT
}

Window_Menu::~Window_Menu()
{
}

void Window_Menu::MousePressed(int x, int y, Window_Manager *window_manager)
{
	if (btn_newObject->TestClick(x, y))  //se click dentro do botão NEW OBJECT, muda a tela para editor de objetos
		window_manager->SetState(1);
}

void Window_Menu::Draw()
{
	ofSetBackgroundColor(255, 228, 225);

	btn_newObject->Draw(); //chamando função de desenho do botão NEW OBJECT

	ofSetColor(255, 218, 185);
	ofDrawRectangle(10, 10, 502, 748); //retangulo branco representando onde os objetos aparecerão na tela de menu
	ofSetColor(255, 255, 255);
}
