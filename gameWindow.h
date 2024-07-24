#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "leaderBoard.h"
#include <chrono>
using namespace std;
using namespace sf;

struct Images{
    Texture debugTexture;
    Texture digitsTexture;
    Texture happyTexture;
    Texture loseTexture;
    Texture winTexture;
    Texture flagTexture;
    Texture leaderboardTexture;
    Texture mineTexture;
    Texture oneTexture;
    Texture twoTexture;
    Texture threeTexture;
    Texture fourTexture;
    Texture fiveTexture;
    Texture sixTexture;
    Texture sevenTexture;
    Texture eightTexture;
    Texture pauseTexture;
    Texture playTexture;
    Texture hiddenTexture;
    Texture revealedTexture;

    Sprite debugSprite;
    Sprite digitsSprite;
    Sprite happySprite;
    Sprite loseSprite;
    Sprite winSprite;
    Sprite flagSprite;
    Sprite leaderboardSprite;
    Sprite mineSprite;
    // numbers
    Sprite pauseSprite;
    Sprite playSprite;
    Sprite hiddenSprite;
    Sprite revealedSprite;

    Images(){
        loadImages();
    };

    void loadTextures(){
        if(!debugTexture.loadFromFile("files/images/debug.png")){
            cout << "Error loading debug.png" << endl;
        }
        if(!digitsTexture.loadFromFile("files/images/digits.png")){
            cout << "Error loading digits.png" << endl;
        }
        if(!happyTexture.loadFromFile("files/images/face_happy.png")){
            cout << "Error loading face_happy.png" << endl;
        }
        if(!loseTexture.loadFromFile("files/images/face_lose.png")){
            cout << "Error loading face_lose.png" << endl;
        }
        if(!winTexture.loadFromFile("files/images/face_win.png")){
            cout << "Error loading face_win.png" << endl;
        }
        if(!flagTexture.loadFromFile("files/images/flag.png")){
            cout << "Error loading flag.png" << endl;
        }
        if(!leaderboardTexture.loadFromFile("files/images/leaderboard.png")){
            cout << "Error loading leaderboard.png" << endl;
        }
        if(!mineTexture.loadFromFile("files/images/mine.png")){
            cout << "Error loading mine.png" << endl;
        }
        if(!oneTexture.loadFromFile("files/images/number_1.png")){
            cout << "Error loading number_1.png" << endl;
        }
        if(!twoTexture.loadFromFile("files/images/number_2.png")){
            cout << "Error loading number_2.png" << endl;
        }
        if(!threeTexture.loadFromFile("files/images/number_3.png")){
            cout << "Error loading number_3.png" << endl;
        }
        if(!fourTexture.loadFromFile("files/images/number_4.png")){
            cout << "Error loading number_4.png" << endl;
        }
        if(!fiveTexture.loadFromFile("files/images/number_5.png")){
            cout << "Error loading number_5.png" << endl;
        }
        if(!sixTexture.loadFromFile("files/images/number_6.png")){
            cout << "Error loading number_6.png" << endl;
        }
        if(!sevenTexture.loadFromFile("files/images/number_7.png")){
            cout << "Error loading number_7.png" << endl;
        }
        if(!eightTexture.loadFromFile("files/images/number_8.png")){
            cout << "Error loading number_8.png" << endl;
        }
        if(!pauseTexture.loadFromFile("files/images/pause.png")){
            cout << "Error loading pause.png" << endl;
        }
        if(!playTexture.loadFromFile("files/images/play.png")){
            cout << "Error loading play.png" << endl;
        }
        if(!hiddenTexture.loadFromFile("files/images/tile_hidden.png")){
            cout << "Error loading tile_hidden.png" << endl;
        }
        if(!revealedTexture.loadFromFile("files/images/tile_revealed.png")){
            cout << "Error loading tile_revealed.png" << endl;
        }
    };

    void loadImages(){
        loadTextures();
        debugSprite.setTexture(debugTexture);
        digitsSprite.setTexture(digitsTexture);
        happySprite.setTexture(happyTexture);
        loseSprite.setTexture(loseTexture);
        winSprite.setTexture(winTexture);
        flagSprite.setTexture(flagTexture);
        leaderboardSprite.setTexture(leaderboardTexture);
        mineSprite.setTexture(mineTexture);
        pauseSprite.setTexture(pauseTexture);
        playSprite.setTexture(playTexture);
        hiddenSprite.setTexture(hiddenTexture);
        revealedSprite.setTexture(revealedTexture);
    }
};

struct Tile{
    float positionX;
    float positionY;
    Images images;
    int value;
    bool revealed;
    bool mine;
    bool flagged;
    vector<Tile*> adjacentTiles;
    Sprite hiddenSprite;
    Sprite revealedSprite;
    Sprite mineSprite;
    Sprite flaggedSprite;
    Sprite oneSprite;
    Sprite twoSprite;
    Sprite threeSprite;
    Sprite fourSprite;
    Sprite fiveSprite;
    Sprite sixSprite;
    Sprite sevenSprite;
    Sprite eightSprite;

    RenderWindow window;

    Tile(){
        value = 0;
        revealed = false;
        flagged = false;
    };
    Tile(int positionX, int positionY, int mineCount){
        value = 0;
        revealed = false;
        flagged = false;
        mine = false;
        this->positionX = positionX;
        this->positionY = positionY;

    }

    // Function to add neighboring tiles
    void addAdjacentTile(Tile *tile){
        adjacentTiles.push_back(tile);
    }
};

struct gameWindow{
    RenderWindow GameWindow;
    Event event;
    int totalSeconds;
    int width;
    int height;
    int row;
    int col;
    int tileCount;
    int mineCount;
    int possibleMines;
    bool lose = false;
    bool win = false;
    bool wincheck;
    string nameInput;
    string time;
    bool revealMines = false;
    bool pause = false;
    bool leaderBoardClicked = false;
    chrono::high_resolution_clock::time_point startTime = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point pauseTime = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point leaderpauseTime = chrono::high_resolution_clock::now();
    Tile tile;
    Images images;
    vector<vector<Tile*>>tiles;
    vector<Sprite*>imageTiles;
    Mouse mouse;

    gameWindow(int &width, int &height, int &col, int &row, int &tileCount, int &mineCount, string nameInput){
        leaderBoard leader(row, col, nameInput, time, win, wincheck);
        this->width = width;
        this->height = height;
        this->col = col;
        this->row = row;
        this->tileCount = tileCount;
        this->mineCount = mineCount;
        this->nameInput = nameInput;
        possibleMines = mineCount;
        bool leaderrun = false;
        for(int i = 0; i < col; i++){
            vector<Tile*> rows;
            for(int j = 0; j < row; j++){
                Tile* temp = new Tile(i * 32, j * 32, mineCount);
                rows.push_back(temp);
            }
            tiles.push_back(rows);
        }
        setMines();
        updateAdjacentTiles();
        updateAdjacentMineCount();

        // creates game window
        GameWindow.create(VideoMode(width, height), "Minesweeper");

        while(GameWindow.isOpen()){
            while(GameWindow.pollEvent(event)){
                if(event.type == Event::Closed){
                    GameWindow.close();
                }
                else if (event.type == Event::MouseButtonPressed){
                    if(event.mouseButton.button == Mouse::Right && !pause && !revealMines && !lose && !win && !leader.window.isOpen()){
                        tileClickRight(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y);
                    }

                    if(event.mouseButton.button == Mouse::Left && !pause && !lose && !win && !leader.window.isOpen()){
                        tileClickLeft(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y, leader);
                    }

                    if(images.pauseSprite.getGlobalBounds().contains(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y) && !pause && !lose && !win){
                        pause = true;
                        pauseTime = chrono::high_resolution_clock::now();
                    }

                    else if((images.playSprite.getGlobalBounds().contains(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y) && pause)){
                        pause = false;
                        auto currentTime = chrono::high_resolution_clock::now();
                        auto pauseDuration = currentTime - pauseTime;  // Calculate how long the game was paused
                        startTime += pauseDuration;
                    }

                    if(images.leaderboardSprite.getGlobalBounds().contains(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y)){
                        leaderBoardClicked = true;
                        leaderpauseTime = chrono::high_resolution_clock ::now();
                    }

                    if(images.debugSprite.getGlobalBounds().contains(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y)){
                        if(revealMines){
                            revealMines = false;
                        }
                        else if(!revealMines){
                            revealMines = true;
                        }
                    }

                    if(images.happySprite.getGlobalBounds().contains(mouse.getPosition(GameWindow).x, mouse.getPosition(GameWindow).y)){
                        resetBoard();
                    }
                }
            }

            boardDisplay(GameWindow, images, leader);
        }
    }

    void revealAdjacent(Tile* tile){
        tile->revealed = true;
        for(int i = 0; i < tile->adjacentTiles.size(); i++){
            if(!tile->adjacentTiles[i]->flagged && !tile->adjacentTiles[i]->mine && tile->adjacentTiles[i]->value == 0 && !tile->adjacentTiles[i]->revealed){
                revealAdjacent(tile->adjacentTiles[i]);
            }
            else if(!tile->adjacentTiles[i]->flagged && !tile->adjacentTiles[i]->mine && tile->adjacentTiles[i]->value > 0 && !tile->adjacentTiles[i]->revealed){
                tile->adjacentTiles[i]->revealed = true;
            }
        }
    }

    void checkWin(leaderBoard &leader){
        int check = 0;
        for(int i = 0; i < tiles.size(); i++){
            for(int j = 0; j < tiles[i].size(); j++){
                if((tiles[i][j]->mine || tiles[i][j]->revealed) && !tiles[i][j]->flagged){
                    check++;
                }
            }
        }
        if(check == tileCount){
            win = true;
            leader.readEntries();
            leader.updateLeaderboard(nameInput, time);
            wincheck = true;
        }
    }

    void drawTimer(int min1, int min2, int sec1, int sec2, int rows, int cols) {
        float baseX = (cols * 32);
        float baseY = 32 * (rows + 0.5) + 16;

        float minX = baseX - 97;
        float minY = baseY;

        float secX = baseX - 54;
        float secY = baseY;

        int digitsWidth = 21;

        char min1char = (char)('0' + min1);
        char min2char = (char)('0' + min2);
        char sec1char = (char)('0' + sec1);
        char sec2char = (char)('0' + sec2);
        time = to_string(min1) + to_string(min2) + ':' + to_string(sec1) + to_string(sec2);

        Sprite min1Sprite, min2Sprite, sec1Sprite, sec2Sprite;;
        min1Sprite.setTexture(images.digitsTexture);
        min1Sprite.setTextureRect(IntRect((min1char - '0') * digitsWidth, 0, digitsWidth, images.digitsTexture.getSize().y));
        min1Sprite.setPosition(minX, minY);
        GameWindow.draw(min1Sprite);

        min2Sprite.setTexture(images.digitsTexture);
        min2Sprite.setTextureRect(IntRect((min2char - '0') * digitsWidth, 0, digitsWidth, images.digitsTexture.getSize().y));
        min2Sprite.setPosition(minX + 21, minY);
        GameWindow.draw(min2Sprite);

        sec1Sprite.setTexture(images.digitsTexture);
        sec1Sprite.setTextureRect(IntRect((sec1char - '0') * digitsWidth, 0, digitsWidth, images.digitsTexture.getSize().y));
        sec1Sprite.setPosition(secX, secY);
        GameWindow.draw(sec1Sprite);

        sec2Sprite.setTexture(images.digitsTexture);
        sec2Sprite.setTextureRect(IntRect((sec2char - '0') * digitsWidth, 0, digitsWidth, images.digitsTexture.getSize().y));
        sec2Sprite.setPosition(secX + 21, secY);
        GameWindow.draw(sec2Sprite);
    }

    void updateTimer() {
        static int min1 = 0, min2 = 0, sec1 = 0, sec2 = 0;

        if (!pause && !lose && !leaderBoardClicked) {
            auto currentTime = chrono::high_resolution_clock::now();
            auto elapsed = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
            totalSeconds = elapsed.count();

            int minutes = (totalSeconds / 60) % 60;
            int seconds = totalSeconds % 60;

            min1 = minutes / 10;
            min2 = minutes % 10;
            sec1 = seconds / 10;
            sec2 = seconds % 10;

        }

        drawTimer(min1, min2, sec1, sec2, row, col);

    }

    void drawCounter(){
        // calculate width of each digit
        int digitWidth = 21;

        //position to draw digits
        float posX;
        float posY = 32 * (row + 0.5f) + 16.0f;

        // convert count to string
        string countStr;
        bool isNegative;

        // adjust starting position for negative counter
        if(possibleMines < 0){
            posX = 12.0f;
            countStr = to_string(abs(possibleMines));
            isNegative = true;
        }
        else{
            posX = 33.0f;
            countStr = to_string(possibleMines);
            while(countStr.size() <= 2){
                countStr = '0' + countStr;
            }
            isNegative = false;
        }

        // loop through each digit in the count
        for(int i = 0; i < countStr.size(); i++){
            if(isNegative){
                if(i == 0){
                    // Create sprite for negative sign
                    Sprite negativeSign;
                    negativeSign.setTexture(images.digitsTexture);

                    // Set texture rectangle for negative sign
                    negativeSign.setTextureRect(IntRect(10 * digitWidth, 0, digitWidth, images.digitsTexture.getSize().y));

                    // Set position of negative sign sprite
                    negativeSign.setPosition(posX, posY);

                    GameWindow.draw(negativeSign);
                    posX += digitWidth;
                }
            }

            int digitIndex = countStr[i] - '0';

            // create sprite for current digit
            Sprite digit;
            digit.setTexture(images.digitsTexture);

            // set texture rectangle
            digit.setTextureRect(IntRect(digitIndex * digitWidth, 0, digitWidth, images.digitsTexture.getSize().y));

            // set position of digit sprite
            digit.setPosition(posX, posY);

            GameWindow.draw(digit);

            posX += digitWidth;
        }
    }

    void drawTile(RenderWindow &window, bool debugClicked){
        for(int i = 0; i < tiles.size(); i++){
            for(int j = 0; j < tiles[i].size(); j++){
                if(!tiles[i][j]->revealed){
                    tiles[i][j]->hiddenSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->hiddenSprite.setTexture(images.hiddenTexture);
                    window.draw(tiles[i][j]->hiddenSprite);
                }
                else if(tiles[i][j]->revealed){
                    tiles[i][j]->revealedSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->revealedSprite.setTexture(images.revealedTexture);
                    window.draw(tiles[i][j]->revealedSprite);
                    if(tiles[i][j]->value == 1){
                        tiles[i][j]->oneSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->oneSprite.setTexture(images.oneTexture);
                        window.draw(tiles[i][j]->oneSprite);
                    }
                    else if(tiles[i][j]->value == 2){
                        tiles[i][j]->twoSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->twoSprite.setTexture(images.twoTexture);
                        window.draw(tiles[i][j]->twoSprite);
                    }
                    else if(tiles[i][j]->value == 3){
                        tiles[i][j]->threeSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->threeSprite.setTexture(images.threeTexture);
                        window.draw(tiles[i][j]->threeSprite);
                    }
                    else if(tiles[i][j]->value == 4){
                        tiles[i][j]->fourSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->fourSprite.setTexture(images.fourTexture);
                        window.draw(tiles[i][j]->fourSprite);
                    }
                    else if(tiles[i][j]->value == 5){
                        tiles[i][j]->fiveSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->fiveSprite.setTexture(images.fiveTexture);
                        window.draw(tiles[i][j]->fiveSprite);
                    }
                    else if(tiles[i][j]->value == 6){
                        tiles[i][j]->sixSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->sixSprite.setTexture(images.sixTexture);
                        window.draw(tiles[i][j]->sixSprite);
                    }
                    else if(tiles[i][j]->value == 7){
                        tiles[i][j]->sevenSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->sevenSprite.setTexture(images.sevenTexture);
                        window.draw(tiles[i][j]->sevenSprite);
                    }
                    else if(tiles[i][j]->value == 8){
                        tiles[i][j]->eightSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                        tiles[i][j]->eightSprite.setTexture(images.eightTexture);
                        window.draw(tiles[i][j]->eightSprite);
                    }
                }

                if(tiles[i][j]->flagged){
                    tiles[i][j]->flaggedSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->flaggedSprite.setTexture(images.flagTexture);
                    tiles[i][j]->hiddenSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->hiddenSprite.setTexture(images.hiddenTexture);
                    window.draw(tiles[i][j]->hiddenSprite);
                    window.draw(tiles[i][j]->flaggedSprite);
                }

                if(debugClicked && tiles[i][j]->mine){
                    tiles[i][j]->mineSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->mineSprite.setTexture(images.mineTexture);
                    tiles[i][j]->hiddenSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->hiddenSprite.setTexture(images.hiddenTexture);
                    window.draw(tiles[i][j]->hiddenSprite);
                    window.draw(tiles[i][j]->mineSprite);
                }
                if(lose && tiles[i][j]->mine){
                    tiles[i][j]->mineSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->mineSprite.setTexture(images.mineTexture);
                    tiles[i][j]->revealedSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->revealedSprite.setTexture(images.revealedTexture);
                    window.draw(tiles[i][j]->revealedSprite);
                    window.draw(tiles[i][j]->mineSprite);
                }

                if(win && tiles[i][j]->mine){
                    tiles[i][j]->flaggedSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->flaggedSprite.setTexture(images.flagTexture);
                    tiles[i][j]->hiddenSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->hiddenSprite.setTexture(images.hiddenTexture);
                    window.draw(tiles[i][j]->hiddenSprite);
                    window.draw(tiles[i][j]->flaggedSprite);
                }

                if(pause || leaderBoardClicked){
                    tiles[i][j]->revealedSprite.setPosition(tiles[i][j]->positionX, tiles[i][j]->positionY);
                    tiles[i][j]->revealedSprite.setTexture(images.revealedTexture);
                    window.draw(tiles[i][j]->revealedSprite);
                }
            }
        }
    }

    void tileClickLeft(float mouseX, float mouseY, leaderBoard &leader){
        for(int i = 0; i < tiles.size(); i++){
            for(int j = 0; j < tiles[i].size(); j++){
                if(tiles[i][j]->hiddenSprite.getGlobalBounds().contains(mouseX, mouseY) && !tiles[i][j]->flagged){
                    if(tiles[i][j]->mine){
                        lose = true;
                    }
                    else {
                        revealAdjacent(tiles[i][j]);
                    }
                }
            }
        }
        checkWin(leader);
    }

    void tileClickRight(float mouseX, float mouseY){
        for(int i = 0; i < tiles.size(); i++){
            for(int j = 0; j < tiles[i].size(); j++){
                if((tiles[i][j]->hiddenSprite.getGlobalBounds().contains(mouseX, mouseY) || tiles[i][j]->revealedSprite.getGlobalBounds().contains(mouseX, mouseY)) && !tiles[i][j]->revealed){
                    if(!tiles[i][j]->flagged){
                        tiles[i][j]->flagged = true;
                        possibleMines--;
                    }
                    else if(tiles[i][j]->flagged){
                        tiles[i][j]->flagged = false;
                        possibleMines++;
                    }
                }
            }
        }
    }

    void updateAdjacentTiles() {
        for (int i = 0; i < tiles.size(); i++) {
            for (int j = 0; j < tiles[i].size(); j++) {
                if (i > 0) {
                    tiles[i][j]->addAdjacentTile(tiles[i - 1][j]); // up

                    if (j > 0) {
                        tiles[i][j]->addAdjacentTile(tiles[i - 1][j - 1]); // up-left
                    }
                    if (j < tiles[i].size() - 1) {
                        tiles[i][j]->addAdjacentTile(tiles[i - 1][j + 1]); // up-right
                    }
                }

                if (i < tiles.size() - 1) {
                    tiles[i][j]->addAdjacentTile(tiles[i + 1][j]); // down
                    if (j > 0) {
                        tiles[i][j]->addAdjacentTile(tiles[i + 1][j - 1]); // down-left
                    }
                    if (j < tiles[i].size() - 1) {
                        tiles[i][j]->addAdjacentTile(tiles[i + 1][j + 1]); // down-right
                    }
                }
                if (j > 0) {
                    tiles[i][j]->addAdjacentTile(tiles[i][j - 1]); // left
                }
                if (j < tiles[i].size() - 1) {
                    tiles[i][j]->addAdjacentTile(tiles[i][j + 1]); // right
                }
            }
        }
    }

    void updateAdjacentMineCount() {
        for (int i = 0; i < tiles.size(); i++) {
            for(int j = 0; j < tiles[i].size(); j++){
                if(!tiles[i][j]->mine){
                    int count = 0;
                    for (int t = 0; t < tiles[i][j]->adjacentTiles.size(); t++) {
                        if (tiles[i][j]->adjacentTiles[t]->mine) {
                            count++;
                        }
                    }
                    tiles[i][j]->value = count;
                }
            }
        }
    }

    void resetBoard(){
        possibleMines = mineCount;
        for(int i = 0; i < tiles.size(); i++){
            startTime = chrono::high_resolution_clock::now();
            for(int j = 0; j < tiles[i].size(); j ++){
                tiles[i][j]->flagged = false;
                tiles[i][j]->mine = false;
                tiles[i][j]->revealed = false;
                tiles[i][j]->value = 0;
                tiles[i][j]->adjacentTiles.clear();
            }
        }
        setMines();
        updateAdjacentTiles();
        updateAdjacentMineCount();
        lose = false;
        win = false;
    }

    void setMines(){
        for(int i = 0; i < mineCount; i++){
            int randRow = (rand() % row);
            int randCol = (rand() % col);
            if(randRow >= 0 && randRow < row && randCol >= 0 && randCol < col){
                while(tiles[randCol][randRow]->mine){
                    randRow = (rand() % row);
                    randCol = (rand() % col);
                }
                tiles[randCol][randRow]->mine = true;
            }
        }
    }

    void setPositions(){
        images.loseSprite.setPosition(((col / 2.0f) * 32)-32, 32 * (row + 0.5f));
        images.winSprite.setPosition(((col / 2.0f) * 32)-32, 32 * (row + 0.5f));
        images.happySprite.setPosition(((col / 2.0f) * 32)-32, 32 * (row + 0.5f));
        images.debugSprite.setPosition((col * 32) - 304, 32 * (row + 0.5f));
        images.pauseSprite.setPosition((col * 32) - 240, 32 * (row + 0.5f));
        images.playSprite.setPosition((col * 32) - 240, 32 * (row + 0.5f));
        images.leaderboardSprite.setPosition((col * 32) - 176, 32 * (row + 0.5f));
        images.digitsSprite.setPosition(33, 32 * (row + .05f) + 16);
    };

    void boardDisplay(RenderWindow &GameWindow, Images &images, leaderBoard &leader){
        GameWindow.clear(Color::White);
        drawTile(GameWindow, revealMines);
        setPositions();
        if(!lose){
            if(win){
                GameWindow.draw(images.winSprite);
            }
            else if(!win){
                GameWindow.draw(images.happySprite);
            }
        }
        else if(lose){
            GameWindow.draw(images.loseSprite);
        }
        GameWindow.draw(images.debugSprite);
        if(pause){
            GameWindow.draw(images.playSprite);
        }
        else if(!pause){
            GameWindow.draw(images.pauseSprite);
        }
        GameWindow.draw(images.leaderboardSprite);
        drawCounter();
        updateTimer();
        GameWindow.display();
        if(leaderBoardClicked){
            leader.run(leaderBoardClicked);
            if(!pause){
                auto currentTime = chrono::high_resolution_clock ::now();
                auto pauseDuration = currentTime - leaderpauseTime;
                startTime += pauseDuration;
            }
        }
    }
};