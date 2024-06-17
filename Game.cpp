#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game() {
    validInput = true;
    srand(static_cast<unsigned int>(time(0)));
    playerScore = 0;
    comScore = 0;
}

void Game::run() {
    char playAgain;
    do {
        playRound();
        displayScore();
        cout << "是否继续游戏？(y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');
}

void Game::playRound() {
    getPlayerInput();
    if (validInput) {
        generateComputerChoice();
        displayChoices();
        determineWinner();
    }
}

void Game::getPlayerInput() {
    cout << "请输入代表数字 1(石头) 2(剪刀) 3(布): ";
    cin >> player;
    switch (player) {
    case 1:
        cout << "你出的是剪刀\n";
        break;
    case 2:
        cout << "你出的是石?\n";
        break;
    case 3:
        cout << "你出的是布\n";
        break;
    default:
        cout << "请不要乱出\n";
        validInput = false;
    }
}

void Game::generateComputerChoice() {
    com = 1 + rand() % 3;
}

void Game::displayChoices() {
    switch (com) {
    case 1:
        cout << "电脑出的是剪刀\n";
        break;
    case 2:
        cout << "电脑出的是石?\n";
        break;
    case 3:
        cout << "电脑出的是布\n";
        break;
    }
}

void Game::determineWinner() {
    int result = (player - com + 3) % 3;
    switch (result) {
    case 0:
        cout << "平手！" << endl;
        break;
    case 1:
        cout << "你赢了!" << endl;
        playerScore++;
        break;
    case 2:
        cout << "你输了!" << endl;
        comScore++;
        break;
    }
}

void Game::displayScore() {
    cout << "之前得分:" << endl;
    cout << "你的得分: " << playerScore << endl;
    cout << "电脑的得分: " << comScore << endl;
    cout << endl;
}
