#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

// change from class to struct to make everything public
struct card{
    sf::Texture cardTexture;
    sf::Sprite cardSprite;
    sf::Texture reverseTexture;
    sf::Sprite reverseSprite;
    bool cardClicked = false;
    int positionX;
    int positionY;
    string textureFilePath;
    card(string textureFilePath, int positionX, int positionY);
    bool cardClick(float positionX, float positionY);
    void drawCard(sf::RenderWindow &window);
};