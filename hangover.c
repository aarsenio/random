#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// random number 
int	randnum()
{
	int rn;
	srand(time(NULL));
	rn = rand() % 10;
	return (rn);
}

// clear the terminal 
void clrscr()
{
    system("cls||clear");
}

// string length 
int	strl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// checks if there is a character in a string
int	checkchar(char *c, char *s, int	i)
{
	while (s[i])
	{
		if (s[i] == c[0])
			return (i);
		i++;
	}
	return (666);
}

// validates the user input string
int	checkstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 'a' || s[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

// checks if the game is over
int	checkwinner(char *h, char *s)
{
	int	i;

	i = 0;
	while (i < strl(s))
	{
		if (h[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

// checks if the letter has been marked as wrong
int	checkwrongletter(char *c, char *wl)
{
	int	i;

	i = 0;
	while (wl[i] != ' ')
	{
		if (wl[i] == c[0])
			return (0);
		i++;
	}
	return (1);
}

//prints the board
void board(char t1, char t2, char t3, char t4, char t5, char t6, char t7, char	*h, int len,char *wrongletter)
{
	int	i;

	i = 0;

	printf("\n");
	clrscr();
	printf("  +--------  \n");
	printf("  |       |                   Wrong Letters\n");
	printf("  |       %c\n", t1);
	printf("  |      %c%c%c              %c   %c   %c   %c   %c   %c\n", t2, t3, t4, wrongletter[0], wrongletter[1], wrongletter[2], wrongletter[3], wrongletter[4], wrongletter[5]);
	printf("  |       %c              ___ ___ ___ ___ ___ ___\n", t5);
	printf("  |      %c %c\n", t6, t7);
	printf(" ----\n\n\n\n\n\n");
	while (i < len)
	{
		printf(" %c  ", h[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < len)
	{
		printf("___ ");
		i++;
	}
	printf("\n\n");
}

int main()
{
	int		lifes = 6;

	int		gameover = 1;

	int		wli = 0;

	int		i;

	int		ih = 0;

	int		modecheck;

	int		r;
	
	int		len;

	char	t1 = ' ';
	char	t2 = ' ';
	char	t3 = ' ';
	char	t4 = ' ';
	char	t5 = ' ';
	char	t6 = ' ';
	char	t7 = ' ';

	char	*s1;

	char 	sp[1024];
		
	char	help[20];
	
	char	h[1024];

	char	wrongletter[6];

	while (ih < 6)
	{
		wrongletter[ih] = ' ';
		ih++;
	}

	ih = 0;

	while (ih <= 30)
	{
		h[ih] = ' ';
		ih++;
	}

	// CHECKS THE GAME MODE
	// either choose a word or get a random one 
	clrscr();
	printf("1 - Choose a Word\n2 - Random Word\nPick The Game Mode: ");
	scanf("%d", &modecheck);
	while (modecheck < 1 || modecheck > 2)
	{
		clrscr();
		printf("(Its Either 1 or 2)\n1 - Choose a Word\n2 - Random Word\nPick The Game Mode: ");
		scanf("%d", &modecheck);
	}

	// choose a word mode
	if (modecheck == 1 )
	{
		clrscr();
		printf("Choose a word: ");
		scanf(" %s", sp);
		while (checkstr(sp) != 1)
		{
			clrscr();
			printf("Remember! Use only small cap letters, try again: ");
			scanf(" %s", sp);
		}
		len = strl(sp);
		while (gameover == 1)
		{
			board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
			printf("pick a letter (small cap!): ");
			scanf(" %s", help);
			if (strl(help) != 1)
			{
				while (strl(help) != 1)
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
					printf("Just one letter please, and remember small cap... Try again: ");
					scanf(" %s", help);
				}
			}
			while (help[0] < 'a' || help[0] > 'z')
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
				printf("thats not a small cap letter... try again: ");
				scanf("%s", help);
				while (strl(help) != 1)
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
					printf("Just one letter please, and remember small cap... Try again: ");
					scanf(" %s", help);
				}
			}
			i = checkchar(help, sp, 0);
			if (i != 666)
			{
				while (i != 666)
				{
					h[i] = help[0];
					i++;
					i = checkchar(help, sp, i);
				}
			}
			else
			{
				if (checkwrongletter(help, wrongletter) == 1)
				{
					wrongletter[wli] = help[0];
					wli++;
					if (lifes == 6)
					{
						lifes--;
						t1 = 'O';
					}
					else if (lifes == 5)
					{
						lifes--;
						t3 = '|';
						t5 = '^';
					}
					else if (lifes == 4)
					{
						lifes--;
						t2 = '-';
					}
					else if (lifes == 3)
					{
						lifes--;
						t4 = '-';
					}
					else if (lifes == 2)
					{
						lifes--;
						t6 = '/';
					}
					else if (lifes == 1)
					{
						lifes--;
						t7 = '\\';
						gameover = 0;
						board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
			}
			if (checkwinner(h, sp) == 1)
			{
				gameover = 0;
				board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
				printf("\n\n--YOU-WIN--\n\n");
			}
		}
	}

	// get a random one mode
	else
	{
		r = randnum();
		if (r == 1)
			s1 = "elefante";
		if (r == 2)
			s1 = "capital";
		if (r == 3)
			s1 = "cimento";
		if (r == 4)
			s1 = "parede";
		if (r == 5)
			s1 = "gravata";
		if (r == 6)
			s1 = "agua";
		if (r == 7)
			s1 = "teclado";
		if (r == 8)
			s1 = "fuckyou";
		if (r == 9)
			s1 = "esquadro";
		len = strl(s1);
		while (gameover == 1)
		{
			board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
			printf("pick a letter (small cap!): ");
			scanf(" %s", help);
			if (strl(help) != 1)
			{
				while (strl(help) != 1)
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
					printf("Just one letter please, and remember small cap... Try again: ");
					scanf(" %s", help);
				}
			}
			while (help[0] < 'a' || help[0] > 'z')
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
				printf("thats not a small cap letter... try again: ");
				scanf("%s", help);
				while (strl(help) != 1)
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
					printf("Just one letter please, and remember small cap... Try again: ");
					scanf(" %s", help);
				}
			}
			i = checkchar(help, s1, 0);
			if (i != 666)
			{
				while (i != 666)
				{
					h[i] = help[0];
					i++;
					i = checkchar(help, s1, i);
				}
			}
			else
			{
				if (checkwrongletter(help, wrongletter) == 1)
				{
					wrongletter[wli] = help[0];
					wli++;
					if (lifes == 6)
					{
						lifes--;
						t1 = 'O';
					}
					else if (lifes == 5)
					{
						lifes--;
						t3 = '|';
						t5 = '^';
					}
					else if (lifes == 4)
					{
						lifes--;
						t2 = '-';
					}
					else if (lifes == 3)
					{
						lifes--;
						t4 = '-';
					}
					else if (lifes == 2)
					{
						lifes--;
						t6 = '/';
					}
					else if (lifes == 1)
					{
						lifes--;
						t7 = '\\';
						gameover = 0;
						board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
			}
			if (checkwinner(h, s1) == 1)
			{
				gameover = 0;
				board(t1,t2,t3,t4,t5,t6,t7,h,len,wrongletter);
				printf("\n\n--YOU-WIN--\n\n");
			}
		}
	}
}
