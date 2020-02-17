#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Het stukje "try {} catch() {}"-code zorgt ervoor dat je errors in een leesbaar stukje tekst terug krijgt. Je eigen code stop je tussen de {} van het try-gedeelte.
    try {
        
        //Deze functie zoekt zelf het juiste path erbij, zodat je niet het hele path hoeft te typen
        string movieDB = ofToDataPath("movies.sqlite");
        
        //Moet aangemaakt worden omdat je een pointer gebruikt. Als je er geen SQLITE::OPEN_READWRITE achter zet, dus alleen movieDB, dan maakt hij hem automatisch read only; SQLite::OPEN_READONLY
        db = new SQLite::Database(movieDB, SQLite::OPEN_READWRITE);
        
        //Om SQL-statements naar database te sturen. Hier vraag je naar de namen van de theatres en de titles van de movies, met als voorwaarde dat de code van de movies uit de tabel "movies" gelijk is aan de code van de movies uit de tabel "theatres". Op die manier krijg je alleen de namen van theaters te zien die een film draaien, met bijbehorende titel van de film die ze draaien.
        SQLite::Statement query(*db, "SELECT name, title FROM movies, theatres WHERE theatres.movie == movies.code;");
        //Loop; geeft een volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). Dus: geef me de waarde van de huidige regel.
                while (query.executeStep()) {
                    ofLog() << query.getColumn("name") << ": "
                    << query.getColumn("title")
                    << std::endl;
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


