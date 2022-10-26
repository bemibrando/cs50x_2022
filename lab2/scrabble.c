#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int compute_score(string word);

int main(void)
{
	// Get input words from both players
	string word1 = get_string("Player 1: ");
	string word2 = get_string("Player 2: ");

	// Score both words
	int score1 = compute_score(word1);
	int score2 = compute_score(word2);

	//    printf("Player1: %d || Player2: %d\n", score1, score2);

	// TODO: Print the winner
	if (score1 > score2)
	{
		printf("Player 1 wins!");
	}
	else if (score1 < score2)
	{
		printf("Player 2 wins!");
	}
	else
	{
		printf("Tie!\n");
	}

	return 0;
}

int compute_score(string _word)
{
	// TODO: Compute and return score for string
	int n = strlen(_word);
	int score = 0;

	for (int i = 0; i < n; i++)
	{
		char letter = tolower(_word[i]);
		if (letter >= 'a' && letter <= 'z')
		{
			int position = letter - 'a';
			score += POINTS[position];
		}
	}
	printf("\n");
	return score;
}