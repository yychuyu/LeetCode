/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
     for (let i = 0; i < letters.length; i++) {
        if (letters[i] > target) {     
            return letters[i];
        }
    }
     return letters[0];
};