#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofFileDialogResult result = ofSystemLoadDialog("Load file");
	//if (result.bSuccess)
	//{
	/*LEITURA DE ARQUIVO*/
	//variaveis para salvar conteudo do arquivo
		string path = "C:\\Users\\maiki\\Source\\Repos\\Object-Editor\\Object-Editor\\Object-Editor\\bin\\data\\grafeno.txt"; 
		string imgPath;
		bool healing;
		int heal;
		bool breakable;
		int hp;
		bool damaging;
		int dmg;
		bool pushable;
		int kg;
		ifstream arquivo(path);
		//arquivo.open("grafeno.txt");
		for (int i = 1; i < 10; i++)
		{//seta o conteudo do arquivo nas variaveis
			switch (i)
			{
			case 1:
				getline(arquivo, imgPath);
				break;
			case 2:
				arquivo >> healing;
				break;
			case 3:
				arquivo >> heal;
				break;
			case 4:
				arquivo >> breakable;
				break;
			case 5:
				arquivo >> hp;
				break;
			case 6:
				arquivo >> damaging;
				break;
			case 7:
				arquivo >> dmg;
				break;
			case 8:
				arquivo >> pushable;
				break;
			case 9:
				arquivo >> kg;
			default:
				break;
			}
		}

		arquivo.close();
	/*Criar objetos usando as variaveis acima como parametros*/
		//Object ...;
	ofSetFrameRate(60);
	//definindo um lugar aleatório e criando inimigo nesse lugar
	srand(time(NULL));

	for (int i = 0; i < e_number; i++) {
		ofVec2f enemy_spawn = ofVec2f(rand() % ofGetWindowWidth(), rand() % ofGetWindowHeight());
		e.push_back(new Enemy(enemy_spawn));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	//update da posição do personagem, mantendo-o preso às bordas
	h->SetPos(destination, limit);

	//atualizando posição dos tiros
	for (int i = 0; i < shots.size(); i++) {
		shots[i]->SetPos(shot_dir[i], limit);

		//deletando tiros que saem das margens
		if (shots[i]->GetPos().x >= limit.x || shots[i]->GetPos().x <= 0 ||
			shots[i]->GetPos().y >= limit.y || shots[i]->GetPos().y <= 0) {
			delete(shots[i]);
			shots.erase(shots.begin() + i);
			shot_dir.erase(shot_dir.begin() + i);
		}
	}

	for (int i = 0; i < shots.size(); i++) {
		for (int j = 0; j < e.size(); j++) {
                if (Module(shots[i]->GetPos(), e[j]->GetPos()) < 5) {
				delete(shots[i]);
				shots.erase(shots.begin() + i);
				shot_dir.erase(shot_dir.begin() + i);
				delete(e[j]);
				e.erase(e.begin() + j);
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	//desenhando heroi
	ofSetColor(255);
	ofDrawCircle(h->GetPos(), 20);

	//desenhando inimigos
	for (int i = 0; i < e.size(); i++) {
		ofSetColor(255, 0, 0);
		ofDrawCircle(e[i]->GetPos(), 10);
	}

	//desenhando projéteis
	for (int i = 0; i < shots.size(); i++) {
		ofSetColor(0, 0, 255);
		ofDrawCircle(shots[i]->GetPos(), 5);
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//fazendo heroi se movimentar enquanto a tecla se manter pressionada
	if (key == 'W' || key == 'w')
		destination.y--;
	if (key == 'S' || key == 's')
		destination.y++;
	if (key == 'A' || key == 'a')
		destination.x--;
	if (key == 'D' || key == 'd')
		destination.x++;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	//fazendo heroi parar se a tecla for solta
	if (key == 'W' || key == 'w')
		destination.y = 0;
	if (key == 'S' || key == 's')
		destination.y = 0;
	if (key == 'A' || key == 'a')
		destination.x = 0;
	if (key == 'D' || key == 'd')
		destination.x = 0;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	//instanciando um novo tiro e definindo sua posição
	shot_dir.push_back(ofVec2f(x, y) - h->GetPos());
	shots.push_back(new HeroBullet(h->GetPos()));
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
