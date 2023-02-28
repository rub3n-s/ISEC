var str = 'Linguagens';
function fazQualquerCoisa() {
    var str2 = ' Script';
    if (str==='Linguagens') {
        var dim='ok';
        console.log("->"+dim);
    }
    console.log(str+str2+"- "+dim);
}
fazQualquerCoisa();
console.log(str+str2);

// 1) str==='Linguagens' => Tem o mesmo tipo e o valor é igual => true
// 2) log => '->ok'
// 3) log => 'Linguagens Script- ok'
// 4) log => str+str2 - error str2 is not defined