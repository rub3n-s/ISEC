'use strict';

const panelControl = document.getElementById('panel-control');
const panelGame = document.getElementById('game');
const btLevel = document.getElementById('btLevel');
const btPlay = document.getElementById('btPlay');
const message = document.getElementById('message');
const cards = panelGame.querySelectorAll('.card');  // array with all the cards
const cardLogos = ['angular','bootstrap','html','javascript','vue','svelte','react','css','backbone','ember'];
const pointsLbl = document.getElementById('points');
let gameStarted = false;
let points = 0;
let pairsLeft = 0;
let flippedCards = []
let totalFlippedCards = 0;

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
    }
    
    // example with forEach
    index = 0;
    cards.forEach(card => {
        // change the card's img src
        let image = card.querySelector('.card-front');
        image.src = 'images/' + newCardsArray[index++] + '.png';
    });

    gameStarted = true;
    
    // Define the number of pairs per level
    switch(btLevel.value) {
        case 0: pairsLeft = 3;
        case 1: pairsLeft = 4;
        case 2: pairsLeft = 5;
    }

    // re-initialize flipped cards array
    flippedCards = [];

    // reset the flipped cards to zero
    totalFlippedCards = 0
}

/* Hide Labels (time,pontuation,etc) */
function stopGame() {
    btLevel.disabled = false;
    btPlay.textContent = 'Iniciar Jogo';
    
    // displays a modal to insert the players nickname
    modalGameOver.style.display = 'block';
    
    cards.forEach(card => {
        card.classList.remove('inative');
        card.classList.remove('grayscale');
        card.removeEventListener('click', flipCard);
    });    
    hideCards();
    reset();
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

/* Flip the clicked card */
function flipCard() {
    if (gameStarted) {
        this.classList.add('flipped');
        /* Store flipped cards in array */
        flippedCards.push(this);
        if (flippedCards.length == 2)
            checkPlay();
    }
}

/* Checks the current play */
async function checkPlay() {
    if (flippedCards[0].dataset.logo != flippedCards[1].dataset.logo) {
        await new Promise(resolve => setTimeout(resolve, 1000));

        flippedCards.forEach(card => {
            card.classList.remove('flipped');
            card.addEventListener('click',flipCard,{once:true});
        });
        console.log('Não são iguais');    // log purpose only
        
        /*setTimeout(() => { 
            flippedCards.forEach(card => {
                card.classList.remove('flipped');
            });
            console.log('Não são iguais');    // log purpose only
         }, 1000);*/
    } else {
        // increase the points, and set it in the label
        points++; 
        pointsLbl.textContent = points;        
       
        flippedCards.forEach(card => {
            card.classList.add('inative');

            let card_front = card.querySelector('.card-front');
            card_front.classList.add('grayscale');
        });

        // Method 1: Counting cards
        totalFlippedCards+=2;
        if (gameOver()) stopGame();

        // Method 2: Counting pairs (pairs number defined by btLevel at startGame function)
        /*
        pairsLeft--;
        if (pairsLeft == 0) levelCompleted();   // level completed, start a new level
        */

        console.log('Iguais');  // log purpose only
    }
    flippedCards = []
}

/* If all the cards were flipped return true, else returns false */
function gameOver() {
    return totalFlippedCards == cards.length;
}

function levelCompleted() {
    // 1) hide cards
    // 2) create new array
    // 3) shuffle
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

    card.addEventListener('click',flipCard,{once:true});
});

/* Initialize functions */
reset()