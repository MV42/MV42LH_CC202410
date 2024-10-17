void	*memset(char *s, unsigned char c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		s[i++] = c;
}
