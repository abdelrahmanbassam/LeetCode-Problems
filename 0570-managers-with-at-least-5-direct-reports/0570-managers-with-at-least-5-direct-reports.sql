# Write your MySQL query statement below
select m.name 
from Employee m 
inner join Employee e on m.id = e.managerId
group by m.id
having count(*) >= 5 

