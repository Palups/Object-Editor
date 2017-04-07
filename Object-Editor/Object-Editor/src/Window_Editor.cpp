#include "Window_Editor.h"

Window_Editor::Window_Editor()
{
	btn_cancel = new Button(550, 100, 200, 50, "images/btn_cancel.png"); //criando bot�o CANCEL
}

Window_Editor::~Window_Editor()
{
}

void Window_Editor::MousePressed(int x, int y, Window_Manager * window_manager)
{
	if (btn_cancel->TestClick(x, y))  //checando se o click foi dentro do bot�o CANCEL
		window_manager->SetState(0);  //se sim, muda o estado para 0 (tela muda para menu)
}

void Window_Editor::Draw()
{
	ofSetColor(0, 0, 0); //setando cor para preto
	ofDrawRectangle(0, 0, 502, 768); //retangulo preto representando onde o desenho do objeto ficar�
	ofSetColor(255, 255, 255); //voltando cores ao normal

	btn_cancel->Draw(); //chamando fun��o de desenho do bot�o CANCEL
}
