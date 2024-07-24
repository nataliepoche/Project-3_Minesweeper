#include <iostream>
#include <SFML/Graphics.hpp>
#include "card.h"
using namespace std;

card::card(string textureFilePath, int positionX, int positionY) {
    this->textureFilePath = textureFilePath;
    this->positionX = positionX;
    this->positionY = positionY;
}

bool card::cardClick(float positionX, float positionY) {
    if(cardSprite.getGlobalBounds().contains(positionX,positionY)){ // record the bounds of the object
        cardClicked = !cardClicked;
        //changeColorCircle(cardClicked, cardSprite);
        //changeCardCircle(cardClicked, cardSprite);
    }
    return cardClicked;
}

void card::drawCard(sf::RenderWindow &window) {
    if(!cardTexture.loadFromFile(textureFilePath)){
        cout << "Loading did not work" << endl;
    }
    cardSprite.setTexture(cardTexture);
    cardSprite.setScale(0.3,0.3);
    cardSprite.setPosition(positionX,positionY);

    if(!reverseTexture.loadFromFile("Images/cards/reverse.png")){
        cout << "Loading did not work" << endl;
    }
    reverseSprite.setTexture(reverseTexture);
    reverseSprite.setScale(0.3,0.3);
    reverseSprite.setPosition(positionX,positionY);
    if(cardClicked){
        window.draw(reverseSprite);
    }
    if(!cardClicked){
        window.draw(cardSprite);
    }
}
