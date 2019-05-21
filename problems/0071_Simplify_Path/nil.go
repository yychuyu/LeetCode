package SimplifyPath

import (
	"bytes"
	"fmt"
	"regexp"
	"strings"
)

func simplifyPath(path string) string {
	r := regexp.MustCompile("//+")
	path = r.ReplaceAllString(path, "/")
	if path[len(path)-1] == '/' {
		path = path[:len(path)-1]
	}
	pathItems :=  strings.Split(path, "/")
	fmt.Println("split: ", pathItems)
	stack := make([]string, 0)
	for _, item := range pathItems{
		if item == "." || item == "" {
			continue
		} else if item == ".." {
			if len(stack) == 0 {
				continue
			} else {
				stack = stack[:len(stack)-1]
			}
		} else {
			stack = append(stack, item)
		}
	}
	if len(stack) == 0 {
		return "/"
	}
	buf := bytes.NewBufferString("")
	for _, str := range stack {
		if str != "" {
			buf.WriteString(fmt.Sprintf("%s%s", "/", str))
		}
	}
	return buf.String()
}
