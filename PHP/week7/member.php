<?php
include './config.php';
session_start();

if ($_POST['loginMode'] == 1) {
    $search_value = $_POST['acc'];

    $sql = "SELECT * FROM `member` where `acc` = '$search_value'";

    // 執行 SQL 訪問
    $result = mysqli_query($link, $sql);
    
    // 檢驗回傳數量
    $num = mysqli_num_rows($result);


    if ($num == 1) {
        $acc = $_POST['acc'];
        $pass = $_POST['pass'];

        if ($result->fetch_array()['pass'] == $pass) { ?>
<script>
alert('登入成功');
window.location.href = './index.php';
</script>
<?php
        } else {?>
<script>
alert('密碼錯誤');
window.location.href = './login.php';
</script>
<?php
        }
    } else {
        ?>
<script>
alert('帳號錯誤');
window.location.href = './login.php';
</script>
<?php
    }
} elseif ($_POST['loginMode'] == 2) {
    $search_value = $_POST['acc'];

    $sql = "SELECT * FROM `member` where `acc` = '$search_value'";

    // 執行 SQL 訪問
    $result = mysqli_query($link, $sql);
    
    // 檢驗回傳數量
    $num = mysqli_num_rows($result);

    if ($num == 0) {
        $acc = $_POST['acc'];
        $pass = $_POST['pass'];
        
        $sql = "INSERT INTO `member` (`acc`, `pass`) VALUES ('$acc', '$pass')";

        mysqli_query($link, $sql); ?>
<script>
alert('註冊成功');
window.location.href = './login.php';
</script>
<?php
    } else { ?>
<script>
alert('該用戶名已經存在');
window.location.href = './login.php';
</script>
<?php
    }
} else { ?>
<script>
alert('未知錯誤');
window.location.href = './login.php';
</script>
<?php
}