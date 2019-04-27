char rot[10] = {'0', '1', '5', '-', '-', '2', '9', '-', '8', '6'};  // index after rotated is rot[index]

bool isGoodNum(char* num)  // process as string
{
    bool flag = false;
    char *p = num;
    
    while (*p != '\0') {
        if (rot[*p-'0'] == '-') return false;
        else if (*p != rot[*p-'0']) {
            *p = rot[*p-'0'];
            flag = true;
        }
        p++;
    }
    if (flag) return true;
    else return false;  // num not change
}

int rotatedDigits(int N) {
    
    char num[10];
    int cnt = 0;
    for (int i=0; i<=N; i++) {
        sprintf(num, "%d\0", i);
        if (isGoodNum(num)) cnt++;
    }
    
    return cnt;
}
