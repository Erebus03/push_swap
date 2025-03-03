long ft_atol(const char *s)
{
	int i;
    int sign;
    long result;
    
    i = 0;
    sign = 1;
    result = 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    return result * sign;
}