/**
 * @param {number[]} prices
 * @return {number}
 */

// 超时代码
var maxProfit = function(prices) {
    let  profits = []
    for (let it in prices) {
        profits[it] = 0
        for (let key in profits) {
            let fit = prices[it] - prices[key]
            if (fit > profits[key]) {
                profits[key] = fit
            }
        }
    }
    let result = 0
    for (let item of profits) {
        if (item > result) {
            result = item
        }
    }
    return result
}

// 已经战胜 22.64 % 的 javascript 提交记录
var maxProfit = function(prices) {
    let flag = true
    for (let i = 1; i < prices.length; i++) {
        if (prices[i - 1] < prices[i]) {
            flag = false
        }
    }
    if (flag) {
        return 0
    }
    let  result = 0
    for (let it = 0; it < prices.length; it++) {
        let midMax = prices[it]
        for (let i = it + 1; i < prices.length; i++) {
            if (prices[i] > midMax) {
                midMax = prices[i]
            }
        }
        let profit = midMax - prices[it]
        if (result < profit) {
            result = profit
        }
    }
    return result
}

console.log('result: ', maxProfit([7, 1, 5, 3, 6, 4]))
console.log('result: ', maxProfit([7, 6, 4, 3, 1]))
console.log('result: ', maxProfit([1, 2]))
