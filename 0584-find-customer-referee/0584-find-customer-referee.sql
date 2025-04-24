# Write your MySQL query statement below
select name
from customer 
where referee_id  IS null || referee_id != 2   