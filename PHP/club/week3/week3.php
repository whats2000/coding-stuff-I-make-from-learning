<?php
    include("./config.php");

    $sql = "SELECT `name`, `birthdate` FROM `student` WHERE `STUID` = 'B04402001'";
    // 執行 SQL 訪問
    $result = mysqli_query($link, $sql);
    // 取得資料數量
    $num = mysqli_num_rows($result);

    if (!$result) {
        // 假如執行錯誤
        mysqli_error($link);
    } else {
        echo $num;

        while ($row = mysqli_fetch_assoc($result)) {
            // 利用 while 取額資料回傳值為 array
            print_r($row);
        }
    }
