#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
private:
    SQLite::Database* db; //"*" is een pointer, dit is dus zelf geen object, maar een verwijzing naar het object in het geheugen. In de addon SQLite moet je een pointer gebruiken.
    
};
