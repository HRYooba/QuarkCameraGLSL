#pragma once

#include "ofMain.h"

#define TEMP_MAX 16
#define INDEX_MAX 1920*1080*3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    int width;
    int height;
    unsigned char pixelsBuffer[INDEX_MAX];
    
    ofVideoGrabber camera;
    ofTexture camBuffer[TEMP_MAX];
    ofShader quarkShader;
    ofFbo quarkFbo;
};
