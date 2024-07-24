#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "gameWindow.h"
using namespace std;
using namespace sf;

struct welcomeWindow{
    RenderWindow window;
    Font font;
    Text cursor;
    Text welcome;
    Text name;
    Text getName;
    string inputName;
    Event event;
    int width;
    int height;
    int col;
    int row;
    int tileCount;
    int mineCount;

    welcomeWindow(int &width, int &height, int &col, int &row, int &tileCount, int &mineCount){
        this->width = width;
        this->height = height;
        this->col = col;
        this->row = row;
        this->tileCount = tileCount;
        this->mineCount = mineCount;

        // creates the window
        window.create(VideoMode(width, height), "Minesweeper");

        // creates the font
        if(!font.loadFromFile("files/font.ttf")){
            cout << "Failed to load font" << endl;
        }

        createWelcomeText();
        createNamePrompt();

        while(window.isOpen()){
            keyPressed();
            createName();
            welcomeDisplay();
        }
    };

    void createWelcomeText(){
        welcome.setFont(font);
        welcome.setString("WELCOME TO MINESWEEPER!");
        welcome.setCharacterSize(24);
        //text.scale(0.2,0.2);
        welcome.setFillColor(sf::Color::White);
        welcome.setStyle(sf::Text::Underlined | sf::Text::Bold);

        // center text
        sf::FloatRect textRect = welcome.getGlobalBounds();
        welcome.setOrigin(textRect.left + textRect.width/2.0f, textRect.top+textRect.height/2.0f);
        welcome.setPosition(window.getSize().x/2.0f, (window.getSize().y/2.0f)-150);
    }

    void createNamePrompt(){
        name.setFont(font);
        name.setString("Enter your name:");
        name.setCharacterSize(20);
        //text.scale(0.2,0.2);
        name.setFillColor(sf::Color::White);
        name.setStyle(sf::Text::Bold);

        // center text
        sf::FloatRect textRect = name.getGlobalBounds();
        name.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
        name.setPosition(window.getSize().x/2.0f, (window.getSize().y/2.0f)-75);
    }

    void keyPressed(){
        while(window.pollEvent(event)){

            if(event.type == Event::Closed){
                window.close();
            }

            else if(event.type == Event::TextEntered){
                if(event.text.unicode == '\b'){ // backspace
                    if(!inputName.empty()){
                        inputName.pop_back();
                    }
                }

                else if(event.text.unicode == '\r'){
                    if(!inputName.empty()){
                        window.close();
                        gameWindow game(width, height, col, row, tileCount, mineCount, inputName);
                    }
                }

                else if(event.text.unicode < 128){ // ASCII characters
                    if(isalpha(event.text.unicode) || isspace(event.text.unicode)){
                        if(inputName.empty()){
                            inputName += toupper(static_cast<char>(event.text.unicode));
                        }
                        else if((inputName.size() < 10)){
                            inputName += static_cast<char>(event.text.unicode);
                        }
                    }
                }
            }
        }
    }

    void createName(){
        getName.setFont(font);
        getName.setString(inputName + "|");
        getName.setCharacterSize(18);
        getName.setFillColor(sf::Color::Yellow);
        getName.setStyle(sf::Text::Bold);

        // center text
        sf::FloatRect textRect = getName.getLocalBounds();
        getName.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
        getName.setPosition(window.getSize().x/2.0f, (window.getSize().y/2.0f)-45);
    }

    void welcomeDisplay(){
        window.clear(sf::Color::Blue);
        window.draw(welcome); // draws the text
        window.draw(name);
        window.draw(cursor);
        window.draw(getName);
        window.display();
    }
};