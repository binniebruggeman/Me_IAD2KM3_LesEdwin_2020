#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::orange);
    ofDrawCircle(100,100, population_NL[selectedYearIndex] * 5);
    
    ofSetColor(ofColor::yellow);
    ofDrawCircle(300,100, population_AU[selectedYearIndex] * 5);
    
    ofSetColor(ofColor::red);
    ofDrawCircle(500,100, population_ZH[selectedYearIndex] * 5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    selectedYearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);

}


