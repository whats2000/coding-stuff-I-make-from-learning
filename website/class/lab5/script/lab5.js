const correct_pw = "web";
const email = "whats2000mc@gmail.com";

function page_load() {
    document.getElementById("email").onclick = email_click;
}

function email_click() {
    let pw = prompt("Enter passcode to show email");
    if (pw != correct_pw) {
        alert("Sorry, incorrect passcode");
        return;
    }

    let email_btn = document.getElementById("email");
    let showed_email = document.getElementById("showed_email");
    email_btn.style.display = "none";
    showed_email.innerText = email;
}

window.onload = page_load; // global code