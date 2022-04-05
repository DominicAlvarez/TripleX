#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty){
    std::cout <<"\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure room.. \nEnter the code to continue and find the hidden file.\n";

}
bool PlayGame(int Difficulty){
    PrintIntro(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    std::cout << "There are 3 hints.." << std:: endl;
    std::cout << "+There are 3 numbers in the code";
    std::cout << "\n+The code adds up to: " << CodeSum;
    std::cout << "\n+The code multiplies up to: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessProduct == CodeProduct && CodeSum == GuessSum){
        std::cout<<"\n*Great, You got the first one, move onto the next!*";
        return true;
    }
    else{
        std::cout<<"\n*Darn, wrong code. Try again, Theyre coming!*";
        return false;
    }
}
int main(){
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxLevel = 5;
    while(LevelDifficulty <= MaxLevel){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        if(bLevelComplete){
            ++LevelDifficulty;
        }
    }
    std::cout<<"\n*Congrats youve finished the game!*";
    return 0;
}