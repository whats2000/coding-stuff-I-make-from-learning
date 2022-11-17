<?php
include("./config.php");
session_start();

if (!isset($_SESSION["name"])) { ?>

<script>
alert('您未登錄')
window.location.href = './login.php'
</script>

<?php
}

$sql = "SELECT * FROM `member` WHERE `acc` = '".$_SESSION["name"]."';";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_assoc($result);
$mid = $row['mid'];

$sql = "SELECT * FROM `photo` WHERE `mid` = '$mid' and `hidden` = 0;";
$result = mysqli_query($link, $sql);
$img = array();

if (mysqli_num_rows($result) != 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $img[$row["pid"]]["src"] = $row["src"];
        $img[$row["pid"]]["title"] = $row["title"];
        $img[$row["pid"]]["description"] = $row["description"];
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>相片資料庫 - 首頁</title>

    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js"
        integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous">
    </script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js"
        integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous">
    </script>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
</head>

<body>
    <div class="card text-center">
        <div class="card-header">
            <ul class="nav nav-pills card-header-pills">
                <li class="nav-item">
                    <a class="btn btn-dark" href="#">帳號設定</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#">Github Link</a>
                </li>
            </ul>
        </div>

        <div class="card-body">
            <div class="row justify-content-center">
                <div class="col-sm-5">
                    <h5>歡迎使用者 <?=$_SESSION["name"]?> ，您好 !</h5>
                    <div class="d-grid gap-2">
                        <input class="form-control form-control-lg" id="formFileLg" type="file">
                        <a href="#" class="btn btn-dark">上傳</a>

                        <form action="member.php" method="get" class="d-grid">
                            <input type="hidden" id="method" name="method" value="logout">
                            <button type="submit" class="btn btn-dark">登出</button>
                        </form>
                    </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
    </div>

    <div class="card">
        <div class="card-header">
            圖片
        </div><?php if (empty($img)) { ?>
        <div class="card-body">
            <p class="card-text text-center text-muted">這裡空空如也</p>
        </div>
        <?php } else {?>
        <div class="container">
            <div class="card-body">
                <div class="row row-cols-1 row-cols-md-3 g-4">
                    <?php foreach ($img as $pid => $photo) { ?>
                    <div class="col">
                        <div class="card h-100">
                            <img src="<?=$photo["src"]?>" class="card-img-top" alt="...">
                            <div class="card-body">
                                <h5 class="card-title"><?=$photo["title"]?></h5>
                                <p class="card-text"><?=$photo["description"]?></p>
                            </div>
                            <div class="card-footer">
                                <div class="btn-group" role="group" aria-label="Basic outlined example">
                                    <a href="#" class="btn btn-outline-dark">修改</a>
                                    <a href="#" class="btn btn-outline-dark">刪除</a>
                                </div>
                            </div>
                        </div>
                    </div>
                    <?php } ?>
                </div>
            </div>
        </div>
        <?php } ?>
    </div>
</body>

</html>