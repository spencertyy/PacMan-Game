"use strict";

const canvas = document.getElementById("canvasDrawing")
canvas.width = window.innerWidth
canvas.height = window.innerHeight
const context = canvas.getContext("2d")

const canvasWidth = canvas.width
const canvasHeight = canvas.height
const imageSize = 77
const getCrabLength = 7//生成蜜蜂数量为7
const crabs = Array(getCrabLength).fill(null).map(createRandomCrab)
let cursorX = 0
let cursorY = 0
let gameEnded = false;
//context 指的是绘图上下文对象
//save(): 保存当前绘图状态，包括位置、旋转，可以恢复之前的状态。
//translate(): 平移绘图。将画布的原点移动到蜜蜂图像的中心位置，以便后续旋转围绕蜜蜂图像中心进行。
//rotate(): 旋转绘图。根据蜜蜂的飞行方向计算旋转角度，并将画布绕蜜蜂图像中心进行旋转。
//drawImage(): 绘制图像。绘制蜜蜂图像在旋转后的位置，保持图像中心在指定的位置。
function drawASingleCrab(Crab) {
    const { xPos, yPos, image } = Crab; //get the xy pos and image to the bee
    context.save(); 
    context.translate(xPos + imageSize / 2, yPos + imageSize / 2);
    context.drawImage(image, -imageSize / 2, -imageSize / 2, imageSize, imageSize);
    context.restore();//恢复之前保存的绘图状态，包括位置、旋转等，以确保后续绘图不受影响。
}
//生成随机蜜蜂的方向速度
function createRandomCrab() {
    const Crab = {
        xPos: canvasWidth * Math.random(),//Random value in[0, canvasWidth)
        yPos: canvasHeight * Math.random(),
        speed: Math.random() * 2, //Random value in[0, 2)
        image: new Image(imageSize, imageSize),
        isHeadingRight: true,
        isHeadingUp: true,
    };
    Crab.image.src = "crab.svg";
    return Crab;
}
// //移动蜜蜂时不留下残留的图像。
// function eraseASingleBee(bee) {
//     context.clearRect(bee.xPos, bee.yPos, imageSize, imageSize);
// }//erase the xy pos change to image size and when u Move the bee without leaving a residual image

// //更新位置
// function updateBeePosition(bee) {
//     bee.xPos += (bee.isHeadingRight ? 1 : -1) * bee.speed;
//     bee.yPos += (bee.isHeadingUp ? -1 : 1) * bee.speed;
// }//if bee is heading right turn 1 else turn -1 

// function calculateBeeHoneypotDistance(bee) {
//     const deltaX = cursorX - bee.xPos;
//     const deltaY = cursorY - bee.yPos;
//     return Math.sqrt(Math.pow(deltaX, 2) + Math.pow(deltaY, 2));
// }

// function isBeeMeetingHoneypot(bee) {
//     const honeypotRadius = imageSize / 2 * Math.sqrt(2);
//     const beeHoneypotDistance = calculateBeeHoneypotDistance(bee);
//     return beeHoneypotDistance <= honeypotRadius;
// }


// function checkIfGameIsEnded() {
//     const areBeesMeetingHoneypot = bees.map(isBeeMeetingHoneypot);
//     return areBeesMeetingHoneypot.some(el => el);
// }

// function updateBeeMovingDirections(bee) {
//     bee.isHeadingRight = bee.xPos < cursorX;
//     bee.isHeadingUp = bee.yPos > cursorY;
// }


// function drawBees() {
//     const ifGameIsEnded = checkIfGameIsEnded();
//     if (ifGameIsEnded) {
//         window.cancelAnimationFrame(handleWindowOnLoad);
//         endTheGame();
//     } else {
//         bees.forEach(eraseASingleBee);
//         bees.forEach(updateBeeMovingDirections);
//         bees.forEach(updateBeePosition);
//         bees.forEach(drawASingleBee);
//         window.requestAnimationFrame(drawBees); // get the browser to run your update/drawing code each frame.
//     }
// }


// const handleWindowOnLoad = window.requestAnimationFrame(drawBees)

function animateImg() {
    if (gameEnded) {
        // 如果游戏已经结束，直接返回，不再处理后续逻辑，因为gameEnded = false;
        return;
    }
    context.clearRect(0, 0, canvas.width, canvas.height);//清空之前的图像，以便绘制新的图像。
    crabs.forEach(Crab => {//对于每个 Crab，计算鼠标指针位置与 Crab 位置之间的距离（distance）
        const dx = cursorX - Crab.xPos;
        const dy = cursorY - Crab.yPos;
        const distance = Math.sqrt(dx * dx + dy * dy);

        if (distance > 1) {//如果距离（distance）大于 1，它将更新 Crab 的位置
            Crab.xPos += (dx / distance) * Crab.speed;
            Crab.yPos += (dy / distance) * Crab.speed;
        }//如果距离小于 imageSize / 2，它调用 endTheGame() 函数，
        if(distance<imageSize/ 2){
            endTheGame()
        }
        context.drawImage(Crab.image, Crab.xPos, Crab.yPos, imageSize, imageSize);
    });//ontext.drawImage 将每个 Crab 的图像绘制到 Canvas 上的新位置
    if(!gameEnded){
        window.requestAnimationFrame(animateImg);
    }
}//如果游戏未结束requestAnimationFrame 来请求下一帧的动画。
//这将使 animateImg 函数在每一帧之间递归调用，创建动画效果
function generateEndingDiv() {
    const ending = document.createElement("div");
    ending.style.textAlign = "center";// 设置文本居中
    ending.style.display = "flex";// 设置为弹性布局
    ending.style.flexDirection = "column";// 设置列布局
    ending.style.alignItems = "center";// 设置元素在交叉轴上的居中对齐
    ending.style.marginTop = `${canvasHeight / 2}px`;// 设置顶部边距
    return ending;
}

function showEndingTip() {
    const ending = generateEndingDiv();
    const oops = document.createElement("h1");
    oops.textContent = "🦀️Ooops you lost the Game!";
    const refreshTip = document.createElement("h1");
    refreshTip.textContent = "🎣Refresh the page to start again!";
    //// 将提示信息添加到 ending 中
    ending.appendChild(oops);
    ending.appendChild(refreshTip);
    // 将 endingDiv 添加到文档中，显示提示信息
    document.body.appendChild(ending);
}

function endTheGame() {
    canvas.remove();
    showEndingTip();
}

function handleMouseMove(event) {
    cursorX = event.clientX
        //- canvas.offsetLeft;
    cursorY = event.clientY
       // - canvas.offsetTop;
}

window.onload = animateImg
window.addEventListener ('mousemove', handleMouseMove);