#pragma once
#include <string>
using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	Invalid_Status,
	OK,
	Not_isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool isGameWon() const;
	
	void Reset(); //TODO make a more rich return value
	EGuessStatus CheckGuessValidity(FString);
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool isIsogram(FString) const;
	bool isLowerCase(FString) const;
};