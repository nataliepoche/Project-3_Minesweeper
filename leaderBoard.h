#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
using namespace std;
using namespace sf;

struct leaderBoardEntry{
    int totalSeconds;
    string time;
    string name;
    string newName;
    bool isNewEntry;

    leaderBoardEntry(string &time, string &name, bool isNewEntry) {
        if(time.size() != 5 || time[2] != ':'){
            cout << "Invalid time arguement for: " << time << endl;
        }
        else{
            string secondsStr = time.substr(3);
            string minStr = time.substr(0,2);
            totalSeconds = stoi(minStr) * 60 + stoi(secondsStr);
            this->time = time;
            this->isNewEntry = isNewEntry;
            if (isNewEntry) {
//                this->newName = " " + name + "*";
                this->name = " " + name + "*";
            }
            else {
                this->name = name;
            }
        }
    }
};

struct leaderBoard{
    RenderWindow window;
    Event event;
    int row;
    int col;
    int width;
    int height;
    string name;
    string time;
    int totalSeconds;
    vector<leaderBoardEntry>entries;
    vector<Text>names;
    Text titleText;
    Text text;
    Font font;
    string leaderBoardText;
    bool update = false;
    bool win;
    bool wincheck;

    leaderBoard();

    leaderBoard(int row, int col, string &name, string time, bool win, bool &wincheck){
        this->row = row;
        this->col = col;
        this->name = name;
        this->time = time;
        this->win = win;
        this->wincheck = wincheck;
        width = col * 16;
        height = (row * 16) + 50;

//        window.create(VideoMode(col * 16, (row * 16) + 50), "Minesweeeper");
//        while(window.isOpen()){
//            while(window.pollEvent(event)){
//                if(event.type == Event::Closed){
//                    window.close();
//                }
//            }
//            readEntries();
//            if(win && !update) {
//                cout << win << endl;
//                updateLeaderboard(name, time);
//                update = true;
//            }
//            setText();
//            window.clear(Color::Blue);
//            displayLeaderboard();
//            window.display();
//        }
    }

    void run(bool &leaderboardclicked){
        window.create(VideoMode(col * 16, (row * 16) + 50), "Minesweeeper");
        while(window.isOpen()){
            leaderboardclicked = true;
            while(window.pollEvent(event)){
                if(event.type == Event::Closed){
                    leaderboardclicked = false;
                    window.close();
                }
            }
            readEntries();
            if(!update && wincheck) {
                updateLeaderboard(name, time);
                win = false;
                update = true;
            }
            setText();
            window.clear(Color::Blue);
            displayLeaderboard();
            window.display();
        }
    };

    void readEntries(){
        entries.clear();
        ifstream leadFile("files/leaderboard.txt");
        if (leadFile.is_open()) {
            string singleLine, time, name;
            while (getline(leadFile, singleLine)) {
                istringstream stream(singleLine);
                getline(stream, time, ',');
                getline(stream, name);
                leaderBoardEntry entry(time, name, false);

                entries.push_back(entry);
            }
        }
        leadFile.close();
        sortEntries();
        writeEntries();
    }

    void updateLeaderboard(string &name, string &time){
        for(int i = 0; i < entries.size(); i++){
            if(entries[i].isNewEntry){
                entries[i].name.pop_back();
                entries[i].isNewEntry = false;
            }
        }
        writeEntries();
        readEntries();
        leaderBoardEntry newEntry(time, name, true);
        entries.push_back(newEntry);
        sortEntries();
        if(entries.size() > 5){
            entries.pop_back();
        }
        writeEntries();
    }

    void sortEntries() {
        int n = entries.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (entries[j].totalSeconds < entries[minIndex].totalSeconds) {
                    // cout << entries[j].totalSeconds << endl;
                    minIndex = j;
                }
            }
            // Swap the minimum element with the first unsorted element
            if (minIndex != i) {
                swap(entries[i], entries[minIndex]);
            }
        }
    }

    void writeEntries() {
        ofstream leadFile("files/leaderboard.txt");
        for (int i = 0; i < 5; i++) {
            leadFile << entries[i].time << "," << entries[i].name << "\n";
        }
        leadFile.close();
    }

    void displayLeaderboard(){
        window.draw(titleText);

        window.draw(text);
    }

    void setText(){
        if (!font.loadFromFile("files/font.ttf")) {
            cerr << "Error: Failed to load font." << endl;
            exit(1);
        }

        // displaying title text
        titleText.setFont(font);
        titleText.setString("LEADERBOARD");
        titleText.setCharacterSize(20);
        titleText.setFillColor(Color::White);
        titleText.setStyle(Text::Bold | Text::Underlined);

        FloatRect title = titleText.getLocalBounds();
        titleText.setOrigin(title.left + title.width/2.0f, title.top + title.height/2.0f);
        titleText.setPosition(width/2.0f, height/2.0f - 120);

        leaderBoardText = "";
        for(int i = 0; i< entries.size(); i++){
            //leaderBoardText += to_string(i + 1) + ".\t" + entries[i].time + " \t " + entries[i].name + "\n\n";
            if(entries[i].isNewEntry){
                leaderBoardText += to_string(i + 1) + ".\t" + entries[i].time + " \t " + entries[i].name + "*\n\n";
            }
            else if(!entries[i].isNewEntry){
                leaderBoardText += to_string(i + 1) + ".\t" + entries[i].time + " \t " + entries[i].name + "\n\n";
            }
        }

        text.setFont(font);
        text.setString(leaderBoardText);
        text.setCharacterSize(18);
        text.setFillColor(Color::White);
        text.setStyle(Text::Bold);

        FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
        text.setPosition(width/2.0f, height/2.0f + 20);
    }

};