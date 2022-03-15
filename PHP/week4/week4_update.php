<?php

$dbh = new PDO('mysql:host=localhost; dbname=php_course; charset=utf8', 'whats2000_', '123456789');
$stuid = $_GET["stuid"];

if ($_GET["status"] == "update") {
    $sql = "UPDATE `student` SET `birthdate` = :birthdate WHERE `STUID` = :stuid";
    $arr["stuid"] = $stuid;
    $arr["birthdate"] = date("Y-m-d");

    $stmt = $dbh->prepare($sql);

    if ($stmt->execute($arr)) {
        echo "<script>";
        echo "alert('已經更新該筆資料');";
        echo "window.location.href = './week4.php';";
        echo "</script>";
    }
} elseif ($_GET["status"] == "del") {
    $sql = "UPDATE `student` SET `birthdate` = '2022-03-15' WHERE `STUID` = :stuid";
    $arr["stuid"] = $stuid;

    $stmt = $dbh->prepare($sql);

    if ($stmt->execute($arr)) {
        echo "<script>";
        echo "alert('已經更新該筆資料');";
        echo "window.location.href = './week4.php';";
        echo "</script>";
    }
}
