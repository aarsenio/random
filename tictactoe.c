#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	randnum()
{
	int rn;
	srand(time(NULL));
	rn = rand() % 10;
	if (rn >= 5)
		rn = 1;
	else
		rn = 0;
	return (rn);
}

void clrscr()
{
    system("cls||clear");
}

void	ft_board(char *board)
{
	printf("\n %c |  %c  | %c \n", board[6], board[7], board[8]);
	printf("---+-----+---\n");
	printf(" %c |  %c  | %c \n", board[3], board[4], board[5]);
	printf("---+-----+---\n");
	printf(" %c |  %c  | %c \n", board[0], board[1], board[2]);
}

int	ft_checkwinner(char *board)
{
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
	{
		if (board[0] == 'X')
			return (1);
		return (2);
	}
	if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
		{
		if (board[3] == 'X')
			return (1);
		return (2);
	}
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
		{
		if (board[6] == 'X')
			return (1);
		return (2);
	}
	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
		{
		if (board[0] == 'X')
			return (1);
		return (2);
	}
	if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
		{
		if (board[1] == 'X')
			return (1);
		return (2);
	}
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
		{
		if (board[2] == 'X')
			return (1);
		return (2);
	}
	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
		{
		if (board[0] == 'X')
			return (1);
		return (2);
	}
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
		{
		if (board[2] == 'X')
			return (1);
		return (2);
	}
	if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' && board[3] != ' ' && board[4] != ' ' && board[5] != ' ' && board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
		return (3);
	return (0);
}

int minimax(char *board, int depth, int maximizing)
{
	int	i;
	int	score;
	int	bestscore;
	int checkwinner;
	
	i = 0;
	checkwinner = ft_checkwinner(board);
	if (checkwinner != 0)
	{
		if (checkwinner == 1)
			return (1);
		if (checkwinner == 2)
			return (-1);
		if (checkwinner == 3)
			return (0);
	}
	if (maximizing == 0)
	{
		bestscore = -2;
		while (i < 9)
		{
			if (board[i] == ' ')
			{
				board[i] = 'O';
				score = minimax(board, depth + 1, 1);
				board[i] = ' ';
				if (score > bestscore)
					bestscore = score;
			}
			i++;
		}
		return (bestscore);
	}
	else
	{
		bestscore = 2;
		while (i < 9)
		{
			if (board[i] == ' ')
			{
				board[i] = 'X';
				score = minimax(board, depth + 1, 0);
				board[i] = ' ';
				if (score < bestscore)
					bestscore = score;
			}
			i++;
		}
		return (bestscore);
	}	
}

int	main()
{
	char	*board;
	int		checkwinner;
	int		player;
	int		move;
	int		oneortwo;
	

	board[0] = ' ';
	board[1] = ' ';
	board[2] = ' ';
	board[3] = ' ';
	board[4] = ' ';
	board[5] = ' ';
	board[6] = ' ';
	board[7] = ' ';
	board[8] = ' ';
	player = 0;
	checkwinner = 0;
	move = 0;
	oneortwo = 0;
	clrscr();
	printf("\nHow many players?\n");
	while (oneortwo < 1 || oneortwo > 2)
	{
		scanf("%d", &oneortwo);
		if (oneortwo < 1 || oneortwo > 2)
		{
			clrscr();
			printf("\nIt can only be 1 or two...Try again\n");
		}
	}
	if (oneortwo == 2)
	{
		while (checkwinner == 0)
		{
		
			if (player == 0)
			{
				clrscr();
				printf("   PLAYER 1\n\n");
				ft_board(board);
				printf("\n..............\n\nChoose a spot from 1 to 9: \n\n");
				while (move < 1 || move > 9 || board[move - 1] != ' ')
				{
					scanf("%d", &move);
					if (move < 1 || move > 9)
					{
						clrscr();
						printf("   PLAYER 1\n\n");
						ft_board(board);
						printf("\n..............\n\nInvalid input (from 1 to 9!), try again:\n\n");
					}
					else if (board[move - 1] == 'X' || board[move - 1] == 'O')
					{
						clrscr();
						printf("   PLAYER 1\n\n");
						ft_board(board);
						printf("\n..............\n\nThat spot has already been used, try again:\n\n");
					}
				}
				board[move - 1] = 'X';
				checkwinner = ft_checkwinner(board);
				player = 1;
			}
			else
			{
				clrscr();
				printf("   PLAYER 2\n\n");
				ft_board(board);
				printf("\n..............\n\nChoose a spot from 1 to 9:\n\n");
				while (move < 1 || move > 9 || board[move - 1] != ' ')
				{
					scanf("%d", &move);
					if (move < 1 || move > 9)
					{
						clrscr();
						printf("   PLAYER 2\n\n");
						ft_board(board);
						printf("\n..............\n\nInvalid input (from 1 to 9!), try again:\n\n");
					}
					else if (board[move - 1] == 'X' || board[move - 1] == 'O')
					{
						clrscr();
						printf("   PLAYER 2\n\n");
						ft_board(board);
						printf("\n..............\n\nThat spot has already been used, try again:\n\n");
					}
				}
				board[move - 1] = 'O';
				checkwinner = ft_checkwinner(board);
				player = 0;
			}
			clrscr();
			printf("--GAME-OVER--\n\n");
			ft_board(board);
			if (checkwinner == 1)
				printf("\n\nPLAYER 1 WINS\n\n");
			else if (checkwinner == 2)
				printf("\n\nPLAYER 2 WINS\n\n");
			else
				printf("\n\n----DRAW----\n\n");
		}
		
	}
	else
	{
		player = randnum();
		while (checkwinner == 0)
		{
			if (player == 0)
			{
				clrscr();
				printf("   PLAYER 1\n\n");
				ft_board(board);
				printf("\n..............\n\nChoose a spot from 1 to 9: \n\n");
				while (move < 1 || move > 9 || board[move - 1] != ' ')
				{
					scanf("%d", &move);
					if (move < 1 || move > 9)
					{
						clrscr();
						printf("   PLAYER 1\n\n");
						ft_board(board);
						printf("\n..............\n\nInvalid input (from 1 to 9!), try again:\n\n");
					}
					else if (board[move - 1] == 'X' || board[move - 1] == 'O')
					{
						clrscr();
						printf("   PLAYER 1\n\n");
						ft_board(board);
						printf("\n..............\n\nThat spot has already been used, try again:\n\n");
					}
				}
				board[move - 1] = 'X';
				checkwinner = ft_checkwinner(board);
				player = 1;
			}
			else
			{
				int	i;
				int	score;
				int	bestscore;

				i = 0;
				bestscore = 9999999;
				while (i < 9)
				{
					if (board[i] == ' ')
					{
						score = minimax(board, 0, 1);
						if (score < bestscore)
						{
							printf("%d", bestscore);
							bestscore = score;
							move = i;
						}
					}
					i++;
				}
				board[move] = 'O';
				checkwinner = ft_checkwinner(board);
				player = 0;
				/* int rn;

				rn = -1;
				srand(time(NULL));
				while (rn < 0 || rn > 8)
				{
					rn = rand() % 10;
					if (board[rn] == ' ')
						break ;
					rn = -1;
				}
				board[rn] = 'O';
				checkwinner = ft_checkwinner(board);
				player = 0; */
			}
			clrscr();
			printf("--GAME-OVER--\n\n");
			ft_board(board);
			if (checkwinner == 1)
				printf("\n\nPLAYER 1 WINS\n\n");
			else if (checkwinner == 2)
				printf("\n\nPLAYER 2 WINS\n\n");
			else
				printf("\n\n----DRAW----\n\n");
		}
	}
}
