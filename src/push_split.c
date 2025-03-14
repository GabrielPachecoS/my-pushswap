
#include "../include/push_swap.h"

/*
 * Frees the memory allocated for a matrix of strings.
 * - Iterates through the array and frees each individual string.
 * - Finally, frees the array itself.
 */
void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

/*
 * Counts the number of words in a string, separated by the specified character.
 * - Ignores multiple consecutive separators.
 * - Returns the total number of words found.
 */
static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

/*
 * Retrieves the next word from the string, separated by the specified character.
 * - Maintains a static cursor to track the position in the string.
 * - Returns the next dynamically allocated word.
 */
static char	*get_next_word(char *str, char separator)
{
	static int	cursor;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	cursor = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

/*
 * Splits a string into an array of words using the specified separator.
 * - Uses `count_words` to determine the number of words.
 * - Uses `get_next_word` to extract each word.
 * - Returns an array of dynamically allocated strings.
 */
char	**push_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}