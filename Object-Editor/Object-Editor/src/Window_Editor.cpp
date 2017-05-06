#include "Window_Editor.h"

Window_Editor::Window_Editor()
{
	btn_cancel = new Button(520, 700, 200, 50, "images/btn_cancel.png"); //criando bot�o CANCEL
	btn_loadSprite = new Button(520, 25, 200, 50, "images/btn_loadSprite.png"); //criando bot�o LOAD SPRITE
	btn_changeObjectColor = new Button(520, 300, 200, 50, "images/meep.png"); // -> mexe na cor do objeto
	btn_changeObjectSat = new Button(800, 300, 200, 50, "images/meep2.png"); // -> mexe na satura��o do objeto
	btn_saveObject = new Button(800, 700, 200, 50, "images/btn_save.png"); // salva


	sw_breakable = new UI_Switch(520, 450, 80, 20); //switch pra objetos destrutiveis
	sw_breakable->SetLabel("Is destructable");
	s_hp = new UI_Slider(700, 450, 300, 25, 1000); //slider pra representar hp do objeto
	s_hp->SetLabel("Initial HP");

	sw_pushable = new UI_Switch(520, 500, 80, 20);
	sw_pushable->SetLabel("Is pushable");
	s_kg = new UI_Slider(700, 500, 300, 25, 1000);
	s_kg->SetLabel("Initial weight");

	sw_healing = new UI_Switch(520, 550, 80, 20);
	sw_healing->SetLabel("Healing object");
	s_heal = new UI_Slider(700, 550, 300, 25, 500);
	s_heal->SetLabel("Healing amount");

	sw_damaging = new UI_Switch(520, 600, 80, 20);
	sw_damaging->SetLabel("Damaging object");
	s_dmg = new UI_Slider(700, 600, 300, 25, 500);
	s_dmg->SetLabel("Damage amount");

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
	if (s_hp->TestClick(x, y) && sw_breakable->GetStatus()) //se o switch de objeto destrutivel estiver ativo
		s_hp->MouseReleased(x, y);

	else if (s_kg->TestClick(x, y) && sw_pushable->GetStatus())
		s_kg->MouseReleased(x, y);

	else if (s_heal->TestClick(x, y) && sw_healing->GetStatus())
		s_heal->MouseReleased(x, y);

	else if (s_dmg->TestClick(x, y) && sw_damaging->GetStatus())
		s_dmg->MouseReleased(x, y);

	if (m_imageOnScreen) //atualiza o atributo do objeto com o valor do switch e do slider
	{
		object->SetHp(sw_breakable->GetStatus(), s_hp->GetValue()); 
		object->SetKg(sw_pushable->GetStatus(), s_kg->GetValue());
		object->SetHeal(sw_healing->GetStatus(), s_heal->GetValue());
		object->SetDamage(sw_damaging->GetStatus(), s_dmg->GetValue());
	}
		
}

void Window_Editor::MouseDragged(int x, int y)
{
	if (s_hp->TestClick(x, y) && sw_breakable->GetStatus()) //se o switch de objeto destrutivel estiver ativo
		s_hp->MouseDragged(x, y);

	else if (s_kg->TestClick(x, y) && sw_pushable->GetStatus())
		s_kg->MouseDragged(x, y);

	else if (s_heal->TestClick(x, y) && sw_healing->GetStatus())
		s_heal->MouseDragged(x, y);

	else if (s_dmg->TestClick(x, y) && sw_damaging->GetStatus())
		s_dmg->MouseDragged(x, y);
}

void Window_Editor::MousePressed(int x, int y, Window_Manager * window_manager)
{									  
	if (btn_loadSprite->TestClick(x, y)) { //se click dentro do bot�o LOAD SPRITE, novo objeto � criado (ap�s selecionar imagem)
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
		if (result.bSuccess) {
			SetImageOnScreen(true); //imagem na tela = verdadeiro

			string path = result.getPath(); //armazena em path o caminho para a imagem selecionada

			object = new Object(path); //criando novo objeto e setando posi��es para imagem ficar no meio da tela preta
			object->SetX(251 - object->GetW() / 2);
			object->SetY(384 - object->GetH() / 2);
		}
	}

	if (btn_cancel->TestClick(x, y)) {  //se click dentro do bot�o CANCEL
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
			arquivo << imgPath + ".png" << endl //salva o path da imagem no arquivo
				<< sw_healing->GetStatus() << endl //salva o status de healing no arquivo
				<< s_heal->GetValue() << endl // salva o valor de heal
				<< sw_breakable->GetStatus() << endl // status de quebravel
				<< s_hp->GetValue() << endl //hp do objeto
				<< sw_damaging->GetStatus() << endl //status de causador de dano
				<< s_dmg->GetValue() << endl //dano causado
				<< sw_pushable->GetStatus() << endl //status de empurravel
				<< s_kg->GetValue() << endl; //peso
			arquivo.close(); //fecha o arquivo
			// save your file to `path`
			ofSystemAlertDialog("Objeto salvo com sucesso!");
			window_manager->SetState(0);
		}
		else {
			ofSystemAlertDialog("N�o foi poss�vel salvar o objeto!");
		}
	}

	if (m_imageOnScreen) //TODAS AS CONFIG DE IMAGEM AQUI!!!!!!!
	{
		/*-----  APARENCIA DO OBJETO  -----*/
		if (btn_changeObjectColor->TestClick(x, y)) //se click for no bot�o CHANGE e objeto estiver na tela
		{
			object->PlusColor();
			object->ChangeColor();
		}

		if (btn_changeObjectSat->TestClick(x, y)) //se click for no bot�o CHANGE e objeto estiver na tela
		{
			object->PlusSatu();
			object->ChangeSatu();
		}

		/*-----  ATRIBUTOS  -----*/
		if (sw_breakable->TestClick(x, y)) // Se o click for no botao 
		{
			sw_breakable->MouseClicked(x, y);
			if(!sw_breakable->GetStatus())
				s_hp->DeactivateSlider(); 
		}
		else if (s_hp->TestClick(x, y)) //se o click for no slider...
		{
			if (sw_breakable->GetStatus()) //...e o switch de objeto destrutivel estiver ativo
				s_hp->MouseClicked(x, y);			
		}
		//EMPURRAVEL
		else if (sw_pushable->TestClick(x, y)) 
		{
			sw_pushable->MouseClicked(x, y);
			if(!sw_pushable->GetStatus())
				s_kg->DeactivateSlider();
		}
		//PESO
		else if (s_kg->TestClick(x, y)) 
		{
			if (sw_pushable->GetStatus()) //...e o switch de objeto destrutivel estiver ativo
				s_kg->MouseClicked(x, y);
		}

		//DA HEAL
		else if (sw_healing->TestClick(x, y))
		{
			sw_healing->MouseClicked(x, y);
			if (!sw_healing->GetStatus())
				s_heal->DeactivateSlider();
		}
		//QUANTO DE HEAL
		else if (s_heal->TestClick(x, y))
		{
			if (sw_healing->GetStatus()) //...e o switch de objeto destrutivel estiver ativo
				s_heal->MouseClicked(x, y);
		}

		//MACHUCA PORRA
		else if (sw_damaging->TestClick(x, y))
		{
			sw_damaging->MouseClicked(x, y);
			if (!sw_damaging->GetStatus())
				s_dmg->DeactivateSlider();
		}
		//QUANTO DE DMG
		else if (s_dmg->TestClick(x, y))
		{
			if (sw_damaging->GetStatus()) //...e o switch de objeto destrutivel estiver ativo
				s_dmg->MouseClicked(x, y);
		}
	}	
}

void Window_Editor::Draw()
{
	ofSetColor(0, 0, 0); //setando cor para preto
	ofDrawRectangle(0, 0, 502, 768); //retangulo preto representando onde o desenho do objeto ficar�
	ofSetColor(255, 255, 255); //voltando cores ao normal

	ofSetBackgroundColor(173, 255, 47);

	btn_cancel->Draw(); //chamando fun��o de desenho do bot�o CANCEL
	btn_saveObject->Draw();
	btn_loadSprite->Draw(); //chamando fun��o de desenho do bot�o LOAD SPRITE

	if (GetImageOnScreen()) //se a imagem estiver na tela
	{
		btn_changeObjectColor->Draw();
		btn_changeObjectSat->Draw();
		if (object->GetH() < MAX_HEIGHT && object->GetW() < MAX_WIDTH) //se a imagem estiver dentro das medidas m�ximas
			object->Draw();
		else
			std::cout << "Imagem grande d+++. escolha outra" << std::endl; //se for muito grande, escolher outra img

		s_hp->Draw();
		sw_breakable->Draw();
		s_kg->Draw();
		sw_pushable->Draw();
		s_heal->Draw();
		sw_healing->Draw();
		s_dmg->Draw();
		sw_damaging->Draw();
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