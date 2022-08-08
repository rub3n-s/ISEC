EXEC LEIBD20_NALUNO(2019116244); 


select count(codigo_livro) "Total livros de Informática"
from livros
where genero = 'Informática';

EXEC LEIBD20_SQLCHECK('FEAHQXIAJQTWFEG');


select count(codigo_livro) "Total de Livros", avg(preco_tabela) "Preço Médio",sum(unidades_vendidas) "Total de livros vendidos"
from livros;

EXEC LEIBD20_SQLCHECK('FETVZGABLESUGNU');



select genero "GENERO", count(genero) "QUANTIDADE"
from livros group by genero order by genero;

EXEC LEIBD20_SQLCHECK('FEHHHERCGBTHHIN');



select titulo "TITULO", min(preco_unitario) "P_MAIS_BAIXO", max(preco_unitario) "P_MAIS_ALTO", round(avg(preco_unitario),2) "P_MEDIO"
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro and genero = 'Informática' group by titulo order by titulo;

EXEC LEIBD20_SQLCHECK('FEGFYBLDUJATION');


select genero "GENERO", max(preco_tabela) - min(preco_tabela) "DIFERENCA"
from livros group by genero order by genero;

EXEC LEIBD20_SQLCHECK('FECASYJEHNOCJLA');



select titulo "TITULO", preco_tabela "PRECO", sum(quantidade) "NUM_VENDIDOS", sum(preco_tabela * quantidade) "REC_ESPERADA", sum(preco_unitario * quantidade) "REC_EFECTIVA"
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro and genero = 'Informática' group by titulo, preco_tabela order by titulo;

EXEC LEIBD20_SQLCHECK('FEPZSNIFJMVFKFO');



select genero "GENERO", round(avg(preco_tabela),0) "Preço Médio"
from livros 
group by genero having count(titulo) > 4;

EXEC LEIBD20_SQLCHECK('FETBBIEGOHCHLSK'); 


select nome "NOME", min(preco_tabela) "Preco Minimo"
from autores, livros
where autores.codigo_autor = livros.codigo_autor group by nome having min(preco_tabela) >= 30 order by min(preco_tabela);

EXEC LEIBD20_SQLCHECK('FEJGQHLHMZOLMUK');



select nome "NOME", NVL(count(genero),'Nenhum') "Num. Livros"
from autores, livros
where autores.codigo_autor = livros.codigo_autor group by nome order by nome;
