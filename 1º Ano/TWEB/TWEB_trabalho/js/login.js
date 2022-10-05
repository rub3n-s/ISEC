$('input').focus(function (event) {
    $(this).closest('.float-label-field').addClass('float').addClass('focus');
})

$('input').blur(function () {
    $(this).closest('.float-label-field').removeClass('focus');
    if (!$(this).val()) {
        $(this).closest('.float-label-field').removeClass('float');
    }
});

//função que esconde a 'ul' se ela estiver ativa e altera o texto do botão para '+' 
//para que se volte a poder expandir a mesma
$(window).resize(function () {
    if ($(window).width() <= 700) {
        var text = $.trim($("#btn-expand").text());
        $("#btn-expand").text(text == "-" ? '+' : '+');

        selectElement('.esconder').style.display = "none";
    }
})

//função que mostra a 'ul' escondida
$('.expand').click(function () {
    var text = $.trim($("#btn-expand").text());
    $("#btn-expand").text(text == "-" ? '+' : '-');
    if (text == '-') {
        $(".esconder").slideUp("fast", function () { });
    } else {
        $(".esconder").slideDown("fast", function () { });
    }
});

//função para selecionar os elementos, com apenas uma linha de código
//não é necessario usar os () e as {}
const selectElement = (s) => document.querySelector(s);

//abrir o menu
selectElement('.open').addEventListener('click', () => {
    selectElement('.nav-list').classList.add('active');
})

//fechar o menu
selectElement('.close').addEventListener('click', () => {
    selectElement('.nav-list').classList.remove('active');
});

window.onload = function () {
    var user = sessionStorage.getItem('username');

    //Verifica se o utilizador existe e no caso de existir é criada uma variável para que se
    //evite que o utilizador aceda à pagina registo.html depois de criar a conta
    if (user != null) {
        sessionStorage.setItem('userCreated', user);
    }

    if (sessionStorage.userLogged != null) {
        alert("Já tem sessão inciada!");
        event.preventDefault();
        window.location = "index.html";
    }
}

function validateFormOnSubmit() {
    //Variáveis para ir buscar os valores inseridos na página registo.html guardados na sessionStorage 			
    var user = sessionStorage.getItem('username');
    var pass = sessionStorage.getItem('password');

    alert("User: " + user + "\nPass: " + pass);

    //Variáveis para guardar os dados inseridos na página login.html
    var userCheck = document.getElementById('userN').value;
    var passCheck = document.getElementById('passW').value;

    alert("Dados inseridos: \nUser: " + userCheck + "\nPass: " + passCheck);

    //Variáveis para comparar os valores inseridos na página registo.html e login.html
    //0 -> iguais , 1 -> diferentes
    var u = user.localeCompare(userCheck);
    var p = pass.localeCompare(passCheck);

    //Compara os dados de registo e login
    //Se sucesso: guardar o valor do user noutra variáveis para uma futura comparação
    //Senão: "Dados incorretos"
    if (u == 0 && p == 0) {
        sessionStorage.setItem('userLogin', user);
        event.preventDefault();
        window.location = "index.html";
    } else {
        alert("Dados incorretos");
    }

    return false;
}