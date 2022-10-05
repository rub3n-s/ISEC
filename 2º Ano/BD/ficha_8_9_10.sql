EXEC LEIBD20_NALUNO(2019116244);

/*---------------- FICHA 8 ----------------*/


/* 3 */
select l.titulo, l.PRECO_TABELA preco, tab.MEDIA preco_medio, (l.preco_tabela-tab.MEDIA) diferença
from livros l ,(select CODIGO_AUTOR, avg(preco_tabela) MEDIA from livros WHERE upper(genero)='INFORMÁTICA' GROUP BY codigo_autor) tab
where upper(genero) = 'INFORMÁTICA' and tab.codigo_autor = l.codigo_autor
order by 1;

EXEC LEIBD20_SQLCHECK('FHMAWEECEBWOKOY'); 


/* 4 */
select distinct genero "GENERO", titulo "TITULO", max(unidades_vendidas) "UNIDADES_VENDIDAS"
from livros l1
group by genero, titulo
having max(unidades_vendidas) >= (select max(unidades_vendidas) from livros l2 where l1.genero = l2.genero)
order by genero;

EXEC LEIBD20_SQLCHECK('FHRXDZFDXEJULJQ'); 


/* 5 */
select l.TITULO, to_char(round((l.UNIDADES_VENDIDAS/total.uv)*100, 1), '990.99') AS PERCENT
from livros l, editoras e, (select sum(li.UNIDADES_VENDIDAS) uv 
                            from livros li, editoras ed 
                            where ed.NOME like '%FCA%' and li.CODIGO_EDITORA=ed.CODIGO_EDITORA) total
where e.NOME like '%FCA%' and l.CODIGO_EDITORA=e.CODIGO_EDITORA
order by 2 desc, 1;

EXEC LEIBD20_SQLCHECK('FHNDXPBEEVCAMXH'); 


/* 6 */
select l.TITULO
from livros l, vendas ven
where l.CODIGO_LIVRO=ven.CODIGO_LIVRO
group by l.TITULO
having sum(ven.QUANTIDADE) = ( select max(sum(v.QUANTIDADE)) 
                                from vendas v, clientes c 
                                where UPPER(c.MORADA) like '%LISBOA%' and C.CODIGO_CLIENTE=V.CODIGO_CLIENTE
                                group by v.CODIGO_LIVRO);

EXEC LEIBD20_SQLCHECK('FHUMAALFQLEXNMJ');


/* 7 */
select tab1.contal "Total de Livros", tab2.contaa "Total de Autores", tab3.contae "Total de Editoras"
from
    (select count(l.CODIGO_LIVRO) contal
      from livros l) tab1,
    (select count(a.CODIGO_AUTOR) contaa
      from autores a) tab2,
    (select count(e.CODIGO_EDITORA) contae
      from editoras e) tab3;

EXEC LEIBD20_SQLCHECK('FHYBTGRGYHEQORP');


/* 8 */
select 'O autor ' || aut.nome || ' escreveu ' || count(livros.codigo_livro) || ' e ' || b.num_edit || ' sob a alçada da editora ' || b.ned || '.' "Resultado"
from autores aut, livros,
                  (select codigo_autor as ca, e.nome as ned, count(codigo_livro) as num_edit
                   from livros l, editoras e, (select editoras.codigo_editora as ce, max(unidades_vendidas)
                                               from editoras, vendas, livros
                                               where editoras.codigo_editora = livros.codigo_editora
                                               and vendas.codigo_livro = livros.codigo_livro
                                               group by editoras.codigo_editora) d
                   where l.codigo_editora = e.codigo_editora
                   and e.codigo_editora = d.ce
                   group by codigo_autor, e.nome) b
where aut.codigo_autor = b.ca
and aut.codigo_autor = livros.codigo_autor
group by aut.nome, b.num_edit, b.ned
order by aut.nome;

EXEC LEIBD20_SQLCHECK('FHOOKBTHLZKTPZP');




/*---------------- FICHA 9 ----------------*/

/* 3 */
select a.nome "NOME", l.titulo "TITULO", count(e.codigo_editora) "LIVROS FCA", count(l.codigo_livro) "Total de Livros"
from autores a, livros l, editoras e
where a.codigo_autor = l.codigo_autor and e.codigo_editora = l.codigo_editora and e.nome = 'FCA - EDITORA' 
group by a.nome, l.titulo
having max(preco_tabela) >= (select max(preco_tabela) from livros);

EXEC LEIBD20_SQLCHECK('FIMMYCCCAVOALSB'); 


/* 4 */
select aut.nome, NVL(ct.ctl, 0) as "Genero Preferido", count(l.codigo_livro) as "Total de Livros"
from livros l, autores aut, (select aut.codigo_autor as ca, count(codigo_livro) as ctl
                             from livros l, autores aut
                             where l.codigo_autor = aut.codigo_autor (+)
                             and upper(l.genero) = upper(aut.genero_preferido)
                             group by aut.codigo_autor) ct
where l.codigo_autor (+) = aut.codigo_autor
and aut.codigo_autor = ct.ca (+)
group by aut.nome, ct.ctl, NVL(ct.ctl, 0)
order by 1;

EXEC LEIBD20_SQLCHECK('FIJCYREDSKVRMEI');

/* 5 */
select 'O autor ' || aut.nome || ' escreveu ' || b.num_edit || ' de ' || count(livros.codigo_livro) || ' livros para a editora ' || b.ned || '.' as Resultado
from autores aut, livros,
                  (select codigo_autor as ca, e.nome as ned, count(codigo_livro) as num_edit
                   from livros l, editoras e, (select editoras.codigo_editora as ce, max(unidades_vendidas)
                                               from editoras, vendas, livros
                                               where editoras.codigo_editora = livros.codigo_editora
                                               and vendas.codigo_livro = livros.codigo_livro
                                               group by editoras.codigo_editora) d
                   where l.codigo_editora = e.codigo_editora
                   and e.codigo_editora = d.ce
                   group by codigo_autor, e.nome) b
where aut.codigo_autor = b.ca
and aut.codigo_autor = livros.codigo_autor
group by aut.nome, b.num_edit, b.ned
order by aut.nome;

EXEC LEIBD20_SQLCHECK('FIBLAOOEDJMVNZU');


/* 6 */
select distinct c.nome
from clientes c, livros l, vendas v
where c.codigo_cliente = v.codigo_cliente and v.codigo_livro = l.codigo_livro and preco_tabela <= (select min(preco_tabela) from livros where upper(genero) = 'INFORMÁTICA');

EXEC LEIBD20_SQLCHECK('FIKIDKRIMVTPRFN');



/*---------------- FICHA 10 ----------------*/

----- 3 -------
CREATE TABLE AUTORES2 (
	CODIGO_AUTOR NUMBER(4),
	NOME VARCHAR(30),
	N_CONTRIBUINTE NUMBER(9) UNIQUE,
	MORADA VARCHAR(50),
	IDADE NUMBER(4),
	SEXO CHAR(1),
	NACIONALIDADE VARCHAR(20),
	GENERO_PREFERIDO VARCHAR(20),
	CONSTRAINT AUTORES2_CODA_PK PRIMARY KEY(CODIGO_AUTOR)
);

EXEC LEIBD20_SQLCHECK('FJMDPQLCLSHJMHS');


----- 4 -------


----- 5 -------
create table LIVROS_BACKUP
as
select codigo_livro,codigo_editora,codigo_autor,titulo,isbn,preco_tabela,paginas,quant_em_stock,unidades_vendidas,data_edicao,upper(genero) genero from livros;

EXEC LEIBD20_SQLCHECK('FJLPTCFELJHXOCF');

----- 6 -------
alter table LIVROS_BACKUP
ADD 
constraint livrosbackup_clivro_pk PRIMARY KEY(codigo_livro);

alter table LIVROS_BACKUP
ADD 
constraint livrosbackup_ceditora_fk FOREIGN KEY (codigo_editora) references editoras(codigo_editora);

alter table LIVROS_BACKUP
ADD 
constraint livrosbackup_cautor_fk FOREIGN KEY(codigo_autor) references autores(codigo_autor);

EXEC LEIBD20_SQLCHECK('FJQIMRZFKSZAPZG');


----- 7 -------
insert into livros_backup(codigo_livro,codigo_editora,codigo_autor,titulo,isbn,preco_tabela,paginas,quant_em_stock,unidades_vendidas,data_edicao,genero)
values(51, NULL, NULL, 'Informática para todos', 123434, 'Informática', 24, 430, NULL, sysdate, NULL);

EXEC LEIBD20_SQLCHECK('FJAZZUPGMKTGQHJ');


----- 8 -------
insert into autores(codigo_autor, nome, n_contribuinte, morada, idade, sexo, nacionalidade, genero_preferido)
values(45, 'José de Magalhães', 77665544, NULL, NULL, NULL, NULL, NULL);

EXEC LEIBD20_SQLCHECK('FJEBORRHGVHSRMG');


----- 9 -------
delete from livros_backup where codigo_livro = 51;

EXEC LEIBD20_SQLCHECK('FJQIMRZFKSZAPZG');


----- 10 -------
update livros_backup
set preco_tabela = (select preco_tabela + preco_tabela * 0.10 from livros_backup);

EXEC LEIBD20_SQLCHECK('FJQIMRZFKSZAPZG');


----- 11 -------
delete from livros_backup l1
where upper(genero) = 'INFORM¡TICA' and preco_tabela < (select avg(preco_tabela) from livros l2 where l1.codigo_livro = l2.codigo_livro);

----- 12 -------
create table autores_backup
as select codigo_autor, nome, n_contribuinte, morada, idade, sexo, nacionalidade, genero_preferido from autores;

----- 13 -------
alter table autores_backup
add column nlivros number(3) not null,
add constraint autores_bk_nlivros_ck check(nlivros < 151);

----- 14 -------
update autores_backup
set nlivros = (select count(l.codigo_livro) from autores a, livros l where a.codigo_autor = l.codigo_autor);

----- 15 -------
update autores_backup
set genero_preferido = (select l.genero from autores a, livros l where a.codigo_autor = l.codigo_autor);

----- 16 -------
create table editoras_backup
as select codigo_editora, nome, n_contribuinte, morada, telefone, fax from editoras;

----- 17 -------
drop table editoras_backup;

----- 18 -------
alter table livros_backup
add column edicao number(7);

----- 19 -------
update livros_backup
set unidades_vendidas = (select quantidade from livros l, vendas v where l.codigo_livro = v.codigo_livro);

----- 20 -------
update vendas_backup
set total_venda = (select quantidade * preco_unitario from vendas v);

----- 21 -------
create table vendas_backup
as select codigo_venda, data_venda, codigo_cliente, codigo_livro, preco_unitario, quantidade, total_venda from vendas;

----- 22 -------
delete from vendas_backup
where to_char(data_venda, 'Month') = 'Janeiro';

----- 23 -------
delete from vendas_backup v
where v.codigo_livro = (select codigo_livro from livros l, autores a where l.codigo_autor = a.codigo_autor and a.nome = 'SÈrgio Sousa' having max(l.preco_tabela) = (select max(preco_tabela) from livros l2, autores a2 where  l2.codigo_autor = a2.codigo_autor and a.nome = 'SÈrgio Sousa');