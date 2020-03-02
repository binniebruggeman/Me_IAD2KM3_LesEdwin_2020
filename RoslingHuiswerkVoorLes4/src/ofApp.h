#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseMoved(int x, int y );
    
private:
    SQLite::Database* db; //* is een pointer dat verwijst naar het object in het geheugen ipv een object, want in de addon SQLite moet je een pointer gebruiken

    
    //Variabele met de naam "font", waarin je het font laadt (ttf bestand). dat je in de bin/data folder van deze app hebt gezet, in dit geval verdana.ttf
    ofTrueTypeFont font;
    
    int selectedYearIndex = 0;
    
    //Deze data wordt uit de database gehaald/opgevraagd
    int lerpYear;
    int popAULerpValue;
    int popNLLerpValue;
    int popZHLerpValue;
    
    
    
    
};
