# Write your MySQL query statement below
select Department,Employee,Salary from 
(
select e.name as Employee ,
e.salary as Salary,
d.name as Department,
dense_rank() over(partition by e.departmentId order by e.salary desc) as ranking
from Employee e
join Department d
on e.departmentId=d.id
) t
where ranking =1;