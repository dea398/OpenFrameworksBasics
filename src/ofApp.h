#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Circle.h"

class ofApp : public ofBaseApp
{
	private:
		ofImage image;
		int x;
		int y;

		ofSpherePrimitive sphere;

		ofTrueTypeFont font;
		string text;

		ofSoundPlayer backgroundSound;
		ofSoundPlayer bulletSound;

		ofPoint pos0;			//Center of suspension
		ofPoint pos;			//Ball's position
		ofPoint velocity;		//Ball's velocity

		ofxPanel gui;

		ofParameterGroup sliderGroup;

		ofParameter<int> intSlider;

		ofParameter<float> floatSlider;

		Circle circle;

		ofParameterGroup mainGroup;

		ofVideoGrabber camera;

		ofFbo fbo;

	public:
		void ifPenduloSetup();
		void ifPenduloUpdate();
		void ifPenduloDraw();
		void ifShapes();
		void if3DShapes();
		void if3dShapesWireFrame();
		void ifImageSetup();
		void ifImage();
		void ifText();
		void ifFontSetup();
		void ifFont();
		void ifAudioSetup();
		void ifKeyboardingSetup();
		void ifVertex();

		void ifEnablingSmoothing();

		void ifEnablingSmoothingSetup();

		void ifWorkingOfParameterSetup();

		void ifWorkingOfParameter();

		void ifWorkingOfParameterUpdate();

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
		
		void ifWorkingWithOfPushMatrix1();

		void ifWorkingWithOfPushMatrix2();

		void ifLiveCameraSetup();

		void ifLiveCameraUpdate();

		void ifLiveCamera();

		void ifFboSetup();

		void ifFbo();

};
