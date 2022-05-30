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