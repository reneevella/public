SELECT title FROM people
JOIN movies, stars ON people.id = stars.person_id AND movies.id = stars.movie_id
WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter'


