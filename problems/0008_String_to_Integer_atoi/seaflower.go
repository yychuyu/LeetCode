import (
	"math"
	"strconv"
)

func MyAtoi(str string) int {
	//先判斷是不是正常的字串, 再判斷正負, 再合成新的字串, 接下來就可以轉了
	//假設 "-123"
	//找出有效起始位置, 開始組裝

	if len(str) == 0 {
		return 0
	}
	strByte := []byte(str)
	Head := true
	var newStr []byte
	for i := 0; i < len(strByte); i++ {
		if strByte[i] == ' ' {
			if Head {
				continue
			} else {
				break
			}
		}
		if strByte[i] >= '0' && strByte[i] <= '9' || (strByte[i] == '-' || strByte[i] == '+') && Head {
			Head = false
			newStr = append(newStr, strByte[i])
			continue
		}
		break
	}

	res, _ := strconv.Atoi(string(newStr))

	if res > math.MaxInt32 {
		return math.MaxInt32
	}

	if res < math.MinInt32 {
		return math.MinInt32
	}

	return res

}