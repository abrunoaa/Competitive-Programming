--- URI Online Judge SQL
--- By Edivânia Pontes
--- Problem 2988

create table teams(
  id INTEGER PRIMARY KEY,
  name VARCHAR (50)
);

create table matches(
  id INTEGER PRIMARY KEY,
  team_1 INTEGER REFERENCES teams (id),
  team_2 INTEGER REFERENCES teams (id),
  team_1_goals INTEGER,
  team_2_goals INTEGER
);

INSERT INTO teams(id, name)
VALUES
       (1, 'CEARA'),
       (2, 'FORTALEZA'),
       (3, 'GUARANY DE SOBRAL'),
       (4, 'FLORESTA');

INSERT INTO matches(id, team_1, team_2, team_1_goals, team_2_goals)
VALUES
       (1, 4, 1, 0, 4),
       (2, 3, 2, 0, 1),
       (3, 1, 3, 3, 0),
       (4, 3, 4, 0, 1),
       (5, 1, 2, 0, 0),
       (6, 2, 4, 2, 1);

select name,
  victories + defeats + draws as "matches",
  victories,
  defeats,
  draws,
  3 * victories + draws as score
from teams t
inner join
    (select t.id,
      case when vic is null then 0 else vic end as victories
    from teams t
    left join
        (select t.id,
          count(t.id) as vic
        from teams t
        join matches
        on (t.id = team_1
            and team_1_goals > team_2_goals)
          or (t.id = team_2
            and team_1_goals < team_2_goals)
        group by t.id
        ) v
      on t.id = v.id
    group by t.id, vic
    ) v
  on t.id = v.id
inner join
    (select t.id,
      case when def is null then 0 else def end as defeats
    from teams t
    left join
        (select t.id,
          count(t.id) as def
        from teams t
        join matches
        on (t.id = team_1
            and team_1_goals < team_2_goals)
          or (t.id = team_2
            and team_1_goals > team_2_goals)
        group by t.id
        ) d
      on t.id = d.id
    group by t.id, def
    ) d
  on t.id = d.id
inner join
    (select t.id,
      case when dr is null then 0 else dr end as draws
    from teams t
    left join
        (select t.id,
          count(t.id) as dr
        from teams t
        join matches
        on (t.id = team_1
            or t.id = team_2)
          and team_1_goals = team_2_goals
        group by t.id
        ) d
      on t.id = d.id
    group by t.id, dr
    ) draw
  on t.id = draw.id
order by score desc, victories desc, draws desc, defeats asc;

  /*  Execute this query to drop the tables */
  DROP TABLE teams, matches; --
