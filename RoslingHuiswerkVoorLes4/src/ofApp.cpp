#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(50);
    
    //Upload een font (ttf bestand) in de bin/data folder van deze app. In dit geval verdana.ttf erin gezet. Het getal is de font size.
    font.load("verdana.ttf", 64);
    
    //Het stukje "try {} catch() {}"-code zorgt ervoor dat je errors in een leesbaar stukje tekst terug krijgt. Je eigen code stop je tussen de {} van het try-gedeelte.
    try {
        
        //Deze functie zoekt zelf het juiste path erbij, zodat je niet het hele path hoeft te typen
        string roslingDB = ofToDataPath("rosling_three.sqlite");
        
        //Moet aangemaakt worden omdat je een pointer gebruikt. Als je er geen SQLITE::OPEN_READWRITE achter zet, dus alleen movieDB, dan maakt hij hem automatisch read only; SQLite::OPEN_READONLY
        db = new SQLite::Database(roslingDB, SQLite::OPEN_READWRITE);
        
        //Om SQL-statements naar database te sturen. in dit geval vraag je alle informatie uit de tabel "population" op
        SQLite::Statement query(*db, "SELECT * FROM population");
        //Loop; geeft een volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). Dus: geef me de waarde van de huidige regel.
        while (query.executeStep()) { //
            ofLog() << query.getColumn("year") << " "
            << query.getColumn("nl") << " "
            << query.getColumn("au") << " "
            << query.getColumn("zh") << std::endl;
        }
        
        ofSetCircleResolution(50);
        
        //Upload een font (ttf bestand) in de bin/data folder van deze app. In dit geval verdana.ttf erin gezet. Het getal is de font size.
        font.load("verdana.ttf", 64);
        
    } catch(SQLite::Exception& e) {
        ofLog() << e.getErrorStr() << std::endl;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //Het stukje "try {} catch() {}"-code zorgt ervoor dat je errors in een leesbaar stukje tekst terug krijgt. Je eigen code stop je tussen de {} van het try-gedeelte.
    try {
        //Om SQL-statements naar database te sturen. in dit geval vraag je alle informatie uit de tabel "population" op
        SQLite::Statement query(*db, "SELECT * FROM population");
        //Loop; geeft een volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). Dus: geef me de waarde van de huidige regel.
        while (query.executeStep()) { //
            ofLog() << query.getColumn("year") << " "
            << query.getColumn("nl") << " "
            << query.getColumn("au") << " "
            << query.getColumn("zh") << std::endl;
            
            //Om een gelijkmatigere overgang te verkrijgen van de ene naar de andere waarde, in dit geval in stapjes van 5%. Lerp rekent in dit geval bij ieder stapje opnieuw 5% van de waarde uit.
            popNLLerpValue = ofLerp(popNLLerpValue, query.getColumn("nl").getInt(), 0.05);
            ofSetColor(ofColor::orange);
            ofDrawCircle(100,100, popNLLerpValue * 5);
            
            popAULerpValue = ofLerp(popAULerpValue, query.getColumn("au").getInt(), 0.05);
            ofSetColor(ofColor::yellow);
            ofDrawCircle(300,100, popAULerpValue * 5);
            
            popZHLerpValue = ofLerp(popZHLerpValue, query.getColumn("zh").getInt(), 0.05);
            ofSetColor(ofColor::red);
            ofDrawCircle(500,100, popZHLerpValue * 5);
            
            ofSetColor(ofColor::black);
            //lerp in steps of 10%, make lerpYear into an int, so that you won't get decimal values for the years
            lerpYear = ofLerp(lerpYear, query.getColumn("year").getInt(), 0.1);
            font.drawString(ofToString((int)lerpYear), 200, 500);
        }
        
        
        
    } catch(SQLite::Exception& e) {
        ofLog() << e.getErrorStr() << std::endl;
    }
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    
    //doe een select om data uit database te halen
    //Om SQL-statements naar database te sturen. in dit geval vraag je alle informatie uit de tabel "population" op
    SQLite::Statement query(*db, "SELECT * FROM population");
    
    while (query.executeStep()) { //
        ofLog() << query.getColumn("year") << std::endl;
        lerpYear= ofLerp(lerpYear, query.getColumn("year").getInt(), 0.1);
        lerpYear = ofMap(x, 0, ofGetWidth(), 0, 5);
    }

}
