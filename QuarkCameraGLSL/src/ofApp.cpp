#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Full HD
    width = 1920;
    height = 1080;
    
    //　カメラの初期設定
    camera.setVerbose(true);
    //    ofSetLogLevel(OF_LOG_VERBOSE);
    //    camera.listDevices();
    camera.setDeviceID(0);
    camera.initGrabber(width, height);
    
    for (int i = 0; i < TEMP_MAX; i ++) {
        camBuffer[i].allocate(width, height, GL_RGB);
    }
    quarkShader.load("", "shader/quark.frag");
    quarkFbo.allocate(width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    if ( camera.isFrameNew() ) {
        unsigned char *pixels = camera.getPixels();
        for (int i = 0; i < INDEX_MAX; i ++) {
            pixelsBuffer[i] = pixels[i];
        }
    }
    camBuffer[ofGetFrameNum() % TEMP_MAX].loadData(pixelsBuffer, width, height, GL_RGB);
    if (ofGetFrameNum() > TEMP_MAX) {
        quarkFbo.begin();
        quarkShader.begin();
        quarkShader.setUniform1f("u_TEMP_MAX", TEMP_MAX);
        quarkShader.setUniform1f("u_time", ofGetElapsedTimef() - (int)ofGetElapsedTimef());
        quarkShader.setUniformTexture("u_camera0", camBuffer[0], 0);
        quarkShader.setUniformTexture("u_camera1", camBuffer[1], 1);
        quarkShader.setUniformTexture("u_camera2", camBuffer[2], 2);
        quarkShader.setUniformTexture("u_camera3", camBuffer[3], 3);
        quarkShader.setUniformTexture("u_camera4", camBuffer[4], 4);
        quarkShader.setUniformTexture("u_camera5", camBuffer[5], 5);
        quarkShader.setUniformTexture("u_camera6", camBuffer[6], 6);
        quarkShader.setUniformTexture("u_camera7", camBuffer[7], 7);
        quarkShader.setUniformTexture("u_camera8", camBuffer[8], 8);
        quarkShader.setUniformTexture("u_camera9", camBuffer[9], 9);
        quarkShader.setUniformTexture("u_camera10", camBuffer[10], 10);
        quarkShader.setUniformTexture("u_camera11", camBuffer[11], 11);
        quarkShader.setUniformTexture("u_camera12", camBuffer[12], 12);
        quarkShader.setUniformTexture("u_camera13", camBuffer[13], 13);
        quarkShader.setUniformTexture("u_camera14", camBuffer[14], 14);
        quarkShader.setUniformTexture("u_camera15", camBuffer[15], 15);
        ofRect(0, 0, width, height);
        quarkShader.end();
        quarkFbo.end();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofScale(-1, 1);
    ofTranslate(-width, 0);
    quarkFbo.draw(0, 0);
    //    camBuffer[5].draw(0, 0);
    ofPopMatrix();
    
    stringstream ss;
    ss << "framerate: " << ofToString(ofGetFrameRate(), 0);
    ofDrawBitmapString(ss.str(), 10, 20);
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
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
