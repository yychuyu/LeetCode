class Solution {
	public String minWindow(String s, String t) {

		if (s.length() == 0 || t.length() == 0) {
			return "";
		}

		// 建立映射计数
		Map<Character, Integer> temp = new HashMap<>();

		for (char c : t.toCharArray()) {
			temp.put(c, temp.getOrDefault(c, 0) + 1);
		}

		// 字符串转换为数组
		char[] ss = s.toCharArray();

		// 建立双指针
		int head = 0, tail = 0;

		// 记录最小宽度 以及当时尾指针位置
		int min = s.length();
		int mt = -1;

		// 开始搜索
		for (int size = temp.size(); head < s.length(); head++) {
			// 计数搜寻（头指针向后移动）
			if (temp.keySet().contains(ss[head])) {
				Integer num = temp.get(ss[head]);
				temp.put(ss[head], num - 1);
				if (num == 1)
					size--;
			}

			// 缩小范围（当窗口满足条件，尾指针开始追赶;不满足条件时停止追赶）
			if (size == 0) {
				do {
					if (temp.keySet().contains(ss[tail])) {
						Integer num = temp.get(ss[tail]) + 1;
						temp.put(ss[tail], num);
						if (num == 1)
							size++;
					}
					tail++;
				} while (size == 0);

				// 记录最小值
				if (head - tail + 1 < min) {
					mt = tail - 1;
					min = head - mt;
				}
			}
		}

		return mt == -1 ? "" : s.substring(mt, mt + min + 1);
	}
}

