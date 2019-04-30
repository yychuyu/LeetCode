bool isLongPressedName(char * name, char * typed){
    char *n = name, *t = typed;
    
    while (*n != '\0' && *t != '\0') {
        int ncnt = 0;
        char nori = *n;
        while (*n != '\0' && *n == nori) {
            n++;
            ncnt++;
        }
        
        int tcnt = 0;
        char tori = *t;
        while (*t != '\0' && *t == tori) {
            t++;
            tcnt++;
        }
        
        if (!(nori == tori && ncnt <= tcnt)) return false;
    }
    
    if (*n == '\0' && *t == '\0') return true;
    else return false;
}


