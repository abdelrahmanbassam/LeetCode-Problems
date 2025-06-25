# Write your MySQL query statement below
select m.name
from employee m 
join employee e on m.id = e.managerId 
group by m.id
having count(*) >= 5