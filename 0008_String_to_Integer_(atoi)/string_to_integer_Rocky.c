int myAtoi(char* str) {
    int n = 0, newN, sign;
    while (isspace(*str))
        str++;
    sign = 1;
    if (*str == '+') 
        str++;
    else if  (*str == '-') {
        str++;
        sign = -1;
    }
    while (*str == '0')
        str++;
    while (isdigit(*str)) {
        newN = n * 10 + (*str - 48);
        if ((newN > 0) && (newN > n))
            n = newN;
        else return (sign == 1) ? 2147483647 : -2147483648;
        str++;
    }
    return n * sign;
}
