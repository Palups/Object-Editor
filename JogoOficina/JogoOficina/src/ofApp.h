#pragma once
#include "Character.h"
#include "Hero.h"
#include "Enemy.h"
#include "Projectile.h"
#include "HeroBullet.h"
#include <time.h>
#include "Object.h"
#include "ofMain.h"
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	    Character* h = new Hero(ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2));
		ofVec2f destination = ofVec2f();
		vector<Character*> e;
		ofVec2f limit = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
		vector<ofVec2f> shot_dir;
		vector<Projectile*> shots;

		int e_number = 3;

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

		int Module(ofVec2f i, ofVec2f j) {
			int k = sqrt((i.x-j.x)*(i.x - j.x) + (i.y-j.y)*(i.y - j.y));
			return k;
		}

		
		Object *bau;
		
		
		
};
