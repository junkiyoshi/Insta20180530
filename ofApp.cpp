#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetColor(239);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	
	int deg_span = 8;
	ofRotate(deg_span * 0.5f);

	float radius = 150;
	float small_radius = 0;
	for (int i = 0; radius < 330; i++) {

		if (small_radius == 0) {

			ofPoint p1 = ofPoint(radius * cos(0), radius * sin(0));
			ofPoint p2 = ofPoint(radius * cos(deg_span * DEG_TO_RAD), radius * sin(deg_span * DEG_TO_RAD));
			small_radius = p1.distance(p2) * 0.5;
		}

		for (int deg = 0; deg < 360 - deg_span; deg += deg_span) {

			float noise_value = ofMap(ofNoise(i * 0.1, deg * 0.02 + ofGetFrameNum() * 0.03), 0, 1, 1, 10);
			ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			for (int tmp_noise_value = 0; tmp_noise_value <= noise_value; tmp_noise_value += 2) {
				
				ofDrawCircle(point, small_radius * tmp_noise_value * 0.1);
			}
		}

		float next_small_radius = 0;
		float tmp_radius = radius;
		while (radius < tmp_radius + small_radius + next_small_radius) {

			ofPoint p1 = ofPoint(radius * cos(0), radius * sin(0));
			ofPoint p2 = ofPoint(radius * cos(deg_span * DEG_TO_RAD), radius * sin(deg_span * DEG_TO_RAD));
			next_small_radius = p1.distance(p2) * 0.5;

			radius += 0.1;
		}

		small_radius = next_small_radius;
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}