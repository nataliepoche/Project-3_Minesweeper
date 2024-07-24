//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace std;
//
//void changeColorCircle(bool circleClicked, sf::CircleShape& shape){
//    if(circleClicked){
//        // changes color on click
//        shape.setFillColor(sf::Color(rand(),rand(),rand()));
//    }
//    if(!circleClicked){
//        shape.setFillColor(sf::Color(255,255,255));
//    }
//}
//
//int main() {
//    // talks about a new object, calling a parameterized default constructor
//    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Red);
//    shape.setPosition(200,200); // sets position of the circle
//    shape.setOrigin(100,100); // allows circle to be set in center
//
//    // Draw with loaded images
//    sf::Texture texturePikachu;
//    texturePikachu.loadFromFile("Images/Pokemon/pikachu.png");
//    sf::Sprite spritePikachu;
//    spritePikachu.setTexture(texturePikachu); // sets texture to draw
//    spritePikachu.scale(0.2,0.2); // scales
//
//    bool circleClicked = false;
//
//    // edits the shape
//    while(window.isOpen()) {
//        sf::Event event; // captures what's happening in the window
//        while(window.pollEvent(event)) { // when something happens in the window
//
//            // std::cout << "event" << std::endl;
//
//            if(event.type == sf::Event::Closed) {
//                window.close();
//            }
//            if(event.type == sf::Event::MouseButtonPressed){
//                sf::Mouse mouse;
//                int mousex = mouse.getPosition(window).x;
//                int mousey = mouse.getPosition(window).y;
//                if(shape.getGlobalBounds().contains(mousex,mousey)){ // record the bounds of the object
//                    circleClicked = !circleClicked;
//                }
//
//                changeColorCircle(circleClicked, shape);
//            }
//        }
//
//        // std::cout << "While the window is open" << std::endl;
//        spritePikachu.setColor(sf::Color(rand(),rand(),rand())); // color changing pikachu
//        window.clear(); // deletes anything in window
//        window.draw(shape); // draws the shape
//        // window.draw(texturePikachu); // textures are not a drawable object
//        window.draw(spritePikachu);
//        window.display(); // display the new drawing
//    }
//    return 0;
//}