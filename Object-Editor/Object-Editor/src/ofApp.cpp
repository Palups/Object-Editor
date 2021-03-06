#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	window_manager = new Window_Manager(0); //criando window_manager iniciando pelo menu (0)
	window_menu = new Window_Menu(); //criando o menu
	window_editor = new Window_Editor(); //criando tela de edi��o
}

//--------------------------------------------------------------
void ofApp::update(){
	switch (window_manager->GetState()) {
	case WINDOW_MENU:
		//window_menu->Update();
		break;
	case WINDOW_EDITOR:
		window_editor->Update();
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (window_manager->GetState()) {
	case WINDOW_MENU:
		window_menu->Draw();
		break;
	case WINDOW_EDITOR:
		window_editor->Draw();
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (window_manager->GetState()) {
	case WINDOW_EDITOR:
		window_editor->KeyPressed(key);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	switch (window_manager->GetState()) {
	case WINDOW_EDITOR:
		window_editor->MouseDragged(x, y);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
		
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	switch (window_manager->GetState()) {
	case WINDOW_MENU:
		window_menu->MousePressed(x, y, window_manager);
		break;
	case WINDOW_EDITOR:
		window_editor->MousePressed(x, y, window_manager);
		window_editor->MouseReleased(x, y);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT); //n�o deixa alterar o tamanho da tela
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


