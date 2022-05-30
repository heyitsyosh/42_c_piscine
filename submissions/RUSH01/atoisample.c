#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int	nbr[16];

	i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			nbr[i] = str[i] - '0';
			i++;
		}
		else if(str[i] == ' ')
		i++;
		// return (0);
	}
	printf("%d", nbr[0]);
	printf("%d", nbr[1]);
	printf("%d", nbr[2]);
	printf("%d", nbr[3]);
	printf("%d", nbr[4]);
	printf("%d", nbr[5]);
	printf("%d", nbr[6]);
	printf("%d", nbr[7]);
	printf("%d", nbr[8]);
	printf("%d", nbr[9]);
	printf("%d", nbr[10]);
	printf("%d", nbr[11]);
	printf("%d", nbr[12]);
	printf("%d", nbr[13]);
	printf("%d", nbr[14]);
	printf("%d", nbr[15]);
	return (0);
}


int main () 
{
	char str[] = "4321122243211222";
	ft_atoi(str);

	return (0);
}