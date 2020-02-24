#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
    
    //Upload a font (ttf file) into the bin/data directory, in this case I uploaded a verdana font
    font.load("verdana.ttf", 64);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //Instead of jumping from 1 value to the other, it will gradually go from 1 value to the other in steps of 5%
    popNLLerpValue = ofLerp(popNLLerpValue, population_NL[selectedYearIndex], 0.05);
    ofSetColor(ofColor::orange);
    ofDrawCircle(100,100, popNLLerpValue * 5);
    
    popAULerpValue = ofLerp(popAULerpValue, population_AU[selectedYearIndex], 0.05);
    ofSetColor(ofColor::yellow);
    ofDrawCircle(300,100, popAULerpValue * 5);
    
    popZHLerpValue = ofLerp(popZHLerpValue, population_ZH[selectedYearIndex], 0.05);
    ofSetColor(ofColor::red);
    ofDrawCircle(500,100, popZHLerpValue * 5);
    
    ofSetColor(ofColor::black);
    //lerp in steps of 10%, make lerpYear into an int, so that you won't get decimal values for the years
    lerpYear = ofLerp(lerpYear, years[selectedYearIndex], 0.1);
    font.drawString(ofToString((int)lerpYear), 200, 500);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    selectedYearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);
    //doe een select om data uit database te halen

}


