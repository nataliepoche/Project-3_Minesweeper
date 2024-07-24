//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace std;
//
//void createWelcomeText(sf::Text &welcome, sf::Font &font, sf::RenderWindow &title){
//    welcome.setFont(font);
//    welcome.setString("WELCOME TO MINESWEEPER!");
//    welcome.setCharacterSize(24);
//    //text.scale(0.2,0.2);
//    welcome.setFillColor(sf::Color::White);
//    welcome.setStyle(sf::Text::Underlined);
//    welcome.setStyle(sf::Text::Bold);
//
//    // center text
//    welcome.setOrigin(welcome.getPosition().x/2.0f,welcome.getPosition().y/2.0f);
//    welcome.setPosition(title.getSize().x/4.25f, title.getSize().y/4.0f);
////    sf::FloatRect textBounds = text.getGlobalBounds();
////    text.setOrigin((textBounds.left + textBounds.width)/2.0f, (textBounds.top + textBounds.height)/2.0f);
////    text.setPosition(title.getSize().x/2.0f, title.getSize().y/0.2f);
//}
//void createName(sf:: Text &name, sf::Font &font, sf::RenderWindow &title){
//    name.setFont(font);
//    name.setString("Enter your name:");
//    name.setCharacterSize(24);
//    //text.scale(0.2,0.2);
//    name.setFillColor(sf::Color::White);
//
//    // center text
//    name.setOrigin(name.getPosition().x/2.0f,name.getPosition().y/2.0f);
//    name.setPosition(title.getSize().x/3.0f, title.getSize().y/3.0f);
//}
//
//int main() {
//    // talks about a new object, calling a parameterized constructor
//    sf::RenderWindow title(sf::VideoMode(600, 600), "Minesweeper!");
//
//    // create font
//    sf::Font font;
//    if(!font.loadFromFile("files/font.ttf")){
//        cout << "Failed to load font" << endl;
//        return 1;
//    }
//
//    // create text object
//    sf::Text welcome;
//    createWelcomeText(welcome, font, title);
//
//    sf::Text name;
//    createName(name, font, title);
//
//    while(title.isOpen()) {
//        sf::Event event;
//        while(title.pollEvent(event)) {
//            if(event.type == sf::Event::Closed) {
//                title.close();
//            }
//        }
//
//        title.clear(sf::Color::Blue);
//        title.draw(welcome); // draws the text
//        title.draw(name);
//        title.display();
//    }
//    return 0;
//}