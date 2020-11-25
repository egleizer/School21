/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:02:01 by phassan           #+#    #+#             */
/*   Updated: 2020/11/03 21:23:17 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <strings.h>

char    f(unsigned int a, char b)
{
	(void) a;
	return (b);
}

int	main(int argc, char *argv[])
{
//Test for memset

	(void) argc;
	char str[39] = "GeeksForGeeks is for programming geeks.";

	printf("\n Test for memset \n");
	memset(str + 13, '.', 8*sizeof(char));
	printf("After real  memset():  %s \n", str);
	ft_memset(str + 13, 'a', 8*sizeof(char));
	printf("After custom  memset():  %s \n", str);

//Test for bzero

	char b_str[50]  = "GeeksForGeeks is for programming geeks.";

	printf("\n Test for bzero \n");
	bzero(b_str + 13, 8*sizeof(char));
	printf("After real  bzero():  %s \n", b_str);
	ft_bzero(b_str + 13, 8*sizeof(char));
	printf("After custom  bzero():  %s \n", b_str);

//Test for meemcpy
	char str1[] = "GeeksGeeks";
	char str2[] = "Quiz";
	char str3[] = "Hello";

	printf("\n Test for memcpy \n");
	printf("Init %s \n", str1);
	memcpy (str1, str2, 9);
	printf("After real  memcpy():  %s \n", str1);
	ft_memcpy (str1, str3, 5);
	printf("After custom  memcpy():  %s \n", str1);

//Test for meemccpy
	char ccpy_str1[] = "GeeksGeeks";
	char ccpy_str2[] = "auiz";
	char ccpy_str3[] = "Healo";
	void *answer;

	printf("\n Test for memccpy \n");
	answer = memccpy(ccpy_str1, ccpy_str2, 97, 4);
	printf("After real  memccpy():  %s \n", answer);
	answer = ft_memccpy (ccpy_str1, ccpy_str3, 97, 4);
	printf("After custom  memccpy():  %s \n", answer);

//Test for memmove
	char move_str1[] = "abcdefghijklmno";

	printf("\n Test for memmove \n");
	memmove (move_str1, move_str1+2, 4);
	printf("After real  memmove():  %s \n", move_str1);
	ft_memmove (move_str1, move_str1+2, 4);
	printf("After custom  memmove():  %s \n", move_str1);

//Test for memchr
	char s[]= "oofrbcdef";

	void *answer_chr = memchr(s, 97, 5);
	void *answer_memchr = ft_memchr(s, 97, 5);
	printf("Answer of real function is %s\n", answer_chr);
	printf("Answer of custom function is %s\n", answer_memchr);

//Test for memcmp
	char cmp_s1[] = "oofrbcdef";
	char cmp_s2[] = "oofracdef";

	printf("\n Test for memcmp \n");
	int answer_memcmp = memcmp(cmp_s1, cmp_s2, 5);
	int answer_memcmp2 = ft_memcmp(cmp_s1, cmp_s2, 5);
	printf("Answer of real function is %d\n", answer_memcmp);
	printf("Answer of custom function is %d\n", answer_memcmp2);

//Test for strlen
	char strlen_s[] = "oofrbcdef";

	printf("\n Test for strlen \n");
	int answer_strlen = strlen(strlen_s);
	int answer_strlen2 = ft_strlen(strlen_s);
	printf("Answer of real function is %d\n", answer_strlen);
	printf("Answer of custom function is %d\n", answer_strlen2);

//Test for strlcpy
	char strlcpy_dst[] = "abcdef";
	char strlcpy_src[] = "hello";

	printf("\n Test for strlcpy \n");
	printf("Answer of real function is %lu\n", strlcpy(strlcpy_dst, strlcpy_src, 4));
	printf("Answer of custom function is %lu\n", ft_strlcpy(strlcpy_dst, strlcpy_src, 4));

//Test for strlcat
	char strlcat_dst[2] = "a\0";
	char strlcat_src[27] = "lorem ipsum dolor sit amet\0";

	printf("\n Test for strlcat \n");
	printf("Answer of real function is %lu\n", strlcat(strlcat_dst, strlcat_src, 0));
	printf("Answer of custom function is %lu\n", ft_strlcat(strlcat_dst, strlcat_src, 0));

//Test for strchr
	char strchr_s[] = "abcdef";
	int	 strchr_c = 97;

	printf("\n Test for strchr \n");
	printf("Answer of real function is %s\n", strchr(strchr_s, strchr_c));
	printf("Answer of custom function is %s\n", ft_strchr(strchr_s, strchr_c));

//Test for strrchr
	char strchrr_s[] = "";
	int  strchrr_c = '\0';

	printf("\n Test for strrchr \n");
	printf("Answer of real function is %s\n", strrchr(strchrr_s, strchrr_c));
	printf("Answer of custom function is %s\n", ft_strrchr(strchrr_s, strchrr_c));

//Test for strnstr
	char hay[] = "bonjour";
	char ne[] = "\0";

	printf("\n Test for strnstr \n");
	printf("Answer of real function is %s\n", strnstr(hay, ne, 7));
	printf("Answer of custom function is %s\n", ft_strnstr(hay, ne, 7));

//Test for strncmp
	char strncmp1[] = "test\200";
	char strncmp2[] = "";

	printf("\n Test for strncmp \n");
	printf("Answer of real function is %d\n", strncmp(strncmp1, strncmp2,0));
	printf("Answer of custom function is %d\n", ft_strncmp(strncmp1, strncmp2,0));

//Test for atoi
	char atoi_s[] = "     +123sfjhga";

	printf("\n Test for atoi \n");
	printf("Answer of real function is %d\n", atoi(atoi_s));
	printf("Answer of custom function is %d\n", ft_atoi(atoi_s));

//Test for isalpha
	int alpha_i = 67;

	printf("\n Test for isalpha \n");
	printf("Answer of real function is %d\n", isalpha(alpha_i));
	printf("Answer of custom function is %d\n", ft_isalpha(alpha_i));

//Test for isdigit
	int digit_i = 67;

	printf("\n Test for isdigit \n");
	printf("Answer of real function is %d\n", isdigit(digit_i));
	printf("Answer of custom function is %d\n", ft_isdigit(digit_i));

//Test for isalnum
	int alnum_i = 67;

	printf("\n Test for isalnum \n");
	printf("Answer of real function is %d\n", isalnum(alnum_i));
	printf("Answer of custom function is %d\n", ft_isalnum(alnum_i));
//Test for isascii
	int ascii_i = 67;

	printf("\n Test for isascii \n");
	printf("Answer of real function is %d\n", isascii(ascii_i));
	printf("Answer of custom function is %d\n", ft_isascii(ascii_i));

//Test for isprint
	int print_i = 67;

	printf("\n Test for isprint \n");
	printf("Answer of real function is %d\n", isprint(print_i));
	printf("Answer of custom function is %d\n", ft_isprint(print_i));

//Test for toupper
	int up_i = 97;

	printf("\n Test for toupper \n");
	printf("Answer of real function is %d\n", toupper(up_i));
	printf("Answer of custom function is %d\n", ft_toupper(up_i));

//Test for tolower
	int dw_i = 65;

	printf("\n Test for tolower \n");
	printf("Answer of real function is %d\n", tolower(dw_i));
	printf("Answer of custom function is %d\n", ft_tolower(dw_i));

//Test for calloc

	size_t calloc_count = 5;
	size_t calloc_size = 3;

	printf("\n Test for calloc \n");
	printf("Answer of real function is %s\n", calloc(calloc_count, calloc_size));
	printf("Answer of custom function is %s\n", ft_calloc(calloc_count, calloc_size));

//Test for strdup
	const char strdup_s[] = "hello";

	printf("\n Test for strdup_s \n");
	printf("Answer of real function is %s\n", strdup(strdup_s));
	printf("Answer of custom function is %s\n", ft_strdup(strdup_s));

//Test for ft_substr
	char const substr_s[] = "hello";
	unsigned int substr_star = 2;
	size_t substr_l = 2;

	printf("\n Test for substr \n");
	printf("Answer of real function is \n");
	printf("Answer of custom function is %s\n", ft_substr(substr_s, substr_star, substr_l));

//Test for ft_strjoin

	char const strjoin_s1[] = "hello";
	char const strjoin_s2[] = "test";

	printf("\n Test for strjoin \n");
	printf("Answer of real function is \n");
	printf("Answer of custom function is %s\n", ft_strjoin(strjoin_s1, strjoin_s2));

//Test for ft_strtrim
	char const strtrim_s[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char const strtrim_set[] = "\t \n";

	printf("\n Test for strtrim \n");
	printf("Answer of real function is \n");
	printf("Answer of custom function is %s\n", ft_strtrim(strtrim_s, strtrim_set));

//Test for ft_split
	//char const split_s[] = "chellochellochelloccchellocpoic";
	//char split_c = 'c';
	char const split_s[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
	char split_c = 'z';
	char **split_a = ft_split(split_s, split_c);

	printf("\n Test for split \n");
	printf("Answer of real function is \n");
	printf("Answer of custom function is \n");
	while (*split_a != 0)
	{
		printf("%s \n", *split_a);
		split_a++;
	}

//Test for ft_itoa
	int itoa_n = -2147483648LL;

	printf("\n Test for itoa \n");
	printf("Answer of real function is \n");
	printf("Answer of custom function is %s\n", ft_itoa(itoa_n));

//Test for ft_strmapi
	char const strmapi_s[] = "abc";
	//  char (*strmapi_f)(unsigned int a, char b) = f;

	printf("\n Test for strmapi \n");
	printf("Answer of real function is \n");
	printf("Answer of custom function is %s\n", ft_strmapi(strmapi_s, f));

//Test for ft_putchar_fd
	char putchar_fd_c = 'j';
	int file;

	file = open(argv[1], O_WRONLY);
	ft_putchar_fd(putchar_fd_c, file);

	printf("\n Test for ft_putchar_fd \n");
	printf("Answer of real function is \n");
	// printf("Answer of custom function is %s\n", ft_putchar_fd(putchar_fd_c, file));

//Test for ft_putstr_fd
	char putstr_fd[] = "abc";

	ft_putstr_fd(putstr_fd, file);

	printf("\n Test for ft_putchar_fd \n");
	printf("Answer of real function is \n");

//Test for ft_putendl_fd

	char putendl_fd[] = "opl";

	ft_putendl_fd(putendl_fd, file);

	printf("\n Test for ft_putendl_fd \n");
	printf("Answer of real function is \n");

//Test for ft_putnbr_fd

	int putnbr_fd = 5;

	ft_putnbr_fd(putnbr_fd, file);

	printf("\n Test for ft_putnbr_fd \n");
	printf("Answer of real function is \n");

	return (0);
}