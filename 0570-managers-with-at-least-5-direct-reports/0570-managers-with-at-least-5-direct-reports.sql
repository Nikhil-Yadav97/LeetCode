select name from Employee where id IN(
select distinct(managerId)
from Employee
where managerId is not null
group by managerId
having count(*)>=5
);