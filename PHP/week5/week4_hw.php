<?php
session_start();
print_r($_SESSION);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>session使用</title>
</head>
<body>
    <?php if(!isset($_SESSION["acc"])){?>
    <form action="week4_hw_act.php" method="post">
        <label for="acc">帳號</label>
        <input type="text" name="acc" id="acc">

        <br>

        <label for="pass">密碼</label>
        <input type="password" name="pass" id="pass">

        <button type="submit">登入</button>
    </form>
    <?php }?>  

    <?php if(isset($_SESSION["acc"])){?>
        <p><?=$_SESSION["acc"]?>，您好</p>

        <button><a href="week4_hw_act.php">登出</a></button>
    <?php }?>
</body>
</html>