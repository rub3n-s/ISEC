'use strict'; 

/*============== Exercicio 2 ==============*/

/* 2 a)*/
/*const num1=prompt("Especifique o numero 1: ");
const num2=prompt("Especifique o numero 2: ");
const num3=prompt("Especifique o numero 3: ");

const n1 = parseInt(num1)
const n2 = parseInt(num2)
const n3 = parseInt(num3)

function maiorNumero() {
    
    if (maior(num1,num2) && maior(num1,num3))
        alert("O maior entre " + n1 + ", " + n2 + ", " + n3 +" é " + n1)
    else if (maior(num2,num1) && maior(num2,num3))
        alert("O maior entre " + n1 + ", " + n2 + ", " + n3 +" é " + n2)
    else
        alert("O maior entre " + n1 + ", " + n2 + ", " + n3 +" é " + n3)
}

function maior(num1,num2) { if (parseInt(num1) > parseInt(num2)) return true }

maiorNumero() */

/* 2  b) */

/*const num1 = prompt("Especifique o numero 1: ");
const num2 = prompt("Especifique o numero 2: ");
let soma = 0;

const n1 = parseInt(num1)
const n2 = parseInt(num2)

if (n1 > n2) {
    for (let i = n1; i < n2; i++)
        if (i!= n1)
            soma+=i;
} else {
    for (let i = n2; i > n1; i--)
        if (i!= n2)
            soma+=i;
} 

//alert(num1 + "+" + num2 + "=" + soma);
alert(`${num1}+${num2}=${soma}`);*/

/* 2 c) */

/*let soma = 0;
let num;
let positivos = 0;
let negativos = 0;
do {
    num = prompt("Inserir numero...");
    if (num != 0) {
        if (num > 0) positivos++;
        else negativos++;
        soma+=parseInt(num);
        console.log(`inseriu=${num}, soma=${soma}`);
    }    
} while(num != 0);

console.log(`positivos=${positivos}`)
console.log(`negativos=${negativos}`)
console.log(`soma=${soma}`); */

/*============== Exercicio 3 ==============*/

/* 3 a) */

/*let str = 'Linguagens Script';
function fazQualquerCoisa() {
console.log(str);
}
fazQualquerCoisa(); */

/* 3 b) */

/*let str = 'Linguagens';
function fazQualquerCoisa() {
str = 'Script';
}
console.log(str);
fazQualquerCoisa();
console.log(str); */

/*============== Exercicio 4 ==============*/

// a)

const num1 = 5;
const num2 = 3;
function numerosIguais(num1,num2) {
    if (num1 == num2)
        return true;
    return false;
}

if (numerosIguais(num1,num2)) 
    console.log(`${num1} e ${num2} são iguais`);
else 
    console.log(`${num1} e ${num2} são diferentes`);


// b)
function parImpar(num) {
    if (num % 2 == 0)
        console.log(`${num} é par`);
    else
        console.log(`${num} é impar`);
}

parImpar(num1);

// c)
function obtemQuadrado(num) {
    return num*num;
}

console.log(`O quadrado de ${num1} é ${obtemQuadrado(num1)}`);

// d)
function areaRectangulo(comp,larg) {
    return comp*larg;
}
console.log(`Retangulo com comprimento=${num1}, largura=${num2} tem area=${areaRectangulo(num1,num2)}`)

// e)
function contaVogais(string) {
    let vogais = 0;
    for (let i = 0; i < string.length; i++) {
        switch(string.toLowerCase().charAt(i)) {
            case 'a': vogais++; break;
            case 'e': vogais++; break;
            case 'i': vogais++; break;
            case 'o': vogais++; break;
            case 'u': vogais++; break;
        }
    }
    return vogais;
}
console.log(`'Ola' tem ${contaVogais("Ola")} vogais`);
console.log(`'Linguagens' Script tem ${contaVogais("Linguagens Script")} vogais`);