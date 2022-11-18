<?php
include("./config.php");
session_start();

if(!isset($_SESSION["name"])){
    echo "<script>";
    echo "window.location.href = './login.php';";
    echo "</script>";
    exit();
}

$sql = "SELECT * FROM `member` WHERE `acc` = '".$_SESSION["name"]."';";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_assoc($result);
$mid = $row["mid"];

$sql = "SELECT * FROM `photo` WHERE `mid` = '$mid' and `hidden` = 0;";
$result = mysqli_query($link, $sql);
$img = array();

// 如果資料回傳> 0筆，把資料繞成我想要呈現的方式（這邊array大家可以根據自己
// 想表達的方式去做包裝）
if(mysqli_num_rows($result) != 0){
    // 取得資料
    while($row = mysqli_fetch_assoc($result)){
        $img[$row["pid"]]["src"] = $row["src"];
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
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    <title>首頁</title>
</head>
<body>
    <div class="container">
        <h4><?=$_SESSION["name"]?>，你好</h4>
        <h4><a href="member.php?method=logout">登出</a></h4>
        <a href="upload.php" class="btn btn-dark">上傳相片</a>

        <div class="mb-3"></div>

        <div class="row justify-md-content-center">
        <?php
            if(empty($img)){
        ?>
            <div class="col-sm-5">
                <div class="alert alert-warning" role="alert">
                    目前暫無照片
                </div>
            </div>
        <?php
            }else{
                foreach($img as $pid => $photo){
        ?>
            <div class="col-md-4">
            <div class="card" style="width: 18rem;">
                <img src="<?=$photo["src"]?>" class="card-img-top">
                <div class="card-body">
                    <div class="description">
                        <p class="card-text"><?=$photo["description"]?></p>
                    </div>
                    <div class="edit_description" style="display:none;" data-pid="<?=$pid?>">
                        <textarea cols="30" rows="3" class="edit_val"><?=$photo["description"]?></textarea>
                    </div>
                    <div class="row row-cols-lg-auto g-3 align-items-center">
                        <a href="#" class="edit_btn btn btn-dark">編輯</a>
                        <form action="photo_process.php" method="post" class="photo_delete">
                            <input type="hidden" name="pid" value="<?=$pid?>">
                            <input type="hidden" name="method" value="delete">
                            <button type="submit" class="btn btn-white photo-delete">刪除</button>
                        </form>
                    </div>
                </div>
                </div>
            </div>
            
        <?php
                } //end foreach
            }// end if..else
        ?>
        </div>
    </div>
</body>

<script src="https://code.jquery.com/jquery-3.5.0.min.js"></script>
<script>
    $(".photo_delete").on("submit",function(){
        return confirm("請問您確認要刪除嗎？");
    })

    $(".edit_btn").on("click", function(){
        let obj = $(this)
        let index = $(".edit_btn").index(obj);

        let description = $(".description").eq(index);
        let edit = $(".edit_description").eq(index);
        
        description.hide();
        // 下面的方法也可以
        // description.css("display", "none")
        edit.show();
    })

    // 使用者滑鼠移開輸入框後
    $(".edit_val").blur(function(){
        let obj = $(this)
        let index = $(".edit_val").index(obj);
        let pid = $(".edit_description").eq(index).data("pid")
        let text = $(".edit_val").eq(index).val();

        $.ajax({
            url: "photo_process.php",
            method: "POST",
            data: "pid=" + pid + "&description=" + text + "&method=update",
            dataType : "json"
        }).done( function(data){
            if(data["status"] == "success"){
                alert("修改成功")
                $(".description").eq(index).show();
                // 記得把顯示內容換成已修改完成的
                $(".description").eq(index).html(text);
                $(".edit_description").eq(index).hide();

            }else if(data["status"] == "fail"){
                alert("修改失敗");
                $(".description").eq(index).show();
                $(".edit_description").eq(index).hide();
            }
        })

    })

</script>
</html>