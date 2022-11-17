<?php

include("./config.php");


$sql = "SELECT * FROM `student`";
// 執行SQL語法
$result = mysqli_query($link, $sql);
// 取得資料數量

if (!($result)) {
    // 假如執行錯誤
    mysqli_error($link);
    // exit()代表網頁就執行到這裡，下面的地方就不會繼續跑了
    exit();
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>week4</title>
</head>
<body>
    <table border="1">
        <tr>
            <td>學號</td>
            <td>姓名</td>
            <td>生日</td>
            <td>狀態</td>
        </tr>
        <?php
        while ($row = mysqli_fetch_assoc($result)) {
            // 運用while迴圈去取得每一筆資料，返回值為array?>
            <tr>
                <td><?=$row['STUID']?>
                <td><?=$row['name']?>
                <td><?=$row['birthdate']?>
                <td>
                    <a href="week4_update.php?status=update&stuid=<?=$row['STUID']?>">更新</a>
                    /
                    <a href="week4_update.php?status=del&stuid=<?=$row['STUID']?>">刪除</a>
                </td>
        <?php
        }
        ?>
    </table>
</body>
</html>