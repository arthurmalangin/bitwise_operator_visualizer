#include <unistd.h>
#include <stdio.h>

#define RED_COLOR "\033[0;31m"
#define DEFAULT_COLOR "\033[0m"
#define GREEN_COLOR "\033[0;32m"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

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
    

    printf("\033[0;32mCODE: \033[0;33m%c\033[0;32m << \033[0;33m%c\033[0;32m)\033[0m\n", value[0], value2[0]);
	write(1, "\033[0;31mOLD      \033[0;32mNEW\n", 33);
	write(1, RED_COLOR, ft_strlen(RED_COLOR));
    display_character(value[0]);
    bit = value[0] << ft_atoi(&value2[0]);
    write(1, " ", 1);
	write(1, GREEN_COLOR, ft_strlen(GREEN_COLOR));
    display_character(bit);
    write(1, "\n", 1);
	write(1, DEFAULT_COLOR, ft_strlen(DEFAULT_COLOR));
}

int rightshift(char *value, char *value2)
{
    int bit;
    
    printf("\033[0;32mCODE: \033[0;33m%c\033[0;32m >> \033[0;33m%c\033[0;32m)\033[0m\n", value[0], value2[0]);
	write(1, "\033[0;31mOLD      \033[0;32mNEW\n", 33);
	write(1, RED_COLOR, ft_strlen(RED_COLOR));
    display_character(value[0]);
    bit = value[0] >> ft_atoi(&value2[0]);
    write(1, " ", 1);
	write(1, GREEN_COLOR, ft_strlen(GREEN_COLOR));
    display_character(bit);
    write(1, "\n", 1);
	write(1, DEFAULT_COLOR, ft_strlen(DEFAULT_COLOR));
}

int set_bit_0(char *value, char *value2)
{
    int bit;
    
	printf("\033[0;32mCODE: \033[0;33m%c\033[0;32m | (1 << \033[0;33m%c\033[0;32m)\033[0m\n", value[0], value2[0]);
	write(1, "\033[0;31mOLD      \033[0;32mNEW\n", 33);
	write(1, RED_COLOR, ft_strlen(RED_COLOR));
    display_character(value[0]);
    bit = value[0] | (1 << ft_atoi(&value2[0]));
    write(1, " ", 1);
	write(1, GREEN_COLOR, ft_strlen(GREEN_COLOR));
    display_character(bit);
    write(1, "\n", 1);
	write(1, DEFAULT_COLOR, ft_strlen(DEFAULT_COLOR));
}

int set_bit_1(char *value, char *value2)
{
    int bit;
    
	printf("\033[0;32mCODE: \033[0;33m%c\033[0;32m & ~(1 << \033[0;33m%c\033[0;32m)\033[0m\n", value[0], value2[0]);
	write(1, "\033[0;31mOLD      \033[0;32mNEW\n", 33);
	write(1, RED_COLOR, ft_strlen(RED_COLOR));
    display_character(value[0]);
    bit = value[0] & ~(1 << ft_atoi(&value2[0]));
    write(1, " ", 1);
	write(1, GREEN_COLOR, ft_strlen(GREEN_COLOR));
    display_character(bit);
	write(1, "\n", 1);
	write(1, DEFAULT_COLOR, ft_strlen(DEFAULT_COLOR));
}

int	toggle_bit(char *value, char *value2)
{
    int bit;
    
	printf("\033[0;32mCODE: \033[0;33m%c\033[0;32m ^ (1 << \033[0;33m%c\033[0;32m)\033[0m\n", value[0], value2[0]);
	write(1, "\033[0;31mOLD      \033[0;32mNEW\n", 33);
	write(1, RED_COLOR, ft_strlen(RED_COLOR));
    display_character(value[0]);
    bit = value[0] ^ (1 << ft_atoi(&value2[0]));
    write(1, " ", 1);
	write(1, GREEN_COLOR, ft_strlen(GREEN_COLOR));
    display_character(bit);
    write(1, "\n", 1);
	write(1, DEFAULT_COLOR, ft_strlen(DEFAULT_COLOR));
}

