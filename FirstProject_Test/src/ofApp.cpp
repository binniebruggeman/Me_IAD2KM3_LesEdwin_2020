#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    try {
        
        string movieDB = ofToDataPath("kmovies.sqlite"); //functie zoekt zelf het juiste path erbij, zodat je niet het hele path hoeft te typen
    
        db = new SQLite::Database(movieDB, SQLite::OPEN_READWRITE); //moet aangemaakt worden omdat je pointer gebruikt, als je er geen SQLITE::OPEN_READWRITE achter zet, dus alleen movieDB, dan maakt hij hem automatisch: SQLite::OPEN_READONLY
    
        SQLite::Statement query(*db, "SELECT * FROM movies"); //om SQL-statements naar database te sturen, dit levert lijst op met alle movies erin
        while (query.executeStep()) { //
            ofLog() << query.getColumn("code") << " "
                    << query.getColumn("title") << std::endl; //geef me de volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). 'Loop' erdoorheen. Dus; geef me de waarde van de huidige regel.
        }
    
        int result = db->exec("UPDATE movies Set rating='NC-17' WHERE title='Avatar'"); //methode aanroepen op de db class, gebruik "->" ipv "." omdat het een pointer is
        ofLog() << "result = " << result << std::endl;
    
        //om SQL-statements naar database te sturen, dit levert lijst op met alle movies erin
        SQLite::Statement query2(*db, "SELECT * FROM movies");
        //geef me de volgende rij terug, totdat je bij laatste rij aangekomen bent (zonder dit stukje code krijg je je resultaten niet te zien). 'Loop' erdoorheen. Dus; geef me de waarde van de huidige regel.
        while (query2.executeStep()) { //
            ofLog() << query2.getColumn("code") << " "
                    << query2.getColumn("title")
                    << query2.getColumn("rating") <<
                    std::endl;
        }
    
    } catch(SQLite::Exception& e) {
        ofLog() << e.getErrorStr() << std::endl;
        } //het stukje try catch code zorgt ervoor dat je de error in een leesbaar stukje tekst terug krijgt.
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

}


