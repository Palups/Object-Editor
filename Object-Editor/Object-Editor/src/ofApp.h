#pragma once

#include "ofMain.h"
//add include do UI novamente (acho)
#include "Window_Manager.h"
#include "Window_Menu.h"
#include "Window_Editor.h"
#include "ofxColorPicker.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Window_Manager *window_manager; //declarando window_manager
		Window_Menu *window_menu; //declarando window_menu
		Window_Editor *window_editor; //declarando window_editor

};
