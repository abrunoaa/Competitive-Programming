CREATE TABLE empregados(
    cpf     varchar(15) PRIMARY KEY,
    enome       varchar(60),
    salario     FLOAT,
    cpf_supervisor  varchar(15),
    dnumero     integer
);
CREATE TABLE departamentos(
    dnumero     integer PRIMARY KEY,
    dnome       varchar(60),
    cpf_gerente     varchar(15) REFERENCES empregados(cpf)
);
CREATE TABLE trabalha(
    cpf_emp     varchar(15) REFERENCES empregados(cpf),
    pnumero     integer
);
CREATE TABLE projetos(
    pnumero     integer PRIMARY KEY,
    pnome       varchar(45),
    dnumero     integer REFERENCES departamentos(dnumero)
);

INSERT INTO empregados(cpf,enome,salario,cpf_supervisor,dnumero)
VALUES
    ('49382234322','João Silva',2350,'2434332222',1010),
    ('586733922290','Mario Silveira',3500,'2434332222',1010),
    ('2434332222','Aline Barros',2350,(null),1010),
    ('1733332162','Tulio Vidal',8350,(null),1020),
    ('4244435272','Juliana Rodrigues',3310,(null),1020),
    ('1014332672','Natalia Marques',2900,(null),1010);

INSERT INTO departamentos(dnumero,dnome,cpf_gerente)
VALUES
    (1010,'Pesquisa','49382234322'),
    (1020,'Ensino','2434332222');

INSERT INTO projetos(pnumero,pnome,dnumero)
VALUES
    (2010,'Alpha',1010),
    (2020,'Beta',1020);

INSERT INTO trabalha(cpf_emp,pnumero)
VALUES
    ('49382234322',2010),
    ('586733922290',2020),
    ('49382234322',2020);

select e.cpf, enome, dnome from empregados e, departamentos d
where e.dnumero = d.dnumero
  and e.cpf not in (
    select cpf_emp from trabalha
  )
order by e.cpf;

drop table empregados, departamentos, trabalha, projetos;
