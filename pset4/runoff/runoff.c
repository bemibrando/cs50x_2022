#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_VOTERS 9

typedef struct
{
	string name;
	int votes;
	bool eliminated;
}
candidate;

// preferences = [voter number] X [candidate index] 
int preferences[MAX_CANDIDATES][MAX_VOTERS];

// Global variables
candidate candidates[MAX_CANDIDATES];
int voter_count;
int candidate_count;

// Functions
bool vote(int _voter, int _rank, string _name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int _min);
void eliminate(int _min);

int main(int argc, string argv[])
{
	// Check for invalid usage
	if (argc < 2)
	{
		printf("Usage: runoff [candidate ...]");
		return 1;
	}

	// The first arg is the file name
	candidate_count = argc - 1;

	// Check how many candidates are
	if (candidate_count > MAX_CANDIDATES)
	{
		printf("Too many candidates. Maximum number of candidates is %i\n", MAX_CANDIDATES);
		return 2;
	}
	// setup candidates
	for (int i = 0; i < candidate_count; i++)
	{
		candidates[i].name = argv[i + 1];
		candidates[i].votes = 0;
		candidates[i].eliminated = false;
	}

	// Receive voters number
	voter_count = get_int("Number of voters: ");

	// Check voter numbers
	if (voter_count > MAX_VOTERS)
	{
		printf("Maximum number of voters is %i\n", MAX_VOTERS);
		return 3;
	}

	// Loop over all votes
	for (int i = 0; i < voter_count; i++)
	{
		// Query for each rank
		for (int j = 0; j < candidate_count; j++)
		{
			string name = get_string("Rank %i: ", j + 1);

			// Check for invalid vote
			if (!vote(i, j, name))
			{
				printf("Invalid vote.\n");
				return 4;
			}
		}

		printf("\n");
	}

	// Keep running until winner exits
	bool winner = false;
	while (!winner)
	{
		tabulate();

		winner = print_winner();

		if (!winner)
		{
			int min = find_min();
			if (is_tie(min))
			{
				printf("It's a tie!!\nWinners:\n");
				for (int i = 0; i < candidate_count; i++)
				{
					// print all candidates available
					if (!candidates[i].eliminated)
					{
						printf("%s\n", candidates[i].name);
					}
				}

				break;
			}

			// Eliminate anyone with minimum number of votes
			eliminate(min);

			// Reset all votes
			for (int i = 0; i < candidate_count; i++)
			{
				candidates[i].votes = 0;
			}
		}
	}

	return 0;
}

// vote
// keep track of all of the preferences.
bool vote(int _voter, int _rank, string _name)
{
	for (int a = 0; a < candidate_count; a++)
	{
		if (strcmp(_name, candidates[a].name) == 0)
		{
			// Alice, Bob, Charlie
			// voter 1; Rank 2; = 2(Charlie)
			preferences[_voter][_rank] = a;
			return true;
		}
	}
	return false;
}

// tabulate
// Look at all of the voters' preferences and compute the current vote totals, 
// by looking at each voter's top choice candidade who hasn't yet been eliminated
void tabulate(void)
{
	for (int a = 0; a < voter_count; a++)
	{
		for (int b = 0; b < candidate_count; b++)
		{
			int candidateNumber = preferences[a][b];
			if (!(candidates[candidateNumber].eliminated))
			{
				candidates[candidateNumber].votes++;
				break;
			}
		}
	}
}

// print_winner
// Print out the winner if there is one and finish the program
// if everyone in the election is tied with the same number of votes, election is declared a tie
// otherwise, the last-place candidate (or candidates) is eliminated
bool print_winner(void)
{
	bool won = false;
	for (int a = 0; a < candidate_count; a++)
	{
		if (candidates[a].votes > voter_count / 2)
		{
			printf("Winner: %s\n", candidates[a].name);
			won = true;
		}
	}

	return won;
}

// find_min
// Determine the fewest number of votes anyone still in the election received
int find_min(void)
{
	// The hiest count is all votes
	int voteCount = voter_count;

	for (int a = 0; a < candidate_count; a++)
	{
		if (candidates[a].votes < voteCount && candidates[a].eliminated == false)
		{
			voteCount = candidates[a].votes;
		}
	}

	return voteCount;
}

// is_tie
// Turns out everyone in the election is tied with the same number of votes
bool is_tie(int _min)
{
	int tieCount = 0;
	int roundCount = 0;

	for (int a = 0; a < candidate_count; a++)
	{
		if (candidates[a].eliminated == false)
		{
			roundCount++;

			if (candidates[a].votes == _min)
			{
				tieCount++;
			}
		}
	}

	if (tieCount == roundCount)
	{
		return true;
	}

	return false;
}

// eliminate
// Eliminate the last-places candidate(or candidates)
void eliminate(int _min)
{
	for (int a = 0; a < candidate_count; a++)
	{
		if (candidates[a].eliminated == false && candidates[a].votes == _min)
		{
			candidates[a].eliminated = true;
		}
	}
}