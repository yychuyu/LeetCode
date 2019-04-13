/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
  let min = 0
  let max = A.length - 1
  while (min <= max) {
    let mid = ~~((min + max) / 2)
    if (A[mid] < A[mid + 1]) {
      min = mid
    } else if (A[mid] < A[mid - 1]) {
      max = mid
    } else {
      return mid
    }
  }
};