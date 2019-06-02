/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
      let f = Array(amount + 1).fill(Number.MAX_SAFE_INTEGER)
  f[0] = 0

  for (const c of coins) {
    for (let i = c; i <= amount; i++) {
      f[i] = Math.min(f[i], f[i - c] + 1)
    }
  }

  if (f[amount] === Number.MAX_SAFE_INTEGER) return -1
  return f[amount]
};