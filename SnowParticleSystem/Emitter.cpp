#include "Emitter.h"
#include "Snow.h"

//konstruktor
Emitter::Emitter(size_t maxParticlesCount) : maxPnumber(maxParticlesCount), particles(std::vector<std::shared_ptr<Particle>>()) {}

//inicjalizuje czasteczki sniegu
void Emitter::SnowInit(uint32_t particlesCount) {
	for(int i = 0; i < particlesCount; i++) {
		add(std::make_shared<Snow>(
			Snow(ofVec3f(ofRandom(-5000.f, 5000.f), ofRandom(10.f, 400.f), ofRandom(-5000.f, 5000.f)),ofVec3f(),ofColor(255, 255, 255),ofRandom(0.5f, 2.f),ofVec3f(0, 0, 0))));
	}
}
//aktualizuje stan czasteczek
void Emitter::update(float deltaTime) {
	for(uint32_t i = 0; i < particles.size(); i++) {
		std::shared_ptr<Particle> particle = particles.at(i);

		if(particle->isToRemove() && particle->getLife() <= 0.f) {
			if(particle->isReviveAfterDeath()) {
				particle->setPosition(ofVec3f(ofRandom(-500.f, 500.f), ofRandom(10.f, 500.f), ofRandom(-500.f, 500.f)));
				particle->setIsToRemove(false);
			} else {
				particles.erase(particles.begin() + i);
			}
			continue;
		}


		particle->update(deltaTime, forces);
	}
}
//wyswietlanie
void Emitter::draw() {
	for(uint32_t i = 0; i < particles.size(); i++) {
		std::shared_ptr<Particle> particle = particles.at(i);
		particle->draw();
	}
}
//dodawanie obiektow do emitera
void Emitter::add(std::shared_ptr<Particle> particle) {
	particles.push_back(particle);
}
//dodawanie sil
void Emitter::addF(std::shared_ptr<glm::vec3> force) {
	forces.push_back(force);
}
//resetuje sily
void Emitter::resetForces() {
	this->forces.clear();
}
//usuwanie czasteczek
void Emitter::clear() {
	particles.clear();
}
//dodawanie obiektu do emitera
void Emitter::addObject(std::shared_ptr<Object> character) {
	object.push_back(character);
}
