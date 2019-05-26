class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<List<String>>();
        queens(result, n, 1, new String[n],
                new int[n + 1], new int[2 * n + 1], new int[2 * n + 1]);
        return result;
    }
    
    /**
     * 从1行开始，逐行扫描
     * 同行判断：单调递增，不作处理
     * 同列判断：j列未被占用，colums[i]=1，表示j列已被占用
     * 左下判断：i+j未被占用，位置坐标特点：x + y恒定
     * 右下判断：i-j+n未被占用，位置坐标特点：x - y恒定
     */
    void queens(List<List<String>> result, int n, int i, String[] lines,
                       int[] columns, int[] lDown, int[] rDown) {
        if (i > n) {
            // 数据复制，防止篡改
            result.add(new ArrayList<String>(Arrays.asList(lines)) );
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (columns[j] == 0 && lDown[i + j] == 0 && rDown[i - j + n] == 0) {
                // 设置占用，i行j列
                char[] line = new char[n];
                Arrays.fill(line, '.');
                line[j - 1] = 'Q';
                lines[i - 1] = new String(line);
                // 同列设置、左下设置、右下设置
                columns[j] = lDown[i + j] = rDown[i - j + n] = 1;
                // 继续i+1行，逐行扫描
                queens(result, n, i + 1, lines, columns, lDown, rDown);
                // 数据清理，结构复用
                columns[j] = lDown[i + j] = rDown[i - j + n] = 0;
            }
        }
    }
}