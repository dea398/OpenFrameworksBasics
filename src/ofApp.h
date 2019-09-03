#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
	private:
		ofImage image;
		int x;
		int y;

		ofTrueTypeFont font;
		string text;

		ofSoundPlayer backgroundSound;
		ofSoundPlayer bulletSound;

		ofPoint pos0;			//Center of suspension
		ofPoint pos;			//Ball's position
		ofPoint velocity;		//Ball's velocity


	public:
		void ifPenduloSetup();
		void ifPenduloUpdate();
		void ifPenduloDraw();
		void ifShapes();
		void if3DShapes();
		void ifImageSetup();
		void ifImage();
		void ifText();
		void ifFontSetup();
		void ifFont();
		void ifAudioSetup();
		void ifKeyboardingSetup();
		void ifVertex();

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
		
};
