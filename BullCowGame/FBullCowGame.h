#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame 
{
public:
	FBullCowGame();
	int32 GetMAxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};