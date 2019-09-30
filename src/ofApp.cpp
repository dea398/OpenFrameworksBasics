//Most of the things comming from the books and from https://github.com/lewislepton/openFrameworksTutorialSeries


#include "ofApp.h"

bool pendulo = false;
bool shapes = false;
bool shapes3D = false;
bool images = false;
bool texts = false;
bool fonts = false;
bool audios = false;
bool keyboarding = false;
bool vertexes = false;
bool shapes3DWireframe = false;
bool enablingSmoothing = false;
bool workingOfParameter = false;
bool workingOfPushMatrix1 = false;
bool workingOfPushMatrix1WithOutPushPopMatrix = false;
bool workingOfPushMatrix2 = false;
bool liveCamera = false;
bool workingWithOffscreen = true;


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

void ofApp::if3dShapesWireFrame()
{
	ofSetColor(255, 255, 255, 255);
	sphere.drawWireframe();
	//ofNoFill();
	//sphere.draw();
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

void ofApp::ifEnablingSmoothing()
{
	ofDrawLine(64, 64, 256, 128);

	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 128);
}

void ofApp::ifEnablingSmoothingSetup()
{
	ofBackground(60);
	ofSetLineWidth(4.0);
	ofEnableSmoothing();
	
	ofSetCircleResolution(128);
}

void ofApp::ifWorkingOfParameterSetup()
{
	sliderGroup.setName("sliders");

	sliderGroup.add(intSlider.set("int slider", 3, 3, 64));

	sliderGroup.add(floatSlider.set("float slider", 32, 32, 256));

	circle.setup();

	mainGroup.add(circle.params);

	mainGroup.add(sliderGroup);

	gui.setup(mainGroup);
}

void ofApp::ifWorkingOfParameter()
{
	ofSetColor(circle.colors->x, circle.colors->y, circle.colors->z);
	ofDrawCircle(circle.x, circle.y, floatSlider);
	gui.draw();
}

void ofApp::ifWorkingOfParameterUpdate()
{
	ofSetCircleResolution(intSlider);
}

void ofApp::ifWorkingWithOfPushMatrix1()
{
	//stripePattern
	ofSetColor(ofColor::white);
	ofSetLineWidth(3.0);
	if (workingOfPushMatrix1WithOutPushPopMatrix)
	{
		for (int i = 0; i < 20; i++)
		{
			ofTranslate(i * 20, 0);
			ofLine(0, -100, 0, 100);
		}
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			ofPushMatrix();
			ofTranslate(i * 20, 0);
			ofLine(0, -100, 0, 100);
			ofPopMatrix();
		}
	}
	
}

void ofApp::ifWorkingWithOfPushMatrix2()
{
	//stripePattern 2
	ofSetColor(ofColor::white); 
	ofSetLineWidth(3.0); 
	ofNoFill(); 
	for (int i = -50; i < 50; i++) 
	{ 
		ofPushMatrix();  
		ofTranslate(i * 20, 0);  
		ofRotate(i * 5);  
		ofScale(6, 6);  
		ofTriangle(0, 0, -50, 100, 50, 100);  
		ofPopMatrix(); 
	}
}

void ofApp::ifLiveCameraSetup()
{
	camera.setDeviceID(0);  
	camera.setDesiredFrameRate(30);  
	camera.initGrabber(640, 480);
}

void ofApp::ifLiveCameraUpdate()
{
	if (camera.isInitialized()) 
		camera.update();
}

void ofApp::ifLiveCamera()
{
	if (camera.isInitialized())
	{ 
		ofSetColor(255);  
		camera.draw(0, 0, ofGetWidth()/2, ofGetHeight()/2); 
	}
}

void ofApp::ifFboSetup()
{
	fbo.allocate(ofGetWidth(), ofGetHeight());

	fbo.begin();

	ofClear(255);

	fbo.end();
}

void ofApp::ifFbo()
{
	fbo.begin();
	  ofSetColor(255);

	  ofDrawCircle(x, y, 16);


	fbo.end();

	fbo.draw(0, 0);
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
	if (shapes3DWireframe)
	{
		sphere.setGlobalPosition(250, 250, 0);
		sphere.set(200,100);
	}
	if (enablingSmoothing)
	{
		ifEnablingSmoothingSetup();
	}
	if (workingOfParameter)
	{
		ifWorkingOfParameterSetup();
	}

	if (liveCamera)
	{
		ifLiveCameraSetup();
	}
	if (workingWithOffscreen)
	{
		ifFboSetup();
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (pendulo)
	{
		ifPenduloUpdate();
	}

	if (workingOfParameter)
	{
		ifWorkingOfParameterUpdate();
	}
	if (liveCamera)
	{
		ifLiveCameraUpdate();
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

	if (shapes3DWireframe)
	{
		if3dShapesWireFrame();
	}

	if (enablingSmoothing)
	{
		ifEnablingSmoothing();
	}

	if (workingOfParameter)
	{
		ifWorkingOfParameter();
	}

	if (workingOfPushMatrix1)
	{
		ifWorkingWithOfPushMatrix1();
	}

	if (workingOfPushMatrix2)
	{
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		ifWorkingWithOfPushMatrix2();
		ofPopMatrix(); 	
	}

	if (liveCamera)
	{
		ifLiveCamera();
	}
	if (workingWithOffscreen)
	{
		ifFbo();
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
void ofApp::mouseDragged(int x, int y, int button)
{
	this->x = x;
	this->y = y;
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
