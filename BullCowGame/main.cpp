#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0; // exit application
}

// introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can youu guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMAxTries();
	//the loop for the number of turns asking for guesses
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess();
		// print the guess back
		std::cout << "You guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess()
{
	// get a guess from the player
	std::cout << "Try" << BCGame.GetCurrentTry() << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
