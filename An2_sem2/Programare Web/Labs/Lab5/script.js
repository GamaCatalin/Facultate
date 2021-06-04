let numbersArray = [];


function readInput(){
    let textAreaInput = document.getElementById("input").value;
    //console.log(textAreaInput);

    let inputArray = textAreaInput.split(" ");

    for(let i = 0 ; i<inputArray.length; i++){
        let numberValue = parseInt(inputArray[i]);
        if(Number.isFinite(numberValue)){
            numbersArray.push(numberValue);
        }
    }
}



function sortArray(){
    let length = numbersArray.length;

    for(let i=0;i<length;i++){
        for(let j=i+1;j<=length;j++){
            if(numbersArray[i]>numbersArray[j]){
                console.log("passed if");
                let temp = numbersArray[i];
                numbersArray[i] = numbersArray[j];
                numbersArray[j] = temp;
            }
        }
    }
}



function updateRows() {
    numbersArray = [];

    readInput();
    sortArray();

    let table;
    table = document.getElementById("table");
    table.innerHTML = "";

    let rows = Math.ceil(numbersArray.length / 5);

    let elementsNr = numbersArray.length;

    for (let i = 0; i < rows * 5 - elementsNr; i++) {
        numbersArray.push("");
    }

    for (let i = 0; i < rows; i++) {
        table.innerHTML = table.innerHTML +
            "<tr>" +
            "<td>" + numbersArray[i * 5] + "</td>" +
            "<td>" + numbersArray[i * 5 + 1] + "</td>" +
            "<td>" + numbersArray[i * 5 + 2] + "</td>" +
            "<td>" + numbersArray[i * 5 + 3] + "</td>" +
            "<td>" + numbersArray[i * 5 + 4] + "</td>" +
            "</tr>"
        ;
    }
}
