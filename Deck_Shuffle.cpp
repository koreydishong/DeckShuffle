//Author: Korey Dishong
//Course: CSC 114
//Section: 450
//Date: 2019-12-04
//Description: Final Project - Shuffle standard deck of cards & deal evenly to 4 players

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void unwrap(vector<int> &deck, int deckSize);

void shuffle(vector<int> &deck, int deckSize);

void deal(vector< vector<int> > &playerHands, vector<int> deck);

void sortHands(vector < vector<int> > &playerHands);

void showHands(vector< vector<int> > &playerHands);

int main() {

	srand((unsigned)time(NULL));

	// Declare deck size & deck vector
	const int deckSize = 52;
	vector<int> deck;

	// Unwrap deck
	unwrap(deck, deckSize);

	// Shuffle deck
	shuffle(deck, deckSize);

	// Create a matrix of 4 rows & 13 columns
	vector< vector<int> > playerHands(4, vector<int>(13));

	// Deal player hands
	deal(playerHands, deck);

	// Sort player hands
	sortHands(playerHands);

	// Show player hands
	showHands(playerHands);

	return 0;
}

void unwrap(vector<int> &deck, int deckSize) {

	// Fill deck with integers 0 to deckSize-1
	for (int i = 0; i < deckSize; ++i) {
		deck.push_back(i);
	}

}

void shuffle(vector<int> &deck, int deckSize) {

	// Shuffle vector
	for (int i = 0; i < deckSize; ++i) {
		int randomIndex = rand() % deckSize;
		int temp = deck[i];
		deck[i] = deck[randomIndex];
		deck[randomIndex] = temp;
	}

}

void deal(vector< vector<int> > &playerHands, vector<int> deck) {

	 //Deal shuffled deck to players
	for (size_t i = 0; i < playerHands.size(); ++i) {
		for (size_t j = 0; j < playerHands[i].size(); ++j) {
			playerHands[i][j] = deck[(i * playerHands[i].size()) + j];
		}
	}

}

void sortHands(vector < vector<int> > &playerHands) {

	for (size_t i = 0; i < playerHands.size(); ++i) {
		sort(playerHands[i].begin(), playerHands[i].end());
	}

}

void showHands(vector< vector<int> > &playerHands) {

	//Arrays for "translating" card index to card rank & suit
	const string RANKS[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	const string SUITS[] = { "Spades", "Hearts", "Diamonds", "Clubs" };

	int i = 1; // Player number counter
	for (vector<int> eachHand : playerHands) {
		cout << "Hand " << i << " holds:" << endl;
		i += 1;
		for (int eachCard : eachHand) {
			cout << RANKS[eachCard % 13] << " of " << SUITS[eachCard / 13] << endl;
		}
		cout << endl;
	}

}
