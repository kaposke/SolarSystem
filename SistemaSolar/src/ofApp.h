#pragma once
#define STARS 500
#define G 20

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	class Ball
	{
	public:
		ofVec2f pos;
		ofVec2f dir;
		ofVec2f vel;
		ofVec2f dist;

		float mass;
		float radius;

		Ball()
		{}

		Ball(ofVec2f pos_, ofVec2f vel_,float mass_, float r)
		{
			pos = pos_;
			vel = vel_;
			mass = mass_;
			radius = r;
		}

		void update(Ball target, float area)
		{
			dist = target.pos - pos;
			dir = dist.normalized();
			float distance = target.pos.distance(pos);
			float atraction = target.mass * mass * G / (distance * distance);
			vel += dir * atraction;
			pos += vel;
		}
	};

	Ball sun;
	Ball sunArea;
	Ball earth;
	Ball earthArea;
	Ball moon;
	Ball moonArea;

	Ball stars[STARS];

	vector<Ball> meteoros;

	int segundos;
};
