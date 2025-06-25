# Write your MySQL query statement below
select 
 st.student_id , 
 st.student_name ,
 sub.subject_name , 
 COUNT(E.subject_name) AS attended_exams 

from Students st 

cross join Subjects sub

left join Examinations E 
 on  st.student_id  = E.student_id 
 and sub.subject_name = E.subject_name
group by sub.subject_name , st.student_id 
order by st.student_id ASC , sub.subject_name ASC