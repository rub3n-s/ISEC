// maior numero?
const num1=5;
const num2=10;
const num3=7;

function maiorNumero() {
    if (num1 > num2 && num1 > num3)
        console.log("Num1=" + num1 + " é o maior numero")
    else if (num2 > num1 && num2 > num3)
        console.log("Num2=" + num2 + " é o maior numero")
    else
        console.log("Num3=" + num3 + " é o maior numero")
}

maiorNumero()