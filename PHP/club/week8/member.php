<?php
include("./config.php");
session_start();

// 變數說明
// $status = 0 => 導回login.php
// $status = 1 => 導向index.php

$status = 0;
$msg = "";

if(@$_POST){
    $acc = $_POST["acc"];
    $pass = $_POST["pass"];   
}


if(@$_GET["method"] == "logout"){
    $msg = "登出成功";
    session_destroy();
}

if(@$_POST["method"] == "login"){

    $sql = "SELECT * FROM `member` WHERE `acc` = '$acc'";
    $result = mysqli_query($link, $sql);

    if($result){
        $num = mysqli_num_rows($result);
        if($num == 0){
            $msg = "目前尚未有會員資料";
        }else{
            $row = mysqli_fetch_assoc($result);
            if($row["pass"] == $pass){
                $status = 1;
                // 將會員名稱存入session
                $_SESSION["name"] = $acc;
                $msg = "登入成功";
            }else{
                $msg = "密碼錯誤";
            }
        }
    }else{
        $msg = "處理失敗";
    }

}else if(@$_POST["method"] == "register"){
    $sql = "SELECT * FROM `member` WHERE `acc` = '$acc'";
    $result = mysqli_query($link, $sql);

    if($result){
        $num = mysqli_num_rows($result);
        if($num == 0){
            $sql = "INSERT INTO `member` (`acc`, `pass`) VALUES ('$acc', '$pass')";

            if(mysqli_query($link, $sql)){
                $status = 1;
                $msg = "註冊成功";
                // 將會員名稱存入session
                $_SESSION["name"] = $acc;
            }else{
                $msg = "處理失敗";
            }
        }else{
            $msg = "該帳號名稱已有使用者使用，請重新填寫新的帳號名稱";
        }
    }else{
        $msg = "處理失敗";
    }
}

if($status == 0){
    $url = "login.php";
}else if($status == 1){
    $url = "index.php";
}

echo "<script>";
echo "alert('".$msg."');";
echo "window.location.href = './".$url."';";
echo "</script>";
exit();
?>