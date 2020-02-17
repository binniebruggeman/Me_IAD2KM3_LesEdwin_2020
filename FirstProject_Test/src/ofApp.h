#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    private:
    SQLite::Database* db; //* is een pointer dat verwijst naar het object in het geheugen ipv een object, want in de addon SQLite moet je een pointer gebruiken
		
};
