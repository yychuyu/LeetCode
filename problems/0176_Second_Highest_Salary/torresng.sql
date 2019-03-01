/***************************************************************
*   Copyright (C) 2019 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/03/01
*
***************************************************************/
/**************************************************************
SQL Schema
    Create table If Not Exists Employee (Id int, Salary int)
    Truncate table Employee
    insert into Employee (Id, Salary) values ('1', '100')
    insert into Employee (Id, Salary) values ('2', '200')
    insert into Employee (Id, Salary) values ('3', '300')

Table: Person

Write a SQL query to get the second highest salary from the Employee table.

    +----+--------+
    | Id | Salary |
    +----+--------+
    | 1  | 100    |
    | 2  | 200    |
    | 3  | 300    |
    +----+--------+

For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.

    +---------------------+
    | SecondHighestSalary |
    +---------------------+
    | 200                 |
    +---------------------+

***************************************************************/

SELECT(
    SELECT DISTINCT Salary FROM Employee 
    ORDER BY Salary DESC 
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
