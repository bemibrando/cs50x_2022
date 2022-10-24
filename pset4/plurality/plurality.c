#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Define how many candidates can bave
#define MAX 9

typedef struct
{
	string name;
	int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

// Functions
bool vote(string _name);
void print_winner(void);

int main(int argc, string argv[])
{
	// Check for invalid usage
	if (argc < 2)
	{
		printf("Usage: plurality [candidate ... ]\n");
		return 1;
	}

	// The first arg is the file name
	candidate_count = argc - 1;
	// Check how many candidates are
	if (candidate_count > MAX)
	{
		printf("Too many candidates. Maximum number of candidates is %i\n", MAX);
		return 2;
	}

	// Setup for count votes
	for (int i = 0; i < candidate_count; i++)
	{
		candidates[i].name = argv[i + 1];
		candidates[i].votes = 0;
	}

	int voter_count = get_int("Number of voters: ");

	// Loop over all voters
	for (int i = 0; i < voter_count; i++)
	{
		string voter_name = get_string("Vote: ");

		// Check for invalid vote || if false, printf Invalid
		if (!vote(voter_name))
		{
			printf("Invalid vote.\n");
			i--;
		}
	}


	// Print the high score candidates
	print_winner();

	return 0;
}

bool vote(string _name)
{
	for (int i = 0; i < candidate_count; i++)
	{
		if (strcmp(_name, candidates[i].name) == 0)
		{
			candidates[i].votes++;
			return true;
		}
	}
	return false;
}

void print_winner()
{
	int high_score = 0;

	// find the highscore
	for (int i = 0; i < candidate_count; i++)
	{
		if (candidates[i].votes > high_score)
		{
			high_score = candidates[i].votes;
		}
	}

	for (int i = 0; i < candidate_count; i++)
	{
		if (candidates[i].votes == high_score)
		{
			printf("%s\n", candidates[i].name);
		}
	}
}