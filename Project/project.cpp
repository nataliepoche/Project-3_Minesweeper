//#include "welcomeWindow.h"
//
//int main() {
//    ifstream filename("files/config.cfg");
//
//    string colStr;
//    string rowStr;
//    string tileStr;
//    if(filename.is_open()){
//        // reads column, row, and tile information
//        getline(filename, colStr);
//        int col = stoi(colStr);
//        getline(filename, rowStr);
//        int row = stoi(rowStr);
//        getline(filename, tileStr);
//        int mineCount = stoi(tileStr);
//
//        // uses col, row, and mineCount to get width, height, and tileCount
//        int width = col * 32;
//        int height = (row * 32) + 100;
//        int tileCount = col * row;
//
//        // Creates welcome window
//        welcomeWindow Welcome(width, height, col, row, tileCount, mineCount);
//    }
//    else{cout << "Error" << endl;}
//    return 0;
//}