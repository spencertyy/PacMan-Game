var previousCell = null;
function mainFunc() {
    var tableBody = document.getElementById("multiplicationTableBody");



    for (var i = 1; i <= 10; i++) {
        var row = document.createElement("tr");

        for (var j = 0; j <= 10; j++) {
            var cell = document.createElement(j === 0 ? "th" : "td");
            cell.textContent = (j === 0 ? i : i * j);

            // Add event listeners for mouse enter and leave

            cell.addEventListener("mouseenter", mouseEnter);

            cell.addEventListener("mouseleave", mouseLeave);

            cell.addEventListener("click", handleCLick);

            row.appendChild(cell);
        }

        tableBody.appendChild(row);
    }

    let btn = document.getElementById('btn')
    btn.addEventListener("click",toggleBackgroundColor)

}
    function mouseEnter(){
        this.classList.add("highlighted");
    }

    function mouseLeave(){
        this.classList.remove("highlighted");
    }

    function handleCLick(){
        if (previousCell !== null) {
            previousCell.classList.remove("clickHighlight");
        }
        this.classList.add("clickHighlight");
        previousCell = this;
    }
    // Toggle background color animation
    let isAnimating = false;

    let isStop = false
    function toggleBackgroundColor() {
        isAnimating = !isAnimating;
        if (isAnimating) {
            startAnimation();
        } else {
            isStop = true
        }
    }

    function startAnimation() {
        isStop = false
        document.body.style.transition = 'background-color 1s';
        setInterval(changeBackgroundColor, 1500);
    }

    function changeBackgroundColor() {
        const currentColor = document.body.style.backgroundColor;
        if(!isStop) {
            if (currentColor === 'blue') {
                document.body.style.backgroundColor = 'red';
            } else {
                document.body.style.backgroundColor = 'blue';
            }
        }
    }


window.onload = mainFunc();