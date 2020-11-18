size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);



int main(void)
{
        char strlcpy_s1[] = "oofrbcdef";
        char strlcpy_s2[] = "abc";


        printf("\n Test for strlcpy \n");
        int answer_strlcpy = strlcpy(strlcpy_s1, strlcpy_s2, 2);
        int answer_strlcpy2 = ft_strlen(strlcpy_s1, strlcpy_s2, 2);
        printf("Answer of real function is %d\n", answer_strlcpy);
        printf("Answer of custom function is %d\n", answer_strlcpy2);
}
