<?php

    $a = 3;
    $b = 5;

    // function
    function multi($a, $b)
    {
        echo "function內 a：".$a." b:".$b."<br>";
        return $a * $b;
    }
    
    echo "跑function前 a：".$a." b:".$b."<br>";
    echo multi(5, 2)."<br>";
    echo "跑function後 a：".$a." b:".$b."<br>";


    // isset 與 empty 用法
    // 可以改$var1裡面的值去做測試
    $var1 = "";

    // 大家可以改$var1為其他變數名稱測試
    if (isset($var1)) {
        echo '$var1變數確實存在<br>';
    } else {
        echo '$var1變數不存在<br>';
    }

    if (empty($var1)) {
        echo '$var1變數為空值<br>';
    } else {
        echo '$var1變數不為空值<br>';
    }

    // $var1 確實存在，然而因為他為空值，因此返回值為false
    if ($var1) {
        echo '$var1變數確實存在<br>';
    } else {
        echo '$var1變數不存在<br>';
    }


    // date 的用法
    // 將時區設置在台北
    date_default_timezone_set('Asia/Taipei');

    // Y：年分 m：月份 d：日期  H：小時 i：分鐘 s：秒數
    $today = date("Y-m-d H:i:s");
    echo "今天：".$today."<br>";

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>week2_上課</title>
</head>
<body>
    <!-- 大家可以改改看method去觀察封包 -->
    <form action="week2_act.php" method="POST" autocomplete="off"  enctype="multipart/form-data">
        <input type="text" name="type" value="val">

        <br>

        <label for="email">電子郵件</label>
        <input type="email" name="email"> 

        <br>

        <label for="password">密碼</label>
        <input type="password" name="password">

        <br>    

        <!-- 單選 -->
        <label for="radio-phone">電話</label>
        <input type="radio" name="contact" id="radio-phone" value="phone" checked>

        <label for="radio-email">電子信箱</label>
        <input type="radio" name="contact" id="radio-email" value="email">

        <label for="radio-text">訊息</label>
        <input type="radio" name="contact" id="radio-text" value="text" >

        <br>

        <label class="block">下拉式選單
            <select name="dropdown-list" id="dropdown-list">
                <option value="" selected disabled>請選擇</option>
                <option value="1">排骨便當</option>
                <option value="2">燒臘便當</option>
                <option value="3">雞腿便當</option>
            </select>
        </label>

        <br>
        
        <button type="submit">submit</button>
    </form>
</body>
</html>