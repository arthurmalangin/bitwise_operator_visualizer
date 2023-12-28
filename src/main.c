#include <stdio.h>
#include <unistd.h>

int leftshift(char *value, char *value2);
int rightshift(char *value, char *value2);
int set_bit_0(char *value, char *value2);
int set_bit_1(char *value, char *value2);

void	print_help(void)
{
	printf("=========================================================\n");
	printf("List of operator: \"<<\" \">>\" \"| <<\" \"& ~ <<\"\n");
	printf("Example:\n");
	printf("		- ./a.out \"10\" \"<<\" \"2\"\n");
	printf("		- ./a.out \"2\" \"| <<\" \"1\"\n");
	printf("		- ./a.out \"5\" \"& ~ <<\" \"5\"\n");
	printf("=========================================================\n");
}

int compare_str(char *str, char *comparator)
{
	int	i;
	int y;

	i = 0;
	while(str[i])
	{
		if(str[i] == comparator[0])
		{
			y = 0;
			while(str[i + y] == comparator[y] && str[i + y] && comparator[y])
			{
				y++;
			}
			if (!comparator[y])
				return (1);
		}
		i++;
	}
	return (0);
}

int	getOperator(char *src)
{
	int i;

	i = 0;
	if (src[i])
	{
		if (compare_str(src, "| <<")) // Met le bit voulu a 0
			return (3);
		else if (compare_str(src, "& ~ <<")) // Met le bit voulu a 1
			return (4);
		else if (compare_str(src, "<<")) // Decale a gauche
			return (1);
		else if (compare_str(src, ">>")) // Decale a droite
			return (2);		
	}
	return (0);
}

void operation(int operator, char *value, char *value2)
{
	if (!operator)
		print_help();
	if (operator == 1)
		leftshift(value, value2);
	if (operator == 2)
		rightshift(value, value2);
	if (operator == 3)
		set_bit_0(value, value2);
	if (operator == 4)
		set_bit_1(value, value2);
}

int main(int argc, char **argv)
{
	int operator;

	if (argc != 4)
	{
		print_help();
		return (1);
	}
	operator = getOperator(argv[2]);
	operation(operator, argv[1], argv[3]);
	return (0);
}