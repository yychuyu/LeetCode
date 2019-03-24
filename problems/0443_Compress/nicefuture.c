int insert(char* chars, int position, int num) {
    int index = position;
    do {
        for (int i = index; i > position; i--) {
            chars[i] = chars[i-1];
        }
        chars[position] = num % 10 + '0';
        index++;
        num /= 10;
    } while (num > 0);
    
    return index;
}

int compress(char* chars, int charsSize) {
    int index = 0;
    
    for (int i = 0; i < charsSize; ) {  // 此处不要再 i++ 
        char c = chars[i];
        int cnt = 0;
        while (i < charsSize && chars[i] == c) {
            i++;
            cnt++;
        }
        chars[index++] = c;
        if (cnt > 1) {  // 12 要拆成数字 '1' '2'  这里算法应该可以更优美
            index = insert(chars, index, cnt);  // 把数字插入到列表中
        }
    }
    // printf("%d\n", index);
    return index;
}
