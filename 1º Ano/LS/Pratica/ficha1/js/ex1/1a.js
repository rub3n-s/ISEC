let n1=3;
let n2=6;
let n3;
console.log(n1+n2); // 1)
console.log(n1+"n3"); // 2)
console.log(n1+"5"); // 3)
console.log(n1+"n2"); // 4)
console.log(n1+n3); // 5) erro por variavel indefinida (nao inicializada)
console.log(n3); // 6) undefined
console.log(`Variavel n1*n2 = ${n1*n2} ( n1=${n1} e n2=${n2})`); //7)
n3=n1+n2;
console.log(n3); //8)
n3=n1+"---"+n2;
console.log(n3); //9)
n3="6";
console.log(n1+n3); // 10
console.log(n2===n3); // 11 True ou False ?
console.log(n2==n3); // 12 True ou False ?
console.log(n2!==n3); // 13 True ou False ?
console.log(n2!=n3); // 14 True ou False ?
console.log(n1++); // 15
console.log('n1='+n1); // 16
n1=4;
console.log(++n1); // 17
console.log('n1='+n1); // 18