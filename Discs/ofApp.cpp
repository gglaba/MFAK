#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { //inicjalizacja
	gui.setup(); //inicjalizacja interfejsu,suwaków itd.
	gui.add(deltTimeSlider.setup("Delta time value", 0.15, 0.001, 1));
	gui.add(gravityX.setup("Gravity point - x coord.", 0, 1, 1024));
	gui.add(gravityY.setup("Gravity point - Y coord.", 0, 1, 768));
	gui.add(numSlider.setup("Number of spheres", 0, 1, 2000));
	gui.add(setGPoint.setup("Set Gravity Point"));
	gui.add(reset.setup("RESET"));
	gui.add(viscoSlider.setup("Viscosity", 1.0e-1, 1.0e-5, 0.1));

	ofSetVerticalSync(true);
	num = 2000;
	spheres.assign(num, DiscGroup()); //tworze wektor dyskow skladajacy sie na num ilosc obiektow

	SphereReset();
}

void ofApp::SphereReset() 
{
	gPoints.clear();//usuwanie punktów grawitacji

	for (unsigned int i = 0; i < spheres.size(); i++) { //resetowanie dyskow
		spheres[i].setGravity(&gPoints);
		spheres[i].reset();
	}
}

//--------------------------------------------------------------
void ofApp::update() { //aktualizowanie
	for (unsigned int i = 0; i < spheres.size(); i++) {
		spheres[i].dt = deltTimeSlider; // nadaje dyskom wartosci suwaków
		spheres[i].viscosity = viscoSlider;
		spheres[i].update(); //wywoluje update kazdego dysku
	}

	int ypos = gravityY;
	int	xpos = gravityX;

	if (setGPoint) // po kliknieciu przycisku tworzy punkt grawitacji i nadaje go kazdemu dyskowi
	{
		gPoints.push_back(glm::vec3(xpos, ypos, 0));
		for (unsigned int i = 0; i < spheres.size(); i++) {
			spheres[i].setGravity(&gPoints);
		}
	}



	if (reset)
	{
		SphereReset(); //resetuje dyski po wcisnieciu przycisku reset
	}

	if (numSlider != spheres.size())
	{
		spheres.clear();
		spheres.assign(numSlider, DiscGroup()); //zmienia ilosc dyskow w zaleznosci od wybranej liczby na sliderze
		SphereReset();
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{ //rysuje dyski i punkty grawitacji
	ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 10));

	ofSetColor(110, 200, 111);
	ofNoFill();
	ofDrawRectangle(0, 0, ofGetWidth() / 3, ofGetHeight());
	ofFill();

	for (unsigned int i = 0; i < spheres.size(); i++) { 

		spheres[i].draw();
		
	}
	int x = gravityX;
	int y = gravityY;
	ofSetColor(255, 255, 0);
	ofDrawCircle(x, y, 12);

	ofSetColor(255, 0, 0);
	for (unsigned int i = 0; i < gPoints.size(); i++) {
		ofDrawCircle(gPoints[i], 15);
	}
	ofSetColor(230);


	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
