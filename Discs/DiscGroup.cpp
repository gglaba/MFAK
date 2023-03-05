#include "DiscGroup.h"


DiscGroup::DiscGroup() {
	gpts = NULL; 
}

void DiscGroup::setGravity(vector<glm::vec3>* attract)
{
	gpts = attract; //ustawia wektor punktów grawitacji na podany wektor attract 
}

void DiscGroup::reset() //resetowanie dysku do losowych wartosci poczatkowych, tarcie = 0, masa,skala,promien i opor powietrza ustawione losowo,kolor dysku zalezny od predkosci i masy
{
	position.x = ofRandomWidth() ;
	position.y = ofRandomHeight();
	position.z = 0;

	velocity.x = ofRandom(-5.f, 5.f);
	velocity.y = ofRandom(-5.f, 5.f);
	velocity.z = 0;

	friction = glm::vec3(0, 0, 0);
	mass = ofRandom(1.0, 10.0);

	scale = ofRandom(1, 2.0);
	r = ofRandom(1.0, 3.5);
	drag = ofRandom(0.9, 0.998);

	color.g = velocity.x * 100.f * mass;
	color.b = fmod(color.g, 200.0f);
	color.r = 100.f * mass;


}

void DiscGroup::update()
{
    if (gpts)
    {
        glm::vec3 closestPt;
        int closest = -1;
        float closestDist = 9999999;

        for (unsigned int i = 0; i < gpts->size(); i++)
        {
            float lenSq = glm::length2(gpts->at(i) - position);
            if (lenSq < closestDist)
            {
                closestDist = lenSq;
                closest = i;

                if (closest != -1)
                {
                    closestPt = gpts->at(closest);
                    float dist = sqrt(closestDist);
                    glm::vec3 dir = (closestPt - position) / dist;

                    float G = 6.67428e-11; //sta³a grawitacji
                    float m1 = mass; //masa dysku
                    float m2 = 999999999999; //masa punktu przyci¹gania
                    glm::vec3 force = (G * (m1 * m2) / dist) * dir; //si³a grawitacji ze wzoru Newtona


                    if (position.x < ofGetWidth() / 3) { //je¿eli dysk znajduje siê w 1/3 ekranu po lewej stronie to liczê si³ê oporu uwzglêdniaj¹c lepkoœæ cieczy
                        glm::vec3 res = -6.0 * 3.14159 * velocity * viscosity * r;
                        acceleration = (force + res) / mass; // a = F/m
                    }
                    else
                    {
                        acceleration = force / mass; //jezeli dysk znajduje sie w pozostalej czesci ekranu to licze przyspieszenie uwzgledniajac jedynie sile grawitacji, wzor: a=F/m
                    }
                }
                    velocity += acceleration * dt; //aktualizuje predkosc dysku
                
                }
            }
        }

    position += velocity * dt; //aktualizuje pozycje dysku

    //ni¿ej odbijanie kulek od krawêdzi
    if (position.x > ofGetWidth()) {
        position.x = ofGetWidth();
        velocity.x *= -1.0;
    }
    else if (position.x < 0) {
        position.x = 0;
        velocity.x *= -1.0;
    }
    if (position.y > ofGetHeight()) {
        position.y = ofGetHeight();
        velocity.y *= -1.0;
    }
    else if (position.y < 0) {
        position.y = 0;
        velocity.y *= -1.0;
    }
}




void DiscGroup::draw()
{
	ofSetColor(color.r, color.g, color.b);
	ofDrawCircle(position.x, position.y, scale * r);

}


