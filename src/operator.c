#include <unistd.h>

int	ft_atoi(const char *string)
{
	int	negative;
	int	i;
	int	nb;

	i = 0;
	negative = 1;
	nb = 0;
	while (string[i] == ' ' || string[i] == '\n' || string[i] == '\t'
		|| string[i] == '\v' || string[i] == '\f' || string[i] == '\r')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			negative = negative * -1;
		i++;
	}
	while (string[i] >= 48 && string[i] <= 57)
	{
		nb = nb * 10 + (string[i] - 48);
		i++;
	}
	return (nb * negative);
}

void	display_character(char c)
{
	int			bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			write(1, "0", 1);
		else
			write(1, "1", 1);
		bit--;
	}
}

int leftshift(char *value, char *value2)
{
    int bit;
    
    display_character(value[0]);
    bit = value[0] << ft_atoi(&value2[0]);
    write(1, " ", 1);
    display_character(bit);
    write(1, "\n", 1);
}

int rightshift(char *value, char *value2)
{
    int bit;
    
    display_character(value[0]);
    bit = value[0] >> ft_atoi(&value2[0]);
    write(1, " ", 1);
    display_character(bit);
    write(1, "\n", 1);
}

int set_bit_0(char *value, char *value2)
{
    int bit;
    
    display_character(value[0]);
    bit = value[0] | (1 << ft_atoi(&value2[0]));
    write(1, " ", 1);
    display_character(bit);
    write(1, "\n", 1);
}

int set_bit_1(char *value, char *value2)
{
    int bit;
    
    display_character(value[0]);
    bit = value[0] & ~(1 << ft_atoi(&value2[0]));
    write(1, "-", 1);
    display_character(bit);
    write(1, "\n", 1);
}

