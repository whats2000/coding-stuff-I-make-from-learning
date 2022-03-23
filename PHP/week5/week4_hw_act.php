<?php
session_start();

if(isset($_SESSION["acc"])){
    unset($_SESSION['acc']);

}else{
     $_SESSION["acc"] = $_POST["acc"];
}
echo "<script>";
    echo "alert('操作成功');";
    echo "window.location.href = './week4_hw.php';";
echo "</script>";

?>

<script src="https://code.jquery.com/jquery-3.5.0.min.js"></script>