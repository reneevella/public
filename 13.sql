SELECT name FROM movies
JOIN people, stars ON people.id = stars.person_id AND movies.id = stars.movie_id
WHERE NOT name = 'Kevin Bacon' AND title IN (SELECT title FROM movies
JOIN people, stars ON people.id = stars.person_id AND movies.id = stars.movie_id
WHERE name = 'Kevin Bacon' AND birth = '1958')
ORDER BY name;
