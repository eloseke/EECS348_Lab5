#include <stdio.h>

void get_score_combos(int score)
{
	int i=0; int j=0; int k=0; int l=0; int m=0;
	printf("\nPossible combinations of scoring plays:\n");
	for (i=0; score>=((8*i)+(7*j)+(6*k)+(3*l)+(2*m)); i++)
	{
		for (j=0; score>=((8*i)+(7*j)+(6*k)+(3*l)+(2*m)); j++)
		{
			for (k=0; score>=((8*i)+(7*j)+(6*k)+(3*l)+(2*m)); k++)
			{
				for (l=0; score>=((8*i)+(7*j)+(6*k)+(3*l)+(2*m)); l++)
				{
					for (m=0; score>=((8*i)+(7*j)+(6*k)+(3*l)+(2*m)); m++)
					{
						if (score == ((8*i)+(7*j)+(6*k)+(3*l)+(2*m)))
						{
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m);
						}
					}
					m=0;
				}
				l=0;
			}
			k=0;
		}
		j=0;
	}
}

int main()
{
	int user_input = 2;
	while (user_input > 1)
	{
		printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d", &user_input);
		if (user_input > 1)
		{
			get_score_combos(user_input);
		}
	}
	printf("\n");
	return 0;
}
