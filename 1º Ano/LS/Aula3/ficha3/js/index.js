'use strict';

const panelControl = document.getElementById('panel-control');
const panelGame = document.getElementById('game');
const btLevel = document.getElementById('btLevel');
const btPlay = document.getElementById('btPlay');
const message = document.getElementById('message');
const cards = panelGame.querySelectorAll('.card');  // array with all the cards
const cardLogos = ['angular','bootstrap','html','javascript','vue','svelte','react','css','backbone','ember'];

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
    for (let i of items)
        i.classList.remove('gameStarted');
}

/* Display Labels (time,pontuation,etc) */
function startGame() {
    btLevel.disabled = true;
    btPlay.textContent = 'Terminar Jogo';
    message.classList.add('hide');

    // get all the elements with the class .list-item inside panel-control
    const items = panelControl.querySelectorAll('.list-item');
    for (let i of items)
        i.classList.add('gameStarted');

    // shuffle the array
    shuffleArray(cardLogos)

    // debug purpose - array after shuffle
    console.table(cardLogos)

    // duplicate the first three cards and shuffle
    const newCardsArray = Array.from(cardLogos).slice(0,3);
    newCardsArray.splice(3,0,newCardsArray[0],newCardsArray[1],newCardsArray[2]);
    shuffleArray(newCardsArray);

    // set the cards based on the sorted card array
    let index = 0;
    for (let card of cards) {
        // change the card's data-logo
        card.dataset.logo = newCardsArray[index++];

        // change the card's img src
        let image = card.querySelector('.card-front');
        image.src = 'images/' + newCardsArray[index++] + '.png';
    }
    
    // example with forEach
    /*index = 0;
    cards.forEach(card => {
        // change the card's img src
        let image = card.querySelector('.card-front');
        image.src = 'images/' + newCardsArray[index++] + '.png';
    });*/

    // display the cards
    showCards();
}

/* Hide Labels (time,pontuation,etc) */
function stopGame() {
    btLevel.disabled = false;
    btPlay.textContent = 'Iniciar Jogo';
    reset();
    hideCards();
}

/* Shuffles an array - Fisher-Yates Algorithm */
const shuffleArray = array => {
    for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    const temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    }
}

/* Turn all the card of the panel */
function showCards() {
    for (let card of cards)
        card.classList.add('flipped');
}

/* Hide all the card of the panel */
function hideCards() {
    for (let card of cards)
        card.classList.remove('flipped');
}

/* EVENTS LISTENERS */
/* Enables play button and display the grid */
btLevel.addEventListener('change',reset);

/* Start/Stop the game */
btPlay.addEventListener('click', function() {
    return (btPlay.textContent == 'Iniciar Jogo') ?  startGame() : stopGame();
});

/* Listener for hover */
cards.forEach(card => {
    card.addEventListener('mouseover', function() {
        card.classList.add('cardHover');
    });

    card.addEventListener('mouseout', function() {
        card.classList.remove('cardHover');
    });
});

/* Initialize functions */
reset()