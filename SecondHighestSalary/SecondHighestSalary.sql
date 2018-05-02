# Write your MySQL query statement below
SELECT (
SELECT DISTINCT Salary from Employee
WHERE Salary = (SELECT MAX(Salary) from Employee WHERE Salary < (Select MAX(Salary) from Employee)))
AS SecondHighestSalary

