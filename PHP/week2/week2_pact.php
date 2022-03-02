<?php
    $drink_id = array(
        1=>array("name"=>"金萱雙Q", "price"=>35),
        2=>array("name"=>"胭脂紅茶", "price"=>40),
        3=>array("name"=>"胭脂多多", "price"=>50),
        4=>array("name"=>"百箱爽響炮", "price"=>60)
    );
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous"></script>
    <title>第二周練習</title>
</head>
<body>
    <div class="row justify-content-center">
        <div class="col-sm-4">
            <form action="week2_pact_act.php" method="post">
                <?php
                    session_start();

                    $_SESSION['drink_id'] = $drink_id;

                    foreach ($drink_id as $i => $drink) { ?>
                        <p><?=$drink["name"]?> 價格 : <?=$drink["price"]?></p>

                        <label for="num<?=$i?>">請填寫數量</label>
                        <input type="number"  min="0" max="10" value="0" id="num<?=$i?>" name="num<?=$i?>">

                        <br>
                        <br>

                        <div class="mb-3">
                            <select name="sugar<?=$i?>" class="form-select form-select mb-3" aria-label=".form-select ">
                                <option selected>請選擇甜度</option>
                                <option value="多糖">多糖</option>
                                <option value="正常糖">正常糖</option>
                                <option value="少糖">少糖</option>
                                <option value="半糖">半糖</option>
                                <option value="微糖">微糖</option>
                                <option value="無糖">無糖</option>
                            </select>
                        </div>
                        <div class="mb-3">
                            <select name="ice<?=$i?>" class="form-select form-select mb-3" aria-label=".form-select ">
                                <option selected>請選擇冰塊</option>
                                <option value="多冰">多冰</option>
                                <option value="正常冰">正常冰</option>
                                <option value="少冰">少冰</option>
                                <option value="微冰">微冰</option>
                                <option value="去冰">去冰</option>
                            </select>
                        </div>
                    <?php
                    } ?>

                <br>
                
                <div class="mb-3 ">
                    <label for="name">姓名</label>
                    <input type="text" name="name" id="name">
                </div>

                <div class="mb-3 ">
                    <label for="phone">聯絡電話</label>
                    <input type="text" name="phone" id="phone">
                </div>

                <div class="mb-3 ">
                    <label for="addr">地址</label>
                    <input type="text" name="addr" id="addr">
                </div>

                <div class="mb-3 ">
                    <input type="checkbox" class="form-check-input" id="check" name="check" required>
                    <label class="form-check-label" for="check">以上資料皆正確</label>
                </div>

                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
        </div>
    </div>
    
</body>
</html>