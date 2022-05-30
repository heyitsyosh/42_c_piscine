#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUF_SIZE 512

Items (or some struct) **type;
type = malloc(sizeof (Items *) * column);

int i = 0;
while (i < column)

int main(void)
{
    // 変数定義
    int fd1, fd2;
    int byte_num;
    char buf[BUF_SIZE];

    // 変数初期化
    fd1 = 0;
    fd2 = 0;
    byte_num = 0;
    memset(buf, '\0', BUF_SIZE);

    // ファイルのオープン
    fd1 = open("../test2", O_RDONLY);  // 読み込み専用でファイルを開く
	
	char	*first_line;
	char	c;
	int		first_line_len;

	first_line_len = 0;
	//first_line = malloc(); do you need to? idk how to
	while ((read(fd1, &c, 1) == 1)  //take first line as char array. What is the biggest possible length of the first line? should I add that to the while argument?
	{
		first_line[first_line_len] = c;
		if (c == '\n')
			break ;
		first_line_len++;
	} 
//malloc for second line
	if (first_line_len < 4)
		//put in error
//get width
		int get_second_line(first_line_len, 0);
		int get_second_line(int first_line_len, int char c)
	{
		c = 0;
		int *second_line_len;
		char *second_line;
		int *line_lengths;
		while (read(fd1, &c, 1) == 1)
		{
			second_line[first_line_len] = c;
			second_line_len++;
			if (c == '\n')
				break ;
		}
		}
	if (fd1 == -1)
		map_error();
	int index;
	int count;
	while ((read(fd1, &c, 1) == 1 && i != '\0')
	{
		count = 0;
		while (c != '\n' && count < second_line_len)
			count++;
		line_lengths[index] = count;
		index++;
	}
	line_lengths[index] = '\0';
	if (index != nbr)
		map_error();

	int check_lines()
	{
		
	}
	/*
	check_line_lengths()
	{
		check_dbl = x + 1;
		while (line_lengths[index])
		{
			if (line_lengths[x] == line_lengths[check_dbl])
				return (0);
			check_dbl++;
		}
		x++;
	} てかここ上でやってるからいらないか。。。
	*/
	void make_symbols(first_line, first_line_len, first_line_len); 
	//check printability of the last 3 elements of the first_line array and write them into new symbols array. 
	//check that last 3 dont repeat.
	char *make_symbols(char *first_line, int first_line_len, int i)
	{
		int j;
		int check_dbl;

		j = 0;
		char *symbols;
		while (--i >= first_line_len - 4 && first_line[i] > 31 && first_line[i] < 127)
		{
			symbols[j] = first_line[i];
			j++;
		}
		while (symbols[x])
		{
			check_dbl = x + 1;
			while (symbols[check_dbl])
			{
				if (symbols[x] == symbols[check_dbl])
					//put in error
				check_dbl++;
			}
			x++;
		}
		return (symbols);
	}

	rows = make_row_int(char *first_line, int first_line_len, 0);
	int make_row_int(char *first_line, int first_line_len, int i)
	{
		int nbr;

		while (i < first_line_len - 4 && ((str[i] >= '0') && (str[i] <= '9')))
		{
			nbr = (nbr * 10) + (str[i] - '0');
			i++;
		}
		if (str[i] < 0 && str[i] > 9)
			//put in error
		return (nbr);
	}

	}


/*
What I think I wanna do (i rly dont think im going in the right direction tho)
read till the first \n
then take the 3 chars before
and put into char pointer (check for rule 4, 5, 6)
then take all the chars before that (and check that theyre all nums) 
and put into int var
then make a loop that reads each byte into 2D array (check for rule 4)
and goes to next row each time it hits \n 
(and has counter array that can be used later to determine how many chars are in each row to check rule 1, 3?)

check for 2? integrate error for no parameters or two maps into int main.

-What to do...
figure out how to allocate dynamic array!!!	全然わからん
omg omg i got it... i think 
Get the first line, figure out how many lines theres supposed to be. then make dynamic array using how many lines. 
Then u can put each line into the 2D dynamic array!!!!!!!! i think...

.ox --> char pointer
take out number before .ox (num of lines)
read until first \n
read until second \n (number of columns)

check map 
• Definition of a valid map :
1 All lines must have the same length.
2 There’s at least one line of at least one box.
3 At each end of line, there’s a line break.
4 The characters on the map can only be those introduced in the first line.
5 The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
6 The characters can be any printable character, even numbers.
7 In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map
*/