#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	randnum()
{
	int rn;
	srand(time(NULL));
	rn = rand() % 10;
	return (rn);
}

void clrscr()
{
    system("cls||clear");
}

int	strl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void board(char t1, char t2, char t3, char t4, char t5, char t6, char t7, char	*h, int len)
{
	int	i;

	i = 0;

	printf("\n");
	clrscr();
	printf("  +--------  \n");
	printf("  |       |\n");
	printf("  |       %c\n", t1);
	printf("  |      %c%c%c\n", t2, t3, t4);
	printf("  |       %c\n", t5);
	printf("  |      %c %c\n", t6, t7);
	printf(" ----\n\n\n\n");
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
	int		lifes;

	int		gameover;

	int		i;

	int		ih;

	int		modecheck;

	int		r;
	
	int		len;

	char	t1;
	char	t2;
	char	t3;
	char	t4;
	char	t5;
	char	t6;
	char	t7;

	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	*s6;
	char	*s7;
	char	*s8;
	char	*s9;

	char 	sp[1024];
		
	char	help[20];
	
	char	h[1024];

	s1 = "elefante";
	s2 = "capital";
	s3 = "cimento";
	s4 = "parede";
	s5 = "gravata";
	s6 = "agua";
	s7 = "teclado";
	s8 = "fuckyou";
	s9 = "esquadro";

	t1 = ' ';
	t2 = ' ';
	t3 = ' ';
	t4 = ' ';
	t5 = ' ';
	t6 = ' ';
	t7 = ' ';

	gameover = 1;

	lifes = 6;

	ih = 0;

	while (ih <= 20)
	{
		h[ih] = ' ';
		ih++;
	}

	// CHECKS THE GAME MODE
	// either choose a word or get a random one 
	clrscr();
	printf("Choose a word(1) or get a random word(2): ");
	scanf("%d", &modecheck);
	while (modecheck < 1 || modecheck > 2)
	{
		clrscr();
		printf("Dude 1 to choose or 2 to get a random one its not that hard... Try again: ");
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
			board(t1,t2,t3,t4,t5,t6,t7,h,len);
			printf("pick a letter (small cap!): ");
			scanf(" %s", help);
			if (strl(help) != 1)
			{
				while (strl(help) != 1)
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("Just one letter please, and remember small cap... Try again: ");
					scanf(" %s", help);
				}
			}
			while (help[0] < 'a' || help[0] > 'z')
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("thats not a small cap letter... try again: ");
				scanf("%s", help);
				while (strl(help) != 1)
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
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
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-LOST--\n\n");
				}
			}
			if (checkwinner(h, sp) == 1)
			{
				gameover = 0;
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("\n\n--YOU-WIN--\n\n");
			}
		}
	}

	// get a random one mode
	else
	{
		r = randnum();
		if (r == 1)
		{
			len = strl(s1);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s1) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 2)
		{
			len = strl(s2);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s2, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s2, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s2) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 3)
		{
			len = strl(s3);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s3, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s3, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s3) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 4)
		{
			len = strl(s4);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s4, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s4, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s4) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 5)
		{
			len = strl(s5);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s5, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s5, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s5) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 6)
		{
			len = strl(s6);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s6, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s6, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s6) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 7)
		{
			len = strl(s7);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s7, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s7, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s7) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 8)
		{
			len = strl(s8);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s8, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s8, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s8) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
		if (r == 9)
		{
			len = strl(s9);
			while (gameover == 1)
			{
				board(t1,t2,t3,t4,t5,t6,t7,h,len);
				printf("pick a letter (small cap!): ");
				scanf(" %s", help);
				if (strl(help) != 1)
				{
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				while (help[0] < 'a' || help[0] > 'z')
				{
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("thats not a small cap letter... try again: ");
					scanf("%s", help);
					while (strl(help) != 1)
					{
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("Just one letter please, and remember small cap... Try again: ");
						scanf(" %s", help);
					}
				}
				i = checkchar(help, s9, 0);
				if (i != 666)
				{
					while (i != 666)
					{
						h[i] = help[0];
						i++;
						i = checkchar(help, s9, i);
					}
				}
				else
				{
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
						board(t1,t2,t3,t4,t5,t6,t7,h,len);
						printf("\n\n--YOU-LOST--\n\n");
					}
				}
				if (checkwinner(h, s9) == 1)
				{
					gameover = 0;
					board(t1,t2,t3,t4,t5,t6,t7,h,len);
					printf("\n\n--YOU-WIN--\n\n");
				}
			}
		}
	}
}
