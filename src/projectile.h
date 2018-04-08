#pragma once
#include "ofMain.h"

class Projectile {
public:
	ofPoint startingPosition;
	ofPoint currentPosition;

	ofVec2f startingVelocity;
	ofVec2f currentVelocity;
	
	float startingTime;

	const float gravityAcceleration = -9.8;
	float pixelsPerMeter = 1;

	float diameter = 50;

	static ofVec2f splitVelocity(float angle, float velocity) {

	}

	Projectile(ofPoint initialPosition, ofVec2f initialVelocity) {
		startingTime = ofGetElapsedTimef();
		startingPosition = initialPosition;
		startingVelocity = initialVelocity;
	}
	void update() {
		float ellapsedTime = ofGetElapsedTimef();
		float deltaT = ellapsedTime - startingTime;

		/*currentVelocity.y = getNewVelocity(startingPosition.y, gravityAcceleration, deltaT);
		currentVelocity.x = startingVelocity.x;*/

		currentPosition.y = startingPosition.y + getDeltaXfromAcceleration(startingVelocity.y, gravityAcceleration, deltaT)*pixelsPerMeter;
		currentPosition.x = startingPosition.x + getDeltaXfromAcceleration(startingVelocity.x, 0, deltaT)*pixelsPerMeter;


		//float yAxisChange = getDeltaX(startingVelocity.y,starting)


	}
	
	//Use the first kinematic equation to determine the single-axis position offset at a given time with the velocities at the start and end of that period
	static float getDeltaX(float v1, float v2, float deltaT) {
		return 0.5*(v1+v2)*deltaT;
	}

	//Use the second kinematic equation to determine the single-axis velocity at a given time with a constant acceleration
	static float getNewVelocity(float v1, float acceleration, float deltaT) {
		return v1 + acceleration*deltaT;
	}
	

	//Use the fourth kinematic equation to determine the single-axis position offset at a given time with a constant acceleration 
	static float getDeltaXfromAcceleration(float v1, float acceleration, float deltaT) {
		return v1*deltaT + 0.5*acceleration*pow(deltaT, 2);
	}
};