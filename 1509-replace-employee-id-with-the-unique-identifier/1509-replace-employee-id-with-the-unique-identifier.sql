# Write your MySQL query statement below
Select u.unique_id as unique_id, e.name 
from Employees e
Left Join EmployeeUNI u ON e.id = u.id;