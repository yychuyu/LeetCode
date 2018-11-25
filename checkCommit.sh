#!/bin/bash
# $1 username

function getUserAddCommit()
{
    if [ $# -lt 1 ]
    then
        echo -e "para error"
        return 0
    fi
    echo -e "$lastWeek $today"
    #git log --since=$1 --until=$2 --author="$3" --oneline --name-status >tmp.txt
    git log --since=1.weeks --author="$1" --oneline --name-status >tmp.txt
    addNum=`sed -n "/^A/p" tmp.txt |wc -l`
#echo -e "$addNum"
    return $addNum
}
#$1 days ago
function getDate()
{
    date1=$(date +%Y-%m-%d  --date '2 days ago') 
#echo -e "$date1"
}
# $1 list 
# $2 output
main()
{
 getUserAddCommit yanbinghu
num=$?
echo -e "$num"


}
main
