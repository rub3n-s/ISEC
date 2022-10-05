//função que fecha o submenu no caso de se alterar a disposição da barra de navegação e altera o símbolo dentro do botão
$(window).resize(function () {
    if ($(window).width() <= 700) {
        var text = $.trim($("#btn-expand").text());
        $("#btn-expand").text(text == "-" ? '+' : '+');

        selectElement('.esconder').style.display = "none";
    }
})

//ao clicar no link expande o sub menu que estava escondido e altera o simbolo do botão
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
})

window.onload = function () {
    var user = sessionStorage.getItem('userLogin');

    if (sessionStorage.getItem('userLogin') !== null) {
        //guarda na sessionStorage para usar na página login.html e bloquear o acesso à mesma                      
        sessionStorage.setItem('userLogged', user);

        //Escreve o valor do username numa tag <p> da barra de navegação
        document.getElementById('pLog').innerText = sessionStorage.getItem('userLogin');

        document.getElementById('log').style.display = "none";
        document.getElementById('reg').style.display = "none";

        document.getElementById('pLog').style.display = "visible";
        document.getElementById('aReg').style.display = "visible";
    } else {
        document.getElementById('pLog').style.display = "none";
        document.getElementById('aReg').style.display = "none";
    }
};

//função que limpa os dados guardados na sessionStorage
//quando o clear é feito os dados são apagados definitivamente
function clearSessionStorage() {
    sessionStorage.clear();
    location.reload();
}

$('input').focus(function (event) {
    $(this).closest('.float-label-field').addClass('float').addClass('focus');
})

$('input').blur(function () {
    $(this).closest('.float-label-field').removeClass('focus');
    if (!$(this).val()) {
        $(this).closest('.float-label-field').removeClass('float');
    }
});

$('textarea').focus(function (event) {
    $(this).closest('.float-label-field').addClass('float').addClass('focus');
})

$('textarea').blur(function () {
    $(this).closest('.float-label-field').removeClass('focus');
    if (!$(this).val()) {
        $(this).closest('.float-label-field').removeClass('float');
    }
});

//slideShow com TimeOut para fazer a transição das imagens automaticamente
var slideIndex = 0;
showSlides();

function showSlides(n) {
    var i;
    var slides = document.getElementsByClassName("mySlides");

   
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }

    
    slideIndex++;
    if (slideIndex > slides.length) { 
        slideIndex = 1 
    }

    //faz display da imagem
    slides[slideIndex - 1].style.display = "block";
    setTimeout(showSlides, 4200); 
}

function showSlides() {
    var i;
    var slides = document.getElementsByClassName("mySlides");
    var dots = document.getElementsByClassName("dot");

    //percorre o número de imagens e atribui-lhes o estilo display:none
    for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";  
    }

    //incrementa a variavel slide index até ser maior que o numero de imagens
    //de seguida verifica se ultrapassou o valor e faz com que comece de novo em 1
    slideIndex++;
    if (slideIndex > slides.length) {slideIndex = 1}    
    for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" slide-active", "");
    }

    slides[slideIndex-1].style.display = "block";  
    dots[slideIndex-1].className += " slide-active";
    setTimeout(showSlides, 4200); //muda de imagem a cada 4,2 segundos
  }

//script que faz smooth scrolling ao clicar nos links da barra de navegação
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();

        document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
        });
    });
});

//função que ao clicar no btn leva o utilizador ao topo da página / fixa a barra de navegação ao topo da página
//quando o utilizador faz scroll 20px desde o topo da página, o botão é mostrado no ecrã caso contrario permanece escondido,
//o mesmo para a barra de navegação que quando o scroll passa dos 20px é adicionada uma classe que a fixa no topo caso contrario remove a classe
window.onscroll = function() {
    scrollFunction()
};

function scrollFunction() {
    if (document.body.scrollTop > 20 || document.documentElement.scrollTop > 20) {
        document.getElementById("btnTopo").style.display = "block";
        document.getElementById("barra-navegacao").classList.add("nav-fixed");
    } else {
        document.getElementById("btnTopo").style.display = "none";
        document.getElementById("barra-navegacao").classList.remove("nav-fixed");
    }
}

// quando o utilizador clica no botão, é redirecionado para o topo da página
function topFunction() {
    $('html, body').animate({scrollTop:0}, 'slow');
}