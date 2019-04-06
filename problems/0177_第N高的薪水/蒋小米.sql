CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    select salary into result from 
    (select id,salary,DENSE_RANK()  OVER(ORDER BY salary desc ) RANK from employee ) t
     where  rownum=1 and t.RANK = n ;
    RETURN result;
END;