#include "Particle.h"

//konstruktor
Particle::Particle(ofVec3f position, ofVec3f acceleration, ofColor color, float size, ofVec3f direction) : position(position), acceleration(acceleration), color(color), size(size), direction(direction) {
    isRemovable = false;
}

void Particle::collide(float deltaTime){
}

bool Particle::isColliding(std::shared_ptr<Object> obj) { //
    return false;
}

void Particle::stop() {

}

ofVec3f Particle::getPosition() const { //getter pozycji
    return position;
}

void Particle::setPosition(ofVec3f position) { //setter pozycji
    this->position = position;
}


void Particle::setAcceleration(ofVec3f acceleration) { //setter przyspieszenia
    this->acceleration = acceleration;
}

float Particle::getLife() const { //getter czasu zycia czasteczki
    return lifeTime;
}

void Particle::setLife(float lifeTime) { //setter czasu zycia czasteczki
    this->lifeTime = lifeTime;
}

bool Particle::isToRemove() const {
    return isRemovable;
}

ofVec3f Particle::getAcceleration() const {
    return acceleration;
}

void Particle::setIsToRemove(bool isRemovable) {
    this->isRemovable = isRemovable;
}

ofColor Particle::getColor() const {
    return color;
}

bool Particle::isReviveAfterDeath() const {
    return comeback;
}

void Particle::setReviveAfterDeath(bool revive) {
    comeback = revive;
}

float Particle::getSize() const {
    return size;
}