SELECT title FROM movies
JOIN people, stars ON people.id = stars.person_id AND movies.id = stars.movie_id
WHERE name = 'Johnny Depp' AND title IN (SELECT title FROM movies
JOIN people, stars ON people.id = stars.person_id AND movies.id = stars.movie_id
WHERE name = 'Helena Bonham Carter')
ORDER BY title;


