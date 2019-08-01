import "fmt"

//用遞迴的方式實作
func LetterCombinations(digits string) []string {
	if len(digits) < 1 {
		return []string{}
	}
	if len(digits) == 1 {
		switch digits {
		case "2":
			return []string{"a", "b", "c"}
		case "3":
			return []string{"d", "e", "f"}
		case "4":
			return []string{"g", "h", "i"}
		case "5":
			return []string{"j", "k", "l"}
		case "6":
			return []string{"m", "n", "o"}
		case "7":
			return []string{"q", "p", "r", "s"}
		case "8":
			return []string{"t", "u", "v"}
		case "9":
			return []string{"w", "x", "y", "z"}
		case "0":
			return []string{" "}
		default:
			return []string{""}
		}
	}

	r := make([]string, 0)

	for _, front := range LetterCombinations(digits[:1]) {
		fmt.Println("digits[:1]", digits[:1], "value", front)
		for _, back := range LetterCombinations(digits[1:]) {
			fmt.Println("digits[1:]", digits[1:], "value", back)
			r = append(r, front+back)
		}
	}

	return r

}