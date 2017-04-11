#include "Window_Editor.h"

Window_Editor::Window_Editor()
{
	btn_cancel = new Button(550, 100, 200, 50, "images/btn_cancel.png"); //criando botão CANCEL
	btn_loadSprite = new Button(550, 300, 200, 50, "images/btn_loadSprite.png"); //criando botão LOAD SPRITE

	m_imageOnScreen = false; //inicializando como falsa
}

Window_Editor::~Window_Editor()
{
}

void Window_Editor::MousePressed(int x, int y, Window_Manager * window_manager)
{									  
	if (btn_loadSprite->TestClick(x, y)) { //se click dentro do botão LOAD SPRITE, novo objeto é criado (após selecionar imagem)
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
		if (result.bSuccess) {
			SetImageOnScreen(true); //imagem na tela = verdadeiro

			string path = result.getPath(); //armazena em path o caminho para a imagem selecionada

			object = new Object(path); //criando novo objeto e setando posições para imagem ficar no meio da tela preta
			object->SetX(251 - object->GetW() / 2);
			object->SetY(384 - object->GetH() / 2);
		}
	}

	if (btn_cancel->TestClick(x, y)) {  //se click dentro do botão CANCEL
		if (GetImageOnScreen()) {  //se tiver imagem de objeto na tela, deleta objeto e volta pro menu
			delete object;
			SetImageOnScreen(false);
			window_manager->SetState(0);
		}
		else
			window_manager->SetState(0);
	}
}

void Window_Editor::Draw()
{
	ofSetColor(0, 0, 0); //setando cor para preto
	ofDrawRectangle(0, 0, 502, 768); //retangulo preto representando onde o desenho do objeto ficará
	ofSetColor(255, 255, 255); //voltando cores ao normal

	btn_cancel->Draw(); //chamando função de desenho do botão CANCEL
	btn_loadSprite->Draw(); //chamando função de desenho do botão LOAD SPRITE

	if (GetImageOnScreen()) //se a imagem estiver na tela
		if (object->GetH() < MAX_HEIGHT && object->GetW() < MAX_WIDTH) //se a imagem estiver dentro das medidas máximas
			object->Draw();
		else
			//void ofSystemAlertDialog(string errorMessage);
			std::cout << "Imagem grande d+++. escolha outra" << std::endl; //se for muito grande, escolher outra img
}

void Window_Editor::SetImageOnScreen(bool imageOnScreen)
{
	m_imageOnScreen = imageOnScreen;
}

bool Window_Editor::GetImageOnScreen()
{
	return m_imageOnScreen;
}
