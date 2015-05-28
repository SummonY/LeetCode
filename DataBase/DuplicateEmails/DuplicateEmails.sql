Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

Answer 1:
select DISTINCT a.Email
from Person a inner join Person b
on a.Email = b.Email
where a.Id <> b.Id


Answer 2:
select DISTINCT p1.Email
from Person p1, Person p2
where p1.Id != p2.Id and p1.Email = p2.Email


Answer 3:
select Email
from Person
GROUP BY Email
HAVING count(*) > 1


Answer 4:
select Email from 
(select Email, count(*) as count from Person
group by Email
having count > 1) as em


Answer 5:
select a.Email
from Person as a
left join (select * from Person group by Email) b
on a.Email = b.Email and a.Id = b.Id
where b.Email is null


Answer 6:
SELECT DISTINCT a.Email
from Person a
WHERE EXISTS(
	select 1 from Person b
	where a.Email = b.Email
	LIMIT 1, 1
)
