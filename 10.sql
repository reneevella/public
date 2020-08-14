SELECT name FROM people
JOIN movies, ratings, directors ON people.id = directors.person_id AND movies.id = directors.movie_id AND ratings.movie_id = movies.id
WHERE rating >= '9.0';