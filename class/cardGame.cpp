//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace std;
//
//void changeColorCircle(bool circleClicked, sf::Sprite& shape){
//    if(circleClicked){
//        // changes color on click
//        shape.setColor(sf::Color(rand(),rand(),rand()));
//    }
//    if(!circleClicked){
//        shape.setColor(sf::Color(255,255,255));
//    }
//}
//void drawPikachu(sf::Sprite &spritePikachu, sf::Texture &texturePikachu){
//    texturePikachu.loadFromFile("Images/Pokemon/pikachu.png");
//    spritePikachu.setTexture(texturePikachu); // sets texture to draw
//    spritePikachu.scale(0.1,0.1); // scales
//}
//
//int main() {
//    // talks about a new object, calling a parameterized default constructor
//    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Works!");
//
//    vector<string> cardnames;
//
//    //2_of_clubs.png, 2_of_hearts.png, 2_of_diamonds.png, 2_of_spades.png
//    cardnames.push_back("Images/cards/2_of_clubs.png");
//    cardnames.push_back("Images/cards/2_of_hearts.png");
//    cardnames.push_back("Images/cards/2_of_diamonds.png");
//    cardnames.push_back("Images/cards/2_of_spades.png");
//
//    sf::Texture cardTexture;
//    sf::Sprite cardSprite;
//    if(!cardTexture.loadFromFile((cardnames[1]))){
//        cout << "Loading did not work" << endl;
//    }
//    cardSprite.setTexture(cardTexture);
//    cardSprite.setScale(0.3,0.3);
//    cardSprite.setPosition(0,0);
//
//
////    sf::CircleShape shape(100.f);
////    shape.setFillColor(sf::Color::Red);
////    shape.setPosition(200,200); // sets position of the circle
////    shape.setOrigin(100,100); // allows circle to be set in center
//
//    // Imitating the eraser behaviour in paint
//    //vector<sf::CircleShape> circle;
//    vector<sf::Sprite> pikachuVector;
//
//    // Draw with loaded images
//    sf::Texture texturePikachu;
//    sf::Sprite spritePikachu;
//    drawPikachu(spritePikachu, texturePikachu);
//
//    sf::Mouse mouse;
//
//    bool cardClicked = false;
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
//
//                int mousex = mouse.getPosition(window).x;
//                int mousey = mouse.getPosition(window).y;
//
//                sf::Sprite tempPikachu;
//
//                tempPikachu.setTexture(texturePikachu);
//                tempPikachu.setPosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
//                tempPikachu.setColor(sf::Color(rand(),rand(),rand()));
//                tempPikachu.setOrigin(50,50);// best because radius is 100
//                tempPikachu.scale(0.1,0.1);
//                pikachuVector.push_back(tempPikachu);
//
////                sf:: CircleShape temp(100.f);
////
////                temp.setPosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
////                temp.setFillColor(sf::Color(rand(),rand(),rand()));
////                temp.setOrigin(50,50);// best because radius is 100
////                circle.push_back(temp); // stores the newly created circle in the position
//
//                // spritePikachu.setPosition(mousex, mousey); // pikachu moves wherever you click the mouse
//                if(cardSprite.getGlobalBounds().contains(mousex,mousey)){ // record the bounds of the object
//                    cardClicked = !cardClicked;
//                    changeColorCircle(cardClicked, cardSprite);
//                }
//            }
//        }
//
//        spritePikachu.setPosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
//
//        // std::cout << "While the window is open" << std::endl;
//        window.clear(); // deletes anything in window
//
//        for(int i = 0; i < pikachuVector.size(); i++){
//            window.draw(pikachuVector[i]);
//        }
//
////        for(int i = 0; i < circle.size(); i++){
////            window.draw(circle[i]);
////        }
////       window.draw(shape); // draws the shape
//        // window.draw(texturePikachu); // textures are not a drawable object
//        window.draw(cardSprite);
//        window.draw(spritePikachu);
//        window.display(); // display the new drawing
//    }
//    return 0;
//}