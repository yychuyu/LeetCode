package algorithm._056_merge;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
给出一个区间的集合，请合并所有重叠的区间。
示例 1:
	输入: [[1,3],[2,6],[8,10],[15,18]]
	输出: [[1,6],[8,10],[15,18]]
	解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:
	输入: [[1,4],[4,5]]
	输出: [[1,5]]
	解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

public class Merge {
	public static void main(String[] args) {
		List<Interval> list = new ArrayList<Interval>();
		list.add(new Interval(1, 3));
		list.add(new Interval(2, 6));
		list.add(new Interval(8, 10));
		list.add(new Interval(15, 18));
		List<Interval> newlist = merge(list);
		for (Interval interval : newlist) {
			System.out.println("[" + interval.start + "," + interval.end + "]");
		}
	}

	public static List<Interval> merge(List<Interval> intervals) {
		//先根据List列表中的Interval对象的start值进行排序
		Collections.sort(intervals, new Comparator<Interval>() {
			public int compare(Interval i1, Interval i2) {
				if (i1.start > i2.start) {
					return 1;
				} else if (i1.start < i2.start) {
					return -1;
				} else {
					return 0;
				}
			}
		});
		//当前的Interval对象与下一个Interval对象进行对比看区间是否存在重叠
		//如果下一个Interval对象的start小于当前Interval对象的end,则表示存在重叠
		//存在则改变当前对象的区别并把下一个对象移除,接着让当前对象是移除一个对象之后的下一个对象进行比较
		//不存在则跳转到一下个对象
		for (int i = 0; i < intervals.size() - 1;) {
			if (intervals.get(i + 1).start <= intervals.get(i).end
					&& intervals.get(i + 1).end >= intervals.get(i).start) {
				intervals.get(i).end = intervals.get(i).end >= intervals
						.get(i + 1).end ? intervals.get(i).end
								: intervals.get(i + 1).end;
				intervals.remove(i + 1);
				continue;
			}
			i++;
		}
		return intervals;
	}
}

class Interval {
	int start;
	int end;

	Interval() {
		start = 0;
		end = 0;
	}

	Interval(int s, int e) {
		start = s;
		end = e;
	}
}
