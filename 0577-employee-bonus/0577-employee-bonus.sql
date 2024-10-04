# Write your MySQL query statement below
select Employee.name, Bonus.bonus 
from Employee 
left join Bonus on Employee.empid =  Bonus.empId
where bonus IS NULL || bonus < 1000 
