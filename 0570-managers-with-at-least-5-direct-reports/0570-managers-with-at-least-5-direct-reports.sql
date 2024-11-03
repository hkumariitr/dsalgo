# Write your MySQL query statement below
Select e1.name from Employee e1
cross join Employee e2
where e1.id = e2.managerId
-- having Count(*)>=5
group by e1.id
having Count(*)>=5;