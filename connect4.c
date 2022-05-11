#include <stdio.h>

void	ft_board(char *str)
{
	printf("-----------------------------\n");
	printf("| %c | %c | %c | %c | %c | %c | %c |\n", str[35], str[36], str[37], str[38], str[39], str[40], str[41]);
	printf("|---+---+---+---+---+---+---|\n");
	printf("| %c | %c | %c | %c | %c | %c | %c |\n", str[28], str[29], str[30], str[31], str[32], str[33], str[34]);
	printf("|---+---+---+---+---+---+---|\n");
	printf("| %c | %c | %c | %c | %c | %c | %c |\n", str[21], str[22], str[23], str[24], str[25], str[26], str[27]);
	printf("|---+---+---+---+---+---+---|\n");
	printf("| %c | %c | %c | %c | %c | %c | %c |\n", str[14], str[15], str[16], str[17], str[18], str[19], str[20]);
	printf("|---+---+---+---+---+---+---|\n");
	printf("| %c | %c | %c | %c | %c | %c | %c |\n", str[7], str[8], str[9], str[10], str[11], str[12], str[13]);
	printf("|---+---+---+---+---+---+---|\n");
	printf("| %c | %c | %c | %c | %c | %c | %c |\n", str[0], str[1], str[2], str[3], str[4], str[5], str[6]);
	printf("--1---2---3---4---5---6---7--\n");
}

int	ft_checkwinner(char *str)
{
	int	i;

	i = 0;
	while (i < 42)
	{
		if (str[i] != ' ')
		{
		//vertical up
			if (str[i] == str[i + 7] && str[i] == str[i + 14] && str[i] == str[i + 21])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//vertical down
			if (str[i] == str[i - 7] && str[i] == str[i - 14] && str[i] == str[i - 21])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//vertical mixed up
			if (str[i] == str[i - 7] && str[i] == str[i + 7] && str[i] == str[i + 14])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//vertical mixed down
			if (str[i] == str[i - 7] && str[i] == str[i - 14] && str[i] == str[i + 7])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//horizontal right
			if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//horizontal left
			if (str[i] == str[i - 1] && str[i] == str[i - 2] && str[i] == str[i - 3])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//horizontal mix right
			if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i - 1])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//horizontal mix left
			if (str[i] == str[i + 1] && str[i] == str[i - 1] && str[i] == str[i - 2])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal + up
			if (str[i] == str[i + 8] && str[i] == str[i + 16] && str[i] == str[i + 24])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal + down
			if (str[i] == str[i - 8] && str[i] == str[i - 16] && str[i] == str[i - 24])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal + mix up
			if (str[i] == str[i - 8] && str[i] == str[i + 8] && str[i] == str[i + 16])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal + mix down
			if (str[i] == str[i - 8] && str[i] == str[i - 16] && str[i] == str[i + 8])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal - up
			if (str[i] == str[i + 6] && str[i] == str[i + 12] && str[i] == str[i + 18])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal - down
			if (str[i] == str[i - 6] && str[i] == str[i - 12] && str[i] == str[i - 18])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal - mix up
			if (str[i] == str[i - 6] && str[i] == str[i + 6] && str[i] == str[i + 12])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
		//diagonal - mix down
			if (str[i] == str[i - 6] && str[i] == str[i - 12] && str[i] == str[i + 6])
			{
				if (str[i] == 'X')
					return (1);
				return (2);
			}
			if (str[35] != ' ' && str[36] != ' ' && str[37] != ' ' && str[38] != ' ' && str[39] != ' ' && str[40] != ' ' && str[41] != ' ')
				return (3);
		}
		i++;
	}
	return (0);
}

int	main()
{
	char	str[42];
	int		i;
	int		checkwinner;
	int		player;
	int		move;

	i = 0;
	checkwinner = 0;
	move = 0;
	player = 0;
	while (i < 42)
	{
		str[i] = ' ';
		i++;
	}
	ft_board(str);
	while (checkwinner == 0)
	{
		while (player == 0)
		{
			printf("\nPLAYER 1\n");
			printf("pick a column: \n");
			while (move < 1 || move > 7)
			{
				scanf("%d", &move);
				if (move < 1 || move > 7)
					printf("BURRO!");
			}
			if (str[move + 34] == ' ' && str[move + 27] != ' ')
			{
				str[move + 34] = 'X';
				player = 1;
			}
			else if (str[move + 27] == ' ' && str[move + 20] != ' ')
			{
				str[move + 27] = 'X';
				player = 1;
			}
			else if (str[move + 20] == ' ' && str[move + 13] != ' ')
			{
				str[move + 20] = 'X';
				player = 1;
			}
			else if (str[move + 13] == ' ' && str[move + 6] != ' ')
			{
				str[move + 13] = 'X';
				player = 1;
			}
			else if (str[move + 6] == ' ' && str[move - 1] != ' ')
			{
				str[move + 6] = 'X';
				player = 1;
			}
			else if (str[move - 1] == ' ')
			{
				str[move - 1] = 'X';
				player = 1;
			}
			move = 0;
		}
		ft_board(str);
		checkwinner = ft_checkwinner(str);
		if (checkwinner != 0)
			break ;
		while (player == 1)
		{
			printf("\nPLAYER 2\n");
			printf("pick a row: \n");
			while (move < 1 || move > 7)
			{
				scanf("%d", &move);
				if (move < 1 || move > 7)
					printf("BURRO!");
			}
			if (str[move + 34] == ' ' && str[move + 27] != ' ')
			{
				str[move + 34] = 'O';
				player = 0;
			}
			else if (str[move + 27] == ' ' && str[move + 20] != ' ')
			{
				str[move + 27] = 'O';
				player = 0;
			}
			else if (str[move + 20] == ' ' && str[move + 13] != ' ')
			{
				str[move + 20] = 'O';
				player = 0;
			}
			else if (str[move + 13] == ' ' && str[move + 6] != ' ')
			{
				str[move + 13] = 'O';
				player = 0;
			}
			else if (str[move + 6] == ' ' && str[move - 1] != ' ')
			{
				str[move + 6] = 'O';
				player = 0;
			}
			else if (str[move - 1] == ' ')
			{
				str[move - 1] = 'O';
				player = 0;
			}
			move = 0;
		}
		ft_board(str);
		checkwinner = ft_checkwinner(str);
	}
	printf("\n\n---------GAME--OVER---------");
	if (checkwinner == 1)
		printf("\nPLAYER 1 WINS\n\n");
	else if (checkwinner == 2)
		printf("\nPLAYER 2 WINS\n\n");
	else
		printf("\n----DRAW----\n\n");
}
