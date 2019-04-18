#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { /*MyCurrentTry = 0; MyMaxTries = 0;*/ Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 4;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength(); // assuming the same length as guess
	
	for (int32 i = 0; i < WordLength; i++)
	{
		for (int32 j = 0; j < WordLength; j++)
		{
			if (Guess[j] == MyHiddenWord[i])
			{
				if (i == j) 
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) 
	{
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1) return true;
	
	TMap<char, bool> LetterSeen;
	
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {

			return false;
		}
		else {

			LetterSeen[Letter] = true;
		}
	}
	
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	if (Guess.length() == 0) return false;

	for(auto Letter : Guess)
	{
		if (Letter == ' ' || Letter == '\0' || !islower(Letter)) return false;
	}

	return true;
}
