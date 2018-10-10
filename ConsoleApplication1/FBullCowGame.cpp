#pragma once
#include "stdafx.h"
#include "FBullCowGame.h"
#include <map>
#define TMap std::map
FBullCowGame::FBullCowGame(){ Reset(); }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { 
	TMap <int32, int32> WordLengthToMaxTryes{ { 3,4 },{ 4,7 },{ 3,10 },{ 6,16 },{7,20} };
	return WordLengthToMaxTryes[MyHiddenWord.length()];
}
void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "pla";
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (!isIsogram(Guess)) {
		return EGuessStatus::Not_isogram;
	}
	else if (!isLowerCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if ( Guess.length() != GetHiddenWordLength() ) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

}
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount bullCowCount;
	int32 WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
	
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
		
			if ( Guess[GChar] == MyHiddenWord[MHWChar] ) {
				if (MHWChar == GChar) 
				{
					bullCowCount.Bulls++;
				}
				else {
					bullCowCount.Cows++;
				}
			}
		
		}
	
	}
	if (bullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return bullCowCount;
}
bool FBullCowGame::isIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap <char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if ( LetterSeen[Letter] == true ) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}
bool FBullCowGame::isLowerCase(FString Word) const
{
	for (auto Letter : Word) {

		if (!islower(Letter)) {
			return false;
		}
	
	}

	return true;
}
