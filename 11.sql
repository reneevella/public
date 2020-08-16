SELECT title FROM movies
JOIN people, ratings, stars ON people.id = stars.person_id AND movies.id = stars.movie_id AND ratings.movie_id = movies.id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;

