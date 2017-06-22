#include "Window_Editor.h"

Window_Editor::Window_Editor()
{
	m_imageOnScreen = false; //se imagem está na tela
	m_sliderControl = 1;

	//-----------------------------------------------------------------------------------------

	btn_cancel = new Button(520, 700, 200, 50, "imgs-editor/btn_cancel.png"); //cancela
	btn_loadSprite = new Button(520, 25, 200, 50, "imgs-editor/btn_loadSprite.png"); //carrega sprite
	btn_changeObjectColor = new Button(520, 150, 200, 50, "imgs-editor/meep.png"); //mexe na cor do objeto
	//btn_changeObjectSat = new Button(520, 150, 200, 50, "imgs-editor/meep2.png"); //mexe na saturação do objeto
	btn_saveObject = new Button(800, 700, 200, 50, "imgs-editor/btn_save.png"); //salva
	btn_changeSliders = new Button(520, 275, 200, 50, "imgs-editor/btn_changeSliders.png"); //altera sliders

	/* --------------------------- AS PORRA DOS SLIDERS PODE CRE --------------------------- */
	/* -- BUFFS -- */
	sw_protection = new UI_Switch(520, 400, 80, 20);
	sw_protection->SetLabel("Protection");
	s_protection = new UI_Slider(700, 400, 300, 25, 20);
	s_protection->SetLabel("Amount of protection");

	sw_healing = new UI_Switch(520, 450, 80, 20);
	sw_healing->SetLabel("Healing object");
	s_heal = new UI_Slider(700, 450, 300, 25, 100);
	s_heal->SetLabel("Healing amount");

	sw_speed = new UI_Switch(520, 500, 80, 20);
	sw_speed->SetLabel("Speed");
	s_speed = new UI_Slider(700, 500, 300, 25, 200);
	s_speed->SetLabel("Speed amount");

	sw_attack = new UI_Switch(520, 550, 80, 20);
	sw_attack->SetLabel("Increase attack");
	s_attack = new UI_Slider(700, 550, 300, 25, 50);
	s_attack->SetLabel("Attack value");

	sw_time = new UI_Switch(520, 600, 80, 20);
	sw_time->SetLabel("Decrease time");
	s_time = new UI_Slider(700, 600, 300, 25, 10);
	s_time->SetLabel("Seconds");


	/* -- DEBUFFS -- */
	sw_lessHP = new UI_Switch(520, 400, 80, 20);
	sw_lessHP->SetLabel("Less HP");
	s_lessHP = new UI_Slider(700, 400, 300, 25, 10);
	s_lessHP->SetLabel("Amount");

	sw_lessSpeed = new UI_Switch(520, 450, 80, 20);
	sw_lessSpeed->SetLabel("Less Speed");
	s_lessSpeed = new UI_Slider(700, 450, 300, 25, 50);
	s_lessSpeed->SetLabel("Amount");

	sw_lessAttack = new UI_Switch(520, 500, 80, 20);
	sw_lessAttack->SetLabel("Less Attack");
	s_lessAttack = new UI_Slider(700, 500, 300, 25, 25);
	s_lessAttack->SetLabel("Amount");

	/* -- OBSTACLE -- */
	sw_obstacle = new UI_Switch(520, 400, 80, 20);
	sw_obstacle->SetLabel("Static?");
	s_obstacleHP = new UI_Slider(700, 400, 300, 25, 500);
	s_obstacleHP->SetLabel("Obstacle HP");
	s_obs = new UI_Slider(700, 450, 300, 25, 500);
	s_obs->SetLabel("Amout of itens inside");

	/* ---------------------------  ---------------------------  --------------------------- */

	/* ---------------------------- PALETA DE CORES ---------------------------- */
	colorPicker.setColorRadius(1.0);
	colorPicker.setColorAngle(0.5);

	int x = 850;
	int y = 25;
	int w = 150;
	int h = 300;
	//int g = (int)((ofGetHeight() - h * 2) / 3); // gap.
	//y = g;

	colorPicker.setSize(x, y, w, h);

	//y = y + h + g; //PRA QUE QUE SERVE? N SEI
	//---------------------------------------------------------------------------

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
	switch (m_sliderControl) {
	case 1:
		if (s_protection->TestClick(x, y) && sw_protection->GetStatus()) //se o switch de objeto destrutivel estiver ativo
			s_protection->MouseReleased(x, y);

		if (s_heal->TestClick(x, y) && sw_healing->GetStatus())
			s_heal->MouseReleased(x, y);

		if (s_speed->TestClick(x, y) && sw_speed->GetStatus())
			s_speed->MouseReleased(x, y);

		if (s_attack->TestClick(x, y) && sw_attack->GetStatus())
			s_attack->MouseReleased(x, y);

		if (s_time->TestClick(x, y) && sw_time->GetStatus())
			s_time->MouseReleased(x, y);

		break;

	case 2:
		if (s_lessHP->TestClick(x, y) && sw_lessHP->GetStatus())
			s_lessHP->MouseReleased(x, y);

		if (s_lessSpeed->TestClick(x, y) && sw_lessSpeed->GetStatus())
			s_lessSpeed->MouseReleased(x, y);

		if (s_lessAttack->TestClick(x, y) && sw_lessAttack->GetStatus())
			s_lessAttack->MouseReleased(x, y);

		break;

	case 3:
		if (s_obstacleHP->TestClick(x, y) && sw_obstacle->GetStatus())
			s_obstacleHP->MouseReleased(x, y);

		break;
	default:
		break;
	}

	//----------------------------------------------------------------------

	if (m_imageOnScreen) { //atualiza o atributo do objeto com o valor do switch e do slider
		object->SetProtection(sw_protection->GetStatus(), s_protection->GetValue());
		object->SetHeal(sw_healing->GetStatus(), s_heal->GetValue());
		object->SetSpeed(sw_speed->GetStatus(), s_speed->GetValue());
		object->SetAttack(sw_attack->GetStatus(), s_attack->GetValue());
		object->SetTime(sw_time->GetStatus(), s_time->GetValue());

		object->SetLessHP(sw_lessHP->GetStatus(), s_lessHP->GetValue());
		object->SetLessSpeed(sw_lessSpeed->GetStatus(), s_lessSpeed->GetValue());
		object->SetLessAttack(sw_lessAttack->GetStatus(), s_lessAttack->GetValue());

		object->SetObstacle(sw_obstacle->GetStatus(), s_obstacleHP->GetValue(), s_obs->GetValue());
	}

}

void Window_Editor::MouseDragged(int x, int y)
{
	switch (m_sliderControl) {
	case 1:
		if (s_protection->TestClick(x, y) && sw_protection->GetStatus()) //se o switch de objeto destrutivel estiver ativo
			s_protection->MouseDragged(x, y);

		if (s_heal->TestClick(x, y) && sw_healing->GetStatus())
			s_heal->MouseDragged(x, y);

		if (s_speed->TestClick(x, y) && sw_speed->GetStatus())
			s_speed->MouseDragged(x, y);

		if (s_attack->TestClick(x, y) && sw_attack->GetStatus())
			s_attack->MouseDragged(x, y);

		if (s_time->TestClick(x, y) && sw_time->GetStatus())
			s_time->MouseDragged(x, y);

		break;

	case 2:
		if (s_lessHP->TestClick(x, y) && sw_lessHP->GetStatus())
			s_lessHP->MouseDragged(x, y);

		if (s_lessSpeed->TestClick(x, y) && sw_lessSpeed->GetStatus())
			s_lessSpeed->MouseDragged(x, y);

		if (s_lessAttack->TestClick(x, y) && sw_lessAttack->GetStatus())
			s_lessAttack->MouseDragged(x, y);

		break;

	case 3:
		if (s_obstacleHP->TestClick(x, y) && sw_obstacle->GetStatus())
			s_obstacleHP->MouseDragged(x, y);

		if (s_obs->TestClick(x, y) && sw_obstacle->GetStatus())
			s_obs->MouseDragged(x, y);
		break;
	default:
		break;
	}
}

void Window_Editor::MousePressed(int x, int y, Window_Manager * window_manager)
{
	if (btn_changeSliders->TestClick(x, y)) { //alterar sliders que são vistos na tela
		m_sliderControl++;
		if (m_sliderControl == 4) {
			m_sliderControl = 1;
		}
	} 

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
		//bool result = ofSystemYesNoDialoge("Boop", "Are you sure you want to cancel?");
		//if (result) {
			if (GetImageOnScreen()) {  //se tiver imagem de objeto na tela, deleta objeto e volta pro menu
				delete object;
				SetImageOnScreen(false);
				window_manager->SetState(0);
				//cout << result;
			}
			/*else
				window_manager->SetState(0);*/
		//}
	}

	if (btn_saveObject->TestClick(x, y)) {
		if (GetImageOnScreen()) {
			ofFileDialogResult result = ofSystemSaveDialog("default.png", "Save");
			if (result.bSuccess) {
				string imgPath = result.getPath();
				ofstream arquivo(imgPath + ".json"); //cria um novo arquivo com o nome que o usuario der pro objeto
				ofSaveImage(object->m_image.getPixelsRef(), imgPath + ".png");

				arquivo << "{" << endl
					<< "\"SpriteName\": " << imgPath << "," << endl //salva o path da imagem no arquivo

					<< "\"ObjType\": " << m_sliderControl << "," << endl //salva o tipo de objeto

					//<< "\"Duration\": " << s_ << "," << endl
					<< "\"Protection\": " << s_protection->GetValue() << "," << endl      //salva valor protecao
					<< "\"Healing\": " << s_heal->GetValue() << "," << endl               //salva valor heal
					<< "\"SpeedIncrease\": " << s_speed->GetValue() << "," << endl		  //salva valor velocidade
					<< "\"AtackIncrease\": " << s_attack->GetValue() << "," << endl       //salva valor ataque
					<< "\"TimeDecrease\": " << s_time->GetValue() << "," << endl          //salva valor tempo

					<< "\"HPDecrease\": " << s_lessHP->GetValue() << "," << endl          //salva valor tirar vida
					<< "\"SpeedDecrease\": " << s_lessSpeed->GetValue() << "," << endl    //salva valor tirar velocidade
					<< "\"AtackDecrease\": " << s_lessAttack->GetValue() << "," << endl   //salva valor tirar ataque

					//<< "\"Damage\": " << s_obstacleHP->GetValue() << endl   //salva valor vida objeto fixo 
				<< "}" << endl;

				arquivo.close(); //fecha o arquivo
				// save your file to `path`
				ofSystemAlertDialog("Object saved successfully!");
				SetImageOnScreen(false);
				window_manager->SetState(0);
			}
			else {
				ofSystemAlertDialog("Could not save current object!");
			}
		}
		/*else
			ofSystemAlertDialog("There is no image!");*/
	}

	if (m_imageOnScreen) //TODAS AS CONFIG DE IMAGEM AQUI!!!!!!!
	{
		/*-----  APARENCIA DO OBJETO  -----*/
		if (btn_changeObjectColor->TestClick(x, y)) //se click for no botão CHANGE e objeto estiver na tela
		{
			// object->PlusColor();
			object->ChangeColor(colorPicker.getColor());
		}

		/*if (btn_changeObjectSat->TestClick(x, y)) //se click for no botão CHANGE e objeto estiver na tela
		{
			object->PlusSatu();
			object->ChangeSatu();
		}*/

		/*-----  ATRIBUTOS  -----*/
		switch (m_sliderControl) {
		case 1:
			//proteção
			if (sw_protection->TestClick(x, y)) {
				sw_protection->MouseClicked(x, y);
				if (!sw_protection->GetStatus())
					s_protection->DeactivateSlider();
			}
			//qntde de proteção
			else if (s_protection->TestClick(x, y))
				if (sw_protection->GetStatus()) //...e o switch de objeto destrutivel estiver ativo
					s_protection->MouseClicked(x, y);

			//DA HEAL
			if (sw_healing->TestClick(x, y)) {
				sw_healing->MouseClicked(x, y);
				if (!sw_healing->GetStatus())
					s_heal->DeactivateSlider();
			}
			//QUANTO DE HEAL
			else if (s_heal->TestClick(x, y))
				if (sw_healing->GetStatus())
					s_heal->MouseClicked(x, y);

			//velocidade
			if (sw_speed->TestClick(x, y)) {
				sw_speed->MouseClicked(x, y);
				if (!sw_speed->GetStatus())
					s_speed->DeactivateSlider();
			}
			//qtde de velocidade
			else if (s_speed->TestClick(x, y))
				if (sw_speed->GetStatus())
					s_speed->MouseClicked(x, y);

			//ataque
			if (sw_attack->TestClick(x, y)) {
				sw_attack->MouseClicked(x, y);
				if (!sw_attack->GetStatus())
					s_attack->DeactivateSlider();
			}
			//qtde de ataque
			else if (s_attack->TestClick(x, y))
				if (sw_attack->GetStatus())
					s_attack->MouseClicked(x, y);

			//tempo
			if (sw_time->TestClick(x, y)) {
				sw_time->MouseClicked(x, y);
				if (!sw_time->GetStatus())
					s_time->DeactivateSlider();
			}
			//qtde de tempo
			else if (s_time->TestClick(x, y))
				if (sw_time->GetStatus())
					s_time->MouseClicked(x, y);

			break;

		case 2:
			//tirar vida
			if (sw_lessHP->TestClick(x, y)) {
				sw_lessHP->MouseClicked(x, y);
				if (!sw_lessHP->GetStatus())
					s_lessHP->DeactivateSlider();
			}
			//qtde de vida tirada
			else if (s_lessHP->TestClick(x, y))
				if (sw_lessHP->GetStatus())
					s_lessHP->MouseClicked(x, y);

			//tirar velocidade
			if (sw_lessSpeed->TestClick(x, y)) {
				sw_lessSpeed->MouseClicked(x, y);
				if (!sw_lessSpeed->GetStatus())
					s_lessSpeed->DeactivateSlider();
			}
			//qtde de velocidade tirada
			else if (s_lessSpeed->TestClick(x, y))
				if (sw_lessSpeed->GetStatus())
					s_lessSpeed->MouseClicked(x, y);

			//tirar ataque
			if (sw_lessAttack->TestClick(x, y)) {
				sw_lessAttack->MouseClicked(x, y);
				if (!sw_lessAttack->GetStatus())
					s_lessAttack->DeactivateSlider();
			}
			//qtde de ataque tirada
			else if (s_lessAttack->TestClick(x, y))
				if (sw_lessAttack->GetStatus())
					s_lessAttack->MouseClicked(x, y);

			break;

		case 3:
			//tirar ataque
			if (sw_obstacle->TestClick(x, y)) {
				sw_obstacle->MouseClicked(x, y);
				if (!sw_obstacle->GetStatus())
					s_obstacleHP->DeactivateSlider();
			}
			//qtde de ataque tirada
			else if (s_obstacleHP->TestClick(x, y))
				if (sw_obstacle->GetStatus())
					s_obstacleHP->MouseClicked(x, y);
			else if (s_obs->TestClick(x, y))
				if (sw_obstacle->GetStatus())
					s_obs->MouseClicked(x, y);
			break;
		default:
			break;
		}
		
	}
}

void Window_Editor::Draw()
{
	ofSetColor(0, 0, 0); //setando cor para preto
	ofDrawRectangle(0, 0, 502, 768); //retangulo preto representando onde o desenho do objeto ficará
	ofSetColor(255, 255, 255); //voltando cores ao normal

	ofSetBackgroundColor(35, 35, 35);

	btn_cancel->Draw(); //chamando função de desenho do botão CANCEL
	btn_loadSprite->Draw(); //chamando função de desenho do botão LOAD SPRITE

	if (GetImageOnScreen()) //se a imagem estiver na tela
	{
		btn_saveObject->Draw();
		btn_changeObjectColor->Draw();
		//btn_changeObjectSat->Draw();
		btn_changeSliders->Draw();

		if (object->GetH() < MAX_HEIGHT && object->GetW() < MAX_WIDTH) //se a imagem estiver dentro das medidas máximas
			object->Draw();
		else {
			ofSystemAlertDialog("The selected image is too large. Please choose another.");
			std::cout << "Imagem grande d+++. escolha outra" << std::endl; //se for muito grande, escolher outra img
			SetImageOnScreen(false);
		}

		switch (m_sliderControl) {
		case 1:
			s_protection->Draw();
			sw_protection->Draw();
			s_heal->Draw();
			sw_healing->Draw();
			s_speed->Draw();
			sw_speed->Draw();
			s_attack->Draw();
			sw_attack->Draw();
			s_time->Draw();
			sw_time->Draw();
			break;
		case 2:
			s_lessHP->Draw();
			sw_lessHP->Draw();
			s_lessSpeed->Draw();
			sw_lessSpeed->Draw();
			s_lessAttack->Draw();
			sw_lessAttack->Draw();
			break;
		case 3:
			s_obstacleHP->Draw();
			sw_obstacle->Draw();
			s_obs->Draw();
			break;
		default:
			break;
		}

		colorPicker.draw();
	}
}

void Window_Editor::Update()
{
	/*update da paleta de cores*/
	colorPicker.update();
	ofColor colorTop = colorPicker.getColor();
	//---------------------------------------
}

void Window_Editor::SetImageOnScreen(bool imageOnScreen)
{
	m_imageOnScreen = imageOnScreen;
}

bool Window_Editor::GetImageOnScreen()
{
	return m_imageOnScreen;
}

int Window_Editor::GetSliderControl()
{
	return m_sliderControl;
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