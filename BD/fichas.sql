EXEC LEIBD20_NALUNO(2019116244); 

/*-------------------- sql ficha 1 --------------------*/

select * 
from autores;

select titulo 
from livros;

select distinct genero 
from livros;

select titulo 
from livros 
where preco_tabela between 25 and 35;



/*-------------------- sql ficha 2 --------------------*/


select codigo_livro, titulo
from livros
where upper(genero) = 'INFORMÁTICA';

EXEC LEIBD20_SQLCHECK('FBUHOJDECAQQSOP');


select titulo
from livros
where paginas > 500 and upper(genero) = 'POLICIAL';

EXEC LEIBD20_SQLCHECK('FBNUMEJFNWJUCVE');


select distinct genero
from livros
where paginas > 700 or preco_tabela > 45;

EXEC LEIBD20_SQLCHECK('FBTGJMYGMKLHLKA');


select titulo
from livros
where upper(genero) = 'INFORMÁTICA' order by preco_tabela desc;

EXEC LEIBD20_SQLCHECK('FBVEMIAHEOADHXS');


select isbn, titulo, preco_tabela,quant_em_stock
from livros
where upper(genero) = 'INFORMÁTICA' order by preco_tabela desc, quant_em_stock asc;

EXEC LEIBD20_SQLCHECK('FBISGKRIZEJXNSS');


select distinct codigo_autor
from livros;

EXEC LEIBD20_SQLCHECK('FBGNPWPJDHXSRNZ');


select titulo
from livros
where not upper(genero) = 'POLICIAL';

EXEC LEIBD20_SQLCHECK('FBDIESEKOVUTTPV');


select titulo
from livros
where not upper(genero) = 'POLICIAL';

EXEC LEIBD20_SQLCHECK('FBWEIAULEXHNAVX');


select nome
from autores
where idade > 30 and upper(genero_preferido) = 'POLICIAL' order by nome asc;

EXEC LEIBD20_SQLCHECK('FBEDRFJMAPTCRPM');


select nome
from autores
where nome like '%r%' and nome like '%d%';

EXEC LEIBD20_SQLCHECK('FBKQIWUNTYJCWHY');


select titulo
from livros
where (titulo like 'O%' and titulo like '%st%') or (titulo like 'M%' and titulo like '%to%');

EXEC LEIBD20_SQLCHECK('FBNEADXOMTHUZXY');


select titulo
from livros
where genero in('Aventura', 'Romance', 'Policial');

EXEC LEIBD20_SQLCHECK('FBOQJEGPTMCGVNA');


select 'O livro "' || titulo || '" custa ' || preco_tabela || ' euros.' as "Listagem de Livros"
from livros;

EXEC LEIBD20_SQLCHECK('FBLPLJHQYFXONHJ'); 



/*-------------------- sql ficha 3 --------------------*/

select titulo
from livros, autores
where livros.codigo_autor = autores.codigo_autor and upper(genero) = 'POLICIAL' and autores.nome like 'Cláudio Tereso';

EXEC LEIBD20_SQLCHECK('FCRJGVRAWCUQDMT'); 


select titulo
from autores, livros
where autores.codigo_autor = livros.codigo_autor and upper(genero) = 'POLICIAL' and upper(morada) like '%COIMBRA';

EXEC LEIBD20_SQLCHECK('FCTFWGYBRRDOETR'); 


select distinct nome
from autores, livros
where autores.codigo_autor = livros.codigo_autor and genero = genero_preferido;

EXEC LEIBD20_SQLCHECK('FCNXSFBCZEMFTOL');


select titulo, preco_tabela
from livros, vendas, clientes
where livros.codigo_livro = vendas.codigo_livro and vendas.codigo_cliente = clientes.codigo_cliente and morada like '%Coimbra';

EXEC LEIBD20_SQLCHECK('FCZBYENDWGNMCZJ'); 


SELECT clientes.nome
FROM livros, autores, vendas, clientes
WHERE livros.CODIGO_AUTOR = autores.CODIGO_AUTOR AND livros.CODIGO_LIVRO = vendas.CODIGO_LIVRO AND vendas.CODIGO_CLIENTE = clientes.CODIGO_CLIENTE AND clientes.nome LIKE autores.nome;

EXEC LEIBD20_SQLCHECK('FCFREDCEKEEXMEQ');


select nome, titulo, genero
from autores, livros
where autores.codigo_autor = livros.codigo_autor and genero != genero_preferido order by nome;

EXEC LEIBD20_SQLCHECK('FCLMFDUFYTDWYAC'); 

select titulo, (preco_tabela * unidades_vendidas * 0.3) as "Rendeu"
from livros;

EXEC LEIBD20_SQLCHECK('FCZQAYZGYAYXJBI'); 


select titulo, (preco_tabela * unidades_vendidas * 0.3) as "Rendimento"
from livros, autores
where livros.codigo_autor = autores.codigo_autor and (preco_tabela * unidades_vendidas * 0.3) > 10000 order by genero, preco_tabela;

EXEC LEIBD20_SQLCHECK('FCLLLIVHUDLXGJG'); 


select titulo, round(preco_tabela/paginas, 2) as "Custo página", ceil(preco_tabela/paginas) as "Custo pág.(sup)", floor(preco_tabela/paginas) as "Custo pág.(inf)"
from livros
where paginas between 400 and 700 order by 2;

EXEC LEIBD20_SQLCHECK('FCIOICFIWPKKPDU'); 


select upper(titulo) "Titulo (em maiúsculas)", lower(titulo) "Titulo (em minúsculas)", initcap(titulo) "Titulo (1ª letra maiúscula)"
from livros;

EXEC LEIBD20_SQLCHECK('FCDEAPRJKRNHXWY'); 


select titulo "Titulo" 
from livros
where upper(genero) = 'INFORMÁTICA';

EXEC LEIBD20_SQLCHECK('FCVLAQFKHBCPVUT'); 


select nome "Nome completo",  substr(nome,1,INSTR(nome, ' ') - 1) "Primeiro Nome", substr(nome,INSTR(nome, ' ', -1) + 1) "Ultimo Nome"
from autores;

EXEC LEIBD20_SQLCHECK('FCEVDVALSQWNMME'); 


select upper(titulo) "Titulo (em maisculas)", lower(genero) "genero (min.)", initcap(autores.nome) "Nome Autor (1a letra)" 
from autores, editoras, livros
where editoras.nome = 'FCA - EDITORA' and livros.codigo_editora = editoras.codigo_editora and autores.codigo_autor = livros.codigo_autor order by autores.nome, titulo desc;

EXEC LEIBD20_SQLCHECK('FCBRVTIMKAXSXAQ'); 


select titulo
from livros
where length(titulo) > 20;

EXEC LEIBD20_SQLCHECK('FCKOECUNNUHUSEY'); 


select titulo "TITULO", preco_tabela "PRECO", round((preco_tabela + preco_tabela * 0.1355), 1) "PRECO_COM_AUMENTO"
from livros
where upper(genero) = 'POLICIAL';

EXEC LEIBD20_SQLCHECK('FCFTFBNOWLIPTJN'); 



/*-------------------- sql ficha 4 --------------------*/

select titulo /* 3 */
from livros
where to_char(data_edicao, 'yyyy') = 2011;

EXEC LEIBD20_SQLCHECK('FDUIIRTAKWEXEMS'); 

select to_char(sysdate, 'HH24:MI:SS AM') "Hora Actual", to_char(sysdate, 'DD, Month, YYYY') "Data Actual" /* 4 */
from dual;

EXEC LEIBD20_SQLCHECK('FDWNLITBBLANFKS');


select titulo "Titulo", preco_tabela "Preço" /* 5 */
from livros
where to_char(sysdate - data_edicao) < 3000;

EXEC LEIBD20_SQLCHECK('FDCAWZTCVLWYGAP');


select distinct titulo /* 6 */
from livros, clientes, vendas
where livros.codigo_livro = vendas.codigo_livro and clientes.codigo_cliente = vendas.codigo_cliente and upper(morada) like '% LISBOA'
and to_char(data_venda, 'MM-YYYY')  = '02-2014' order by titulo;

EXEC LEIBD20_SQLCHECK('FDVHQSPDEEBFHIW');

select titulo /* 7 */
from livros, vendas, clientes
where upper(genero) = 'INFORMÁTICA' and livros.codigo_livro = vendas.codigo_livro and clientes.codigo_cliente = vendas.codigo_cliente and to_char(data_edicao, 'MON-YYYY') = to_char(data_venda, 'MON-YYYY')
order by titulo;

EXEC LEIBD20_SQLCHECK('FDRRBNZEHNWOISK');


select nome /* 8 - não funciona corretamente */
from autores, livros
where autores.codigo_autor = livros.codigo_autor and paginas > 190 and (to_char(data_edicao, 'DD-MM-YYYY') <= '22-09-2013' and to_char(data_edicao, 'DD-MM-YYYY') >= '21-06-2013');

EXEC LEIBD20_SQLCHECK('FDYHZMQFGKWTJJM');

select titulo "Titulo", to_char(data_edicao,'YYYY-MM-DD HH24:MI:SS') "DATA_EDICAO",floor((sysdate-data_edicao)/365) "Num. de anos" /* 9 */
from livros
where upper(genero) = 'INFORMÁTICA' order by titulo;

EXEC LEIBD20_SQLCHECK('FDLODEOGLOGAKUD'); 

select distinct nome /* 10 NAO FUNCIONA */
from clientes, livros, vendas
where clientes.codigo_cliente = vendas.codigo_cliente and livros.codigo_livro = vendas.codigo_livro and upper(genero) = 'INFORMÁTICA' and to_char(data_venda, 'DY HH24:MI:SS') < 'TER 17:00:00';

EXEC LEIBD20_SQLCHECK('FDCYRYZHRTDHLVG');


select nome /* 11 */
from autores
minus
select nome
from autores, livros
where autores.codigo_autor = livros.codigo_autor;

EXEC LEIBD20_SQLCHECK('FDLBDDBIQETTMFB'); 

select nome /* 12 */
from autores
minus
select nome
from autores, livros
where autores.codigo_autor = livros.codigo_autor;

EXEC LEIBD20_SQLCHECK('FDMBAEUJCCTONSE'); 




/*-------------------- sql ficha 5 --------------------*/


select count(codigo_livro) "Total livros de Informática" /* 3 */
from livros
where genero = 'Informática';

EXEC LEIBD20_SQLCHECK('FEAHQXIAJQTWFEG');


select count(codigo_livro) "Total de Livros", avg(preco_tabela) "Preço Médio",sum(unidades_vendidas) "Total de livros vendidos" /* 4 */
from livros;

EXEC LEIBD20_SQLCHECK('FETVZGABLESUGNU');



select genero "GENERO", count(genero) "QUANTIDADE" /* 5 */
from livros 
group by genero 
order by genero;

EXEC LEIBD20_SQLCHECK('FEHHHERCGBTHHIN');



select titulo "TITULO", min(preco_unitario) "P_MAIS_BAIXO", max(preco_unitario) "P_MAIS_ALTO", round(avg(preco_unitario),2) "P_MEDIO" /* 6 */
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro and genero = 'Informática' group by titulo order by titulo;

EXEC LEIBD20_SQLCHECK('FEGFYBLDUJATION');


select genero "GENERO", max(preco_tabela) - min(preco_tabela) "DIFERENCA" /* 7 */
from livros group by genero order by genero;

EXEC LEIBD20_SQLCHECK('FECASYJEHNOCJLA');



select titulo "TITULO", preco_tabela "PRECO", sum(quantidade) "NUM_VENDIDOS", sum(preco_tabela * quantidade) "REC_ESPERADA", sum(preco_unitario * quantidade) "REC_EFECTIVA" /* 8 */
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro and genero = 'Informática' group by titulo, preco_tabela order by titulo;

EXEC LEIBD20_SQLCHECK('FEPZSNIFJMVFKFO');



select genero "GENERO", round(avg(preco_tabela),0) "Preço Médio" /* 9 */
from livros 
group by genero having count(titulo) > 4;

EXEC LEIBD20_SQLCHECK('FETBBIEGOHCHLSK'); 


select nome "NOME", min(preco_tabela) "Preco Minimo" /* 10 */
from autores, livros
where autores.codigo_autor = livros.codigo_autor group by nome having min(preco_tabela) >= 30 order by min(preco_tabela);

EXEC LEIBD20_SQLCHECK('FEJGQHLHMZOLMUK');


/* 11 */

select c.codigo_cliente "CODIGO_CLIENTE", c.nome "NOME", sum(v.quantidade) "N.Livros", round(avg(v.preco_unitario),2) "Preco Medio", count(distinct a.codigo_autor) "N. Autores Diferentes"
from livros l, autores a, vendas v, clientes c, editoras e
where a.codigo_autor = l.codigo_autor and c.codigo_cliente = v.codigo_cliente and v.codigo_livro = l.codigo_livro and e.codigo_editora = l.codigo_editora and c.morada like '%Lisboa'
group by c.codigo_cliente, c.nome
having sum(v.quantidade) > 3 and count(distinct e.codigo_editora) <= 1
order by c.nome;

EXEC LEIBD20_SQLCHECK('FEUVKRRIJJGINIO');

select nome "NOME", NVL(to_char(count(codigo_autor)), 'Nenhum') "Num. Livros" /* 12 nao funciona corretamente */
from autores a, livros l, vendas v
where a.codigo_autor = l.codigo_autor and v.codigo_livro = l.codigo_livro
group by nome, NVL(to_char(quantidade), 'Nenhum')
order by nome;

EXEC LEIBD20_SQLCHECK('FENMESWJTYLQODP');



/*-------------------- sql ficha 6 --------------------*/


select titulo "TITULO", MAX(preco_tabela) "PRECO_TABELA"  /* 3 */
from livros
where upper(genero) = 'INFORMÁTICA'
group by titulo
having max(preco_tabela) >= (select max(preco_tabela) from livros where upper(genero) = 'INFORMÁTICA');

EXEC LEIBD20_SQLCHECK('FFPITHOCONBWIOQ');



select titulo "TITULO", MAX(preco_tabela) "PRECO_TABELA" /* 4 */
from livros
where upper(genero) = 'INFORMÁTICA'
group by titulo
having max(preco_tabela) >= ALL(select preco_tabela from livros where upper(genero) = 'INFORMÁTICA');

EXEC LEIBD20_SQLCHECK('FFWEIURDXWFRJDS');



select titulo "TITULO",  MAX(preco_tabela) "PRECO_TABELA" /* 5 */
from livros l
where exists(select * from livros where livros.codigo_livro = l.codigo_livro and upper(genero) = 'INFORMÁTICA')
group by titulo
having max(preco_tabela) >= ALL(select preco_tabela from livros where upper(genero) = 'INFORMÁTICA');

EXEC LEIBD20_SQLCHECK('FFJTNKDEIBSUKMX');



SELECT l.titulo, l.preco_tabela  /* 6 */
FROM livros l, (SELECT MAX(preco_tabela) as maximo
                FROM livros
                WHERE genero='Informática') b
WHERE genero='Informática' AND l.preco_tabela= b.maximo;

EXEC LEIBD20_SQLCHECK('FFONRKIFWHBFLQG');


select distinct a.nome "NOME"  /* 7 */
from autores a, livros l, (SELECT avg(paginas) as avg_pag
                           FROM livros
                           where upper(genero) = 'INFORMÁTICA') b
where a.codigo_autor = l.codigo_autor and paginas > b.avg_pag
order by nome;

EXEC LEIBD20_SQLCHECK('FFFMTIWGIRFSMOG');


select distinct a.nome "NOME"  /* 8 não funciona corretamente */
from autores a, livros l, (SELECT avg(codigo_livro) as avg_livro, count(codigo_livro) as cnt_livro
                           FROM livros
                           where upper(genero) = 'INFORMÁTICA') b
where a.codigo_autor = l.codigo_autor and b.cnt_livro > b.avg_livro;

EXEC LEIBD20_SQLCHECK('FFNZNFHHLRSMNNQ'); 




/*--------------------------------------------------*/

select count(codigo_livro) "Total livros de Informática"
from livros
where upper(genero) = 'INFORMÁTICA';

select count(codigo_livro) "Total de Livros", avg(preco_tabela) "Preco Médio", sum(unidades_vendidas) "Total de livros vendidos"
from livros;

select distinct genero "GENERO", count(quant_em_stock) "QUANTIDADE"
from livros 
group by genero
order by genero;

select titulo "TITULO", min(preco_unitario) "P_MAIS_BAIXO", max(preco_unitario) "P_MAIS_ALTO", round(avg(preco_unitario),2) "P_MEDIO"
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro and upper(genero) = 'INFORMÁTICA' 
group by titulo
order by titulo;


select genero "GENERO", max(preco_tabela) - min(preco_tabela)"DIFERENCA"
from livros
group by genero
order by genero;


select titulo "TITULO", preco_tabela "PRECO", sum(quantidade) "NUM_VENDIDOS", sum(preco_tabela * quantidade) "REC_ESPERADA", sum(preco_unitario * quantidade) "REC_EFECTIVA"
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro and genero = 'Informática' group by titulo, preco_tabela order by titulo;

select genero, round(avg(preco_tabela),0)
from livros 
group by genero
order by 2;

select nome, min(preco_tabela)
from autores, livros
where autores.codigo_autor = livros.codigo_autor and preco_tabela >= 30
group by nome
order by 2, 1;

select c.codigo_cliente "CODIGO_CLIENTE", c.nome "NOME", sum(v.quantidade) "N.Livros", round(avg(v.preco_unitario),2) "Preco Medio", count(distinct a.codigo_autor) "N. Autores Diferentes"
from livros l, autores a, vendas v, clientes c, editoras e
where a.codigo_autor = l.codigo_autor and c.codigo_cliente = v.codigo_cliente and v.codigo_livro = l.codigo_livro and e.codigo_editora = l.codigo_editora and c.morada like '%Lisboa'
group by c.codigo_cliente, c.nome
having sum(v.quantidade) > 3 and count(distinct e.codigo_editora) <= 1
order by c.nome;

 