#include "Window_Menu.h"

Window_Menu::Window_Menu()
{
	btn_new = new Button(100, 50, 80, 70);
}


Window_Menu::~Window_Menu()
{
}

void Window_Menu::MousePressed(int x, int y, Window_Manager * window_manager)
{
	btn_new->TestClick(x, y);
	std::cout << "vai toma no cu justino" << std::endl;
}

void Window_Menu::Update()
{
}

void Window_Menu::Draw()
{
	btn_new->Draw();
}
