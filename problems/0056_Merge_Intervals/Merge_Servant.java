package algorithm._056_merge;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
����һ������ļ��ϣ���ϲ������ص������䡣
ʾ�� 1:
	����: [[1,3],[2,6],[8,10],[15,18]]
	���: [[1,6],[8,10],[15,18]]
	����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ�� 2:
	����: [[1,4],[4,5]]
	���: [[1,5]]
	����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
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
		//�ȸ���List�б��е�Interval�����startֵ��������
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
		//��ǰ��Interval��������һ��Interval������жԱȿ������Ƿ�����ص�
		//�����һ��Interval�����startС�ڵ�ǰInterval�����end,���ʾ�����ص�
		//������ı䵱ǰ��������𲢰���һ�������Ƴ�,�����õ�ǰ�������Ƴ�һ������֮�����һ��������бȽ�
		//����������ת��һ�¸�����
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
