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
        session_start();

        $drink_id = $_SESSION['drink_id'];

        if (!empty($_POST)) {
            foreach ($drink_id as $i => $drink) {
                if ($_POST["num".strval($i)] > 0) { ?>
                    <h4>
                        <?=$drink["name"]?> 
                        數量 : <?=$_POST["num".strval($i)]?> 
                        價格 : <?=$drink["price"] * $_POST["num".strval($i)]?>
                    </h4>

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