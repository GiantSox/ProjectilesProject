#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	tank.position = ofPoint(0, 100);
	tank.setSize(100, 100);
	
	target.setPosition(500, 100);
	target.setSize(200, 100);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	velocitySlider = gui->addSlider("Velocity (pixels/sec)", 0, 100);
	angleSlider = gui->addSlider("Angle", 0, 90);
	gui->addSlider("Vx", 0, 100);
	gui->addSlider("Vy", 0, 100);

	gui->onSliderEvent(this, &ofApp::sliderHandler);

	ofSetVerticalSync(true);
}

void ofApp::sliderHandler(ofxDatGuiSliderEvent e) {

}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto projectile : projectiles) {
		projectile->update();

		ofPoint circleCenter = projectile->currentPosition;
		ofPoint rectCenter = target.getCenter();
		float rectWidth = target.getWidth();
		float rectHeight = target.getHeight();

		//First, find closest point to circle on rectangle
		float nearestRectX = std::max(rectCenter.x, std::min(circleCenter.x, rectCenter.x + rectWidth));
		float nearestRectY = std::max(rectCenter.y, std::min(circleCenter.y, rectCenter.y + rectHeight));
		float distance = ofDist(circleCenter.x, circleCenter.y, nearestRectX, nearestRectY);

		if (distance < projectile->diameter / 2) {
			target.hit = true;
			target.hitTime = ofGetElapsedTimef();
		}
	}
	if (target.hit && ofGetElapsedTimef() > target.hitTime + 3) {
		target.setPosition(ofRandom(ofGetWidth()-target.width, tank.getCenter().x + tank.width), 100);
		target.hit = false;
	}

	/*if (testProjectile != nullptr) {
		testProjectile->update();
	}*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofRectangle flippedTank = tank;
	flippedTank.setFromCenter(ofPoint(tank.getCenter().x, ofGetHeight() - tank.getCenter().y), tank.width, tank.height);
	ofDrawRectangle(flippedTank);

	ofPushStyle();
	ofSetColor(255, 0, 0);
	if (target.hit) ofSetColor(0, 255, 0);
	ofRectangle flippedTarget = target;
	flippedTarget.setFromCenter(ofPoint(target.getCenter().x, ofGetHeight() - target.getCenter().y), target.width, target.height);
	ofDrawRectangle(flippedTarget);
	ofPopStyle();

	//ofDrawLine(flippedTank.getCenter(), ofPoint(ofGetMouseX(), ofGetMouseY()));

	/*for (auto projectile : projectiles) {
		ofDrawCircle(projectile.currentPosition, 25);
	}*/

	for(auto projectile : projectiles) {
		ofPushStyle();
		ofSetColor(0);
		ofPoint flippedProjectile = ofPoint(projectile->currentPosition.x, ofGetHeight() - projectile->currentPosition.y);
		ofDrawCircle(flippedProjectile, 25);
		ofPopStyle();
	}
	
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		projectiles.clear();
	}
	if (key == 32) {	//spacebar
		//determine angle from tank center to mouse position
		float theta = DEG_TO_RAD*angleSlider->getValue();
		float V = velocitySlider->getValue();
		float Vx = V*cos(theta);
		float Vy = V*sin(theta);

		//float Vx = gui->getSlider("Vx")->getValue();
		//float Vy = gui->getSlider("Vy")->getValue();

		std::cout << "Vx: " << Vx << std::endl;
		std::cout << "Vy: " << Vy << std::endl;


		Projectile *p = new Projectile(tank.getCenter(), ofVec2f(Vx, Vy));
		std::cout << p->startingVelocity << std::endl;
		projectiles.push_back(p);
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
