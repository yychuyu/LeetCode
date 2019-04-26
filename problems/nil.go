package InsertInterval


type Interval struct {
	Start int
	End   int
}


// 返回下一个要更新的index直接撞到
func locateEnd(startIndex, length, startVal, endVal int, nums []Interval, res *[]Interval){
	end := endVal
	var flag bool
	index := startIndex
	for ; index < length; index++ {
		if endVal < nums[index].Start {
			end = endVal
			flag = true
			break
		} else if endVal <= nums[index].End{
			end = nums[index].End
			break
		}
	}
	*res = append(*res, Interval{startVal, end})
	if index < length {
		if flag {
			*res = append(*res, nums[index:]...)
		} else {
			*res = append(*res, nums[index+1:]...)
		}
	}
}

func insert(intervals []Interval, newInterval Interval) []Interval {
	if len(intervals) == 0 {
		return []Interval{newInterval}
	}
	res := make([]Interval, 0)
	index := 0
	length := len(intervals)
	for ;index < length; index ++ {
		if newInterval.Start <= intervals[index].Start {
			locateEnd(index, length, newInterval.Start, newInterval.End, intervals, &res)
			return res
		} else if newInterval.Start <= intervals[index].End {
			locateEnd(index, length, intervals[index].Start, newInterval.End, intervals, &res)
			return res
		} else {
			res = append(res, intervals[index])
		}
	}
	if index == length {
		res = append(res, newInterval)
	}
	return res
}
