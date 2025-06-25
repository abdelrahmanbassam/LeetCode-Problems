# Write your MySQL query statement below
select name , Bonus 
FROM Employee e
LEFT JOIN Bonus b 
 ON e.empId = b.empId

where b.bonus  is null or b.bonus  < 1000