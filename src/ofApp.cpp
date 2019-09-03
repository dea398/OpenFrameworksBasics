//Most of the things comming from the books and from https://github.com/lewislepton/openFrameworksTutorialSeries


#include "ofApp.h"

bool pendulo = false;
bool shapes = false;
bool shapes3D = false;
bool images = false;
bool texts = true;
bool fonts = true;
bool audios = true;
bool keyboarding = true;
bool vertexes = false;


void ofApp::ifPenduloSetup()
{
	//Set initial values
	pos0 = ofPoint(512, 300);
	pos = ofPoint(600, 200);
	velocity = ofPoint(100, 0);
}

void ofApp::ifPenduloUpdate()
{
	//Constants
	float dt = 1.0 / 60.0;         //Time step
	float mass = 0.1;              //Mass of a ball
	float rubberLen = 200.0;       //Segment's length
	float k = 0.5;                 //Segment's stiffness
	ofPoint g(0.0, 9.8);         //Gravity force

	//Compute Hooke's force
	ofPoint delta = pos - pos0;
	float len = delta.length();   //Vector's length
	float hookeValue = k * (len - rubberLen);
	delta.normalize();            //Normalize vector's length
	ofPoint hookeForce = delta * (-hookeValue);

	//Update velocity and pos
	ofPoint force = hookeForce + g;  //Resulted force
	ofPoint a = force / mass;        //Second Newton's law
	velocity += a * dt;              //Euler method
	pos += velocity * dt;            //Euler method

}

void ofApp::ifPenduloDraw()
{

	//Draw rubber as a blue line
	ofSetColor(0, 0, 255);                //Set blue color
	ofDrawLine(pos0.x, pos0.y, pos.x, pos.y); //Draw line

	//Draw ball as a red circle
	ofSetColor(255, 0, 0);                //Set red color
	ofFill();                               //Enable filling
	ofDrawCircle(pos.x, pos.y, 20);           //Draw circle

}



void ofApp::ifShapes()
{
	ofNoFill();
	
	ofDrawRectangle(64, 64, 64, 64);
	ofDrawCircle(192, 96, 32);
	ofDrawLine(256, 64, 320, 128);
	ofDrawTriangle(352, 128, 384, 64, 416, 128);
	ofFill();
	ofDrawEllipse(512, 96, 128, 64);
	ofDrawRectRounded(608, 64, 64, 64, 9);
	
	//ofDrawBezier(704, 64, 736, 128, 768, 160, 800, 64);
}

void ofApp::if3DShapes()
{
	ofNoFill();
	ofDrawBox(64, 256, 0, 64, 64, 64);
	ofDrawCone(160, 256, 0, 32, 128);
	ofDrawCylinder(256, 256, 32, 128);
	ofDrawIcoSphere(352, 256, 0, 32);
	ofDrawPlane(448, 256, 64, 64);
	ofDrawSphere(544, 256, 32);
}

void ofApp::ifImageSetup()
{
	image.load("images/spaceship3.png");

	if (keyboarding)
	{
		x = ofGetWidth() / 2 - image.getWidth() / 2;
		y = ofGetHeight() / 2 - image.getHeight() / 2;
	}
}

void ofApp::ifImage()
{
	ofSetColor(255, 255, 255);
	if (keyboarding)
	{
		image.draw(x, y);
	}
	else
	{
		image.draw(ofGetWidth() / 2 - image.getWidth() / 2, ofGetHeight() / 2 - image.getHeight() / 2);
	}
	
	image.resize(200, 200);
}

void ofApp::ifText()
{
	ofSetColor(255,0,0);
	//no es mucho lo que podamos controlar
	ofDrawBitmapString("Hello World", 300, 300);
}

void ofApp::ifFontSetup()
{
	//https://www.1001freefonts.com/

	//Aunque la clase se llama ofTrueTypeFont soporta OpenType
	//Cambiar por GistLight.otf
	font.load("fonts/Transformers.ttf", 32);

	text = "Hello from Computer Graphics";
}

void ofApp::ifFont()
{
	font.drawString(text, ofGetWidth() / 2 - font.stringWidth(text) / 2, ofGetHeight() / 2 - font.stringHeight(text) / 2);
}

void ofApp::ifAudioSetup()
{
	backgroundSound.load("audios/drumloop.wav");
	backgroundSound.setVolume(0.4);
	backgroundSound.play();
	backgroundSound.setLoop(true);
	backgroundSound.setSpeed(1.2);
}

void ofApp::ifKeyboardingSetup()
{
	bulletSound.load("audios/bullet.wav");
	bulletSound.setVolume(1.0);
	bulletSound.setLoop(false);
	bulletSound.setMultiPlay(true);
}

void ofApp::ifVertex()
{
	//ofNoFill();
	ofBeginShape();
		ofVertex(200, 135);
		ofVertex(15, 135);
		ofVertex(165, 25);
	ofEndShape();
}


//--------------------------------------------------------------
void ofApp::setup()
{
	//Set screen frame rate
	ofSetFrameRate(60);

	//Set white background
	ofBackground(0, 0, 0);

	if (pendulo)
	{
		ifPenduloSetup();
	}
	if (images || keyboarding)
	{
		ifImageSetup();
	}
	if (fonts)
	{
		ifFontSetup();
	}
	if (audios)
	{
		ifAudioSetup();
	}
	if (keyboarding)
	{
		ifKeyboardingSetup();
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (pendulo)
	{
		ifPenduloUpdate();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	
	if (pendulo)
	{
		ifPenduloDraw();
	}

	if (shapes)
	{
		ifShapes();
	}

	if (shapes3D)
	{
		if3DShapes();
	}

	if (images || keyboarding)
	{
		ifImage();
	}

	if (texts)
	{
		ifText();
	}

	if (fonts)
	{
		ifFont();
	}

	if (vertexes)
	{
		ifVertex();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (keyboarding)
	{
		switch (key)
		{
			case ofKey::OF_KEY_LEFT:
			{
				x -= 5;
				break;
			}
			case ofKey::OF_KEY_RIGHT:
			{
				x += 5;
				break;
			}
			case ' ':
			{
				bulletSound.play();
				break;
			}
			default:
				break;
		}
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
