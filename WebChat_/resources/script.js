//make by: yuyaotu  HW8  Week4/Day16/WebChat/
"use strict"
const chatRoom =document.getElementById("chat-room");
const chatMessages = document.getElementById("chat-messages");
const messageInput =document.getElementById("message-input");
const sendButton = document.getElementById("send-button")
const userName = document.getElementById("username");
const roomNumber = document.getElementById("roomNumber");
const joinButton = document.getElementById("joinBtn");
const leaveButn =document.getElementById("leave-button");
let wsOpen = false;

let ws = new WebSocket("ws://localhost:8080");
ws.onopen=handleOpenCB;

function handleOpenCB(){
    wsOpen = true;
    console.log("WebSocket connection is open.");
}
ws.onmessage = (event) =>{
    let data = JSON.parse(event.data);
    //event.data 中的 JSON 数据解析成 JavaScript 对象，并将该对象存储在 data 变量中，以便后续在代码中使用。
    console.log(data);//console.log 来输出变量的值、查看函数的执行结果
    if (data.type === "join") {
        const joinTheRoom = document.createElement("div");
        joinTheRoom.textContent=`${data.user} has joined the ${data.room}`;
        chatRoom.appendChild(joinTheRoom);
    }
    if (data.type === "leave") {
        const leaveTheRoom = document.createElement("div");
        leaveTheRoom.textContent=`${data.user} had leave the ${data.room}`;
        chatRoom.appendChild(leaveTheRoom);
    }
    if (data.type === "message") {
        let messageDiv= document.createElement("p")
        messageDiv.textContent = `${data.user}:${data.message}`
        chatMessages.appendChild(messageDiv);

    }
}
// Add an event listener for the send button
sendButton.addEventListener("click", sendMessage);
joinButton.addEventListener("click", joinRoom);
leaveButn.addEventListener("click", leaveTheRoom);

function sendMessage() {
    const messageText = messageInput.value;
    if (messageText !== "") {//if the message is not empty
        ws.send(`message ${messageText}`);
    }
}

function joinRoom() {
    console.log("join");//print the join to see is work or not
    let user = userName.value;
    let roomName = roomNumber.value;
    // 使用正则表达式检查是否只包含小写字母
    const isLowerCaseOnly = /^[a-z]+$/.test(roomName);
    if (!isLowerCaseOnly) {
        alert("Invalid room name. Please use only lowercase letters.");
    } else {
    // if(roomName.indexOf(" ") >= 0){
    //     alert("Invalid room name. Please use only lowercase letters and no spaces.")
    // }
    // else {
        ws.send(`join ${user} ${roomName}`);
    }
}
function leaveTheRoom(){
    ws.send(`leave`);
}