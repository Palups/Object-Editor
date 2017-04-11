#include "Window_Editor.h"

Window_Editor::Window_Editor()
{
	btn_cancel = new Button(550, 100, 200, 50, "images/btn_cancel.png"); //criando botão CANCEL
	btn_loadSprite = new Button(550, 300, 200, 50, "images/btn_loadSprite.png"); //criando botão LOAD SPRITE
}

Window_Editor::~Window_Editor()
{
}

void Window_Editor::MousePressed(int x, int y, Window_Manager * window_manager)
{
	if (btn_cancel->TestClick(x, y))  //checando se o click foi dentro do botão CANCEL
		window_manager->SetState(0);  //se sim, muda o estado para 0 (tela muda para menu)

	if (btn_loadSprite->TestClick(x, y)) {
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
		if (result.bSuccess) {
			string path = result.getPath(); //armazena em path o caminho para a imagem selecionada
			// load your file at `path`
			std::cout << path << std::endl; //mostrar no console o caminho para a imagem selecionada
		}
	}

}

void Window_Editor::Draw()
{
	ofSetColor(0, 0, 0); //setando cor para preto
	ofDrawRectangle(0, 0, 502, 768); //retangulo preto representando onde o desenho do objeto ficará
	ofSetColor(255, 255, 255); //voltando cores ao normal

	btn_cancel->Draw(); //chamando função de desenho do botão CANCEL
	btn_loadSprite->Draw(); //chamando função de desenho do botão LOAD SPRITE
}
