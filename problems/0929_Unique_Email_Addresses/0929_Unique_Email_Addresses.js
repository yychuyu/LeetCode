/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    return [...new Set( emails.map(e => e.split('@')[0].split('.').join('').split('+')[0] + '@' + e.split('@')[1]))].length;
}
