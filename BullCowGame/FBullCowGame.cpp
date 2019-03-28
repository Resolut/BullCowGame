#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMAxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	const int32 MAX_TRIES = 5;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
}

bool FBullCowGame::CheckGuessValidity(FString str)
{
	return false;
}
