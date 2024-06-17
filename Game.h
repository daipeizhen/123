#ifndef GAME_H
#define GAME_H

class Game {
private:
    int player;
    int com;
    bool validInput;
    int playerScore;
    int comScore;
    void playRound();
    void getPlayerInput();
    void generateComputerChoice();
    void displayChoices();
    void determineWinner();
    void displayScore();

public:
    Game();
    void run();

};

#endif 
