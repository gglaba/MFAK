#include "ofApp.h"


void ofApp::setup() { //ustawiam parametry
	ofSetBackgroundColor(0, 0, 0); //kolor t³a
	ofEnableLighting(); //oœwietlenie
	ofEnableDepthTest(); //g³êbia
	ofSetVerticalSync(false); 

	camera->init(); //inicjalizuje kamere

	//pêtla w której generuje i iloœæ choinek i i/2 iloœæ ba³wanów
	for (int i = 0; i < 10; i++)
	{
		ofSeedRandom(i*3427589);
		if (i % 2 == 0) //ograniczam liczbe balwanow
		{
			//tworzenie ba³wanka
			std::shared_ptr<Snowman> snowman = std::make_shared<Snowman>(Snowman(ofVec3f(ofRandom(-500, 500), 0, ofRandom(-500, 500)), ofColor(200, 200, 200)));
			objects.push_back(snowman);
			//dodanie ba³wanka do emitera
			p_emitter->addObject(snowman);
		}
		//tworzenie choinki
		std::shared_ptr<ChristmasTree> tree = std::make_shared<ChristmasTree>(ChristmasTree(ofVec3f(ofRandom(-1000,1000), 100, ofRandom(-1000,1000)), ofColor(1, 50, 32)));
		objects.push_back(tree);
		//dodanie choinki do emitera
		p_emitter->addObject(tree);

	}
	//inicjalizacja emitera cz¹steczek
	p_emitter->SnowInit(snowParticlesAmount);
	//dodaje si³y do emitera
	p_emitter->addF(std::make_shared<glm::vec3>(ofRandom(-.05, .05), 0.f, ofRandom(-.05, .05)));
	p_emitter->addF(std::make_shared<glm::vec3>(0.f, -0.981f, 0.f));
}

void ofApp::update() { //aktualizowanie stanu animacji
	float deltaTime = ofGetLastFrameTime(); //pobieram czas od ostatniej klatki
	for(auto& object : objects) //aktualizowanie obiektów
		object->update(deltaTime);

	p_emitter->update(deltaTime); //aktualizuje emiter sniegu

	dtChange -= deltaTime;
	if(dtChange <= 0) { //resetuje sily gdy force time sie konczy
		dtChange = 5.f;
		p_emitter->resetForces();
		p_emitter->addF(std::make_shared<glm::vec3>(ofRandom(-.005, .005), 0.f, ofRandom(-.005, .005)));
		p_emitter->addF(std::make_shared<glm::vec3>(0.f, -0.981f, 0.f));
	}
}

void ofApp::draw() {
	ofSetColor(255, 255, 255);
	camera->Begin(); //renderuje z kamera
	float  dt = ofGetElapsedTimef();
	for(auto& object : objects)
		object->draw(); //wyswietlam wszystkie obiekty

	p_emitter->draw(); //wyswietlam czasteczki
	ofSetColor(2, 48, 32);
	ofDrawBox(0, -5000, 0, 10000);//rysuje podloze
	std::make_unique<ofEasyCam>()->end();
}

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::reset() { //reset animacji
	p_emitter->clear();
	p_emitter->SnowInit(snowParticlesAmount);
}
