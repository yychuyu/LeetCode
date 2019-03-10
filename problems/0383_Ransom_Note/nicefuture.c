bool canConstruct(char* ransomNote, char* magazine) {
      // 'only contain lowercase letters' 由此确定计数数组的长度
      int cnt[26] = {}, len_ran=strlen(ransomNote), len_mag=strlen(magazine);  // strlen 不宜作为循环判断条件多次执行，会消耗大量无谓时间
      for (int i=0; i<len_ran; i++) {
          cnt[ransomNote[i]-'a'] += 1;
      }
      for (int i=0; i<len_mag; i++) {
          cnt[magazine[i]-'a'] -= 1;
      }
      for (int i=0; i<26; i++) {
          if (cnt[i] > 0) return false;
      }
      return true;
  }


/* 慢得不能再慢系列解法
bool canConstruct(char* ransomNote, char* magazine) {
    char *p = ransomNote;
    while (*p != '\0') {
        for (int i=0; i<=strlen(magazine); i++) {
            if (magazine[i] == *p) {
                magazine[i] = -1;  //只能被匹配一次
                break;
            }
            if (magazine[i] == '\0') return false;
        }
        p++;
    }
    return true;
}
*/
