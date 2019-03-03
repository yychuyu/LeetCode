/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s){
			var str = '';//存放当前最大无重复项字符串
			var len = 0;//存放当前当前最大无重复项字符串长度
			for(var i=0;i<s.length;i++){
				var char = s.charAt(i);
				var index = str.indexOf(char);
				if(index === -1){  //遍历s将元素挨个放入到str中，每放入一次判断str中是否有重复项
					str += char;
					len = len<str.length?str.length:len;//记录最大长度项,每次重新记录str进行判断，是否大于上次一次最大项
				}
				else{
					str = str.substr(index + 1) + char; //从当前重复项开始重新记录str
				}
			}
			return len;
}
