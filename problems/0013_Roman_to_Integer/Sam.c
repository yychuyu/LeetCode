int romanToInt(char* s) {
    
    int sum =0;
    while ( *s != '\0')
    {
        switch(*s)
        {
            case 'I':
                if ( *(s+1) == 'V' )
                {
                    sum += 4;
                    s++;
                }
                else if ( *(s+1) == 'X')
                {
                    sum += 9;
                    s++;                    
                }
                else if ( ( *(s+1) == 'I' ) && ( *(s+2) == 'I' ) )
                {
                    sum += 3;
                    s += 2;                    
                }
                else
                {
                    sum += 1;
                }
                s++;
                break;
            case 'V':
                sum += 5;
                s++;
                break;
            case 'X':
                if ( *(s+1) == 'L')
                {
                   sum += 40;
                    s++;
                }
                else if ( *(s+1) == 'C')
                {
                    sum += 90;
                    s++;
                }
                else
                {
                    sum += 10;
                }
                s++;                
                break;
            case 'L':
                sum += 50;
                s++;
                break;
            case 'C':
                if ( *(s+1) == 'D')
                {
                   sum += 400;
                    s++;
                }
                else if ( *(s+1) == 'M' )
                {
                    sum += 900;
                    s++;
                }
                else 
                {
                    sum += 100;
                }
                s++;
                break;
            case 'D':
                sum += 500;
                s++;                
                break;
            case 'M':
                sum += 1000;
                s++;                
                break;
            default:
                break;             
        }
    }
    return sum;
}
