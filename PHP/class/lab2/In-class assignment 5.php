<?php
session_start();
$response = 0;

$formstyle = true;

$correct_acc = "web";
$correct_pass = "programming";

if (isset($_POST['submit-button'])) {
    $acc = $_POST["name"];
    $pass = $_POST["pass"];

    if (($acc == $correct_acc) && ($pass == $correct_pass)) {
        $formstyle = "hidden";
        $response = 1;
    } else {
        $response = 2;
    }
}

?>
<!DOCTYPE html>
<html>

<head>
    <title>whats2000</title>

    <link rel="stylesheet" type="text/css" href="static/css/all.css" />
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto">
</head>

<body>
    <!--Name-->
    <h1>whats2000</h1>

    <!--Login-->
    <div id="login">
        <?php if ($response=1) {?>
        <p>Web logged in</p>
        <?php } elseif ($response=2) {?>
        <p style="color: red">Incorrect login information</p>
        <?php }?>

        <?php if ($r = true) { ?>
        <form class="login" action="<?=$_SERVER['PHP_SELF'];?>" method="post">
            <label for="username">Username: </label>
            <input id="username" type="text" name="name" />

            <br>
            <label for="password">Password: </label>
            <input id="password" type="password" name="pass" />

            <br>
            <input type="submit" name="submit-button" />
        </form>;
        <?php }?>
    </div>

    <!--Main information of me-->
    <p>
        Hello, I am a <em>student</em> at the
        <strong>
            National Sun Yat-sen University
        </strong> in Taiwan.

        <br>

        <a href="https://whats2000.github.io/coding-stuff-I-make-from-learning/website/class/lab6/lab6.html">
            Link to my website
        </a>
    </p>

    <blockquote>Never give up an idea without trying to do it!</blockquote>

    <!--Information of coding experience-->
    <h3>Expertise</h3>

    <ul>
        <li class="li-highlight">Coding Experience</li>
        <li>Watch Movie</li>
        <li>Reading</li>
    </ul>

    <!--Information of project-->
    <h3>Projects</h3>

    <table>
        <tr class="table-header">
            <th>Year</th>
            <th>Projects</th>
        </tr>
        <tr>
            <td>2021</td>
            <td>PearlCalculatorBlazor: A website designed for simulated projectile for a game.</td>
        </tr>
        <tr>
            <td>2021</td>
            <td>Hypixel chinese skyblock bot: A chat bot designed for a discord community.</td>
        </tr>
        <tr>
            <td>2021</td>
            <td>SystemC Group 21 final project: A project developed to simulated Department of Mechanical Engineering
                Circuit Board.</td>
        </tr>
        <tr>
            <td>2022</td>
            <td>Facebooc: Proof-of-concept Facebook clone in C. We minimal the essential dependencies.</td>
        </tr>
    </table>
</body>

</html>