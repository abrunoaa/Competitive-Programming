--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2737

CREATE TABLE lawyers(
  register INTEGER PRIMARY KEY,
  name VARCHAR(255),
  customers_number INTEGER
 );


 INSERT INTO lawyers(register, name, customers_number)
 VALUES (1648, 'Marty M. Harrison', 5),
  (2427, 'Jonathan J. Blevins', 15),
  (3365, 'Chelsey D. Sanders', 20),
  (4153, 'Dorothy W. Ford', 16),
  (5525, 'Penny J. Cormier', 6);

select name, customers_number
from (
    select name, customers_number, 1 as filter
    from (
        select name, customers_number
        from lawyers
        order by customers_number desc
        limit 1
    ) big
    union
    select name, customers_number, 2 as filter
    from (
        select name, customers_number
        from lawyers
        order by customers_number
        limit 1
    ) small
    union
    select 'Average' as "name", customers_number, 3 as filter
    from (
        select cast(avg(customers_number) as int) as customers_number
        from lawyers
    ) average
) maintain_order
order by filter;

  /*  Execute this query to drop the tables */
  DROP TABLE lawyers; --
