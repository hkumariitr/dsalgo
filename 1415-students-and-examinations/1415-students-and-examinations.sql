# Write your MySQL query statement below
Select st.student_id, st.student_name,sub.subject_name,Count(e.subject_name) as attended_exams
from Students st
Cross join Subjects sub
Left Join Examinations e
on st.student_id = e.student_id and sub.subject_name = e.subject_name
group by st.student_id, st.student_name, sub.subject_name
order by st.student_id, sub.subject_name;