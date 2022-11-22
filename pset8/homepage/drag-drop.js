const cards = document.querySelectorAll('.card-container');
const cardsBoxes = document.querySelectorAll('.cards-container');
let dragCard = null;
let cardId = null;
let cardHeightPositionDefault = [];
let mouseY = null;
let cardOrder = [];

setCardsHeight()

function setCardsHeight(){
    let i = 0
    cards.forEach(card =>{
        cardHeightPositionDefault.push(getPosition(card));
        cardOrder.push(card.id)
        i++;
    })
    console.log(cardOrder)
}

function getPosition(element){
    console.log(element.id);
    const cardElement = element.getElementsByTagName("div").item(0);
    const y = cardElement.offsetTop;
    console.log(y)
    return y;
}


cards.forEach(card => {
    card.addEventListener('dragstart', dragStart);
    card.addEventListener('dragend', dragEnd);
});
function dragStart(e){
    cardId = e.target.id;
    
    setTimeout(() => {
        e.target.classList.add('hide');
    }, 0);
}

function dragEnd() {
  	this.className = 'card-container'
  	dragCard = null;
}

cardsBoxes.forEach(box => {
    box.addEventListener('dragenter', dragEnter);
    box.addEventListener('dragover', dragOver);
    box.addEventListener('drop', drop);
});

function dragEnter(e) {
    e.preventDefault();
}

function dragOver(e) {
    e.preventDefault();
}

function dragDrop() {
    this.append(dragCard);
}

function getElement(id){
    for(let i = 0; i < cards.length; i++){
        if(cards[i].id == id){
            return cards[i]
        }
    }
}

function drop(e) {
    const draggable = document.getElementById(cardId);
    const dragPosition = e.pageY;
    
    console.log(dragPosition);
    
    for(var i = 0; i < cardHeightPositionDefault.length; i++){
        if(dragPosition < cardHeightPositionDefault[i]){
            let next = cardOrder[i-1];
            // i is card position
            if(next >= cardHeightPositionDefault.length){
                break;
            }
            else{
                console.log(next + " || " + cardId)
                let origin = 0
                for(let j = 0; j < cardOrder.length;j++){
                    if(cardOrder[j] == cardId){
                        origin = j;
                        break;
                    }
                }
                // case 1 -> 3
                if(origin < i){
                    for(let j = origin; j < cardHeightPositionDefault.length-1; j++){
                        if(j == (i - 1)){
                            cardOrder[j] = cardId;
                            break;
                        }
                        cardOrder[j] = cardOrder[j + 1];
                    }
                }
                else{
                    cardOrder[i-1] = cardId;
                    for(let j = i; j < cardHeightPositionDefault.length-1; j++){
                        let temp = cardOrder[j];
                        cardOrder[j] = next
                        if(temp == cardId){
                            break
                        }
                        else{
                            next = temp;
                        }
                }
                }
                    console.log("New: "+cardOrder)
                break
            }
        }
    }
    
    this.innerHTML = "";
    for(let i = 0; i < cardOrder.length; i++){
        this.append(getElement(cardOrder[i]))

    }

    // display the draggable element
    draggable.classList.remove('hide');
}