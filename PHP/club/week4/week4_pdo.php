<?php

// 建立連線
$dbh = new PDO('mysql:host=localhost;dbname=php_course;charset=utf8', 'php_course', '123456789');

$sql = "SELECT * FROM `student` WHERE `STUID` = :stuid";
$arr["stuid"] = "B04402001";

// 準備執行sql
$stmt = $dbh->prepare($sql);
// 將條件句需要的值以array的方式傳遞，並執行sql
$stmt->execute($arr);

// 將結果以陣列的方式返回
while($result = $stmt->fetch(PDO::FETCH_ASSOC)){
    print_r($result);
}

// 將結果以物件的方式返回
// $result = $stmt->fetch(PDO::FETCH_OBJ);
// echo $result->STUID;

/* 
大家可以去玩玩看
https://www.php.net/manual/en/pdostatement.fetch.php
*/