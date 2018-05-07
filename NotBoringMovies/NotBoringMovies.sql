SELECT
    *
FROM
    cinema
WHERE
    MOD(cinema.id, 2) = 1
    AND
    cinema.description != 'boring'
ORDER BY
    cinema.rating DESC
