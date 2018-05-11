DELETE
FROM
    Person
WHERE
    Person.Id
IN 
(
    SELECT tmp.Id FROM (
        SELECT 
            Id
        FROM 
            Person
        WHERE 
            Id
        NOT IN
            (SELECT tmp2.Id FROM (
                SELECT
                    MIN(Person.Id) as Id
                FROM
                    Person
                GROUP BY
                    Person.Email
            ) tmp2)
    ) tmp
)
 
