#include "../stack_list/stack_list.h"

t_bool	checkBracketMatching(char *exp);

int main(void)
{
	char	*str1 = "( ( A + B ) / C ) - { ( D + E ) && ( F - G ) }";
	char	*str2 = "( ( A + B ) / C  - { ( D + E ) && ( F - G ) ) }";
	char	*str3 = "(((()(){()()}";
	t_bool	bool;

	bool = checkBracketMatching(str1);
	if (bool == TRUE)
		printf("'%s' is matched.\n", str1);
	else
		printf("'%s' is unmatched\n", str1);

	bool = checkBracketMatching(str2);
	if (bool == TRUE)
		printf("'%s' is matched.\n", str2);
	else
		printf("'%s' is unmatched\n", str2);

	bool = checkBracketMatching(str3);
	if (bool == TRUE)
		printf("'%s' is matched.\n", str3);
	else
		printf("'%s' is unmatched\n", str3);
	//while (1);
	return (0);
}