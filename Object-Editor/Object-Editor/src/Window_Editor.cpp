#include "Window_Editor.h"

Window_Editor::Window_Editor()
{
	btn_cancel = new Button(520, 700, 200, 50, "images/btn_cancel.png"); //criando botão CANCEL
	btn_loadSprite = new Button(520, 25, 200, 50, "images/btn_loadSprite.png"); //criando botão LOAD SPRITE
	btn_changeObjectColor = new Button(600, 300, 200, 50, "images/meep.png"); // -> mexe na cor do objeto
	btn_changeObjectSat = new Button(600, 250, 200, 50, "images/meep2.png"); // -> mexe na saturação do objeto
	btn_saveObject = new Button(800, 700, 200, 50, "images/btn_save.png"); // salva

	s_hp = new UI_Slider(600, 450, 100, 25, 100); //slider pra representar hp do objeto
	s_hp->SetLabel("HP");

	m_imageOnScreen = false; //inicializando como falsa

	//gui = new ofxUISuperCanvas("tela de edicao"); //Creates a canvas at (0,0) using the default width	
	//gui.setup();
	//gui.add(m_hp.setup("HP", 0, 0, 100));
}

Window_Editor::~Window_Editor()
{
}

void Window_Editor::KeyPressed(int key)
{
	switch (key)
	{
	case 'k':
		InputText();
		break;
	}
}

void Window_Editor::MouseReleased(int x, int y)
{
	s_hp->MouseReleased(x, y);
}

void Window_Editor::MouseDragged(int x, int y)
{
	s_hp->MouseDragged(x, y);
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

	if (btn_saveObject->TestClick(x, y))
	{		
		ofFileDialogResult result = ofSystemSaveDialog("default.png", "Save");
		if (result.bSuccess) {
			string imgPath = result.getPath();
			ofstream arquivo(imgPath + ".txt"); //cria um novo arquivo com o nome que o usuario der pro objeto
			ofSaveImage(object->m_image.getPixelsRef(),imgPath +".png");
			arquivo << imgPath +".png" << endl; //salva o path da imagem no arquivo
			arquivo.close(); //fecha o arquivo
			// save your file to `path`
		}				
	}

	if (btn_changeObjectColor->TestClick(x, y) && m_imageOnScreen) //se click for no botão CHANGE e objeto estiver na tela
	{
		object->PlusColor();
		object->ChangeColor();
	}

	if (btn_changeObjectSat->TestClick(x, y) && m_imageOnScreen) //se click for no botão CHANGE e objeto estiver na tela
	{
		object->PlusSatu();
		object->ChangeSatu();
	}
	
	

	s_hp->MouseClicked(x, y);
}

void Window_Editor::Draw()
{
	ofSetColor(0, 0, 0); //setando cor para preto
	ofDrawRectangle(0, 0, 502, 768); //retangulo preto representando onde o desenho do objeto ficará
	ofSetColor(255, 255, 255); //voltando cores ao normal

	btn_cancel->Draw(); //chamando função de desenho do botão CANCEL
	btn_saveObject->Draw();
	btn_loadSprite->Draw(); //chamando função de desenho do botão LOAD SPRITE

	if (GetImageOnScreen()) //se a imagem estiver na tela
	{
		btn_changeObjectColor->Draw();
		btn_changeObjectSat->Draw();
		if (object->GetH() < MAX_HEIGHT && object->GetW() < MAX_WIDTH) //se a imagem estiver dentro das medidas máximas
			object->Draw();
		else
			std::cout << "Imagem grande d+++. escolha outra" << std::endl; //se for muito grande, escolher outra img

		//gui.draw();
		s_hp->Draw();
	}
}

void Window_Editor::SetImageOnScreen(bool imageOnScreen)
{
	m_imageOnScreen = imageOnScreen;
}

bool Window_Editor::GetImageOnScreen()
{
	return m_imageOnScreen;
}

void Window_Editor::InputText()
{
	input = ofSystemTextBoxDialog("Nome", input);
	std::cout << input << std::endl;
}

void Window_Editor::exit()
{
	/*gui->saveSettings("settings.xml");
	delete gui;*/
}

void Window_Editor::guiEvent(ofxUIEventArgs & e)
{
}