CREATE TABLE doctors (
id SERIAL PRIMARY KEY,
name VARCHAR(50));

CREATE TABLE work_shifts (
id SERIAL PRIMARY KEY,
name VARCHAR(50),
bonus NUMERIC);

CREATE TABLE attendances (
id SERIAL PRIMARY KEY,
id_doctor INTEGER REFERENCES doctors(id),
hours INTEGER,
id_work_shift INTEGER REFERENCES work_shifts(id));

INSERT INTO doctors (name)
VALUES
('Arlino'),
('Tiago'),
('Amanda'),
('Wellington');

INSERT INTO work_shifts (name, bonus)
VALUES
('nocturnal', 15),
('afternoon', 2),
('day', 1);

INSERT INTO attendances (id_doctor, hours, id_work_shift)
VALUES
(1, 5, 1),
(3, 2, 1),
(3, 3, 2),
(2, 2, 3),
(1, 5, 3),
(4, 1, 3),
(4, 2, 1),
(3, 2, 2),
(2, 4, 2);

select name, sum(totalTurno) from doctors
select id_doctor,
  (150 * hours * (1 + (select bonus from work_shifts
    where id = id_work_shift) / 100)) as totalTurno
from attendances;

drop table doctors, work_shifts, attendances;
