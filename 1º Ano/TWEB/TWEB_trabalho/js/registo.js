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
    //guarda o valor da variável criada pa página index.html para se poder verificar se o utilizador
    //está a tentar entrar na página registo.html a partir da index.html com sessão iniciada
    var user = sessionStorage.getItem('userLogged');

    //Verifica se o utilizador está a tentar entrar na página registo.html a partir da página
    //index.html com a sessão inciada, e redireciona-o para a página index.html caso seja verdade
    if (user != null) {
        alert("Já tem sessão inciada!");
        event.preventDefault();
        window.location = "index.html";

        return;
    }

    //variavél auxiliar para prevenir que utilizador entre na página registo.html
    //depois de ter criado a conta (é chamada na página login.html)
    var userC = sessionStorage.getItem('userCreated');
    var userAlert = sessionStorage.getItem('username');

    //Verifica se a conta foi criada. Para o caso do utilizador a ter criado e tentar entrar
    //de novo na página de registo.html, mandado-o de volta para a pagina login.html
    if (userC != null) {
        alert("Já existe uma conta criada com o nome: " + userAlert);
        event.preventDefault();
        window.location = "login.html";
    }
}

function callme() {
    //guarda os valores inseridos nos inputs na sessionStorage
    var user = document.getElementById('username').value;
    var pass = document.getElementById('password').value;

    //guarda os valores das variáveis 'user' e 'pass' na sessionStorage
    //para que possam ser acessados em todas as páginas
    sessionStorage.setItem('username', user);
    sessionStorage.setItem('password', pass);

    window.location = "login.html";
}