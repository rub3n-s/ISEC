// 1)
/*let n = 50
if (true) {
    let n = 2
    console.log(n)
}
console.log(n); */

// output:
// 2
// 50


// 2)
/*let n = 50
if (true) {
    console.log(n); 
    n = 2
    console.log(n)
}
console.log(n); */

// output: 
// 50
// 2
// 2


// 3)
let n = 50
if (true) { 
    console.log(n);
    let n = 2
    console.log(n)
}
console.log(n);

// output: 
// error n not defined inside if scope
