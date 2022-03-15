<?php
    include("./config.php");

    print_r($_POST);

    $stu_id = $_POST['stu_id'];
    $stu_name = $_POST['stu_name'];
    $stu_birth = $_POST['stu_birth'];

    $sql = "INSERT INTO `student` (`STUID`, `name`, `birthdate`) VALUES ('$stu_id', '$stu_name', '$stu_birth')";

    $result = mysqli_query($link, $sql);

    if ($result) {
        echo "執行正確";
    } else {
        echo $sql;
        echo "執行錯誤";
    }
