'use strict';

const panelControl = document.getElementById('panel-control');
const panelGame = document.getElementById('game');
const btLevel = document.getElementById('btLevel');
const btPlay = document.getElementById('btPlay');
const btOkTop = document.getElementById('okTop');
const message = document.getElementById('message');
//const cards = panelGame.querySelectorAll('.card');  // array with all the cards
const cardsLogos = ['angular','bootstrap','html','javascript','vue','svelte','react','css','backbone','ember'];
const labelPoints = document.getElementById('points');

let topGamers = [
    {nickname:'xpto',points:10},
    {nickname:'ruben',points:69}
];
let cards = [];
let gameStarted = false;
let flippedCards = [];
let totalFlippedCards = 0;
let totalPoints = 0;
let totalPairs;

//const TIMEOUTGAME = 20; // initial game interval
const labelGameTime = document.getElementById('gameTime');
let levelTimeOut;
let timer;
let timerId;    // stores the identifier for the interval (when specified the function setInterval)

/* FUNCTIONS */
/* Initial reset */
function reset() {
    panelGame.style.display = 'none';
    message.textContent = '';
    message.classList.remove('hide');
    labelGameTime.removeAttribute('style');
    labelGameTime.textContent = '0s';

    // toggle btLevel/panelGame visibility
    const selectedItem = btLevel.value;
    switch(selectedItem.toString()) {
        case '0': 
            btPlay.disabled = true;
            panelGame.style.display = 'none';
            totalPairs = 0;
            break;
        case '1': 
            totalPairs = 3; 
            levelTimeOut = 10;
            readyToStart(); 
            break;    // Basic
        case '2': 
            totalPairs = 6; 
            levelTimeOut = 60;
            readyToStart(); 
            break;   // Medium
        case '3': 
            totalPairs = 10; 
            levelTimeOut = 180;
            readyToStart(); 
            break;   // Advanced
    }

    // get all the elements with the class .list-item inside panel-control
    const items = panelControl.querySelectorAll('.list-item');
    for (let i of items)
        i.classList.remove('gameStarted');

    // fill the grid
    createPanelGame();
}

/* Displays the grid with the cards and unlocks the play button */
function readyToStart() {
    btPlay.disabled = false;
    panelGame.style.display = 'grid';
    message.textContent = 'Clique para iniciar o jogo!';
}

/* Creates the grid panel dynamically */
function createPanelGame() {
    panelGame.className = '';
    panelGame.innerHTML = '';

    // create a card
    let div = document.createElement('div');
    div.setAttribute('class','card');
    
    let imgBack = document.createElement('img');
    imgBack.setAttribute('class','card-back');
    imgBack.setAttribute('src','images/ls.png');
    
    let imgFront = document.createElement('img');
    imgFront.setAttribute('class','card-front');

    div.appendChild(imgBack);
    div.appendChild(imgFront);
    
    for (let i = 0; i < totalPairs*2; i++) {
        panelGame.appendChild(div.cloneNode(true));
    }    

    cards = panelGame.childNodes;
    cards.forEach(card => {
        createCardEventListener(card);
    });

    switch(totalPairs) {
        case 3: panelGame.classList.add('basic');
        case 6: panelGame.classList.add('medium');
        case 10: panelGame.classList.add('advanced');
    }
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

    let [indice, newCardLogos] = [0, [...cardsLogos]];
    createAndShuffleCards(newCardLogos);
    cards.forEach(card => {
        card.querySelector('.card-front').src = `images/${newCardLogos[indice]}.png`;
        card.dataset.logo = newCardLogos[indice++];
        createCardEventListener(card);
    });
       
    // re-initialize flipped cards array
    // reset:
    //   flipped cards to zero
    //   totalPoints to zero
    [flippedCards,totalFlippedCards,totalPoints] = [[],0,0];
    
    // set the initial interval
    // setInterval() - calls udpdateGameTime() every 1000 ms (1 sec)
    [timer,timerId] = [levelTimeOut,setInterval(updateGameTime,1000)];

    labelGameTime.textContent = timer + 's';
    gameStarted = true;

    // set top score on the label's textContent
    getTopPoints();
}

/* Hide Labels (time,pontuation,etc) */
function stopGame() {
    btLevel.disabled = false;
    btPlay.textContent = 'Iniciar Jogo';
    gameStarted = false;

    // displays a modal to insert the players nickname
    modalGameOver.style.display = 'block';
    document.getElementById('messageGameOver').textContent = 'Pontuação: ' + totalPoints;
    
    cards.forEach(card => {
        card.classList.remove('inative');
        card.classList.remove('grayscale');
        card.removeEventListener('click', flipCard);
    });    
    
    // cancels timer defined at setInterval()
    clearInterval(timerId);
    
    hideCards();
    reset();
    checkTop10();
}

const createAndShuffleCards = array => {
    shuffleArray(array);
    array.splice(cards.length / 2, Number.MAX_VALUE);
    array.push(...array);
    shuffleArray(array)
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
    const success = flippedCards[0].dataset.logo === flippedCards[1].dataset.logo;
    if (success) {       
        flippedCards.forEach(card => {
            card.classList.add('inative');
            card.querySelector('.card-front').classList.add('grayscale');
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
    } else {
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
    }

    // update totalPoints based on the cards compare result
    updatePoints(success);

    // clear flipped cards array
    flippedCards = [];
}

/* If all the cards were flipped return true, else returns false */
const gameOver = () => {return totalFlippedCards == cards.length};

/* Decrement the timer */
function updateGameTime() {
    labelGameTime.textContent = --timer + 's';
    timer == 0 ? stopGame() : timer <= 10 ? labelGameTime.style.background = 'red' : labelGameTime.style.background = 'grey';
}

/* Updates the user's total points */
function updatePoints(success) {
    if (success)
        totalPoints += timer * totalPairs;
    else
        totalPoints >= 5 ? totalPoints-=5 : totalPoints = 0;
    labelPoints.textContent = totalPoints;
}

/* Get the TOP10 */
function getTop10() {
    /*let top10str = '';
    for (let i of topGamers)
        top10str+=`${i.nickname} - ${i.points} \n`;
    console.log(top10str);
    document.getElementById('infoTop').innerHTML = top10str; */

    let infoTop = document.getElementById('infoTop');
    infoTop.innerHTML = '';

    // Create first line of the table
    let div = document.createElement('div');
    let pNick = document.createElement('p');
    let pPoints = document.createElement('p');
    
    // Apppend p's to the div
    div.appendChild(pNick);
    div.appendChild(pPoints);

    // Define de p's values
    pNick.textContent = 'Nick Name';
    pPoints.textContent = 'Pontuação';

    // Append the created strucuture to the main structure (infoTop)
    infoTop.appendChild(div);

    // for each i create a <div> with 2 <p>
    for (let i of topGamers) {
        // Clone the div created outside
        let clonedDiv = div.cloneNode(true);

        // Set the firstchild (p - nickName) and lastChild (p - points) values
        clonedDiv.firstChild.textContent = i.nickname;
        clonedDiv.lastChild.textContent = i.points;

        // Append the cloned div to the main structure (infoTop)
        infoTop.appendChild(clonedDiv);
    }
}

function getTopPoints() {
    let maxPoints = 0;
    for (let i of topGamers) 
        maxPoints = Math.max(maxPoints,i.points);
    document.getElementById('pointsTop').textContent = maxPoints;
}   

// Returns the points of the player with the least points
function getLastPoints() {
    let minPoints = Infinity;
    for (let i of topGamers) 
        minPoints = Math.min(minPoints,i.points);
    return minPoints;
}

// Checks if a player enters the top10
function checkTop10() {
    let playerPoints = document.getElementById('points').textContent;
    
    // Check the array length
    if (topGamers.length == 10 && playerPoints <= getLastPoints())
        return;

    // If the player has more points than other player or the array isn't full
    // Display the nickname dialog box
    document.getElementById('nickname').style.display = 'block';

    // Display a message
    document.getElementById('messageGameOver').innerHTML = '<br> Parabens! Entrou no TOP 10';
}

// Store the player in the top10 array
function saveTop10() {
    let player = {nickname: document.getElementById('inputNick').value, points: document.getElementById('points').textContent};
    let exitsInArray = topGamers.includes(player.nickname);

    if (exitsInArray) {
        // If the user already exits in the list his points are updated
        for (let i of topGamers) {
            if (i.nickname == player.nickname && i.points < player.points) {
                i.points = playerPoints;
                updated = true;
            }        
        }
        return;
    }
    
    // Push the new player in the top10 array
    topGamers.push(player);

    // Sort the array
    topGamers.sort(function(a,b) { return b.points - a.points });

    // Store localy the data of player and the top10
    localStorage.setItem('nickname',player.nickname);
    localStorage.setItem('top10',JSON.stringify(topGamers));
}

// Get the localy saved nickname and top10 on localStorage
// This function is a IIFE(Immediately Invoked Function Expression) and its executed once
(function() {
    if (localStorage.getItem('top10') != null) {
        console.log(localStorage.getItem('nickname'));
        topGamers = JSON.parse(localStorage.getItem('top10'));
    }        
}) ();

/* EVENTS LISTENERS */
/* Implement card listeners hover/click */
function createCardEventListener(card) {
    card.addEventListener('mouseover', function() {
        card.classList.add('cardHover');
    });

    card.addEventListener('mouseout', function() {
        card.classList.remove('cardHover');
    });

    card.addEventListener('click',flipCard,{once:true});
}

/* Enables play button and display the grid */
btLevel.addEventListener('change',reset);

/* Start/Stop the game */
btPlay.addEventListener('click', function() {
    return (btPlay.textContent == 'Iniciar Jogo') ?  startGame() : stopGame();
});

/* Save player info in the top10 */
btOkTop.addEventListener('click', function() {
    modalGameOver.style.display = 'none';
    saveTop10();    
    reset();
});

/* Initialize functions */
reset()