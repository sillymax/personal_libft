#include "libft.h"

int main()
{
	char	*str = "hi % 3.1  dam";
	printf("%s\n", ft_subdel(str, 3, 8));
	printf("%s\n", ft_substr(str, 3, 8));
}