

int		map(void)
{
	write(2, "map error\n", 10);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	buf[2];

	i = 0;
	if (argc < 2)
	{
		buffer = malloc(sizeof(char*));
		while ((ret = read(0, &buf, 1)))
			buffer[i++] = *buf;
	}
	else if (argc >= 2)
	{
		
	else
		ft_putstr("too many arguments\n", 2);
	return (1);
}