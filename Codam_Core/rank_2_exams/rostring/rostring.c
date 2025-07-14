/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rostring.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 15:10:35 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/06 16:28:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int is_alphanum(int letter)
{
	if (
			(letter >= 'a' && letter <= 'z')
			|| (letter >= 'A' && letter <= 'Z')
			|| (letter >= '0' && letter <= '9')
	   )
	   return (1);

	return (0);
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	char *extracted_word;
	int inside_word = 0;
	int	alpha_num = 0;
	int i_string = 0;
	int i_first_word = 0;

	if (argc != 2)
		return (write(1, "\n", 1), 1);
	while (str[i_string])
	{
		if (str[i_string] == ' ' || str[i_string] == '	')
			i_string++;
	}
	alpha_num = is_alphanum(str[i_string]);
	while (str[i_string] && str[i_string])
	{
		
	}
	return 0;
}
