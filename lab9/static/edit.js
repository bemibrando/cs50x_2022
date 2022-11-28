const table = document.getElementById("birthTable")
let updateName, updateMonth, updateDay;
let updateButton

function nameInput(name){
    return `<input class="edit-input" id='updateName' type='text' value=${name}></input>`
}

function dateInput(date){
    const dateArr = date.split(" / ");
    
    return `
      <input id='updateMonth' type='number' value=${dateArr[0]} ></input> / <input id='updateDay' type='number' value=${dateArr[1]}></input>
    `
}

function submitOnClick(){
    updateName.removeEventListener("change", setUpdateInfo)
    updateMonth.removeEventListener("change", setUpdateInfo)
    updateDay.removeEventListener("change", setUpdateInfo)
    updateButton.removeEventListener("click", submitOnClick)
}

const edit = e => {
    const editForm = e.target.parentElement; // Get edit form
    const rowId = editForm.firstElementChild.value; // Get row number to edit
    
    const updateForm = editForm.parentElement.children[1]; // Get update form
    
    // Hide edit button and show up update button
    editForm.classList.add("hidden");
    updateForm.classList.remove("hidden");
    
    // Add id at inputs to edit
    updateForm.children[1].id = "nameUpdated"
    updateForm.children[2].id = "monthUpdated"
    updateForm.children[3].id = "dayUpdated"
    
    // Get update button
    updateButton = updateForm.children[4]
    updateButton.addEventListener("click", submitOnClick)
    
    // Get tr to edit
    const row = table.children[rowId];
    
    name = row.children[0].innerHTML;
    row.children[0].innerHTML = nameInput(name);
    
    date = row.children[1].innerHTML;
    row.children[1].innerHTML = dateInput(date);
    
    updateName = document.getElementById("updateName")
    updateMonth = document.getElementById("updateMonth")
    updateDay = document.getElementById("updateDay")
    
    
    updateName.addEventListener("change", setUpdateInfo);
    updateMonth.addEventListener("change", setUpdateInfo);
    updateDay.addEventListener("change", setUpdateInfo);
}

let timeoutUpdate
function updateInfo(){
    nameForm = document.getElementById("nameUpdated")
    monthForm = document.getElementById("monthUpdated")
    dayForm = document.getElementById("dayUpdated")

    nameForm.value = updateName.value
    monthForm.value = updateMonth.value
    dayForm.value = updateDay.value
}

function setUpdateInfo(){
    clearTimeout(timeoutUpdate)
    timeoutUpdate = setTimeout(updateInfo, 200)
}