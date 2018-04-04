#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	tank.position = ofPoint(100, 100);
	tank.setSize(100, 100);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	velocitySlider = gui->addSlider("Velocity (pixels/sec)", 0, 100);
	angleSlider = gui->addSlider("Angle", 0, 90);
}

//--------------------------------------------------------------
void ofApp::update(){
	/*for (auto projectile : projectiles) {
		projectile.update();
	}*/

	if (testProjectile != nullptr) {
		testProjectile->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawRectangle(tank);
	ofDrawCircle(tank.getCenter(), 5);

	ofDrawLine(tank.getCenter(), ofPoint(ofGetMouseX(), ofGetMouseY()));

	/*for (auto projectile : projectiles) {
		ofDrawCircle(projectile.currentPosition, 25);
	}*/

	if (testProjectile != nullptr) {
		std::cout << testProjectile->currentPosition << std::endl;
		ofDrawCircle(testProjectile->currentPosition, 25);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	//determine angle from tank center to mouse position
	float Vx = velocitySlider->getValue()*cos(angleSlider->getValue());
	float Vy = velocitySlider->getValue()*sin(angleSlider->getValue());
	
	
	testProjectile = new Projectile(tank.getCenter(), ofVec2f(Vx, Vy));

	//ayy lmao fuck memory management amirite?
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
