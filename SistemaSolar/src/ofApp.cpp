#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(60);
	sun.pos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	sun.radius = 50;
	sun.mass = 100;

	sunArea.pos = sun.pos;
	sunArea.radius = 350;

	earth.pos = sun.pos + ofVec2f(200, 0);
	earth.radius = 20;
	earth.mass = 10;

	earthArea.pos = earth.pos;
	earthArea.radius = 100;

	moon.pos = earth.pos + ofVec2f(50, 0);
	moon.radius = 8;
	moon.mass = 2;

	moonArea.pos = moon.pos;
	moonArea.radius = 50;

	for (int i = 0; i < STARS; i++)
	{
		stars[i].pos = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
		stars[i].radius = ofRandom(1, 3);
	}

	segundos = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
	earth.pos.rotate(1.2, sun.pos);
	moon.pos.rotate(1.2, sun.pos);
	moon.pos.rotate(5, earth.pos);

	for (int i = 0; i < meteoros.size(); i++)
	{
		meteoros.at(i).update(sun, 350);
		meteoros.at(i).update(earth, 100);
		meteoros.at(i).update(moon, 50);
	}


	if (round(ofRandom(1, 30)) == 1)
	{
		int lado = round(ofRandom(1, 4));
		ofVec2f spawnPos;
		switch (lado)
		{
		case 1:
			spawnPos = ofVec2f(0, ofRandom(0,ofGetHeight()));
			meteoros.push_back(Ball(spawnPos, ofVec2f(ofRandom(1, 5), ofRandom(-5, 5)), ofRandom(1, 5), ofRandom(3, 10)));
			break;
		case 2:
			spawnPos = ofVec2f(ofGetWidth(), ofRandom(0, ofGetHeight()));
			meteoros.push_back(Ball(spawnPos, ofVec2f(ofRandom(-5, -1), ofRandom(-5, 5)), ofRandom(1, 5), ofRandom(3, 10)));
			break;
		case 3:
			spawnPos = ofVec2f(ofRandom(0, ofGetWidth()), 0);
			meteoros.push_back(Ball(spawnPos, ofVec2f(ofRandom(-5,5), ofRandom(1, 5)), ofRandom(1, 5), ofRandom(3, 10)));
			break;
			spawnPos = ofVec2f(ofRandom(0, ofGetWidth()), ofGetHeight());
			meteoros.push_back(Ball(spawnPos, ofVec2f(ofRandom(-5, 5), ofRandom(-5, -1)), ofRandom(1, 5), ofRandom(3, 10)));
			break;
		}
		
	}


	//destrutor de meteoros
	for (int i = meteoros.size(); i > 0; i--)
	{
		if (meteoros[i-1].pos.x < 0 || meteoros[i - 1].pos.x > ofGetWidth() || meteoros[i - 1].pos.y < 0 || meteoros[i - 1].pos.y > ofGetHeight()) {
			meteoros.erase(meteoros.begin() + i-1);
		}
	}
	for (int i = meteoros.size(); i > 0; i--)
	{
		if (meteoros[i - 1].pos.distance(sun.pos)<sun.radius + meteoros[i - 1].radius || meteoros[i - 1].pos.distance(earth.pos) < earth.radius + meteoros[i - 1].radius) {
			meteoros.erase(meteoros.begin() + i - 1);
		}
	}

	// oq aparece na segunda tela
	segundos = floor(ofGetFrameNum() / 60);

	system("CLS");
	cout << "Segundos: " << segundos << endl;
	cout << "Earth.pos = " << earth.pos << endl;
	cout << "fps: " << ofGetFrameRate() << endl;


}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);
	for (int i = 0; i < STARS; i++)
	{
		ofDrawCircle(stars[i].pos, stars[i].radius);
	}

	/*ofSetColor(0, 100, 150, 50);
	ofDrawCircle(sun.pos, sunArea.radius);
	ofDrawCircle(earth.pos, earthArea.radius);
	ofDrawCircle(moon.pos, moonArea.radius);*/

	ofSetColor(255, 150, 0);
	ofDrawCircle(sun.pos, sun.radius);

	ofSetColor(0, 0, 255);
	ofDrawCircle(earth.pos, earth.radius);

	ofSetColor(255);
	ofDrawCircle(moon.pos, moon.radius);


	ofSetColor(255, 0, 0);
	for (int i = 0; i < meteoros.size(); i++)
	{
		ofDrawCircle(meteoros[i].pos, meteoros[i].radius);
	}
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
