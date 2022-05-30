#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUF_SIZE 512

int main(void)
{
	int fd1, fd2;
    int byte_num;
    char buf[BUF_SIZE];

    // 変数初期化
    fd1 = 0;
    fd2 = 0;
    byte_num = 0;
	char	*first_line;
	char	c;
	int		first_line_len;

	
	first_line_len = 0;
    memset(first_line, '\0', BUF_SIZE);

    // ファイルのオープン
    fd1 = open("../test2", O_RDONLY);  // 読み込み専用でファイルを開く
	//if (fd1 == -1)
	//{
		//put in error
	//}
	
	//first_line = malloc(); do you need to? idk how to
	while (read(fd1, &c, 1) == 1 && first_line[first_line_len - 1] != '\n')  //take first line as char array. What is the biggest possible length of the first line? should I add that to the while argument?
	{
		first_line[first_line_len] = c;
		printf("letter: %c, Times: %d", first_line[first_line_len], first_line_len);
		if (c == '\n')
			break ;
		first_line_len++;
	} 
	printf("Read end");
}