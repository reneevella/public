SELECT name FROM people
JOIN movies, ratings, directors ON people.id = directors.person_id AND movies.id = stars.movie_id
WHERE rating >= '9.0';