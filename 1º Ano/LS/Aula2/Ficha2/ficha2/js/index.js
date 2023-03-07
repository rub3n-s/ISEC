'use strict';

const panelControl = document.getElementById('panel-control');
const panelGame = document.getElementById('game');
const btLevel = document.getElementById('btLevel');
const btPlay = document.getElementById('btPlay');
const message = document.getElementById('message');

/* FUNCTIONS */
/* Initial reset */
function reset() {
    panelGame.style.display = 'none';
    message.textContent = '';
    message.classList.remove('hide');

    // toggle btLevel/panelGame visibility
    if (btLevel.value == 0) {
        btPlay.disabled = true;
        panelGame.style.display = 'none';
    } else {
        btPlay.disabled = false;
        panelGame.style.display = 'grid';
        message.textContent = 'Clique para iniciar o jogo!';
    }  

    // get all the elements with the class .list-item inside panel-control
    const items = panelControl.querySelectorAll('.list-item');
    for (const i of items)
        i.classList.remove('gameStarted');
}

/* Display Labels (time,pontuation,etc) */
function startGame() {
    btLevel.disabled = true;
    btPlay.textContent = 'Terminar Jogo';
    message.classList.add('hide');

    // get all the elements with the class .list-item inside panel-control
    const items = panelControl.querySelectorAll('.list-item');
    for (const i of items)
        i.classList.add('gameStarted');
}

/* Hide Labels (time,pontuation,etc) */
function stopGame() {
    btLevel.disabled = false;
    btPlay.textContent = 'Iniciar Jogo';
    reset();
}

/* EVENTS LISTENERS */
/* Enables play button and display the grid */
btLevel.addEventListener('change',reset);

/* Start/Stop the game */
btPlay.addEventListener('click', function() {
    return (btPlay.textContent == 'Iniciar Jogo') ?  startGame() : stopGame();
});

/* Initialize functions */
reset()