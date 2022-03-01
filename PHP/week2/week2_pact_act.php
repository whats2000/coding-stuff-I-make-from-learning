<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>week2_pact_act</title>
</head>
<body>
<?php
    $drink_id = array(
        1=>array("name"=>"金萱雙Q", "price"=>35),
        2=>array("name"=>"胭脂紅茶", "price"=>40),
        3=>array("name"=>"胭脂多多", "price"=>50)
    );

    if (!empty($_POST)) {
        for ($i = 1; $i < 4; $i++) {
            if ($_POST["num".strval($i)] > 0) { ?>
                <h4><?=$drink_id[$i]["name"]?> 數量 : <?=$_POST["num".strval($i)]?> 價格 : <?=$drink_id[$i]["price"] * $_POST["num".strval($i)]?></h4>

                <p>冰度 : <?=$_POST["ice".strval($i)]?> </p>
                <p>甜度 : <?=$_POST["sugar".strval($i)]?></p>

                <br>
            <?php }
        } ?>
        <h4>訂購人資料</h4>

        <p>姓名 : <?=$_POST["name"]?> </p>

        <p>聯絡資訊 : <?=$_POST["phone"]?></p>

        <p>地址 : <?=$_POST["addr"]?></p>
    <?php
    } ?>
</body>
</html>