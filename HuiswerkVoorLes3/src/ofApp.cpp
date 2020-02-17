#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Het stukje "try {} catch() {}"-code zorgt ervoor dat je errors in een leesbaar stukje tekst terug krijgt. Je eigen code stop je tussen de {} van het try-gedeelte.
    try {
        
        //Deze functie zoekt zelf het juiste path erbij, zodat je niet het hele path hoeft te typen
        string movieDB = ofToDataPath("kmovies.sqlite");
        
        //Moet aangemaakt worden omdat je een pointer gebruikt. Als je er geen SQLITE::OPEN_READWRITE achter zet, dus alleen movieDB, dan maakt hij hem automatisch read only; SQLite::OPEN_READONLY
        db = new SQLite::Database(movieDB, SQLite::OPEN_READWRITE);
        
        //Om SQL-statements naar database te sturen, dit levert een lijst op met alle codes en titles van de movies.
        SQLite::Statement query(*db, "SELECT * FROM movies");
        //Loop; geeft een volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). Dus: geef me de waarde van de huidige regel.
        while (query.executeStep()) { //
            ofLog() << query.getColumn("code") << " "
            << query.getColumn("title") << std::endl;
        }
        
        //Methode aanroepen op de db class, gebruikt "->" ipv "." omdat het een pointer is. Hier zet je de rating van de movie Avatar op NC-17
        int result = db->exec("UPDATE movies Set rating='NC-17' WHERE title='Avatar'");
        ofLog() << "result = " << result << std::endl;
        
        //Om SQL-statements naar database te sturen, levert een lijst op met de codes, titles en ratings van alle movies.
        SQLite::Statement query2(*db, "SELECT * FROM movies");
         //Loop; geeft een volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). Dus: geef me de waarde van de huidige regel.
        while (query2.executeStep()) { //
            ofLog() << query2.getColumn("code") << " "
            << query2.getColumn("title")
            << query2.getColumn("rating") <<
            std::endl;
        }
        
    } catch(SQLite::Exception& e) {
        ofLog() << e.getErrorStr() << std::endl;
    }
  
    
    
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}


