static char	**ft_matrix_posit(char **matrix, char *strim, char c)
{
	size_t	word;
	int		i;	
	int		j;
	int		w_ini;
	int		w_len;

	word = 0;
	i = 0;
	j = 0;
	w_ini = 0;
	w_len = 0;
	while (word <= ft_calcrows(strim, c) && strim[i] != '\0')
	{
		w_ini = i;
		while (strim[i] != c && strim[i] != '\0')
		{	
			w_len++;
			i++;
		}
		while (strim[i] == c)
			i++;
		matrix[word] = (char *)ft_calloc((w_len + 1), sizeof(char));
		if (!matrix)
		{
			ft_freedom(matrix, word);
			return (NULL);
		}
		while (j < w_len)
		{
			matrix[word][j] = strim[w_ini + j];
			j++;
		}
		matrix[word][j] = '\0';
		w_ini = i;
		word++;
		j = 0;
		w_len = 0;
	}
	return (matrix);
}