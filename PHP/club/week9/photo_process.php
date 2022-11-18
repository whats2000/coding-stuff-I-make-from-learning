<?php
include("./config.php");
session_start();

// 得到mid
$sql = "SELECT * FROM `member` WHERE `acc` = '".$_SESSION["name"]."'";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_assoc($result);
$mid = $row["mid"];

if($_POST["method"] == "upload"){
    $text = $_POST["description"];

    // $_FILES["這邊填input的name"]["error"]
    if($_FILES["myfile"]["error"] != 0){
        $msg = "出錯".$_FILES["myfile"]["error"];
    }else{
        $filename = $_FILES["myfile"]["name"];
        $dest = "./img/".$mid."_".$filename;

        if(file_exists($dest)){
            $msg = "目前已有檔案存在";
        }else{
            if(move_uploaded_file($_FILES["myfile"]["tmp_name"], $dest)){
                $sql = "INSERT INTO `photo`(`mid`, `src`, `description`) 
                        VALUES ('$mid','$dest','$text')";
                if(mysqli_query($link, $sql)){
                    $msg = "檔案上傳成功";
                }else{
                    $msg = "檔案上傳失敗";
                }
            }else{
                $msg = "檔案上傳失敗";
            }
        }
    }
    
    echo "<script>";
    echo "alert('".$msg."');";
    echo "window.location.href = './index.php';";
    echo "</script>";
}
else if($_POST["method"] == "update"){
    $pid = $_POST["pid"];
    $text = $_POST["description"];

    $sql = "UPDATE `photo` SET `description` = '$text' WHERE `pid` = '$pid'";
    $result = mysqli_query($link, $sql);

    if($result){
        exit(json_encode(array("status"=>"success")));
    }else{
        exit(json_encode(array("status"=>"fail")));
    }

}else if($_POST["method"] == "delete"){
    $pid = $_POST["pid"];
    
    $sql ="UPDATE `photo` SET `hidden` = '1' WHERE `pid` = '$pid' AND `mid` = '$mid'";
    $result = mysqli_query($link, $sql);

    if($result){
        $msg = "刪除成功";
    }else{
        $msg = "刪除失敗";
    }

    echo "<script>";
    echo "alert('".$msg."');";
    echo "window.location.href = './index.php';";
    echo "</script>";
}
