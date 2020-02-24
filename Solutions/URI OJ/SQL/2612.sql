--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2612

CREATE TABLE genres (
  id numeric PRIMARY KEY,
  description varchar(50)
);

CREATE TABLE movies (
  id numeric PRIMARY KEY,
  name varchar(50),
  id_genres numeric REFERENCES genres (id)
);

CREATE TABLE actors (
  id numeric PRIMARY KEY,
  name varchar(50)
);

CREATE TABLE movies_actors (
  id_movies numeric REFERENCES movies (id),
  id_actors numeric REFERENCES actors (id)
);

INSERT INTO genres (id, description)
VALUES
  (1, 'Animation'),
  (2, 'Horror'),
  (3, 'Action'),
  (4, 'Drama'),
  (5, 'Comedy');

INSERT INTO movies (id, name, id_genres)
VALUES
  (1, 'Batman', 3),
  (2, 'The Battle of the Dark River', 3),
  (3, 'White Duck', 1),
  (4, 'Breaking Barriers',  4),
  (5, 'The Two Hours',  2);

INSERT INTO actors (id, name)
VALUES
  (1, 'Brad Antonio'),
  (2, 'Marcelo Silva'),
  (3, 'Miguel Silva'),
  (4, 'Drake Frost'),
  (5, 'Rodrigo Juares Rodriguez');

INSERT INTO movies_actors (id_movies, id_actors)
VALUES
  (1,1),
  (2,3),
  (2,2),
  (4,1),
  (5,2);

-- Para fazer isso, selecione o código e o nome dos filmes em que atuaram os atores ‘Marcelo Silva’ ou ‘Miguel Silva’ e que o gênero do filme seja 'Action'.
select m.id, m.name
from movies m
where m.id_genres in (
    select id
    from genres
    where description = 'Action')
  and m.id in (
    select id_movies
    from movies_actors
    where id_actors in (
        select id
        from actors
        where name = 'Marcelo Silva'
          or name = 'Miguel Silva'));

  /*  Execute this query to drop the tables */
DROP TABLE movies_actors, actors, movies, genres; --
